#pragma once

#include <queue>

#include "SkullEngine.hpp"
#include "AssetManager.hpp"
#include "Window.hpp"

namespace SkullEngine
{
    class SKULLENGINE_API Core
    {
    private:
        typedef std::queue<Window::Window *> window_queue;
    public:
        Core() {};
        ~Core() {};

        void AddWindow(Window::Window &);
        void Run();
        Asset::AssetManager &Assets();

    private:
        Asset::AssetManager _assets;
        Window::Window  *_current;
        window_queue    _windows;

    };
}
