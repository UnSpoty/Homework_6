#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

#ifndef __INCLUDES_H__
#define __INCLUDES_H__

typedef struct subscriber {
    unsigned int count;
    unsigned int block_size;
    char* userinfo;
    } subscriber;


subscriber* createArray(unsigned int block_size);

void menu_draw(subscriber* struct_init);

void subscriber_add(subscriber* struct_init, void* el);

void subscriber_del(subscriber* struct_init, unsigned int del_id);

void setArrayEl(subscriber* struct_init, unsigned int i, void* el);

void* get_member_by_id(subscriber* struct_init, unsigned int i); 

void print_all_members(subscriber* struct_init); 

void freeArray(subscriber* struct_init);

#endif /*end .h*/