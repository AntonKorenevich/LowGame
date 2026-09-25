set(SFML_DIR "C:/Users/User/source/SFML/lib/cmake/SFML")

find_package(SFML 3 REQUIRED COMPONENTS Graphics Window System)

add_executable(LowGame
    main.cpp
    stdafx.h
    Game/Game.h
    Game/Game.cpp
    Game/InputController.h
    Game/InputController.cpp
    Game/Player.h
    Game/Player.cpp
    Game/GameObject.h
    Game/GameObject.cpp
    Game/GameObjectFactory.h
    Game/GameObjectFactory.cpp
    Game/Particle.h
    Game/Particle.cpp
    Game/Definitions.h
)

target_compile_features(LowGame PRIVATE cxx_std_20)

target_link_libraries(LowGame PRIVATE
    SFML::Graphics
    SFML::Window
    SFML::System
)