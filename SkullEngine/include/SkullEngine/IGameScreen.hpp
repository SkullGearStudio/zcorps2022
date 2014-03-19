#pragma once

namespace SkullEngine
{
    namespace GameScreen
    {
        class IGameScreen
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
