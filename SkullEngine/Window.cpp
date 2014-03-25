#include "SkullEngine/Window.hpp"

namespace SkullEngine
{
    namespace Window
    {
        Window::Window(WindowType t, uint w, uint h, const std::string &n, Asset::AssetManager &a) :
            _type(t),
            _width(w),
            _height(h),
            _name(new std::string(n)),
            _assets(a),
            _exit(false),
            _current(NULL),
            _scm(ScreenManager::ScreenManager(*this))
        {
        }

        ScreenManager::ScreenManager    &Window::Manager()
        {
            return _scm;
        }
        const std::string &Window::Name()
        {
            return *_name;
        }

        void    Window::FirstScene(Scene &s)
        {
            _scenes[s.Name()] = &s;
            _current = &s;
        }
        void    Window::AddScene(Scene &s)
        {
            _scenes[s.Name()] = &s;
        }
        void    Window::LoadScene(const std::string &name)
        {
            scene_map::iterator it = _scenes.find(name);

            if (it != _scenes.end())
                LoadScene(*(it->second));
        }
        void    Window::LoadScene(Scene &s)
        {
            screen_list::iterator it = s.Screens().begin();

            _scm.Purge();
            while (it != s.Screens().end())
            {
                Screen &current = *(*it);
                _scm.LoadFromScene(current);
                ++it;
            }
            _scm.OrderActive();
        }
        sf::RenderWindow  &Window::Render()
        {
            return *_render;
        }
        void    Window::Start()
        {
            if (_type == WindowType::SPLASHSCREEN)
                _render = new sf::RenderWindow(sf::VideoMode(_width, _height), "", sf::Style::None);
            else
                _render = new sf::RenderWindow(sf::VideoMode(_width, _height), *_name, sf::Style::Close | sf::Style::Titlebar);
            _clock.restart();
            LoadScene(*_current);
        }
        void    Window::Exit()
        {
            _render->close();
        }
        void    Window::Run()
        {
            _scm.Run(_clock);
        }
    }
}
