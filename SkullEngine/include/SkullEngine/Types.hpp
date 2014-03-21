#pragma once

namespace SkullEngine
{
    namespace GameScreen
    {
        class AGameScreen;
    }
    namespace ScreenManager
    {
        class ScreenManager;
    }

    typedef unsigned short  ushort;
    typedef unsigned int    uint;
    typedef GameScreen::AGameScreen Screen;

    enum WindowType
    {
        DEFAULT,
        SPLASHSCREEN
    };
}
