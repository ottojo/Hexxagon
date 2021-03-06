cmake_minimum_required(VERSION 3.10)
project(Hexxagon)

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif (NOT CMAKE_BUILD_TYPE)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wpedantic -Werror -mtune=native -march=native")
if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    message("DEBUG BUILD")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0 -ggdb -fsanitize=address --coverage")
else ()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Ofast")
endif ()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-error=unused-parameter")

# nlohmann/json
include_directories(ext_lib)

# GTest
find_package(GTest QUIET)
if (NOT GTest_FOUND)
    message(WARNING "GTest not found!")
endif ()

# SFML
find_package(SFML COMPONENTS system window graphics REQUIRED)
if (NOT SFML_FOUND)
    message(FATAL_ERROR "Could not find SFML")
endif ()

# TGUI
find_package(TGUI REQUIRED)
if (NOT TGUI_FOUND)
    message(FATAL_ERROR "Could not find TGUI")
endif ()

file(GLOB_RECURSE SOURCES src/*.cpp)

set(LIBS
        tgui
        sfml-system
        sfml-window
        sfml-graphics
        gcov
        pthread)

if (USE_LOCAL_NETWORK)
    include_directories(../WebsocketCPP/src)
    include_directories(../WebsocketCPP/src/Client)
    set(SOURCES ${SOURCES}
            ${CMAKE_SOURCE_DIR}/../WebsocketCPP/src/Client/WebSocketClient.cpp)
    set(LIBS ${LIBS} websockets)
else ()
    set(LIBS ${LIBS} SopraNetwork)
endif ()

include_directories(src)

add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} ${LIBS})

# GTest
set(TEST_SOURCES
        src/messages/Message.cpp
        src/messages/server/Welcome.cpp
        src/util/HexGridTools.cpp
        test/json.cpp
        test/hexGrid.cpp)

set(TEST_LIBS gtest gmock pthread
        gcov)

if (GTest_FOUND)
    enable_testing()
    include_directories(${GTEST_INCLUDE_DIR})
    add_executable(unitTests test/main.cpp ${TEST_SOURCES})
    target_link_libraries(unitTests ${TEST_LIBS})
    add_test(
            NAME unitTests
            COMMAND unitTests
    )
endif ()
