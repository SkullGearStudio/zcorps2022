#pragma once

#include <queue>
#include <fstream>

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
        Core();
        ~Core() {};

        Asset::AssetManager &Assets();
        Window::Window  &getWin(const std::string &);

        void AddWindow(Window::Window &);
        void Run();
        void    cout(const std::string &);
        

    private:
        Asset::AssetManager _assets;
        Window::Window  *_current;
        window_queue    _windows;
        window_map      _map;
        std::ofstream   _output;

    };
}
