#pragma once

#include <Skullengine\AGameScreen.hpp>
#include <SkullEngine\Assets.hpp>

class MainMenuBackground : public SkullEngine::GameScreen::AGameScreen
{
public:
    MainMenuBackground(SkullEngine::ScreenManager::ScreenManager &, SkullEngine::Asset::AssetManager &, SkullEngine::Window::Window &, SkullEngine::Core &);
    ~MainMenuBackground(void) {};

    void    Init();
    void    Update() {};
    void    Draw();
    void    Destroy() {};

private:
    SkullEngine::Asset::SimpleSprite   *_background;
};
