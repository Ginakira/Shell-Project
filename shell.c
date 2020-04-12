/************************************************************
    File Name : main.c
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/04/12 19:20:47
************************************************************/

#include "common/command.h"
#include "common/common.h"
#include "common/dir.h"
#include "common/head.h"

int main() {
    char command[BUFF_SIZE] = {0};
    char paras[BUFF_SIZE] = {0};
    get_names();

    while (1) {
        get_current_dir();
        print_header();
        get_command(command, paras);
        printf("COMMAND: %s, PARAS: %s\n", command, paras);
        parse_command(command, paras);
    }
    return 0;
}