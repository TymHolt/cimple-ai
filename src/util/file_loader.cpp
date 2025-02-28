#include <util/file_loader.h>
#include <iostream>
#include <fstream>

std::string readTextFile(std::string path)
{
    std::string line, content = "";
    std::ifstream fileStream (path);

    if(!fileStream.is_open())
        throw "File \"" + path + "\" could not be read"; 

    while(getline(fileStream, line))
        content += line + "\n";
    
    fileStream.close();    
    return content;
}

void writeTextFile(std::string path, std::string content)
{
    std::ofstream fileStream;
    fileStream.open(path);

    if(!fileStream.is_open())
        throw "File \"" + path + "\" could not be written"; 

    fileStream << content;
    fileStream.close();
}