#pragma once

#include <string>

#include "SkullEngine\IGameScreen.hpp"
#include "SkullEngine\Types.hpp"

namespace SkullEngine
{
    namespace GameScreen
    {
        class AGameScreen : public IGameScreen
        {
        public:
            AGameScreen(ScreenManager::ScreenManager &, Asset::AssetManager &, Window::Window &, const std::string &);
            virtual ~AGameScreen(void) {};

            virtual void Init() = 0;
            virtual void Update() = 0;
            void Event();
            virtual void Draw() = 0;
            virtual void Destroy() = 0;

            bool IsActive() const;
            bool IsPopup() const;
            ushort Layer() const;
            const std::string &Name() const;

            void On();
            void Off();
            void PopUp();
            void PopDown();
            void LayerUp();
            void LayerDown();

        protected:
            bool        _active;
            bool        _popup;
            ushort      _layer;
            std::string *_name;
            ScreenManager::ScreenManager &_manager;
            Asset::AssetManager &_assets;
            Window::Window &_win;
        };
    }
}
