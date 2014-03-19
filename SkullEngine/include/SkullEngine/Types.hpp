#pragma once

namespace SkullEngine
{
    // Forward declaration
    namespace GameScreen
    {
        class AGameScreen;
    }

    typedef unsigned short  ushort;
    typedef unsigned int    uint;
    typedef GameScreen::AGameScreen Screen;
    typedef	std::map<std::string, Screen *> screen_map;
    typedef std::list<Screen *> screen_list;
}
