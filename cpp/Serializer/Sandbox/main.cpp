#include <iostream>
#include <filesystem>

#include <Serializer.h>

int main()
{
    MG1::SceneSerializer serializer;
    auto scene = serializer.LoadScene("./file_example_2.json");

    std::cout << "Hello World!\n";
}
