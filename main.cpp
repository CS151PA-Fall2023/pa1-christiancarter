#include <iostream>
#include <fstream>

int main()
{
    std::cout << "SUCCESSFUL INIT RUN";
    std::ofstream outputFile;
    outputFile.open("something.txt");
    if(!outputFile)
    {
        std::cout << "Unable to output file.";
        outputFile.close();
    }

    outputFile << "FOR FUN";
    outputFile.flush(); // Flush the output buffer
    outputFile.close();

    std::ifstream inputFile("something.txt");


    std::string line;
    while(getline(inputFile, line))
    {
        std::cout << line << std::endl;
    }
    std::cout << "SUCCESSFUL COMPLETE RUN";

    inputFile.close();

    return 0;
}