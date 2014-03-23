#include "SplashScreenBackground.hpp"
#include "SkullEngine\ScreenManager.hpp"
#include "SkullEngine\Window.hpp"


SplashScreenBackground::SplashScreenBackground(SkullEngine::ScreenManager::ScreenManager &scm, SkullEngine::Asset::AssetManager &am, SkullEngine::Window::Window &w) :
    AGameScreen(scm, am, w, "Splash Screen")
{
}

void    SplashScreenBackground::Init()
{
    On();
    _background = &dynamic_cast<SkullEngine::Asset::Image &>(_assets.GetAsset("splash_background_image"));
}

void    SplashScreenBackground::Draw()
{
}
