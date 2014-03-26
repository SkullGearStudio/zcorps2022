#include <iostream>
#include <cstdio>
#include <ctime>

#include "SkullEngine\Core.hpp"
#include "SkullEngine\Exception.hpp"

namespace SkullEngine
{
    Core::Core() :
        _assets(Asset::AssetManager(*this))
    {
        std::time_t rawtime;
        std::tm* timeinfo;
        char buffer [80];

        std::time(&rawtime);
        timeinfo = std::localtime(&rawtime);
        std::strftime(buffer,80,"%d/%m/%Y - %H:%M:%S", timeinfo);

        _output.open("log.txt", std::ofstream::out | std::ofstream::trunc);

        cout("Start log file at [" + std::string(buffer) + "]");
        cout("_______________");
    }

    Asset::AssetManager &Core::Assets()
    {
        return _assets;
    }
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
            cout("EXCEPTION : " + ex.msg());
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
    void    Core::cout(const std::string &s)
    {
        if (_output.is_open())
            _output << s << std::endl;
        std::cout << s << std::endl;
    }
}
