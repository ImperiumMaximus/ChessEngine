cmake_minimum_required(VERSION 2.8)

include(CheckSymbolExists)
function(detect_architecture symbol arch)
    if (NOT DEFINED ARCHITECTURE)
        set(CMAKE_REQUIRED_QUIET 1)
        check_symbol_exists("${symbol}" "" ARCHITECTURE_${arch})
        unset(CMAKE_REQUIRED_QUIET)

        # The output variable needs to be unique across invocations otherwise
        # CMake's crazy scope rules will keep it defined
        if (ARCHITECTURE_${arch})
            set(ARCHITECTURE "${arch}" PARENT_SCOPE)
            set(ARCHITECTURE_${arch} 1 PARENT_SCOPE)
            add_definitions(-DARCHITECTURE_${arch}=1)
        endif()
    endif()
endfunction()

project(ChessEngine)

option (CHESSENGINE_USE_BUNDLED_GLIB "Use Bundled GLib Libraries for you compiler/platform" OFF)

if (MSVC)
	detect_architecture("_M_AMD64" x86_64)
    detect_architecture("_M_IX86" x86)
else()
	detect_architecture("__x86_64__" x86_64)
    detect_architecture("__i386__" x86)
endif()

if (NOT DEFINED ARCHITECTURE)
    set(ARCHITECTURE "GENERIC")
    set(ARCHITECTURE_GENERIC 1)
    add_definitions(-DARCHITECTURE_GENERIC=1)
endif()

if (NOT MSVC)
	set(GNU_WARNINGS "-fomit-frame-pointer -Wshadow -Wredundant-decls \
	                  -Wcast-align -Wundef -Wfloat-equal -Winline \
	                  -Wunreachable-code -Wmissing-declarations \
	                  -Wmissing-include-dirs -Wswitch-enum -Wswitch-default \
	                  -Wmain -pedantic -Wextra -Wall")
	set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${GNU_WARNINGS}")
	
	set(CMAKE_C_FLAGS_DEBUG "-g -O0")
	set(CMAKE_C_FLAGS_RELEASE "-O2")
	
	set(CMAKE_EXE_LINKER_FLAGS_RELEASE "${CMAKE_EXE_LINKER_FLAGS_RELEASE} -s")
	
	if (ARCHITECTURE_x86_64)
		set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -m64")
	endif()
else()
	set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
    set(CMAKE_CONFIGURATION_TYPES Debug Release CACHE STRING "" FORCE)
	
	set(CMAKE_C_FLAGS "/W3 /MP /Zi /Zo" CACHE STRING "" FORCE)
	
	set(CMAKE_C_FLAGS_DEBUG  "/Od /MDd" CACHE STRING "" FORCE)
	set(CMAKE_C_FLAGS_RELEASE  "/O2 /GS- /MD" CACHE STRING "" FORCE)
	
	set(CMAKE_EXE_LINKER_FLAGS_DEBUG   "/DEBUG" CACHE STRING "" FORCE)
    set(CMAKE_EXE_LINKER_FLAGS_RELEASE "/DEBUG /INCREMENTAL:NO /OPT:REF,ICF" CACHE STRING "" FORCE)
endif()

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/externals/cmake-modules")

if (CHESSENGINE_USE_BUNDLED_GLIB)
	if (MSVC14 AND ARCHITECTURE_x86_64)
		set(GLIB_BUNDLED_LIBDIR "${CMAKE_SOURCE_DIR}/externals/glib/vs14_release/x64/lib" CACHE STRING "" FORCE)
		set(GLIB_BUNDLED_INCLUDEDIR "${CMAKE_SOURCE_DIR}/externals/glib/vs14_release/x64/include" CACHE STRING "" FORCE)
	elseif (MSVC14 AND ARCHITECTURE_x86)
		set(GLIB_BUNDLED_LIBDIR "${CMAKE_SOURCE_DIR}/externals/glib/vs14_release/Win32/lib" CACHE STRING "" FORCE)
		set(GLIB_BUNDLED_INCLUDEDIR "${CMAKE_SOURCE_DIR}/externals/glib/vs14_release/Win32/include" CACHE STRING "" FORCE)
	endif()
endif()
find_package(GLIB REQUIRED)

include_directories(${CMAKE_SOURCE_DIR}/include ${GLIB_INCLUDE_DIRS})

set(SRCS src/x86/cpu.c src/x86/bitscan.c src/board.c src/genmoves.c src/main.c)

add_executable(ChessEngine ${SRCS})
target_link_libraries(ChessEngine ${GLIB_LIBRARIES})
