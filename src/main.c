#include <stdio.h>
#include "config_lib/config.h"

int main(int argc, char *argv[])
{
    printf("Hello, World!\n");
    char config_info[200];
    get_config_info(config_info, 200);
}