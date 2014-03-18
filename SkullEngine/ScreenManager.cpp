#include "ScreenManager.hpp"

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

            /*if (it == _screens.end())
            exception*/
            selected = it->second;
            if (selected->IsActive())
                UnactiveScreen(selected);
            _screens.erase(it);
        }
        void	ScreenManager::ActiveScreen(const std::string &screenName)
        {
            screen_map::iterator it = _screens.find(screenName);
            screen_list::iterator l = _active.begin();
            Screen	*selected;

            /*if (it == _screens.end())
            exception*/
            selected = it->second;
            selected->On();
            selected->PopUp();
            while (l != _active.end())
            {
                (*l)->LayerDown();
                (*l)->PopDown();
                ++l;
            }
            _active.push_front(selected);
        }
        void	ScreenManager::UnactiveScreen(const std::string &screenName)
        {
            screen_map::iterator it = _screens.find(screenName);
            Screen	*selected;
            /*if (it == _screens.end())
            exception*/
            selected = it->second;
            UnactiveScreen(selected);
        }
        void	ScreenManager::UnactiveScreen(Screen *screen)
        {
            Screen *maxLayer = NULL;
            screen_list::iterator it = _active.begin();

            /*if (!(screen->IsActive()))
            exception*/
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
        }
    }
}
