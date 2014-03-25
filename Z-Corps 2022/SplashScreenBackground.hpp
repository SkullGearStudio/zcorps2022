#pragma once

#include <Skullengine\AGameScreen.hpp>
#include <SkullEngine\Assets.hpp>

class SplashScreenBackground : public SkullEngine::GameScreen::AGameScreen
{
public:
    SplashScreenBackground(SkullEngine::ScreenManager::ScreenManager &,
                           SkullEngine::Asset::AssetManager &,
                           SkullEngine::Window::Window &,
                           SkullEngine::Core &);
    ~SplashScreenBackground(void) {};

    void    Init();
    void    Update() {};
    void    Event();
    void    Draw();
    void    Destroy() {};

private:
    SkullEngine::Asset::SimpleSprite   *_background;
};

