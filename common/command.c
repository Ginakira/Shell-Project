/************************************************************
    File Name : command.c
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/04/12 21:05:08
************************************************************/
#include "common.h"
#include "dir.h"
#include "head.h"

void get_command(char *command, char *paras) {
    char buff[BUFF_SIZE] = {0};
    memset(command, 0, BUFF_SIZE);
    memset(paras, 0, BUFF_SIZE);

    scanf("%[^\n]s", buff);
    getchar();
    int len = strlen(buff);
    char *blank_pos = strchr(buff, ' ');
    if (blank_pos == NULL) blank_pos = buff + len;
    strncpy(command, buff, blank_pos - buff);
    strncpy(paras, blank_pos + 1, buff + len - blank_pos);
    return;
}

void parse_command(char *command, char *paras) {
    if (!strcmp(command, "cd")) {
        change_dir(paras);
    } else if (!strcmp(command, "pwd")) {

    }
    return;
}