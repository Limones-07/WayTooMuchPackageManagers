#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "config/config.h"
// #include "config/info.h"

int main(int argc, char *argv[])
{
    const char SUPPORTED_PACKAGE_MANAGERS[][10] = {"apt", "dnf", "pacman", "xbps", "pip", "cargo", "node"};
    printf("Hello, World!\n");
    int package_managers;
    char *config_info = calloc(1, sizeof(char));
    get_config_info(&package_managers, &config_info, "config");

    // for (int i = 0; i < )
}