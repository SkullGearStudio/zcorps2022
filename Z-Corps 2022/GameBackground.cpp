#include <iostream>
#include <SkullEngine\ScreenManager.hpp>
#include <SkullEngine\Window.hpp>

#include "GameBackground.hpp"

GameBackground::GameBackground(SkullEngine::ScreenManager::ScreenManager &scm, SkullEngine::Asset::AssetManager &am, SkullEngine::Window::Window &w, SkullEngine::Core &c) :
    AGameScreen(scm, am, w, c, "main_menu_background")
{
    _up_left = &dynamic_cast<SkullEngine::Asset::SimpleSprite &>(_assets.GetAsset("up_left"));
    _up_center = &dynamic_cast<SkullEngine::Asset::SimpleSprite &>(_assets.GetAsset("up_center"));
    _up_right = &dynamic_cast<SkullEngine::Asset::SimpleSprite &>(_assets.GetAsset("up_right"));
    _center_left = &dynamic_cast<SkullEngine::Asset::SimpleSprite &>(_assets.GetAsset("center_left"));
    _center_center = &dynamic_cast<SkullEngine::Asset::SimpleSprite &>(_assets.GetAsset("center_center"));
    _center_right = &dynamic_cast<SkullEngine::Asset::SimpleSprite &>(_assets.GetAsset("center_right"));
    _down_left = &dynamic_cast<SkullEngine::Asset::SimpleSprite &>(_assets.GetAsset("down_left"));
    _down_center = &dynamic_cast<SkullEngine::Asset::SimpleSprite &>(_assets.GetAsset("down_center"));
    _down_right = &dynamic_cast<SkullEngine::Asset::SimpleSprite &>(_assets.GetAsset("down_right"));
}

void    GameBackground::Init()
{
    On();
    //LayerDown();
    //PopUp();
}

void    GameBackground::Draw()
{
    _win.Render().draw(_up_left->res());
    _win.Render().draw(_up_center->res());
    _win.Render().draw(_up_right->res());
    _win.Render().draw(_center_left->res());
    _win.Render().draw(_center_center->res());
    _win.Render().draw(_center_right->res());
    _win.Render().draw(_down_left->res());
    _win.Render().draw(_down_center->res());
    _win.Render().draw(_down_right->res());
}
