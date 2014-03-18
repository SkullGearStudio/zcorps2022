#pragma once

#include <string>

#include "Types.hpp"

namespace SkullEngine
{
    namespace ScreenManager
    {
        class ScreenManager;
    }

    namespace GameScreen
    {
        class AScreenManager
        {
        public:
            AScreenManager(ScreenManager::ScreenManager &, std::string &);
            virtual ~AScreenManager(void) {};

            virtual void Init() const = 0;
            virtual void Update() const = 0;
            virtual void Event() const = 0;
            virtual void Draw() const = 0;
            virtual void Destroy() const = 0;

            bool IsActive() const;
            bool IsPopup() const;
            ushort Layer() const;
            const std::string &Name() const;
            const ScreenManager::ScreenManager &SCM() const;

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
            std::string _name;
            ScreenManager::ScreenManager &_screenManager;
        };
    }
}
