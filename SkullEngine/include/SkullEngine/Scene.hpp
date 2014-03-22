#pragma once

#include <list>

#include "SkullEngine.hpp"
#include "Types.hpp"
#include "AGameScreen.hpp"

namespace SkullEngine
{
    namespace Window
    {
        class SKULLENGINE_API Scene
        {
        private:
            typedef std::list<Screen *> screen_list;

        public:
            Scene(void) {};
            ~Scene(void) {};

            void AddScreen(const Screen &);
            const screen_list &Screens() const;

        private:
            screen_list _screens;
        };
    }
}
