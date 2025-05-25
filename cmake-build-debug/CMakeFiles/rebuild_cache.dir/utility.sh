set -e

cd /cygdrive/c/Users/asmaa/CLionProjects/lab1/cmake-build-debug
/cygdrive/c/Users/asmaa/AppData/Local/JetBrains/CLion2025.1/cygwin_cmake/bin/cmake.exe --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
