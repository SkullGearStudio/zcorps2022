#pragma once

#include "Skullengine\AGameScreen.hpp"

class SplashScreen : public SkullEngine::GameScreen::AGameScreen
{
public:
    SplashScreen(SkullEngine::ScreenManager::ScreenManager &);
    ~SplashScreen(void);

    void    Init() const {};
    void    Update() const {};
    void    Event() const {};
    void    Draw() const {};
    void    Destroy() const {};
};

