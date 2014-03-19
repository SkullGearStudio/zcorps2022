#pragma once

#include <string>
#include <SFML\Graphics.hpp>

#include "Types.hpp"
#include "AGameScreen.hpp"

namespace SkullEngine
{
    namespace Window
    {
        class Window
        {
        public:
            Window(WindowType, uint, uint, const std::string &, Screen &);
            ~Window() {};

        private:
            //AssetManager  &_asm;
            bool    _exit;
            //Game  &_main;
            //Scene *_current;
            //scene_map   _scenes;
            SCM     &_scm;
            sf::RenderWindow *_render;
        };
    }
}
