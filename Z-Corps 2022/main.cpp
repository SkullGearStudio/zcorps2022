#include <iostream>

#include <SkullEngine\Core.hpp>
#include <SkullEngine\Window.hpp>
#include <SkullEngine\Assets.hpp>

#include "Screens.hpp"

int     main()
{
    SkullEngine::Core GameCore;
    GameCore.cout("Game core initialized...");
    SkullEngine::Asset::AssetManager &AssetManager = GameCore.Assets();
    GameCore.cout("Asset manager initialized...");
    
    initSplashScreen(GameCore, AssetManager);
    GameCore.Run();

    //system("PAUSE");
    return 0;
}
