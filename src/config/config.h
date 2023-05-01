#ifndef CONFIG_H
#define CONFIG_H

typedef enum PackageManagers
{
    apt = 0b1, 
    dnf = 0b10,
    pacman = 0b100,
    xbps = 0b1000
    // pip = 0b10000,
    // cargo = 0b100000,
    // node = 0b10000000
} PackageManagers;

void get_package_managers(int *package_managers, char *configFileName);

#endif