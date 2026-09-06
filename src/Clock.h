#pragma once

#include <cstdint>

class Clock
{
private:
    uint64_t lastCounter;
    uint64_t frequency;
    float deltaTime;
    float fps;

public:
    Clock();


    void tick(int targetFPS = 0);


    float getDeltaTime() const;


    float getFPS() const;
};
