#ifndef INTERACTION_H
#define INTERACTION_H

#include "raylib.h"
#include <string>

class InteractionSystem
{
public:
    static void DisplayInteractionPrompt(Vector3 npcPos, const std::string& npcName);
    static bool CheckInteractionInput();
};

#endif
