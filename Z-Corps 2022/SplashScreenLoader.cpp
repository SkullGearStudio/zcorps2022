#include <iostream>
#include <SFML\Graphics.hpp>
#include <SFML\System\Vector2.hpp>
#include <SkullEngine\Window.hpp>
#include <SkullEngine\ScreenManager.hpp>
#include <SkullEngine\Core.hpp>

#include "SplashScreenLoader.hpp"

SplashScreenLoader::SplashScreenLoader(SkullEngine::ScreenManager::ScreenManager &scm, SkullEngine::Asset::AssetManager &am, SkullEngine::Window::Window &w, SkullEngine::Core &c) :
    AGameScreen(scm, am, w, c, "Splash Screen Loader"),
    _loader(NULL),
    _winLoad(false),
    _screenLoad(false),
    _stringLoad(false),
    _imgLoad(false),
    _fontLoad(false),
    _objectLoad(false),
    _soundLoad(false)
{
    _load_tab = new oppTab[2];
    _load_tab[0]._trigger = &_winLoad;
    _load_tab[0]._fct = &SplashScreenLoader::WindowLoad;
    _load_tab[1]._trigger = NULL;
    _load_tab[1]._fct = NULL;
}

void    SplashScreenLoader::Init()
{
    On();
    PopUp();
}

void    SplashScreenLoader::Update()
{
    int i = 0;
    fct_ptr ptr;

    if (_mutexL.try_lock())
    {
        while (_load_tab[i]._trigger && *(_load_tab[i]._trigger))
            ++i;
        if (_load_tab[i]._trigger == NULL)
        {
            std::cout << "Load complete !" << std::endl;
            system("PAUSE");
            _mutexL.unlock();
            _win.Exit();
            _manager.Break();
            return ;
        }
        else
        {
            ptr = _load_tab[i]._fct;
            _mutexL.unlock();
            _loader = NewThread(_loader, ptr);
            return ;
        }
    }
}

void    SplashScreenLoader::Draw()
{
    std::cout << "Draw loader" << std::endl;
    sf::RectangleShape rect(sf::Vector2f(10, 10));
    rect.setFillColor(sf::Color::Green);

    if (_mutexD.try_lock())
    {
        _win.Render().draw(rect);
        _mutexD.unlock();
    }
}

void    SplashScreenLoader::WindowLoad()
{
    SkullEngine::Window::Window *gameWin = new SkullEngine::Window::Window(SkullEngine::WindowType::DEFAULT, 1600, 900, "Z-Corps 2022", _assets);
    std::cout << "Game window created" << std::endl;
    _core.AddWindow(*gameWin);
    _winLoad = true;
}

sf::Thread  *SplashScreenLoader::NewThread(sf::Thread *loader, fct_ptr ptr)
{
    sf::Thread *new_loader;

    if (loader != NULL)
        delete loader;
    new_loader = new sf::Thread(ptr, this);
    new_loader->launch();
    return new_loader;
}
