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
            Scene(const std::string &);
            ~Scene(void) {};

            void AddScreen(Screen &);
            const std::string &Name();
            const screen_list &Screens() const;

        private:
            screen_list *_screens;
            std::string *_name;
        };
    }
}
