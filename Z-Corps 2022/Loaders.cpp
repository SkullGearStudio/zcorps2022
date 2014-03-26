#include <iostream>
#include <SkullEngine\Window.hpp>
#include <SkullEngine\Core.hpp>
#include <SkullEngine\Assets.hpp>

#include "SplashScreenLoader.hpp"
#include "Screens.hpp"

void    SplashScreenLoader::ImgLoad()
{
    SkullEngine::Asset::Texture *main_menu_bg_tex = new SkullEngine::Asset::Texture("main_menu_background_texture", "Assets/img/menu_background.jpg");
    _assets.LoadAsset(*main_menu_bg_tex);
    SkullEngine::Asset::SimpleSprite *main_menu_bg = new SkullEngine::Asset::SimpleSprite("main_menu_background", _assets.GetAsset("main_menu_background_texture"));
    _assets.LoadAsset(*main_menu_bg);

    _core.cout("Imgs loaded...");
}

void    SplashScreenLoader::WindowLoad()
{
    _mutexL.lock();
    SkullEngine::Window::Window *gameWin = new SkullEngine::Window::Window(SkullEngine::WindowType::DEFAULT, 1600, 900, "Z-Corps 2022", _assets, _core);
    
    _core.AddWindow(*gameWin);
    _core.cout("Game window created...");
    _mutexL.unlock();
}

void    SplashScreenLoader::ScenesLoad()
{
    _mutexL.lock();
    SkullEngine::Window::Window &gameWin = _core.getWin("Z-Corps 2022");

    SkullEngine::Window::Scene *menuScene = new SkullEngine::Window::Scene("main_menu");
    SkullEngine::Window::Scene *optionScene = new SkullEngine::Window::Scene("option_menu");

    gameWin.FirstScene(*menuScene);
    gameWin.AddScene(*optionScene);
    _core.cout("Game scenes created...");
    _mutexL.unlock();
}

void    SplashScreenLoader::ScreensLoad()
{
    _mutexL.lock();
    SkullEngine::Window::Window &gameWin = _core.getWin("Z-Corps 2022");
    SkullEngine::Window::Scene &menuScene = gameWin.getScene("main_menu");

    MainMenuBackground *main_menu_bg = new MainMenuBackground(gameWin.Manager(), _assets, gameWin, _core);
    menuScene.AddScreen(*main_menu_bg);
    _core.cout("Game screens loaded");
    _mutexL.unlock();
}
