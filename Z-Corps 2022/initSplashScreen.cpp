#include <iostream>
#include <SkullEngine\Core.hpp>
#include <SkullEngine\AssetManager.hpp>
#include <SkullEngine\Assets.hpp>

#include "Screens.hpp"

void    initSplashScreen(SkullEngine::Core &core, SkullEngine::Asset::AssetManager &assets)
{
    SkullEngine::Asset::Texture *bg_tex = new SkullEngine::Asset::Texture("splash_background_texture", "Assets/img/splash.jpg");
    assets.LoadAsset(*bg_tex);
    SkullEngine::Asset::SimpleSprite *bg_spr = new SkullEngine::Asset::SimpleSprite("splash_background", assets.GetAsset("splash_background_texture"));
    assets.LoadAsset(*bg_spr);
    SkullEngine::Asset::Font *consolas = new SkullEngine::Asset::Font("consolas", "Assets/font/consola.ttf");
    assets.LoadAsset(*consolas);
    std::cout << "Splash screen assets loaded..." << std::endl;

    SkullEngine::Window::Window *splash_window = new SkullEngine::Window::Window(SkullEngine::WindowType::SPLASHSCREEN, 1004, 357, "Splash screen", assets);

    SkullEngine::Window::Scene  *splash_scene = new SkullEngine::Window::Scene("Splash Screen");
    SplashScreenBackground  *splash_screen = new SplashScreenBackground(splash_window->Manager(), assets, *splash_window);

    splash_scene->AddScreen(*splash_screen);

    splash_window->FirstScene(*splash_scene);
    std::cout << "Splash window initialized..." << std::endl;

    core.AddWindow(*splash_window);
    std::cout << "Splash screen initialized..." << std::endl;
}
