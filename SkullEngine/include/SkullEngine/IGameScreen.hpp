#pragma once

#include "SkullEngine.hpp"

namespace SkullEngine
{
    namespace GameScreen
    {
        class SKULLENGINE_API IGameScreen
        {
        public:
            virtual ~IGameScreen(void) {}

            virtual void Init() const = 0;
            virtual void Update() const = 0;
            virtual void Event() const = 0;
            virtual void Draw() const = 0;
            virtual void Destroy() const = 0;
        };
    }
}
