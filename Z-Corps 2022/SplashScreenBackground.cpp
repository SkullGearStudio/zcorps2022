#include <iostream>
#include <SkullEngine\ScreenManager.hpp>
#include <SkullEngine\Window.hpp>

#include "SplashScreenBackground.hpp"



SplashScreenBackground::SplashScreenBackground(SkullEngine::ScreenManager::ScreenManager &scm, SkullEngine::Asset::AssetManager &am, SkullEngine::Window::Window &w, SkullEngine::Core &c) :
    AGameScreen(scm, am, w, c, "Splash Screen")
{
}

void    SplashScreenBackground::Init()
{
    On();
    LayerDown();
    _background = &dynamic_cast<SkullEngine::Asset::SimpleSprite &>(_assets.GetAsset("splash_background"));
}

void    SplashScreenBackground::Draw()
{
    std::cout << "Draw background" << std::endl;
    _win.Render().draw(_background->res());
}
