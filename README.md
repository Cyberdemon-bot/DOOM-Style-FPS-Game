# DOOM-Style FPS Game

A classic first-person shooter built from scratch in C++17 using SDL2 and XMake, featuring raycasting rendering, A* AI pathfinding, and retro DOOM-inspired gameplay.

## ✨ Features

### Core Engine
- **Raycasting 3D Renderer**: Classic DOOM-style pseudo-3D rendering with texture mapping.
- **Modern Build System**: Built using **XMake** with automated dependency management.
- **Modular Architecture**: Clean separation between rendering, physics, audio, and game logic.

### Gameplay
- **AI Pathfinding**: A* algorithm for intelligent enemy navigation.
- **Multiple Enemy Types**: Cacodemon and Cyberdemon with unique stats and animations.
- **Weapon System**: Multiple weapons (Shotgun, Handgun) with frame-based sprite animations.
- **Round-Based Survival**: Progressive difficulty - enemies scale with each round.
- **Health System**: Visual damage feedback with screen overlay effects.

### Graphics & Audio
- **Texture Mapping**: Perspective-correct wall textures with multiple texture support.
- **Sprite Rendering**: 8-directional sprite rendering with proper depth sorting.
- **Dynamic Lighting**: Distance-based shading for atmospheric depth.
- **Pitch Control**: Look up/down functionality with horizon adjustment.
- **Audio Manager**: Music and sound effects with exclusive channel control.
- **2D Minimap**: Real-time overhead view for navigation.

### Physics & Collision
- **Spatial Partitioning**: Grid-based collision detection for performance.
- **Raycasting Physics**: Wall collision and sprite visibility checks.
- **Entity Management**: Rigid body collision between player, enemies, and walls.

---

## 📋 Requirements

- **XMake** (v2.8+ recommended)
- **C++17 Compiler** (Clang, GCC, or MSVC)

> **Note:** You do **not** need to manually download SDL2 libraries. XMake will automatically fetch and set up all dependencies (`SDL2`, `SDL2_image`, `SDL2_mixer`, `SDL2_ttf`).

---

## 🚀 How to Build and Run

### Install XMake
- **macOS:** `brew install xmake`
- **Windows:** `winget install xmake` (or download installer from [xmake.io](https://xmake.io))
- **Linux:** `wget -qO - https://xmake.io/shget.text | bash`

### Build & Run Commands

```bash
# 1. Compile the project (dependencies will be auto-downloaded on first run)
xmake

# 2. Run the executable with root working directory
xmake run
```

---

## 🎮 Controls

| Input | Action |
|-------|--------|
| **W / A / S / D** | Move forward / left / backward / right |
| **Mouse Movement** | Look around (camera rotation) |
| **Mouse Up/Down** | Look up / down (pitch control) |
| **Arrow Keys** | Alternative rotation controls |
| **Left Mouse Button** | Shoot |
| **1 / 2** | Switch weapons |
| **ESC** | Release mouse / Pause |
| **Space** | Restart game (when dead) |

---

## 🏗️ Project Structure

```
.
├── src/                      # C++ source files
│   ├── main.cpp             # Entry point with map definition
│   ├── Game.cpp             # Game loop and state management
│   ├── Engine.cpp           # Core engine facade
│   ├── Renderer.cpp         # Raycasting and rendering
│   ├── Physics.cpp          # Collision detection and raycasting
│   ├── Player.cpp           # Player entity
│   ├── Sprites.cpp          # Enemy/sprite entity
│   ├── Map.cpp              # World map management
│   ├── Audio.cpp            # Audio playback system
│   ├── Interface.cpp        # UI and weapon rendering
│   └── Clock.cpp            # Frame timing and FPS control
├── include/                 # Header files
├── res/                     # Asset folder
│   ├── texture-doomstyle/  # Wall textures
│   ├── sprites/            # Enemy sprite sheets
│   ├── weapon/             # Weapon animations
│   ├── sound/              # Sound effects (.wav)
│   ├── music/              # Background music (.mp3, .ogg)
│   ├── bg/                 # Sky texture
│   └── font/               # Fonts for UI
├── xmake.lua               # XMake build script
└── README.md
```

---

## 🎯 Architecture Overview

### Engine Module
The `Engine` class acts as a facade, coordinating between subsystems:
- **Renderer**: Handles all 3D rendering and raycasting
- **Physics Manager**: Collision detection, movement, and raycasting queries
- **Audio Manager**: Sound and music playback
- **Interface**: UI elements, weapons, and crosshair
- **World Map**: Grid-based level representation

### Game Loop Flow

```
Initialize
    ↓
┌─────────────────────┐
│   Handle Events     │ → Mouse/keyboard input
└──────────┬──────────┘
           ↓
┌─────────────────────┐
│   Update Game       │ → AI, physics, player state
│   - Update AI       │ → A* pathfinding
│   - Move Entities   │ → Physics checks
│   - Check Victory   │ → Round completion
└──────────┬──────────┘
           ↓
┌─────────────────────┐
│   Render Frame      │
│   - Raycasting      │ → Wall rendering
│   - Sprite Sort     │ → Depth sorting
│   - Sprite Render   │ → Draw enemies
│   - UI/Weapons      │ → Overlay HUD
└──────────┬──────────┘
           ↓
┌─────────────────────┐
│   Display & Sync    │ → Present frame, maintain FPS
└──────────┘
```

---

## 📊 Performance

The game targets 60 FPS and includes:
- Frame-rate limiting with SDL_Delay
- Delta time compensation for consistent movement
- Spatial partitioning for efficient collision detection
- Depth-sorted sprite rendering

---

## 🤝 Contributing

This is an educational project. Feel free to fork and experiment with new features, weapons, and AI behaviors!