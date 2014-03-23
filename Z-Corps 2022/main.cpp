#include "SkullEngine\Core.hpp"
#include "SkullEngine\Types.hpp"
#include "SkullEngine\Window.hpp"

int     main()
{
    SkullEngine::Core GameCore;
    SkullEngine::Asset::AssetManager &AssetManager = GameCore.Assets();

    SkullEngine::Window::Scene splash_scene("Splash Screen");
    SkullEngine::Window::Window splash_screen(SkullEngine::WindowType::SPLASHSCREEN, 1004, 357, "Splash screen", splash_scene, AssetManager);
    
    return 0;
}
