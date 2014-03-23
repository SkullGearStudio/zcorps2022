#pragma once

#include <string>
#include <SFML\Graphics.hpp>

#include "SkullEngine.hpp"
#include "ScreenManager.hpp"
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
            typedef std::list<Screen *> screen_list;
        public:
            // CTOR / DTOR
            Window(WindowType, uint, uint, const std::string &, Scene &, Asset::AssetManager &);
            ~Window() {};

            // GETTER
            Asset::AssetManager &ASM();


            // FCT
            void    AddScene(Scene &);
            void    LoadScene(const std::string &);
            void    LoadScene(Scene &); // TODO
            const sf::RenderWindow &Render();
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
