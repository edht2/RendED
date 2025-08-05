cmake_minimum_required(VERSION 3.10)
project(RendED CXX)

# --- Find SFML (still use it to get SFML_INCLUDE_DIR) ---
# We still want to find the SFML configuration to get the include directory,
# but we won't rely on SFML_LIBRARIES for the linker.
find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)


# --- Define Source Files ---
set(SOURCE_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/loaders/obj_loader.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/render/object_projection.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/object/object.cpp
)

set(EXE_NAME rended)

# --- Add Executable ---
add_executable(${EXE_NAME} ${SOURCE_FILES})

# Set the working directory for the executable
# This tells IDEs (like VS Code, CLion, Visual Studio) and 'cmake --build . --target RendED'
# to run the executable from this specified directory.
set_target_properties(${EXE_NAME} PROPERTIES
    CUD_BUILD_WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}" # Set working directory to project root
    VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}" # For Visual Studio
)

# --- Specify Include Directories ---
target_include_directories(${EXE_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${SFML_INCLUDE_DIR} # This should still work and is important
)

# --- Manually Link Dynamic SFML Libraries ---
# Tell the linker the paths to the .so files directly.
# These are the *names* of the libraries without "lib" prefix and ".so" suffix.
# Common for SFML on Linux: sfml-graphics, sfml-window, sfml-system.
# The linker will automatically search standard library paths like /usr/lib/x86_64-linux-gnu/
target_link_libraries(${EXE_NAME} PRIVATE
    sfml-graphics
    sfml-window
    sfml-system
)

# --- Optional: C++ Standard ---
set_target_properties(${EXE_NAME} PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS OFF
)