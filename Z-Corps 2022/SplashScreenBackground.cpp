#include <SkullEngine\ScreenManager.hpp>
#include <SkullEngine\Window.hpp>

#include "SplashScreenBackground.hpp"



SplashScreenBackground::SplashScreenBackground(SkullEngine::ScreenManager::ScreenManager &scm, SkullEngine::Asset::AssetManager &am, SkullEngine::Window::Window &w) :
    AGameScreen(scm, am, w, "Splash Screen")
{
}

void    SplashScreenBackground::Init()
{
    On();
    _background = &dynamic_cast<SkullEngine::Asset::SimpleSprite &>(_assets.GetAsset("splash_background"));
}

void    SplashScreenBackground::Draw()
{
    _win.Render().draw(_background->res());
}
