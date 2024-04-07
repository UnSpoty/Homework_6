#include "includes.h"

//Написать программу абонентский справочник. Список абонентов представляет собой статический массив (100 элементов) из структур следующего в виде:

//Переписать справочник абонентов (задание на структуры) со статического
//массива структур на динамический. При запуске программы массив пуст, при
//добавлении первого абонента выделяется память только под один элемент. По
//мере добавления абонентов массив увеличивается по одному элементу. При
//удалении, элемент, который удаляется, перемещается в конец массива и размер
//массива уменьшается на один элемент. По завершению программы память под
//массив высвобождается. В остальном функционал, как и в предыдущем
//задании.

int main()
{
    subscriber* struct_init = createArray(sizeof(int)*10);

    menu_draw(struct_init); // call menu
    return 0;
}


void menu_draw(subscriber* struct_init)
{
    unsigned int task_num;
    char info;
    unsigned int user_id = 0;

    printf("\nPlease, select task from 1..5\n");

   //task list
   printf("1.Add new subscriber.\n");
   printf("2.Delete subscriber.\n");
   printf("3.Find subscriber by IDs.\n");
   printf("4.Draw all subscriber.\n");
   printf("5.Exit.\n");

   scanf("%u", &task_num);

  switch(task_num)
  {
    case 1:
        printf("Add user, like: Name,Surrname,Tel.\n");
        scanf("%s", &info );
        subscriber_add(struct_init, &info);
    break;
    case 2:
        printf("Write user IDs.\n");
        scanf("%d", &user_id );
        subscriber_del(struct_init,user_id);
    break; 
    case 3:
       printf("Write user IDs.\n");
       scanf("%d", &user_id );
       printf("struct_init[%d], %s\n",user_id, (char*)get_member_by_id(struct_init, user_id));
       menu_draw(struct_init);  
    break;
    case 4:  
        print_all_members(struct_init);
    break;
    case 5:
        freeArray(struct_init);
        exit(0);
    break;

   default:
    printf("Selected task %u does not exist\n", task_num);
    menu_draw(struct_init); // re-call menu func.
  }
}
