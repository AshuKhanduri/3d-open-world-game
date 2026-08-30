#include "player.h"
#include "raylib.h"
#include "math.h"

Player::Player()
    : position({0, 0, 0}), velocity({0, 0, 0}), speed(0.3f), 
      jumpForce(0.5f), isGrounded(false), groundHeight(0.5f)
{
    camera = {0};
}

Player::~Player()
{
}

void Player::Initialize(Vector3 startPos)
{
    position = startPos;
    velocity = {0, 0, 0};
    
    // Setup camera
    camera.position = {position.x, position.y + 1.7f, position.z};
    camera.target = {position.x, position.y + 1.7f, position.z + 10.0f};
    camera.up = {0.0f, 1.0f, 0.0f};
    camera.fovy = 60.0f;
    camera.projection = CAMERA_PERSPECTIVE;
}

void Player::Update()
{
    HandleInput();
    UpdatePhysics();
    CheckCollisions();
    UpdateCamera();
}

void Player::HandleInput()
{
    Vector3 moveDirection = {0, 0, 0};
    
    // WASD Movement
    if (IsKeyDown(KEY_W)) moveDirection.z += 1;
    if (IsKeyDown(KEY_S)) moveDirection.z -= 1;
    if (IsKeyDown(KEY_A)) moveDirection.x -= 1;
    if (IsKeyDown(KEY_D)) moveDirection.x += 1;
    
    // Normalize and apply speed
    if (Vector3Length(moveDirection) > 0)
    {
        moveDirection = Vector3Normalize(moveDirection);
        velocity.x += moveDirection.x * speed;
        velocity.z += moveDirection.z * speed;
    }
    
    // Jump
    if (IsKeyPressed(KEY_SPACE) && isGrounded)
    {
        velocity.y = jumpForce;
        isGrounded = false;
    }
    
    // Friction
    velocity.x *= 0.9f;
    velocity.z *= 0.9f;
}

void Player::UpdatePhysics()
{
    // Gravity
    if (!isGrounded)
    {
        velocity.y -= 0.01f; // Gravity
    }
    
    // Apply velocity
    position.x += velocity.x;
    position.y += velocity.y;
    position.z += velocity.z;
    
    // Ground collision (simple plane at y=0.5)
    if (position.y <= groundHeight)
    {
        position.y = groundHeight;
        velocity.y = 0;
        isGrounded = true;
    }
    
    // World boundaries (prevent going too far)
    if (position.x > 50) position.x = 50;
    if (position.x < -50) position.x = -50;
    if (position.z > 50) position.z = 50;
    if (position.z < -50) position.z = -50;
}

void Player::UpdateCamera()
{
    // Get mouse movement for camera look
    Vector2 mouseDelta = GetMouseDelta();
    
    // Rotate camera based on mouse
    static float yaw = 0;
    static float pitch = 0;
    
    yaw -= mouseDelta.x * 0.01f;
    pitch -= mouseDelta.y * 0.01f;
    
    // Clamp pitch
    if (pitch > 1.2f) pitch = 1.2f;
    if (pitch < -1.2f) pitch = -1.2f;
    
    // Calculate camera target based on yaw and pitch
    Vector3 forward = {sinf(yaw), sinf(pitch), cosf(yaw)};
    forward = Vector3Normalize(forward);
    
    camera.position = {position.x, position.y + 1.7f, position.z};
    camera.target = Vector3Add(camera.position, Vector3Scale(forward, 10.0f));
    camera.up = {0.0f, 1.0f, 0.0f};
}

void Player::CheckCollisions()
{
    // Simple collision with static objects can be added here
    // For now, just prevent going through terrain
}

void Player::Draw()
{
    // Optional: Draw player model/capsule
    // For now, the camera represents the player
}
