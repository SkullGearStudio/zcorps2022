#include "Core.hpp"

namespace SkullEngine
{
    void    Core::AddWindow(Window::Window &w)
    {
        _windows.push(&w);
    }
    void    Core::Run()
    {
        while (!_windows.empty())
        {
            _current = _windows.front();
            _windows.pop();
            _current->Start();
            while (_current->Render().isOpen())
                _current->Run();
        }
    }
    Asset::AssetManager &Core::Assets()
    {
        return _assets;
    }
}
