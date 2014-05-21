#include <iostream>
#include <Windows.h>
#include <SkullEngine\Window.hpp>
#include <SkullEngine\Core.hpp>

#include "SplashScreenLoader.hpp"

SplashScreenLoader::oppTab  _load_tab[] =
{
    { false, &SplashScreenLoader::ImgLoad },
    { false, &SplashScreenLoader::WindowLoad },
    { false, &SplashScreenLoader::ScenesLoad },
    { false, &SplashScreenLoader::ScreensLoad },
    { false, NULL}
};

SplashScreenLoader::SplashScreenLoader(SkullEngine::ScreenManager::ScreenManager &scm, SkullEngine::Asset::AssetManager &am, SkullEngine::Window::Window &w, SkullEngine::Core &c) :
    AGameScreen(scm, am, w, c, "splash_screen_loader"),
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
    int i;
    fct_ptr ptr;

    if (_mutexL.try_lock())
    {
        i = 0;
        while (_load_tab[i]._fct != NULL && _load_tab[i]._trigger == true)
            ++i;
        if (_load_tab[i]._fct == NULL)
        {
            Sleep(1500);
            _core.cout("Load complete !");
            _mutexL.unlock();
            //system("PAUSE");
            //exit(-1);
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

sf::Thread  *SplashScreenLoader::NewThread(sf::Thread *loader, fct_ptr ptr)
{
    sf::Thread *new_loader;

    if (loader != NULL)
        delete loader;
    new_loader = new sf::Thread(ptr, this);
    new_loader->launch();
    return new_loader;
}
