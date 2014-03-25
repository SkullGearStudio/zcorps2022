#pragma once

#include <mutex>
#include <SFML\System.hpp>
#include <SkullEngine\AGameScreen.hpp>

class SplashScreenLoader : public SkullEngine::GameScreen::AGameScreen
{
public:
    SplashScreenLoader(SkullEngine::ScreenManager::ScreenManager &, SkullEngine::Asset::AssetManager &, SkullEngine::Window::Window &, SkullEngine::Core &);
    ~SplashScreenLoader(void) {};

    void Init();
    void Update();
    void Draw();
    void Destroy() {};

    void    WindowLoad();
    void    SceneLoad();

    typedef void (SplashScreenLoader::*fct_ptr)();
    struct oppTab
    {
        bool    _trigger;
        fct_ptr   _fct;
    };

private:
    sf::Thread    *NewThread(sf::Thread *, void (SplashScreenLoader::*)());

    sf::Thread  *_loader;
    std::mutex  _mutexL;
    std::mutex  _mutexD;
};
