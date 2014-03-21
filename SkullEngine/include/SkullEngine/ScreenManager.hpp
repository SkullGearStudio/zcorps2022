#pragma once

#include <map>
#include <list>

#include "SkullEngine.hpp"
#include "AGameScreen.hpp"
#include "Types.hpp"

namespace SkullEngine
{
    namespace ScreenManager
    {
        class SKULLENGINE_API ScreenManager
        {
        private:
            typedef	std::map<std::string, Screen *> screen_map;
            typedef std::list<Screen *> screen_list;

        public:
            ScreenManager(void) {};
            ~ScreenManager(void) {};

            void	AddScreen(Screen &);
            void	RemoveScreen(const std::string &);
            void	ActiveScreen(const std::string &);
            void	UnactiveScreen(const std::string &);
            void	UnactiveScreen(Screen *);
            void	Dump();
            void	Run();

        private:
            screen_map _screens;
            screen_list _actives;
        };
    }
}
