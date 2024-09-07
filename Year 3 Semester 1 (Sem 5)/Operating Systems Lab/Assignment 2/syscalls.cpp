#include <iostream>
#include <fstream>

int main()
{
    // opening output file
    std::ofstream outputFile("output.txt");
    if (!outputFile)
    {
        std::cerr << "Failed to open the file for writing." << std::endl;
        return 1;
    }

    // writing data to file
    outputFile << "Hi my name is Abhinav Dinesh Srivatsa." << std::endl;
    outputFile << "My registration number is 21BDS0340." << std::endl;
    outputFile.close();

    // opening input file
    std::ifstream inputFile("output.txt");
    if (!inputFile)
    {
        std::cerr << "Failed to open the file for reading." << std::endl;
        return 1;
    }

    // reading data from file
    std::string line;
    while (std::getline(inputFile, line))
    {
        std::cout << line << std::endl;
    }
    inputFile.close();
}