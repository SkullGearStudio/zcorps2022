#pragma once

namespace SkullEngine
{
    namespace GameScreen
    {
        class IGameScreen
        {
        public:
            virtual ~IGameScreen(void) {}

            virtual void Init() = 0;
            virtual void Update() = 0;
            virtual void Event() = 0;
            virtual void Draw() = 0;
            virtual void Destroy() = 0;
        };
    }
}
