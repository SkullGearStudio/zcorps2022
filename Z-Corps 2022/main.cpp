#include "SkullEngine\Core.hpp"
#include "SkullEngine\Window.hpp"
#include "SkullEngine\Assets.hpp"
#include "Screens.hpp"

int     main()
{
    SkullEngine::Core GameCore;
    SkullEngine::Asset::AssetManager &AssetManager = GameCore.Assets();

    AssetManager.LoadAsset(SkullEngine::Asset::Texture("splash_background_texture", "Assets/img/splash.jpg"));
    AssetManager.LoadAsset(SkullEngine::Asset::Image("splash_background_image", reinterpret_cast<SkullEngine::Asset::Texture &>(AssetManager.GetAsset("splash_background_texture"))));

    SkullEngine::Window::Scene splash_scene("Splash Screen");
    SkullEngine::Window::Window splash_screen(SkullEngine::WindowType::SPLASHSCREEN, 1004, 357, "Splash screen", splash_scene, AssetManager);

    splash_scene.AddScreen(SplashScreenBackground(splash_screen.Manager()));

    GameCore.AddWindow(splash_screen);
    GameCore.Run();
    
    system("PAUSE");
    return 0;
}
