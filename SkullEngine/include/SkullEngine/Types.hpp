#pragma once

// Forward declaration
namespace std
{
    template<typename T, typename U>
    class map;
    template<typename T>
    class list;
}

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
