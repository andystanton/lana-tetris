cmake_minimum_required(VERSION 2.8)
project(lana-tetris)

set(lana-tetris_VERSION_MAJOR 1)
set(lana-tetris_VERSION_MINOR 0)

set (
    HEADERS
    src/drawing/foundation/Colour.h
    src/drawing/foundation/Palette.h
    src/drawing/GameplayDisplayer.h
    src/drawing/PrimitiveDisplayer.h
    src/drawing/TextDisplayer.h
    src/drawing/UIDisplayer.h
    src/model/entity/basic/Alphabet.h
    src/model/entity/basic/Character.h
    src/model/entity/collision/Collidable.h
    src/model/entity/Coordinated.h
    src/model/entity/Drawable.h
    src/model/entity/Entity.h
    src/model/entity/tetris/Quad.h
    src/model/entity/tetris/QuadHeap.h
    src/model/entity/tetris/Tetromino.h
    src/model/entity/tetris/TetrominoFactory.h
    src/model/entity/tetris/TetrominoType.h
    src/model/entity/tetris/TetrominoTypeFactory.h
    src/model/entity/tetris/World.h
    src/model/entity/transformation/Pipeline.h
    src/model/entity/transformation/PipelineResult.h
    src/model/entity/transformation/Rotation.h
    src/model/entity/transformation/Transformation.h
    src/model/entity/transformation/TransformationData.h
    src/model/entity/transformation/TransformationType.h
    src/model/entity/transformation/Translation.h
    src/model/foundation/Vec2d.h
)

set (
    SOURCES
    src/main.cpp
    src/drawing/foundation/Colour.cpp
    src/drawing/foundation/Palette.cpp
    src/drawing/GameplayDisplayer.cpp
    src/drawing/PrimitiveDisplayer.cpp
    src/drawing/TextDisplayer.cpp
    src/drawing/UIDisplayer.cpp
    src/model/entity/basic/Alphabet.cpp
    src/model/entity/basic/Character.cpp
    src/model/entity/Entity.cpp
    src/model/entity/tetris/Quad.cpp
    src/model/entity/tetris/QuadHeap.cpp
    src/model/entity/tetris/Tetromino.cpp
    src/model/entity/tetris/TetrominoFactory.cpp
    src/model/entity/tetris/TetrominoType.cpp
    src/model/entity/tetris/TetrominoTypeFactory.cpp
    src/model/entity/tetris/World.cpp
    src/model/entity/transformation/Pipeline.cpp
    src/model/entity/transformation/PipelineResult.cpp
    src/model/entity/transformation/Rotation.cpp
    src/model/entity/transformation/Transformation.cpp
    src/model/entity/transformation/TransformationData.cpp
    src/model/entity/transformation/Translation.cpp
    src/model/foundation/Vec2d.cpp
)

if (CMAKE_COMPILER_IS_GNUCXX)
    set(CMAKE_CXX_FLAGS "-std=gnu++11")
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    set(CMAKE_CXX_FLAGS "-std=c++11")
    if (${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
        set(CMAKE_XCODE_ATTRIBUTE_CLANG_CXX_LIBRARY "libc++")
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")
    endif ()
elseif (MSVC)
    # On by default
endif ()

# lana-tetris
include_directories(src)

add_executable (
    lana-tetris 
    ${SOURCES}
    ${HEADERS}
)

# enable testing - not currently in use but required for 'make test' that travis-ci runs.
enable_testing()

# glfw
add_subdirectory(lib/glfw)
include_directories(lib/glfw/include)
target_link_libraries(lana-tetris glfw ${GLFW_LIBRARIES})
target_link_libraries(lana-tetris glfw ${OPENGL_glu_LIBRARY} ${GLFW_LIBRARIES})
