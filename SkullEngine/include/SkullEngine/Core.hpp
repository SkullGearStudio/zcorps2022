#pragma once

#include <queue>

#include "SkullEngine\AssetManager.hpp"
#include "SkullEngine\Window.hpp"

namespace SkullEngine
{
    class Core
    {
    private:
        typedef std::queue<Window::Window *> window_queue;
        typedef std::map<std::string, Window::Window *> window_map;
    public:
        Core() {};
        ~Core() {};

        Window::Window  &getWin(const std::string &);
        void AddWindow(Window::Window &);
        void Run();
        Asset::AssetManager &Assets();

    private:
        Asset::AssetManager _assets;
        Window::Window  *_current;
        window_queue    _windows;
        window_map      _map;

    };
}
