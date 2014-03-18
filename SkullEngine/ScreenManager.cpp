#include "ScreenManager.hpp"
#include "Exception.hpp"

namespace SkullEngine
{
    namespace ScreenManager
    {
        void	ScreenManager::AddScreen(Screen &screen)
        {
            _screens[screen.Name()] = &screen;
        }
        void	ScreenManager::RemoveScreen(const std::string &screenName)
        {
            screen_map::iterator it = _screens.find(screenName);
            Screen	*selected;

            try
            {
                if (it == _screens.end())
                    throw Exception(std::string("Screen [" + screenName + "] doesn't exist").c_str());
                selected = it->second;
                if (selected->IsActive())
                    UnactiveScreen(selected);
                _screens.erase(it);
            } catch (Exception ex)
            {
                ex.box();
                ::exit(-1);
            }
        }
        void	ScreenManager::ActiveScreen(const std::string &screenName)
        {
            screen_map::iterator it = _screens.find(screenName);
            screen_list::iterator l = _active.begin();
            Screen	*selected;

            try
            {
                if (it == _screens.end())
                    throw Exception(std::string("Screen [" + screenName + "] doesn't exist").c_str());
                selected = it->second;
                if (selected->IsActive())
                    throw Exception(std::string("Screen [" + screenName + "] is already active").c_str());
                selected->On();
                selected->PopUp();
                while (l != _active.end())
                {
                    (*l)->LayerDown();
                    (*l)->PopDown();
                    ++l;
                }
                _active.push_front(selected);
            } catch (Exception ex)
            {
                ex.box();
                ::exit(-1);
            }
        }
        void	ScreenManager::UnactiveScreen(const std::string &screenName)
        {
            screen_map::iterator it = _screens.find(screenName);
            Screen	*selected;

            try
            {
                if (it == _screens.end())
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
            Screen *maxLayer = NULL;
            screen_list::iterator it = _active.begin();

            try
            {
                if (!screen->IsActive())
                    throw Exception(std::string("Screen [" + screen->Name() + "] is already unactive").c_str());
                screen->Off();
                screen->PopDown();
                while (it != _active.end())
                {
                    if ((*it)->Name() == screen->Name())
                        _active.erase(it);
                    ++it;
                }
                it = _active.begin();
                maxLayer = *it;
                while (it != _active.end())
                {
                    (*it)->LayerUp();
                    if (maxLayer->Layer() < (*it)->Layer())
                        maxLayer = *it;
                    ++it;
                }
                maxLayer->PopUp();
            } catch (Exception ex)
            {
                ex.box();
                ::exit(-1);
            }
        }
    }
}
