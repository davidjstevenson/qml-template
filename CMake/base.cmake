# find includes in build directories
if(CMAKE_VERSION VERSION_LESS "3.7.0")
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

if(WIN32)
   add_definitions(-DWIN32_LEAN_AND_MEAN)
   add_definitions(-DNOMINMAX)
endif()

SET(CMAKE_CXX_STANDARD_REQUIRED ON)
SET(CMAKE_CXX_STANDARD 17)
SET(CMAKE_CXX_EXTENSIONS TRUE)

# setup warning levels and errors for three main compilers
if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4 /WX")
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror -Wall")
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror -Wall")
endif()


if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    set(USE_ADDRESS_SANITIZER OFF CACHE BOOL "Use Clang address santizer")
    if (${USE_ADDRESS_SANITIZER})
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -fno-omit-frame-pointer")
        set(CMAKE_LD_FLAGS "${CMAKE_LD_FLAGS} -fsanitize=address")
    endif()

    set(USE_UNDEFINED_BEHAVIOUR_SANITIZER OFF CACHE BOOL "Use Clang undefined behaviour santizer")
    if (${USE_UNDEFINED_BEHAVIOUR_SANITIZER})
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=undefined")
        set(CMAKE_LD_FLAGS "${CMAKE_LD_FLAGS} -fsanitize=undefined")
    endif()

    set(USE_THREAD_SANITIZER OFF CACHE BOOL "Use Clang thread santizer")
    if (${USE_THREAD_SANITIZER})
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=thread")
        set(CMAKE_LD_FLAGS "${CMAKE_LD_FLAGS} -fsanitize=thread")
    endif()
endif()

