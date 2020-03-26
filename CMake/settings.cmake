set(BUILD_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin CACHE PATH "Path to the build artifacts")
mark_as_advanced(BUILD_OUTPUT_PATH)

# CMake has four configuration types, restrict the options to the only two useful ones
set(CMAKE_CONFIGURATION_TYPES "Debug;RelWithDebInfo" CACHE STRING "limited configs" FORCE)

