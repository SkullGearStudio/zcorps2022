#pragma once

#include <string>
#include <SFML\Graphics.hpp>

#include "SkullEngine.hpp"
#include "Types.hpp"
#include "AGameScreen.hpp"

namespace SkullEngine
{
    namespace Window
    {
        class SKULLENGINE_API Window
        {
        public:
            // CTOR / DTOR
            Window(WindowType, uint, uint, const std::string &, Screen &);
            ~Window() {};

            // GETTER
            //AssetManager &ASM();

            // FCT
            void    AddScene(/*Scene &*/);
            void    LoadScene(const std::string &);
            void    Exit();
            void    Run();


        private:
            //AssetManager  &_asm;
            bool    _exit;
            //Game  &_main;
            //Scene *_current;
            //scene_map   _scenes;
            ScreenManager::ScreenManager     &_scm;
            sf::RenderWindow *_render;
        };
    }
}
