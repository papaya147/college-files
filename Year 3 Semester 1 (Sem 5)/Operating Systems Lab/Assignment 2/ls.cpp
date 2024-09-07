#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

void listDirectoryContents(const std::string &path)
{
    // listing contents of directory
    for (const auto &entry : fs::directory_iterator(path))
        std::cout << entry.path().filename().string() << std::endl;
}

int main(int argc, char *argv[])
{
    std::string path;

    // if number of arguments > 1, then path is given
    if (argc > 1)
        path = argv[1];
    // else assigne path to current directory
    else
        path = fs::current_path().string();

    listDirectoryContents(path);
}
