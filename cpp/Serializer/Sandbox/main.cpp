#include <iostream>
#include <filesystem>

#include <Serializer.h>

using namespace MG1;

int main()
{
    SceneSerializer serializer;
    auto scene = serializer.LoadScene("./file_example.json");

    std::cout << "Hello World!\n";
}
