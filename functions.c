#include "includes.h"

subscriber* createArray(unsigned int block_size)
{
    subscriber* struct_init = (subscriber*)malloc(sizeof(subscriber));
    struct_init->count = 0;
    struct_init->block_size = block_size;
    struct_init->userinfo = NULL;

    return struct_init;
}

void subscriber_add(subscriber* struct_init, void* el)
{
    struct_init->count++;
    struct_init->userinfo = (char*)realloc(struct_init->userinfo, struct_init->count * struct_init->block_size);
    memcpy(&struct_init->userinfo[(struct_init->count-1)*struct_init->block_size] , el , struct_init->block_size);

    menu_draw(struct_init);
}

void setArrayEl(subscriber* struct_init, unsigned int i, void* el)
{
    memcpy(&struct_init->userinfo[i*struct_init->block_size],el, struct_init->block_size );
}

void subscriber_del(subscriber* struct_init, unsigned int del_id)
{

    if(struct_init->count < 1)
    {
            printf("Nothing to del.");
            menu_draw(struct_init);
    }

   for(unsigned int j=1; j<struct_init->count-1; j++)
        setArrayEl(struct_init, j, get_member_by_id(struct_init,j) );

    struct_init->count--;
    struct_init->userinfo = (char*)realloc(struct_init->userinfo,  struct_init->count*struct_init->block_size);

    menu_draw(struct_init);
}


void* get_member_by_id(subscriber* struct_init, unsigned int i)
{
   return &struct_init->userinfo[i * struct_init->block_size];
}

void print_all_members(subscriber* struct_init)
{
    for (unsigned int i = 0 ; i < struct_init->count ; i++)
    {

        printf("User IDs:[%d], %s\n",i, (char*)get_member_by_id(struct_init,i));

    }

    menu_draw(struct_init);
}

void freeArray(subscriber* struct_init)
{
    if(struct_init)
    {
        if(struct_init->userinfo)
        {
            free(struct_init->userinfo);
        };
      free(struct_init);
    };
}