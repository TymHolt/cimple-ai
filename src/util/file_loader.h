#ifndef FILE_LOADER_H
#define FILE_LOADER_H

#include <string>

std::string readTextFile(std::string path);
void writeTextFile(std::string path, std::string content);

#endif