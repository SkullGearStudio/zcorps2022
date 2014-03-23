#pragma once

#include <list>

#include "SkullEngine\Types.hpp"
#include "SkullEngine\AGameScreen.hpp"

namespace SkullEngine
{
    namespace Window
    {
        class Scene
        {
        private:
            typedef std::list<Screen *> screen_list;

        public:
            Scene(const std::string &);
            ~Scene(void) {};

            void AddScreen(Screen &);
            const std::string &Name();
            screen_list &Screens() const;

        private:
            screen_list *_screens;
            std::string *_name;
        };
    }
}
