#include "SplashScreenBackground.hpp"
#include "SkullEngine\ScreenManager.hpp"
#include "SkullEngine\Window.hpp"


SplashScreenBackground::SplashScreenBackground(SkullEngine::ScreenManager::ScreenManager &scm) :
    AGameScreen(scm, "Splash Screen")
{
}

void    SplashScreenBackground::Init()
{
    _background = &reinterpret_cast<SkullEngine::Asset::Image &>(Manager().Win().ASM().GetAsset("splash_background_image"));
    On();
}

void    SplashScreenBackground::Draw()
{
    Manager().Win().Render().draw(_background->res());
}
