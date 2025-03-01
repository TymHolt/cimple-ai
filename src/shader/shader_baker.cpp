#include <util/file_loader.h>
#include <iostream>
#include <string>

bool isValidNamespaceChar(char c)
{
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') || c == '_';
}

bool isValidNameSpace(std::string nameSpace) 
{
    if(nameSpace.size() == 0)
        return false;

    for(char& c : nameSpace)
        if(!isValidNamespaceChar(c))
            return false;

    // Class names may not start with a number
    return !(nameSpace[0] >= '0' && nameSpace[0] <= '9');
}

std::string convertContent(std::string inContent, std::string nameSpace)
{
    std::string outContent = "";

    outContent += "#ifndef " + nameSpace + "_DEF\n";
    outContent += "#define " + nameSpace + "_DEF\n\n";
    outContent += "#include <string>\n\n";
    outContent += "namespace " + nameSpace + " \n{\n";
    outContent += "\tconst std::string content =\n\t\t\"";
    
    for(char& c : inContent)
        if(c == '\n')
            outContent += "\\n\"\n\t\t\"";
        else if(c == '"')
            outContent += "\\\"";
        else
            outContent += c;    

    outContent += "\";\n}\n\n";
    outContent += "#endif\n";
    return outContent;
}

int main(int argc, char *argv[])
{
    if(argc != 4) 
    {
        std::cerr << "Needs 3 arguments to bake: [FILE_IN] [FILE_OUT] [NAME_SPACE]" << std::endl;
        return -1;
    }

    std::string fileInPath = argv[1], fileOutPath = argv[2], nameSpace = argv[3];
    
    if(!isValidNameSpace(nameSpace))
    {
        std::cerr << "Name space is invalid" << std::endl;
        return -1;    
    }
    
    std::string fileInContent = readTextFile(fileInPath);
    writeTextFile(fileOutPath, convertContent(fileInContent, nameSpace));

    return 0;
}