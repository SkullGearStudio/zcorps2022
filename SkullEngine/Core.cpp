#include "SkullEngine\Core.hpp"
#include "SkullEngine\Exception.hpp"

namespace SkullEngine
{
    Window::Window  &Core::getWin(const std::string &name)
    {
        window_map::iterator it = _map.find(name);

        try
        {
            if (it == _map.end())
                throw Exception("Window [" + name + "] doesn't exist.");
            return *(it->second);
        } catch (Exception ex)
        {
            ex.box();
            exit(-1);
        }
    }
    void    Core::AddWindow(Window::Window &w)
    {
        _windows.push(&w);
        _map[w.Name()] = &w;
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
