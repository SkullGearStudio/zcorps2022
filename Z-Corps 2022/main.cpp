#include <iostream>

#include <SkullEngine\Core.hpp>
#include <SkullEngine\Window.hpp>
#include <SkullEngine\Assets.hpp>

#include "Screens.hpp"

int     main()
{
    SkullEngine::Core GameCore;
    std::cout << "Game core initialized..." << std::endl;
    SkullEngine::Asset::AssetManager &AssetManager = GameCore.Assets();
    std::cout << "Asset manager initialized..." << std::endl;
    
    initSplashScreen(GameCore, AssetManager);
    GameCore.Run();

    return 0;
}
