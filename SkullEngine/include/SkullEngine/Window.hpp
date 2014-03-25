#pragma once

#include <string>
#include <SFML\Graphics.hpp>
#include <SFML\System\Clock.hpp>


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
            Window(WindowType, uint, uint, const std::string &, Asset::AssetManager &);
            ~Window() {};

            // GETTER
            ScreenManager::ScreenManager    &Manager();
            const std::string   &Name();
            Scene   &getScene(const std::string &);

            // FCT
            void    FirstScene(Scene &);
            void    AddScene(Scene &);
            void    LoadScene(const std::string &);
            void    LoadScene(Scene &); // TODO
            sf::RenderWindow &Render();
            void    Start();
            void    Exit();
            void    Run();

        private:
            WindowType  _type;
            uint    _width;
            uint    _height;
            std::string *_name;
            Asset::AssetManager  &_assets;
            bool    _exit;
            Scene *_current;
            scene_map   _scenes;
            ScreenManager::ScreenManager _scm;
            sf::RenderWindow *_render;
            sf::Clock _clock;
        };
    }
}
