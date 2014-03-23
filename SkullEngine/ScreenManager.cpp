#include "ScreenManager.hpp"
#include "Exception.hpp"

#include <algorithm>

namespace SkullEngine
{
    namespace ScreenManager
    {
        struct LayerComparator
        {
            bool operator() (Screen *s1, Screen *s2) { return (true); }
        } LayerComp;

        ScreenManager::ScreenManager(Window::Window &w) :
            _screens(new screen_map),
            _actives(new screen_list),
            _win(w)
        {
        }
        void	ScreenManager::AddScreen(Screen &screen)
        {
            (*_screens)[screen.Name()] = &screen;
            screen.Init();
        }
        void    ScreenManager::LoadFromScene(Screen &sc)
        {
            (*_screens)[sc.Name()] = &sc;
            sc.Init();
            if (sc.IsActive())
                _actives->push_front(&sc);
            OrderActive();
        }
        void	ScreenManager::RemoveScreen(const std::string &screenName)
        {
            screen_map::iterator it = _screens->find(screenName);
            Screen	*selected;

            try
            {
                if (it == _screens->end())
                    throw Exception(std::string("Screen [" + screenName + "] doesn't exist").c_str());
                selected = it->second;
                if (selected->IsActive())
                    UnactiveScreen(selected);
                //selected->Destroy();
                _screens->erase(it);
            } catch (Exception ex)
            {
                ex.box();
                ::exit(-1);
            }
        }
        void	ScreenManager::ActiveScreen(const std::string &screenName)
        {
            screen_map::iterator it = _screens->find(screenName);
            screen_list::iterator l = _actives->begin();
            Screen	*selected;

            try
            {
                if (it == _screens->end())
                    throw Exception(std::string("Screen [" + screenName + "] doesn't exist").c_str());
                selected = it->second;
                selected->On();
                selected->PopUp();
                while (l != _actives->end())
                {
                    (*l)->LayerDown();
                    (*l)->PopDown();
                    ++l;
                }
                _actives->push_front(selected);
                OrderActive();
            } catch (Exception ex)
            {
                ex.box();
                ::exit(-1);
            }
        }
        void	ScreenManager::UnactiveScreen(const std::string &screenName)
        {
            screen_map::iterator it = _screens->find(screenName);
            Screen	*selected;

            try
            {
                if (it == _screens->end())
                    throw Exception(std::string("Screen [" + screenName + "] doesn't exist").c_str());
                selected = it->second;
                UnactiveScreen(selected);
            } catch (Exception ex)
            {
                ex.box();
                ::exit(-1);
            }
        }
        void	ScreenManager::UnactiveScreen(Screen *screen)
        {
            screen_list::iterator it = _actives->begin();

            screen->Off();
            screen->PopDown();
            while (it != _actives->end())
            {
                if ((*it)->Name() == screen->Name())
                    _actives->erase(it);
                ++it;
            }            
            OrderActive();
            it = _actives->begin();
            (*it)->PopUp();
        }
        const Window::Window &ScreenManager::Win() const
        {
            return _win;
        }
        void    ScreenManager::OrderActive()
        {
            _actives->sort(LayerComp);
        }
        void    ScreenManager::Break()
        {
            break_r = true;
        }
        void    ScreenManager::Purge()
        {
            while (!_screens->empty())
                RemoveScreen(_screens->begin()->second->Name());
        }
        void    ScreenManager::Run()
        {
            screen_list::iterator it = _actives->begin();

            break_r = false;
            while (it != _actives->end())
            {
                if ((*it)->IsPopup())
                    (*it)->Event();
                if (break_r)
                    break;
                (*it)->Update();
                if (break_r)
                    break;
                (*it)->Draw();
                ++it;
            }
        }
    }
}
