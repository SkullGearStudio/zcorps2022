#include "SplashScreenLoader.hpp"

SplashScreenLoader::SplashScreenLoader(SkullEngine::ScreenManager::ScreenManager &scm,
                                       SkullEngine::Asset::AssetManager &am,
                                       SkullEngine::Window::Window &w,
                                       SkullEngine::Core &c) :
    AGameScreen(scm, am, w, c, "Splash Screen Loder")
{
}
