#pragma once

#include <map>
#include <vector>
#include <list>
#define Forward -1
#define Backward -2
#define Right -3
#define Left -4
#define PI 3.14159265f
#define INF 10000000.0f

class Player;
class Map;
class Clock;
class Sprites;

class Physics
{
private:
    std::vector<Sprites>* PhySptList; // list of physics entity
    std::map<std::pair<int, int>, std::list<Sprites*>> SptManager; // Sprites manager on map
    Player* mainPlayer; // get player state
    Map* mainMap; // get map
    Clock* MyClock; // get delta time
    float RayVert(float angle, float px, float py, float& xvert, float& yvert);
    float RayHor(float angle, float px, float py, float& xhor, float& yhor);
    
    template<typename T>
    std::pair<float, float> MoveEnt(T& ent, int type);

public:
    void ImportEntity(Map& mp, Player& py, Clock& clk, std::vector<Sprites>& psl);
    void UpdateAllSpt();
    void UpdateSpt(Sprites& spt);
    void MoveSpt(int index, int type);
    void MovePly(int type);
    Sprites* Praycast(); // ray from player
    bool Sraycast(int index, float SptFov, float maxDepth); // ray from sprite
    bool Check_wall(float x, float y);
    bool CheckEnt(float ax, float ay, float bx, float by);
    std::vector<Sprites*> CheckSptCollision(float newX, float newY, Sprites* spt);
};
