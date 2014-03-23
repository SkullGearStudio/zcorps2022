#pragma once

#include <string>
#include <SFML\Graphics.hpp>


#include "SkullEngine\ScreenManager.hpp"
#include "SkullEngine\Types.hpp"
#include "SkullEngine\AssetManager.hpp"
#include "SkullEngine\Scene.hpp"

namespace SkullEngine
{
    namespace Window
    {
        class Window
        {
        private:
            typedef std::map<std::string, Scene *> scene_map;
            typedef std::list<Screen *> screen_list;
        public:
            // CTOR / DTOR
            Window(WindowType, uint, uint, const std::string &, Scene &, Asset::AssetManager &);
            ~Window() {};

            // GETTER
            Asset::AssetManager &ASM();
            ScreenManager::ScreenManager    &Window::Manager();

            // FCT
            void    AddScene(Scene &);
            void    LoadScene(const std::string &);
            void    LoadScene(Scene &); // TODO
            sf::RenderWindow &Render();
            void    Start();
            void    Exit() const;
            void    Run() const;


        private:
            WindowType  _type;
            uint    _width;
            uint    _height;
            std::string *_name;
            Asset::AssetManager  &_assets;
            bool    _exit;
            Scene *_current;
            scene_map   _scenes;
            ScreenManager::ScreenManager *_scm;
            sf::RenderWindow *_render;
        };
    }
}
