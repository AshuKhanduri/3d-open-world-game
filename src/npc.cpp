#include "npc.h"
#include "raylib.h"

NPC::NPC()
    : position({0, 0, 0}), name("NPC"), dialogue("Hello!"), 
      radius(3.0f), isInteracting(false), interactionCooldown(0.0f)
{
}

NPC::~NPC()
{
}

void NPC::Initialize(Vector3 startPos, const std::string& npcName, const std::string& npcDialogue)
{
    position = startPos;
    name = npcName;
    dialogue = npcDialogue;
    isInteracting = false;
    interactionCooldown = 0.0f;
}

void NPC::Update(Vector3 playerPos)
{
    // Update interaction cooldown
    if (interactionCooldown > 0)
    {
        interactionCooldown -= GetFrameTime();
        if (interactionCooldown <= 0)
        {
            isInteracting = false;
        }
    }
}

void NPC::Draw()
{
    // Draw NPC body (sphere)
    DrawSphere(position, 0.5f, RED);
    
    // Draw NPC head (smaller sphere)
    DrawSphere({position.x, position.y + 0.7f, position.z}, 0.3f, ORANGE);
    
    // Draw interaction radius when near player
    // DrawWireBox({position.x, position.y, position.z}, radius*2, radius*2, radius*2, GREEN);
}

bool NPC::IsPlayerNear(Vector3 playerPos)
{
    float distance = Vector3Distance(position, playerPos);
    return distance < radius;
}
