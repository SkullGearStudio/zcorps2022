#include <iostream>
#include <SkullEngine\Window.hpp>
#include <SkullEngine\Core.hpp>
#include <SkullEngine\Assets.hpp>

#include "SplashScreenLoader.hpp"
#include "Screens.hpp"

void    SplashScreenLoader::ImgLoad()
{
    // MAIN MENU
    SkullEngine::Asset::Texture *main_menu_bg_tex = new SkullEngine::Asset::Texture("main_menu_background_texture", "Assets/img/menu_background.jpg");
    _assets.LoadAsset(*main_menu_bg_tex);
    SkullEngine::Asset::SimpleSprite *main_menu_bg = new SkullEngine::Asset::SimpleSprite("main_menu_background", _assets.GetAsset("main_menu_background_texture"));
    _assets.LoadAsset(*main_menu_bg);

    // GAME BG
    SkullEngine::Asset::Texture *up_left_tex = new SkullEngine::Asset::Texture("up_left_texture", "Assets/img/up_left.png");
    _assets.LoadAsset(*up_left_tex);
    SkullEngine::Asset::SimpleSprite *up_left = new SkullEngine::Asset::SimpleSprite("up_left", _assets.GetAsset("up_left_texture"));
    _assets.LoadAsset(*up_left);
    up_left->res().setPosition(0, 0);

    SkullEngine::Asset::Texture *up_center_tex = new SkullEngine::Asset::Texture("up_center_texture", "Assets/img/up_center.png", true);
    _assets.LoadAsset(*up_center_tex);
    SkullEngine::Asset::SimpleSprite *up_center = new SkullEngine::Asset::SimpleSprite("up_center", _assets.GetAsset("up_center_texture"));
    _assets.LoadAsset(*up_center);
    up_center->res().setTextureRect(sf::IntRect(0, 0, (W_WIDTH - (300 + 300)), 101));
    up_center->res().setPosition(300, 0);

    SkullEngine::Asset::Texture *up_right_tex = new SkullEngine::Asset::Texture("up_right_texture", "Assets/img/up_right.png");
    _assets.LoadAsset(*up_right_tex);
    SkullEngine::Asset::SimpleSprite *up_right = new SkullEngine::Asset::SimpleSprite("up_right", _assets.GetAsset("up_right_texture"));
    _assets.LoadAsset(*up_right);
    up_right->res().setPosition((300 + (W_WIDTH - (300 + 300))), 0);

    SkullEngine::Asset::Texture *center_left_tex = new SkullEngine::Asset::Texture("center_left_texture", "Assets/img/center_left.png", true);
    _assets.LoadAsset(*center_left_tex);
    SkullEngine::Asset::SimpleSprite *center_left = new SkullEngine::Asset::SimpleSprite("center_left", _assets.GetAsset("center_left_texture"));
    _assets.LoadAsset(*center_left);
    center_left->res().setTextureRect(sf::IntRect(0, 0, 300, (W_HEIGHT - (101 + 143))));
    center_left->res().setPosition(0, 101);

    SkullEngine::Asset::Texture *center_center_tex = new SkullEngine::Asset::Texture("center_center_texture", "Assets/img/center_center.png", true);
    _assets.LoadAsset(*center_center_tex);
    SkullEngine::Asset::SimpleSprite *center_center = new SkullEngine::Asset::SimpleSprite("center_center", _assets.GetAsset("center_center_texture"));
    _assets.LoadAsset(*center_center);
    center_center->res().setTextureRect(sf::IntRect(0, 0, (W_WIDTH - (300 + 300)), (W_HEIGHT - (101 + 143))));
    center_center->res().setPosition(300, 101);

    SkullEngine::Asset::Texture *center_right_tex = new SkullEngine::Asset::Texture("center_right_texture", "Assets/img/center_right.png", true);
    _assets.LoadAsset(*center_right_tex);
    SkullEngine::Asset::SimpleSprite *center_right = new SkullEngine::Asset::SimpleSprite("center_right", _assets.GetAsset("center_right_texture"));
    _assets.LoadAsset(*center_right);
    center_right->res().setTextureRect(sf::IntRect(0, 0, 300, (W_HEIGHT - (101 + 143))));
    center_right->res().setPosition((W_WIDTH - 300), 101);

    SkullEngine::Asset::Texture *down_left_tex = new SkullEngine::Asset::Texture("down_left_texture", "Assets/img/down_left.png");
    _assets.LoadAsset(*down_left_tex);
    SkullEngine::Asset::SimpleSprite *down_left = new SkullEngine::Asset::SimpleSprite("down_left", _assets.GetAsset("down_left_texture"));
    _assets.LoadAsset(*down_left);
    down_left->res().setPosition(0, (W_HEIGHT - 143));

    SkullEngine::Asset::Texture *down_center_tex = new SkullEngine::Asset::Texture("down_center_texture", "Assets/img/down_center.png", true);
    _assets.LoadAsset(*down_center_tex);
    SkullEngine::Asset::SimpleSprite *down_center = new SkullEngine::Asset::SimpleSprite("down_center", _assets.GetAsset("down_center_texture"));
    _assets.LoadAsset(*down_center);
    down_center->res().setTextureRect(sf::IntRect(0, 0, (W_WIDTH - (300 + 300)),  143));
    down_center->res().setPosition(300, (W_HEIGHT - 143));

    SkullEngine::Asset::Texture *down_right_tex = new SkullEngine::Asset::Texture("down_right_texture", "Assets/img/down_right.png");
    _assets.LoadAsset(*down_right_tex);
    SkullEngine::Asset::SimpleSprite *down_right = new SkullEngine::Asset::SimpleSprite("down_right", _assets.GetAsset("down_right_texture"));
    _assets.LoadAsset(*down_right);
    down_right->res().setPosition(W_WIDTH - 300, W_HEIGHT - 143);
    
    _core.cout("Imgs loaded...");
}

void    SplashScreenLoader::WindowLoad()
{
    _mutexL.lock();
    SkullEngine::Window::Window *gameWin = new SkullEngine::Window::Window(SkullEngine::WindowType::DEFAULT, W_WIDTH, W_HEIGHT, W_TITLE, _assets, _core);
    
    _core.AddWindow(*gameWin);
    _core.cout("Game window created...");
    _mutexL.unlock();
}

void    SplashScreenLoader::ScenesLoad()
{
    _mutexL.lock();
    SkullEngine::Window::Window &gameWin = _core.getWin("Z-Corps 2022");

    SkullEngine::Window::Scene *menuScene = new SkullEngine::Window::Scene("main_menu");
    SkullEngine::Window::Scene *optionScene = new SkullEngine::Window::Scene("option_menu");

    gameWin.FirstScene(*menuScene);
    gameWin.AddScene(*optionScene);
    _core.cout("Game scenes created...");
    _mutexL.unlock();
}

void    SplashScreenLoader::ScreensLoad()
{
    _mutexL.lock();
    SkullEngine::Window::Window &gameWin = _core.getWin("Z-Corps 2022");
    SkullEngine::Window::Scene &menuScene = gameWin.getScene("main_menu");

    MainMenuBackground *main_menu_bg = new MainMenuBackground(gameWin.Manager(), _assets, gameWin, _core);
    menuScene.AddScreen(*main_menu_bg);
    GameBackground *game_bg = new GameBackground(gameWin.Manager(), _assets, gameWin, _core);
    menuScene.AddScreen(*game_bg);

    _core.cout("Game screens loaded");
    _mutexL.unlock();
}
