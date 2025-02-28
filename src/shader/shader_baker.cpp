#include <shader/shader_baker.h>
#include <util/file_loader.h>
#include <iostream>

int main(void)
{
    writeTextFile("NewLicense.txt", readTextFile("LICENSE.txt"));
    return 0;
}