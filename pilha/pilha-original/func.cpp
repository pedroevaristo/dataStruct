#include <iostream>
#include <cstdlib>
#include "head.h"

using namespace std;

list createList()
{
    list *create = (list *)malloc(sizeof(list));

    if (create != Null)
    {
        create->begin = NULL;
        create->top = NULL;
    }

    else
    {
        cout << "Erro creating list" << endl;
    }
    return list;
}

void sizeOfList(list *list)
{
    if (list == NULL)
    {
        cout << "the list is empty" << endl;
        return 0;
    }
    else
    {
        int count = 0;
        infor *size = list->begin;
        while (size != NULL)
        {
            count += 1;
            size = size->next;
        }
        return count;
    }
}

int beginOfList(list *list, head student)//Se usa o int para a criação
{
    if (list == NULL)
    {
        return 0;
    }
    else
    {
        infor *begin = (infor *)malloc(sizeof(infor));

        if (begin == NULL)
        {
            return 0;
        }
        begin->studentsInfor = student;
        begin->next = NULL;
        if (list->begin == NULL)
        {
            list->begin = begin;
            list->top = begin;
        }
        else{
            begin->next = list->begin;
            list->begin = begin;
        }
    }
}

int finalOfList(list *list, head student){
    
}
