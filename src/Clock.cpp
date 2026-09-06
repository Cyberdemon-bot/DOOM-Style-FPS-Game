#include "Clock.h"
#include <SDL2/SDL.h>
#include <algorithm>

Clock::Clock()
{
    lastCounter = SDL_GetPerformanceCounter();
    frequency = SDL_GetPerformanceFrequency();
    deltaTime = 0.0;
    fps = 0.0;
}

void Clock::tick(int targetFPS)
{
    uint64_t currentCounter = SDL_GetPerformanceCounter();
    deltaTime = (float)(currentCounter - lastCounter) / (float)frequency;
    lastCounter = currentCounter;


    if (deltaTime > 0)
        fps = 1.0 / deltaTime;


    if (targetFPS > 0)
    {
        float frameDuration = 1.0 / (float)targetFPS;
        if (deltaTime < frameDuration)
        {
            uint32_t delayMs = static_cast<uint32_t>((frameDuration - deltaTime) * 1000.0);
            if (delayMs > 0) SDL_Delay(delayMs);

            uint64_t newCounter = SDL_GetPerformanceCounter();
            deltaTime = (float)(newCounter - currentCounter) / (float)frequency;
            deltaTime = std::max(deltaTime, 0.025f);
            lastCounter = newCounter;
        }
    }
}

float Clock::getDeltaTime() const {return deltaTime;}

float Clock::getFPS() const {return fps;}
