#include "world.h"
#include "raylib.h"

World::World()
    : worldOffset({0, 0, 0})
{
}

World::~World()
{
}

void World::Initialize()
{
    // Initialize world environment
    // In a real game, you'd load terrain from files or generate procedurally
}

void World::Draw()
{
    // Draw ground plane
    DrawPlane({0, 0.5f, 0}, {100, 100}, DARKGREEN);
    
    // Draw some simple obstacles/terrain features
    // Trees
    DrawCube({15, 2, 15}, 1, 4, 1, BROWN);           // Trunk
    DrawCube({15, 5, 15}, 3, 3, 3, GREEN);           // Foliage
    
    DrawCube({-15, 2, 20}, 1, 4, 1, BROWN);
    DrawCube({-15, 5, 20}, 3, 3, 3, GREEN);
    
    // Rocks
    DrawCube({20, 1, -10}, 2, 1, 2, GRAY);
    DrawCube({-20, 1, -15}, 2.5f, 1.5f, 2.5f, GRAY);
    
    // House structure
    DrawCube({30, 2, 0}, 6, 4, 6, BROWN);             // Walls
    DrawCube({30, 5, 0}, 6, 2, 6, DARKBROWN);        // Roof
    DrawCube({27, 2.5f, 0}, 1.5f, 2, 0.2f, LIGHTBLUE); // Door
    
    // Mountains/hills in distance
    DrawCube({-40, 5, -40}, 20, 8, 20, DARKGRAY);
    DrawCube({40, 3, 40}, 15, 5, 15, DARKGRAY);
    
    // Water feature (simple plane)
    DrawPlane({0, 0.4f, -35}, {30, 30}, BLUE);
}

void World::Cleanup()
{
    // Cleanup resources if needed
}
