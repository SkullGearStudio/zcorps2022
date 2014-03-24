#pragma once

#include <map>
#include <list>

#include "AGameScreen.hpp"
#include "Types.hpp"
#include "SFML\System\Clock.hpp"

namespace SkullEngine
{
    namespace Window
    {
        class Window;
    }

    namespace ScreenManager
    {
        class ScreenManager
        {
        private:
            typedef	std::map<std::string, Screen *> screen_map;
            typedef std::list<Screen *> screen_list;

        public:
            ScreenManager(Window::Window &);
            ~ScreenManager(void) {};

            void	AddScreen(Screen &);
            void    LoadFromScene(Screen &);
            void	RemoveScreen(const std::string &);
            void	ActiveScreen(const std::string &);
            void	UnactiveScreen(const std::string &);
            void	UnactiveScreen(Screen *);
            Window::Window  &Win() const;
            void    OrderActive();
            void    Break();
            void    Purge();
            void	Run(sf::Clock &);

        private:
            screen_map *_screens;
            screen_list *_actives;
            Window::Window  &_win;
            bool    break_r;
        };
    }
}
