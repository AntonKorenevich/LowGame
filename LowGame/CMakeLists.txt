set(SFML_DIR "C:/Users/User/source/SFML/lib/cmake/SFML")

find_package(SFML 3 REQUIRED COMPONENTS Graphics Window System)

add_executable(LowGame
    main.cpp
)

target_compile_features(LowGame PRIVATE cxx_std_20)

target_link_libraries(LowGame PRIVATE
    SFML::Graphics
    SFML::Window
    SFML::System
)