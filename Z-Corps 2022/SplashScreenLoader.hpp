#pragma once

#include <SkullEngine\AGameScreen.hpp>

class SplashScreenLoader : public SkullEngine::GameScreen::AGameScreen
{
public:
    SplashScreenLoader(SkullEngine::ScreenManager::ScreenManager &,
                       SkullEngine::Asset::AssetManager &,
                       SkullEngine::Window::Window &,
                       SkullEngine::Core &);
    ~SplashScreenLoader(void) {};
};
