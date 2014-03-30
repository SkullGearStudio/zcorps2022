#pragma once

#include <Skullengine\AGameScreen.hpp>
#include <SkullEngine\Assets.hpp>

class GameBackground : public SkullEngine::GameScreen::AGameScreen
{
public:
    GameBackground(SkullEngine::ScreenManager::ScreenManager &, SkullEngine::Asset::AssetManager &, SkullEngine::Window::Window &, SkullEngine::Core &);
    ~GameBackground(void) {};

    void    Init();
    void    Update() {};
    void    Draw();
    void    Destroy() {};

private:
    SkullEngine::Asset::SimpleSprite    *_up_left;
    SkullEngine::Asset::SimpleSprite    *_up_center;
    SkullEngine::Asset::SimpleSprite    *_up_right;
    SkullEngine::Asset::SimpleSprite    *_center_left;
    SkullEngine::Asset::SimpleSprite    *_center_center;
    SkullEngine::Asset::SimpleSprite    *_center_right;
    SkullEngine::Asset::SimpleSprite    *_down_left;
    SkullEngine::Asset::SimpleSprite    *_down_center;
    SkullEngine::Asset::SimpleSprite    *_down_right;
};
