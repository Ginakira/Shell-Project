/************************************************************
    File Name : common.h
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/04/12 19:23:50
************************************************************/

#ifndef _COMMON_H
#define _COMMON_H

char CUR_DIR[1024];
char USER_NAME[512];
char HOST_NAME[512];
char HOME_PATH[512];

#define BUFF_SIZE 1024

void get_names();
void print_header();

#endif