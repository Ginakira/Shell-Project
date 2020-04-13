/************************************************************
    File Name : command.c
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/04/12 21:05:08
************************************************************/
#include "command.h"

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
        return;
    }

    if (!strcmp(command, "pwd")) {
        show_current_dir();
        return;
    }

    excute_command(command, paras);
    // printf("%s: command not found\n", command);
    return;
}

void excute_command(char *command, char *paras) {
    char cmd_witth_paras[BUFF_SIZE] = {0};
    char buffer[BUFF_SIZE] = {0};
    sprintf(cmd_witth_paras, "%s %s", command, paras);
    FILE *fp = popen(cmd_witth_paras, "r");
    while (fgets(buffer, BUFF_SIZE, fp)) {
        printf("%s", buffer);
        memset(buffer, 0, BUFF_SIZE);
    }
    pclose(fp);
    return;
}