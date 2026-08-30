#ifndef NPC_H
#define NPC_H

#include "raylib.h"
#include <string>

class NPC
{
private:
    Vector3 position;
    std::string name;
    std::string dialogue;
    float radius;
    bool isInteracting;
    float interactionCooldown;
    
public:
    NPC();
    ~NPC();
    
    void Initialize(Vector3 startPos, const std::string& npcName, const std::string& npcDialogue);
    void Update(Vector3 playerPos);
    void Draw();
    
    Vector3 GetPosition() const { return position; }
    std::string GetName() const { return name; }
    std::string GetDialogue() const { return dialogue; }
    bool IsPlayerNear(Vector3 playerPos);
    void Interact() { isInteracting = true; interactionCooldown = 3.0f; }
    bool GetIsInteracting() const { return isInteracting; }
};

#endif
