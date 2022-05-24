# Scene-Serializer

## Installation (CMake)

To include library in CMake project add to `CMakeList.txt` of project, after `project()` command, following lines:

```
# add subdirectory with path to folder containing Scene-Serializer CMakeList.txt, this should include it in build process
add_subdirectory(Scene-Serializer/cpp/Serializer)

# add Serializer library to project libraries; path to Serializer subproject built lib file
target_link_libraries(<PROJECT-NAME> PRIVATE Scene-Serializer/cpp/Serializer/MGSerializer)

# add header files to include search path
target_include_directories(<PROJECT-NAME> PRIVATE Scene-Serializer/cpp/Serializer/Serializer)
```

If CMake build configuration doesn't build all targets it's required to manually build MGSerializer target. Otherwise adding library file will fail.
