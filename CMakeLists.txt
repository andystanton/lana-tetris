cmake_minimum_required(VERSION 2.8)
project(lana-tetris)

set(lana-tetris_VERSION_MAJOR 1)
set(lana-tetris_VERSION_MINOR 0)

IF (CMAKE_COMPILER_IS_GNUCXX)
  SET (CMAKE_CXX_FLAGS "-std=gnu++11")
ELSEIF (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
  set(CMAKE_CXX_FLAGS "-std=c++11")
  IF(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")
  ENDIF ()
ELSEIF (MSVC)
  # On by default
ENDIF ()

# lana-tetris
include_directories(src)

add_executable(
            lana-tetris 
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

# enable testing - not currently in use but required for 'make test' that travis-ci runs.
enable_testing()

# glfw
add_subdirectory(lib/glfw)
include_directories(lib/glfw/include)
target_link_libraries(lana-tetris glfw ${GLFW_LIBRARIES})
target_link_libraries(lana-tetris glfw ${OPENGL_glu_LIBRARY} ${GLFW_LIBRARIES})

