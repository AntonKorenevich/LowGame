set(SFML_DIR "C:/Users/User/source/SFML/lib/cmake/SFML")

find_package(SFML 3 REQUIRED COMPONENTS Graphics Window System)

add_executable(CppGameTemplate
    main.cpp
)

target_compile_features(CppGameTemplate PRIVATE cxx_std_20)

target_link_libraries(CppGameTemplate PRIVATE
    SFML::Graphics
    SFML::Window
    SFML::System
)