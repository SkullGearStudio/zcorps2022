#pragma once

#include <string>
#include <SFML\Graphics.hpp>

#include "SkullEngine.hpp"
#include "Types.hpp"
#include "AssetManager.hpp"
#include "Scene.hpp"

namespace SkullEngine
{
    namespace Window
    {
        class SKULLENGINE_API Window
        {
        private:
            typedef std::map<std::string, Scene *> scene_map;
        public:
            // CTOR / DTOR
            Window(WindowType, uint, uint, const std::string &, Screen &);
            ~Window() {};

            // GETTER
            Asset::AssetManager &ASM();

            // FCT
            void    AddScene(Scene &);
            void    LoadScene(const std::string &);
            void    Exit() const;
            void    Run() const;


        private:
            Asset::AssetManager  &_assets;
            bool    _exit;
            Scene *_current;
            scene_map   _scenes;
            ScreenManager::ScreenManager     &_scm;
            sf::RenderWindow *_render;
        };
    }
}
