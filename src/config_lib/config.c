#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "info.h"

void get_config_home(char **pConfigHome)
{
    if (getenv("XDG_CONFIG_HOME") != NULL)
    {
        char *configHome = getenv("XDG_CONFIG_HOME");
        unsigned int size = strlen(configHome);
        *pConfigHome = (char*) realloc(*pConfigHome, size);
        *pConfigHome = configHome;
    }
    else
    {
        char *configHome = (char*) calloc(1, sizeof(char));
        {
            char *homeDir = getenv("HOME");
            configHome = realloc(configHome, sizeof(homeDir) + 8); 
            configHome = strcpy(configHome, homeDir);
        }
        configHome = strcat(configHome, "/.config");
        unsigned int size = strlen(configHome);
        *pConfigHome = (char*) realloc(*pConfigHome, size);
        *pConfigHome = strcpy(*pConfigHome, configHome); 
        free(configHome);
    }
}

void get_config_info(int *package_managers, char **pConfigInfo, char *configFileName)
{
    char *configFilePath = malloc(sizeof(char));
    {
        char *configHome = calloc(1, sizeof(char));
        get_config_home(&configHome);
        configFilePath = realloc(configFilePath, strlen(configHome) + strlen(PROJECT_NAME) + strlen(configFileName) + 1);
        configFilePath = strcpy(configFilePath, configHome);
        configFilePath = strcat(configFilePath, "/");
        configFilePath = strcat(configFilePath, PROJECT_NAME);
        configFilePath = strcat(configFilePath, "/");
        configFilePath = strcat(configFilePath, configFileName);
        free(configHome);
    }

    // printf("%s\n", configFilePath);

    FILE *pConfigFile = fopen(configFilePath, "r");
    if (pConfigFile == NULL)
    {
        puts("Coudn't find the config file! Exiting!");
        exit(1);
    }
    

    fclose(pConfigFile);
}
