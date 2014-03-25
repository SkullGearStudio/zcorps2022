#include <iostream>
#include <SkullEngine\ScreenManager.hpp>
#include <SkullEngine\Window.hpp>

#include "MainMenuBackground.hpp"



MainMenuBackground::MainMenuBackground(SkullEngine::ScreenManager::ScreenManager &scm, SkullEngine::Asset::AssetManager &am, SkullEngine::Window::Window &w, SkullEngine::Core &c) :
    AGameScreen(scm, am, w, c, "main_menu_background")
{
}

void    MainMenuBackground::Init()
{
    On();
    LayerDown();
    PopUp();
    _background = &dynamic_cast<SkullEngine::Asset::SimpleSprite &>(_assets.GetAsset("main_menu_background"));
}

void    MainMenuBackground::Draw()
{
    _win.Render().draw(_background->res());
}
