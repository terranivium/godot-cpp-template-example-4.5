# Godot C++ Template

A clean template for developing Godot games with C++ extensions using CMake.

## 🚀 Quick Start

```bash
# Clone and setup
git clone <your-repo-url>
cd godot-cpp-template
git submodule update --init --recursive

# Build C++ extension
cmake -B build -DCMAKE_BUILD_TYPE=Debug
cmake --build build --config Debug

# Open in Godot
# Open example-project/ in Godot and run the scene
```

## 📁 Structure

```
├── src/                          # C++ Source Code
│   ├── cube_renderer.h/cpp       # Example C++ class
│   └── register_types.cpp        # Class registration
├── example-project/              # Godot Game Project
│   ├── project.godot             # Game configuration
│   ├── example.tscn              # 3D scene with lighting
│   └── example.gd                # GDScript using C++ class
└── CMakeLists.txt                # CMake build configuration
```

## 🔧 Adding New C++ Classes

1. **Create your class** in `src/your_class.h` and `src/your_class.cpp`
2. **Register it** in `src/register_types.cpp`:
   ```cpp
   GDREGISTER_CLASS(YourClass);
   ```
3. **Update CMakeLists.txt** to include your files
4. **Rebuild**: `cmake --build build --config Debug`
5. **Restart Godot** to see your new class

## 🎯 Development Workflow

**C++ Development Cycle:**
1. Write C++ code in `src/`
2. Build extension with CMake
3. Restart Godot (required for C++ changes)
4. Test in editor
5. Repeat

**Note:** Unlike GDScript, C++ extensions require a restart to see changes.

## 🛠️ Prerequisites

- **CMake 3.17+**
- **Python 3.4+** (for godot-cpp bindings)
- **Git** (for submodules)
- **C++ Compiler** (Visual Studio, GCC, or Clang)
- **Godot 4.5+**

## 📚 Resources

- [Godot C++ Documentation](https://docs.godotengine.org/en/stable/tutorials/scripting/gdextension/)
- [CMake Documentation](https://cmake.org/documentation/)

---

**Happy Game Development!** 🎮✨