#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"

class Player
{
private:
    Vector3 position;
    Vector3 velocity;
    Camera3D camera;
    float speed;
    float jumpForce;
    bool isGrounded;
    float groundHeight;
    
public:
    Player();
    ~Player();
    
    void Initialize(Vector3 startPos);
    void Update();
    void Draw();
    
    Vector3 GetPosition() const { return position; }
    Camera3D GetCamera() const { return camera; }
    void SetPosition(Vector3 newPos) { position = newPos; }
    
private:
    void HandleInput();
    void UpdatePhysics();
    void UpdateCamera();
    void CheckCollisions();
};

#endif
