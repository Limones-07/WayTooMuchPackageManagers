#ifndef CONFIG_H
#define CONFIG_H

typedef enum PackageManagers
{
    apt = 1, 
    dnf = 2,
    pacman = 4,
    xbps = 8,
    // pip = 16,
    // cargo = 32,
    // node = 64
} PackageManagers;

void get_config_info(int *package_managers, char **pConfigInfo, char *configFileName);

#endif