#include "raylib.h"
#include "world.h"
#include "player.h"
#include "npc.h"
#include <vector>

int main()
{
    // Initialize window
    const int SCREEN_WIDTH = 1280;
    const int SCREEN_HEIGHT = 720;
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "3D Open World Game");
    SetTargetFPS(60);
    
    // Initialize audio
    InitAudioDevice();
    
    // Create world
    World world;
    world.Initialize();
    
    // Create player
    Player player;
    player.Initialize({0.0f, 2.0f, 0.0f});
    
    // Create NPCs
    std::vector<NPC> npcs;
    NPC npc1;
    npc1.Initialize({5.0f, 1.0f, 5.0f}, "Guard", "Hello traveler!");
    npcs.push_back(npc1);
    
    NPC npc2;
    npc2.Initialize({-5.0f, 1.0f, -5.0f}, "Merchant", "Want to trade?");
    npcs.push_back(npc2);
    
    NPC npc3;
    npc3.Initialize({10.0f, 1.0f, -8.0f}, "Archer", "Stay sharp!");
    npcs.push_back(npc3);
    
    // Main game loop
    while (!WindowShouldClose())
    {
        // Update
        player.Update();
        
        // Update NPCs
        for (auto& npc : npcs)
        {
            npc.Update(player.GetPosition());
        }
        
        // Rendering
        BeginDrawing();
        ClearBackground(SKYBLUE);
        
        // 3D mode
        BeginMode3D(player.GetCamera());
        {
            // Draw world
            world.Draw();
            
            // Draw NPCs
            for (auto& npc : npcs)
            {
                npc.Draw();
            }
            
            // Draw grid for reference
            DrawGrid(20, 1.0f);
        }
        EndMode3D();
        
        // 2D UI
        DrawText("WASD: Move | SPACE: Jump | Mouse: Look | E: Interact", 10, 10, 20, WHITE);
        DrawText(TextFormat("Position: (%.1f, %.1f, %.1f)", player.GetPosition().x, player.GetPosition().y, player.GetPosition().z), 10, 40, 15, LIGHTGREEN);
        DrawText("NPCs: Press E when near to interact", 10, 70, 15, YELLOW);
        
        EndDrawing();
    }
    
    // Cleanup
    CloseAudioDevice();
    CloseWindow();
    
    return 0;
}
