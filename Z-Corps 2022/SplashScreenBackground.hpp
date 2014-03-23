#pragma once

#include "Skullengine\AGameScreen.hpp"
#include "SkullEngine\Assets.hpp"

class SplashScreenBackground : public SkullEngine::GameScreen::AGameScreen
{
public:
    SplashScreenBackground(SkullEngine::ScreenManager::ScreenManager &);
    ~SplashScreenBackground(void) {};

    void    Init();
    void    Update() {};
    void    Event() {};
    void    Draw();
    void    Destroy() {};

private:
    SkullEngine::Asset::Image   *_background;
};

