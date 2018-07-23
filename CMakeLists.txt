cmake_minimum_required(VERSION 3.10)
project(SpaceAdventures)

set(CMAKE_CXX_STANDARD 17)

add_library(SoureCode
        src/SoureCode/Core/Game.hpp
        src/SoureCode/Core/Game.cpp
        src/SoureCode/Core/DebugDraw.hpp
        src/SoureCode/Core/DebugDraw.cpp
        src/SoureCode/Core/Event/EventEmitter.cpp
        src/SoureCode/Core/Event/EventEmitter.hpp
        src/SoureCode/Core/Event/EventListener.cpp
        src/SoureCode/Core/Event/EventListener.hpp
        src/SoureCode/Core/Event/EventCallback.hpp
        src/SoureCode/Contract/Ables/Eventable.hpp
        src/SoureCode/Contract/Ables/Eventable.cpp
        src/SoureCode/Contract/Ables/Updatable.hpp
        src/SoureCode/Contract/Ables/Updatable.cpp
        src/SoureCode/Contract/Ables/Pauseable.hpp
        src/SoureCode/Contract/Ables/Pauseable.cpp
        src/SoureCode/Contract/Ables/Initialable.hpp
        src/SoureCode/Contract/Ables/Initialable.cpp
        src/SoureCode/Contract/Ables/Drawable.hpp
        src/SoureCode/Contract/Ables/Drawable.cpp
        src/SoureCode/Contract/Ables/Selectable.cpp
        src/SoureCode/Contract/Ables/Selectable.hpp
        src/SoureCode/Contract/Ables/Activatable.cpp
        src/SoureCode/Contract/Ables/Activatable.hpp
        src/SoureCode/Contract/Ables/Stylable.cpp
        src/SoureCode/Contract/Ables/Stylable.hpp
        src/SoureCode/Contract/Ables/StylableStates.hpp
        src/SoureCode/Contract/Ables/StylableStyle.hpp
        src/SoureCode/Contract/Ables/StylableTypes.hpp
        src/SoureCode/Contract/State.hpp
        src/SoureCode/Contract/State.cpp
        src/SoureCode/Contract/Entity.hpp
        src/SoureCode/Contract/Entity.cpp
        src/SoureCode/Manager/StateManager.hpp
        src/SoureCode/Manager/StateManager.cpp
        src/SoureCode/Manager/ResourceManager.hpp
        src/SoureCode/Manager/ResourceManager.cpp
        src/SoureCode/Entity/State.hpp
        src/SoureCode/Entity/State.cpp
        src/SoureCode/UI/Styles.cpp
        src/SoureCode/UI/Styles.hpp
        src/SoureCode/UI/Stylables/Background.cpp
        src/SoureCode/UI/Stylables/Background.hpp
        src/SoureCode/UI/Stylables/Border.cpp
        src/SoureCode/UI/Stylables/Border.hpp
        src/SoureCode/UI/Button/Button.cpp
        src/SoureCode/UI/Button/Button.hpp
        )

add_executable(${PROJECT_NAME}
        src/main.cpp
        src/SpaceAdventures/Kernel.hpp
        src/SpaceAdventures/Kernel.cpp
        src/SpaceAdventures/Entity/Entity.hpp
        src/SpaceAdventures/Entity/Entity.cpp
        src/SpaceAdventures/State/LoadState.hpp
        src/SpaceAdventures/State/LoadState.cpp
        src/SpaceAdventures/State/MenuState.hpp
        src/SpaceAdventures/State/MenuState.cpp
        )

target_link_libraries(${PROJECT_NAME} SoureCode)

# Detect and add Box2D

set(BOX2D_STATIC_LIBRARIES TRUE)
find_package(Box2D)

if (BOX2D_FOUND)
    include_directories(${BOX2D_INCLUDE_DIR})
    target_link_libraries(${PROJECT_NAME} ${BOX2D_LIBRARIES})
endif ()


# Detect and add SFML
set(SFML_STATIC_LIBARIES true)


set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(SFML 2 REQUIRED system window graphics network audio)

if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES})
endif ()

