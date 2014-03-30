#pragma once

#define W_WIDTH 1600
#define W_HEIGHT 900
#define W_TITLE "Z-Corps 2022"

#include "SplashScreenBackground.hpp"
#include "SplashScreenLoader.hpp"
#include "MainMenuBackground.hpp"
#include "GameBackground.hpp"

void    initSplashScreen(SkullEngine::Core &, SkullEngine::Asset::AssetManager &);
