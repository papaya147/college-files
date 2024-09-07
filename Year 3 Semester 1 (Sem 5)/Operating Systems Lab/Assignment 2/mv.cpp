#include <iostream>
#include <cstdio>

int main(int argc, char *argv[])
{
    // checking if 3 arguments provided
    if (argc != 3)
    {
        std::cerr << "Usage: " << argv[0] << " <source> <destination>" << std::endl;
        return 1;
    }

    const char *source = argv[1];
    const char *destination = argv[2];

    // if renaming file did not work, throw error
    if (rename(source, destination) != 0)
    {
        std::cerr << "Failed to move the file." << std::endl;
        return 1;
    }

    // display success message
    std::cout << "File moved successfully." << std::endl;
}