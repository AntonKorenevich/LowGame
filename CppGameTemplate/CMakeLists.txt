# CMakeList.txt : CMake project for CppGameTemplate, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable(CppGameTemplate
    main.cpp
)

target_compile_features(CppGameTemplate PRIVATE cxx_std_20)
# TODO: Add tests and install targets if needed.
