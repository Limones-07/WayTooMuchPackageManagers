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
        free(configHome);
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

void get_config_info(char *pConfigInfo, int buffersize)
{
    char *configHome = calloc(1, sizeof(char));
    get_config_home(&configHome);
    
}