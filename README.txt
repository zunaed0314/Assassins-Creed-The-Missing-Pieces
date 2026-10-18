# 🗡️ Assassin’s Creed: The Missing Pieces

*A 2D action-adventure game built with C++ and iGraphics.*

Explore five challenging levels, fight enemies and powerful bosses, unlock different attack abilities, and restore the missing pieces to their rightful places. Each level introduces new challenges, enemies, and background environments as the difficulty increases.

## 🎮 Gameplay Preview

Watch the gameplay on YouTube:

[▶️ **Assassin’s Creed: The Missing Pieces — Gameplay Preview**](https://www.youtube.com/watch?v=LH5OPsbQmW4&t=38s)

## ✨ Features

- **5 Challenging Levels** — Progress through five levels with increasing difficulty.
- **Unique Environments** — Experience different backgrounds and scenarios as you advance.
- **Boss Battles** — Face a final boss at the end of every level.
- **Multiple Attack Abilities** — Unlock additional attacks as you progress.
- **Level Completion Objectives** — Place each missing piece in its correct location after completing a level.

## 🕹️ Controls

| Key | Action |
|---|---|
| `N` | Basic attack |
| `F` | Additional attack available in later levels |
| `I` | Additional attack available in later levels |

**Tip:** In the first level, only the `N` attack is available. The `F` and `I` attacks become available in subsequent levels and deal more damage.

## 🛠️ Built With

- **Language:** C++
- **Graphics Library:** iGraphics
- **Development Environment:** Microsoft Visual Studio Professional 2013

## 💻 Getting Started

### Prerequisites

This project was originally developed using **Microsoft Visual Studio Professional 2013** and the older iGraphics library.

Before running the game, make sure you have the required development environment and dependencies configured.

### ⚠️ Fixing the MSB8020 Build Error

When opening the project in a newer version of Visual Studio, you may encounter the following error:

```text
Error MSB8020: The build tools for v143
(Platform Toolset = 'v143') cannot be found.
```

This happens when the project is configured to use the v143 toolset, but the required build tools are not installed.

**Follow these steps to fix it:**

1. Navigate to the project directory:

   ```text
   D:\Assassins\Assassin_s Creed- The missing pieces\main
   ```

2. Locate the `main.vcxproj` file.

3. Open the file using Notepad or Notepad++.

4. Find this line:

   ```xml
   <PlatformToolset>v143</PlatformToolset>
   ```

5. Replace it with:

   ```xml
   <PlatformToolset>v120</PlatformToolset>
   ```

6. Save the file and reopen or reload the project in Visual Studio.

7. Build and run the game.

**Why does this work?**

The `v143` toolset belongs to newer versions of Visual Studio, while `v120` corresponds to Visual Studio 2013. Switching the project to `v120` aligns it with the original development environment.

> **Note:** If you are using Visual Studio 2013, the v120 toolset is the expected toolset. If you are using a newer Visual Studio version, make sure the v120 build tools and any required iGraphics dependencies are available. Changing the project file alone does not install missing dependencies.

## 📈 Level Progression

The game becomes progressively more challenging as you advance.

- **Level 1:** Begin your journey with the basic attack.
- **Later Levels:** Unlock additional attack abilities and face tougher enemies.
- **End of Each Level:** Defeat the final boss and place the missing piece in its rightful location.

## ⚠️ Known Limitations

This game was developed using the older iGraphics library, so you may encounter compatibility issues on modern systems or newer versions of Visual Studio.

If you experience build errors, check your platform toolset configuration and ensure the required dependencies are installed.

## 👨‍💻 Author

Developed as a C++ graphics programming project using iGraphics.

---

*Ready to recover the missing pieces? Enter the game, defeat the bosses, and complete your mission!* ⚔️
