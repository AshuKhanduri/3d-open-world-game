#ifndef WORLD_H
#define WORLD_H

#include "raylib.h"

class World
{
private:
    Model terrainModel;
    Vector3 worldOffset;
    
public:
    World();
    ~World();
    
    void Initialize();
    void Draw();
    void Cleanup();
    
private:
    void GenerateSimpleTerrain();
};

#endif
