# CLI-Tetris++

Command line tetris for Linux / WSL / MacOS.  
This is just a for fun project and will be rewritten in C and Go for comparison.  
Feel free to do whatever you want with it.

# Building
## Linux
- Build in vscode (`CTRL+SHIFT+B`), the build config is in tasks.json
- Alternatively run g++ manually `g++ -o tetris.out *.cpp`

## MacOS
clang++ uses C++98 by default so we need to specify the compiler version, I'm working with C++23.  
clang++ -o tetris.out *.cpp -std=c++23

# TODO

- When debugging, stopping with `CTRL + C` does not restore the cursor. (Works on MacOS, check if still an issue on Linux)
- Add a proper build system, CMAKE
