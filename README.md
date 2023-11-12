# Base CMake template for Visual Studio

This is a template for CMake project.

Is is cross-platform as it is usable for Visual Studio, WSL and MingW on Windows, Linux and MacOS.

What's important is to have a `CMakeLists.txt` and a `config.cmake` files in the root of the project.

The `config.cmake` file must be in the `.gitignore`, as it is a local configuration file, with informs the local paths to the external libraries.

The `config-example.cmake` shows the structure of the `config.cmake` file, and what needs to be inside of it.

A `bin/` folder is automatically created, and the executable is copied inside of it after the compilation.

You have to put the `.dll` inside, if you are using external libraries.

For Visual Studio, you do not have any additionnal setup to do. You can start the project pressing F5.

On this base template, I wrote a little example of a GLFW/GLEW/GLM window.