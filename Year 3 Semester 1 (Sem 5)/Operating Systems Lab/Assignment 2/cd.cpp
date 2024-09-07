#include <iostream>
#include <unistd.h>

int main(int argc, char *argv[])
{
    // checking if 2 arguments present
    if (argc != 2)
    {
        std::cerr << "Usage: " << argv[0] << " <directory>" << std::endl;
        return 1;
    }

    // sending error if change directory invalid
    if (chdir(argv[1]) != 0)
    {
        std::cerr << "Failed to change directory." << std::endl;
        return 1;
    }

    // displaying current directory if valid
    char *cwd = getcwd(nullptr, 0);
    if (cwd != nullptr)
    {
        std::cout << "Current directory: " << cwd << std::endl;
        free(cwd);
    }
    else
    {
        std::cerr << "Failed to get current directory." << std::endl;
        return 1;
    }
}