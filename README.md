# 🕹️ so_long - 42 Project

Welcome to **so_long**, a simple 2D graphical game written in C, using the MiniLibX graphics library. The game is part of the 42 school curriculum, and its goal is to validate your skills in window rendering, keyboard input handling, and basic game logic.

---

## 🎮 Game Overview

Your mission is to control a character through a small 2D map, collect all the collectibles (`C`), and reach the exit (`E`) without running into enemies (bonus).

> The game ends when:
> - All collectibles are gathered ✅  
> - You reach the exit 🚪  
> - Or you're caught by an enemy (bonus) ☠️

---

## 📸 Screenshots

> *(Optional: Replace with your own screenshots)*

**Legend**:  
- `1` - Wall 🧱  
- `0` - Empty space  
- `P` - Player 👤  
- `C` - Collectible 💎  
- `E` - Exit 🚪  

---

## 🧩 Features

- ⌨️ Handle keyboard inputs (W, A, S, D)
- 🖼️ Render maps with images using MiniLibX
- 🔄 Dynamic movement and map updates
- ❌ Error handling for invalid maps
- 🕷️ BONUS: Enemies, animations, move counter display

---

## ⚙️ Installation

Make sure you have **MiniLibX** and dependencies set up.

```bash
git clone https://github.com/Tweakkin/So_long.git
cd So_long
make
