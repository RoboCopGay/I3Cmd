#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#include "menu.h"

void createMenu(Menu * menu, int lenght, ...){
    va_list items_list;

    // checking number of items on list
    va_list check_items_list;
    va_start(check_items_list, lenght);

    int number_of_items = 0;
    TEST test = va_arg(check_items_list, TEST);
    while (!TEST_ISEQUAL(test, ITEM_NULL)){
        number_of_items ++;
        test = va_arg(check_items_list, TEST);
    }

    // creating menu
    va_start(items_list, lenght);

    menu->selected = 0;
    menu->lenght = lenght;

    menu->menu.items = malloc(sizeof(Item)*lenght);

    int i = 0;
    Item item = va_arg(items_list, Item);
    while (i < lenght){
        if (i < number_of_items){
            menu->menu.items[i].value = item.value;
            menu->menu.items[i].output = item.output;
        } else {
            menu->menu.items[i].value = "\0";
            menu->menu.items[i].output = "\0";
        }

        i ++;
        item = va_arg(items_list, Item);
    }

    va_end(items_list);
}

int main(int argc, char *argv[])
{
    Item joao = {"joao", "maria"};
    Menu j;
    createMenu(&j, 5, joao, joao, ITEM_NULL);

    for (int i = 0; i<j.lenght; i++)
        printf("%s: %s\n", j.menu.items[i]);

    free(j.menu.items);
    return 0;
}
