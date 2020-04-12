/************************************************************
    File Name : dir.c
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/04/12 19:58:28
************************************************************/

#include "common.h"
#include "head.h"

void get_cur_dir() {
    char buff[BUFF_SIZE], *pos;
    int home_len, buff_len;
    getcwd(buff, BUFF_SIZE);
    home_len = strlen(HOME_PATH), buff_len = strlen(buff);

    if ((pos = strstr(buff, HOME_PATH)) != NULL) {
        CUR_DIR[0] = '~';
        strncpy(CUR_DIR + 1, buff + home_len, buff_len - home_len);
        CUR_DIR[buff_len - home_len + 1] = 0;
    } else {
        strncpy(CUR_DIR, buff, buff_len);
        CUR_DIR[buff_len] = 0;
    }
    return;
}

void change_dir(char *path) {
    int retval;
    if (strlen(path) != 0) {
        retval = chdir(path);
    } else {
        retval = chdir(HOME_PATH);
    }

    if (retval < 0) {
        perror("cd");
    }
    return;
}