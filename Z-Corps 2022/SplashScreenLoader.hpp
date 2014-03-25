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

private:
    typedef void (SplashScreenLoader::*fct_ptr)();
    sf::Thread    *NewThread(sf::Thread *, void (SplashScreenLoader::*)());

    struct oppTab
    {
        bool    *_trigger;
        fct_ptr   _fct;
    };

    oppTab  *_load_tab;

    sf::Thread  *_loader;
    std::mutex  _mutexL;
    std::mutex  _mutexD;

    bool    _winLoad;
    bool    _screenLoad;
    bool    _sceneLoad;
    bool    _stringLoad;
    bool    _imgLoad;
    bool    _fontLoad;
    bool    _objectLoad;
    bool    _soundLoad;
};
