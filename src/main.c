#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "config/config.h"
// #include "config/info.h"

int main()
{
    const char SUPPORTED_PACKAGE_MANAGERS[][10] = {"apt", "dnf", "pacman", "xbps", "pip", "cargo", "node"};
    printf("Hello, World!\n");
    unsigned char package_managers;
    get_package_managers(&package_managers, "config");

}