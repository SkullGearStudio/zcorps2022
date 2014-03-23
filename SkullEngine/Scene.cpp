#include "Scene.hpp"

namespace SkullEngine
{
    namespace Window
    {
        Scene::Scene(const std::string &n) :
            _screens(new Scene::screen_list),
            _name(new std::string(n))
        {
        }

        void    Scene::AddScreen(Screen &sc)
        {
            _screens->push_front(&sc);
        }
        const std::string &Scene::Name()
        {
            return *_name;
        }
        Scene::screen_list &Scene::Screens() const
        {
            return *_screens;
        }
    }
}
