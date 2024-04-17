# ImGui Playground

This is a playground for ImGui. It is a simple project that demonstrates how to use ImGui in a C++ project with [GLFW](https://www.glfw.org/) and [CMake](https://cmake.org/).

Code should be put in the `src/custom.cpp` file. It also has a variable called `overwriteDefaultWindows` that can be set to `true` to overwrite the default windows that are created by the playground.

The `src/main.cpp` file is the entry point of the application.

## Building
You can build the project using [CMake](https://cmake.org/). Here is how you can build the project:
```bash
cmake -B build .
cd build
make
```

The project will be built in the `build` directory and is cross-platform.
