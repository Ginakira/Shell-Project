/************************************************************
    File Name : common.c
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/04/12 19:24:28
************************************************************/

#include "common.h"

#include "color.h"
#include "head.h"

void get_names() {
    struct passwd *pwd = getpwuid(getuid());
    strncpy(USER_NAME, pwd->pw_name, strlen(pwd->pw_name));
    gethostname(HOST_NAME, sizeof(HOST_NAME));
    strncpy(HOME_PATH, pwd->pw_dir, strlen(pwd->pw_dir));
    return;
}

void print_header() {
    printf(L_GREEN "%s@%s" NONE ":" L_BLUE "%s" NONE "$ ", USER_NAME, HOST_NAME,
           CUR_DIR);
    return;
}