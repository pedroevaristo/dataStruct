#include "head.h"
#include <iostream>
#include <cstdlib>

using namespace std;

queue *create()
{

    queue *create = (queue *)malloc(sizeof(queue));

    if (create != NULL)
    {
        create->begin == NULL;
        create->final == NULL;
    }
    else
    {
        cout << "Eroor to create the row !" << endl;
    }
    return create;
}

int sizeOfTheQueue(queue *queue)
{
    if (statusOfTheQueue(queue))
    {
        
        return 0;
    }
    else
    {
        int count = 0;
        slotInforQ *size = queue->begin;
        while (size != NULL)
        {
            count++;
            size = size->next;
        }
        return count;
    }
}


int statusOfTheQueue(queue *queue)
{
    if (queue == NULL || queue->begin == NULL)
    {
        cout << "This row is empty" << endl;
        return 1; // caso seja verdade, sim
    }
    else if(queue != NULL || queue->begin != NULL)
    { // caso não seja verdade
        cout << "This row isn't empty" << endl;
        return 0;
    }
}

/*============================*/
int insertTheRow(queue *queue, head registry)
{
    cout<<"entrou "<<endl;

    if (queue == NULL)
    {
        return 0;
    }
    else
    {
        cout<<"entrou "<<endl;
        slotInforQ *insert = (slotInforQ *)malloc(sizeof(slotInforQ));
        if (insert == NULL)
        {
            return 0;
        }

        insert->registry = registry;
        insert->next = NULL;

        if (queue->final == NULL)
        {
            cout<<"entrou if "<<endl;
            queue->begin = insert;
        }
        else
        {
            cout<<"entrou else"<<endl;
            queue->final->next = insert;
        }
        queue->final = insert;
        return 1;
    }
}

int removeTheRow(queue *queue)
{
    if (statusOfTheQueue(queue))
    {
        return 0;
    }
    else
    {
        slotInforQ *removed = queue->begin;

        queue->begin = queue->begin->next;
        if (queue->begin != NULL)
        {
            queue->final = NULL;
        }
        free(removed);
        return 1;
    }
}

/*============================*/

void freeQueue(queue *queue)
{
    if(queue != NULL){
        slotInforQ *freeq;
        while(queue->begin !=NULL){
            freeq = queue->begin;
            queue->begin = queue->begin->next;
            free(freeq);
        }
        free(queue);
    }
}
/*============================*/
void printOutTheRow(queue *queue)
{
    system("cls");
    if (statusOfTheQueue(queue))
    {
        cout << "This queue is empty !" << endl;
        return;
    }
    else
    {
        int count = 0;
        slotInforQ *print = queue->begin;

        while (print != NULL)
        {

            cout << "information: \n"
                 << endl;
            cout << "Name:" << print->registry.name << endl;
            cout << "Age: " << print->registry.age << endl;
            cout << "PassWord: " << print->registry.password << endl;
            cout << "Account: " << print->registry.money << endl;
        }
    }
}
/*============================*/

int consult(queue *queue, head *registry){
    if(statusOfTheQueue(queue)){
        return 0;
    }else{
        *registry = queue->begin->registry;
        return 1;

    }
}