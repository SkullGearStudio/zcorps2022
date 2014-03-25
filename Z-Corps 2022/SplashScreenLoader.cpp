#include <iostream>
#include <SFML\Graphics.hpp>
#include <SFML\System\Vector2.hpp>
#include <SkullEngine\Window.hpp>
#include <SkullEngine\ScreenManager.hpp>
#include <SkullEngine\Core.hpp>

#include "SplashScreenLoader.hpp"

SplashScreenLoader::oppTab  _load_tab[] =
{
    { false, &SplashScreenLoader::WindowLoad },
    { false, &SplashScreenLoader::SceneLoad },
    { false, NULL}
};

SplashScreenLoader::SplashScreenLoader(SkullEngine::ScreenManager::ScreenManager &scm, SkullEngine::Asset::AssetManager &am, SkullEngine::Window::Window &w, SkullEngine::Core &c) :
    AGameScreen(scm, am, w, c, "Splash Screen Loader"),
    _loader(NULL)
{
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
        while (_load_tab[i]._fct != NULL && _load_tab[i]._trigger == true)
            ++i;
        if (_load_tab[i]._fct == NULL)
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
            _mutexL.unlock();
            _load_tab[i]._trigger = true;
            ptr = _load_tab[i]._fct;
            _loader = NewThread(_loader, ptr);
            return ;
        }
    }
}

void    SplashScreenLoader::Draw()
{
    if (_mutexD.try_lock())
    {
        _mutexD.unlock();
    }
}

void    SplashScreenLoader::WindowLoad()
{
    _mutexL.lock();
    SkullEngine::Window::Window *gameWin = new SkullEngine::Window::Window(SkullEngine::WindowType::DEFAULT, 1600, 900, "Z-Corps 2022", _assets);
    std::cout << "Game window created" << std::endl;
    _core.AddWindow(*gameWin);
    _mutexL.unlock();
}

void    SplashScreenLoader::SceneLoad()
{
    _mutexL.lock();
    SkullEngine::Window::Window &gameWin = _core.getWin("Z-Corps 2022");
    std::cout << "Game scene created" << std::endl;
    _mutexL.unlock();
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
