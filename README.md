# 3D Open World Game - C++ + Raylib

A foundation for a 3D open world game with player movement, NPC interaction, and expandable game mechanics.

## Features

- ✅ **3D Player Movement** - WASD to move, mouse to look around, SPACE to jump
- ✅ **NPC System** - Multiple NPCs with dialogue and interaction
- ✅ **Open World Environment** - Terrain, obstacles, buildings, and scenery
- ✅ **Camera System** - First-person perspective with smooth mouse look
- ✅ **Physics** - Basic gravity and collision detection
- ✅ **Clean Architecture** - Modular code structure for easy expansion

## Controls

| Key | Action |
|-----|--------|
| **W/A/S/D** | Move |
| **SPACE** | Jump |
| **Mouse** | Look around |
| **E** | Interact with NPCs |
| **ESC** | Quit |

## Project Structure

```
src/
├── main.cpp          # Main game loop
├── player.h/cpp      # Player class (movement, camera)
├── npc.h/cpp         # NPC class (characters, dialogue)
├── world.h/cpp       # World/terrain system
├── interaction.h/cpp # NPC interaction system
└── CMakeLists.txt    # Build configuration
```

## Building & Running

### Prerequisites
- **C++17** or higher
- **CMake 3.10+**
- **Raylib 4.5.0** (automatically downloaded if not found)

### Build Instructions

**Linux/Mac:**
```bash
mkdir build
cd build
cmake ..
make
./OpenWorldGame
```

**Windows (Visual Studio):**
```bash
mkdir build
cd build
cmake .. -G "Visual Studio 16 2019"
cmake --build . --config Release
.\Release\OpenWorldGame.exe
```

**Windows (MinGW):**
```bash
mkdir build
cd build
cmake .. -G "MinGW Makefiles"
make
.\OpenWorldGame.exe
```

## What's Included

### Player System
- First-person camera control
- WASD movement with physics (inertia, friction)
- Jump mechanic with gravity
- World boundary detection

### NPC System
- Multiple NPC characters
- Detection when player is near (3-unit radius)
- Dialogue system framework
- Customizable names and dialogue

### World/Environment
- Ground plane
- Various terrain features (trees, rocks, buildings)
- Mountains and water features
- Simple geometry for obstacles

### Interaction System
- E-key to interact with nearby NPCs
- Interaction prompts when player is close
- Cooldown system to prevent spam

## Next Steps - Easy Improvements

1. **Better Graphics**
   - Load 3D models (.obj, .glb)
   - Add textures to objects
   - Implement better lighting
   - Add skybox

2. **Enhanced Gameplay**
   - Quest system
   - Inventory management
   - Combat mechanics
   - Item pickup system

3. **World Expansion**
   - Procedural terrain generation
   - Multiple areas/levels
   - Dynamic weather
   - Day/night cycle

4. **NPC Improvements**
   - AI pathfinding
   - Animation support
   - More complex dialogue trees
   - NPC schedules

5. **Audio**
   - Background music
   - Sound effects
   - Voice lines for NPCs

## Resources

- [Raylib Documentation](https://www.raylib.com/)
- [Raylib GitHub](https://github.com/raysan5/raylib)
- [Raylib Examples](https://github.com/raysan5/raylib/tree/master/examples)
- [C++ Game Dev Guide](https://learnopengl.com/)

## Tips for Your College Project

- **Start simple** - Get the base working, then add features
- **Use version control** - Commit frequently with meaningful messages
- **Document your code** - Comments help others understand your work
- **Test often** - Build and run frequently to catch bugs early
- **Expand gradually** - Add one feature at a time
- **Performance matters** - Test FPS and optimize if needed

## License

Open source - feel free to use and modify!

---

**Ready to build?** Start by running the project and familiarizing yourself with the controls. Then explore the code files to understand the structure. Let me know what features you'd like to add next!
