#include "interaction.h"
#include "raylib.h"

void InteractionSystem::DisplayInteractionPrompt(Vector3 npcPos, const std::string& npcName)
{
    // Draw 3D text or UI element above NPC
    DrawText(TextFormat("E - Talk to %s", npcName.c_str()), 
             (int)npcPos.x, (int)npcPos.y - 100, 20, YELLOW);
}

bool InteractionSystem::CheckInteractionInput()
{
    return IsKeyPressed(KEY_E);
}
