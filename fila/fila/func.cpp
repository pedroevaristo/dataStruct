#include "head.h"
#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

Queue *createQueue()
{
    Queue *create = (Queue *)malloc(sizeof(Queue));
    if (create != NULL)
    {
        create->begin == NULL;
        create->final == NULL;
    }
    else
    {
        cout << "Error to create the row ! " << endl;
    }
    return create;
}

int sizeOfTheQueue(Queue *queue)
{
    if (queue == NULL)
    {

        return 0;
    }
    else
    {
        int count = 0;
        slotInforQ *sizeOf = queue->begin;
        while (sizeOf != NULL)
        {
            count += 1;
            sizeOf = sizeOf->next;
        }
        return count;
    }
}

void freeQueue(Queue *queue)
{
    if (queue != NULL)
    {
        slotInforQ *freeQ;
        while (queue->begin != NULL)
        {
            freeQ = queue->begin;
            queue->begin = queue->begin->next; // proxima informação a frente de le, será o novo início.
            free(freeQ);
        }
        free(queue);
    }
}

int statusOfTheQueue(Queue *queue)
{
    if (queue == NULL || queue->begin == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void printOutTheRow(Queue *queue)
{
    system("cls");

    if (statusOfTheQueue(queue))
    {

        cout << "This is empty" << endl;
    }
    else
    {
        int count = 0;
        slotInforQ *printout = queue->begin;

        if (printout != NULL)
        {

            cout << "the person's data: " << count + 1 << endl;
            cout << "Name: " << printout->registry.name << endl;
            cout << "Age: " << printout->registry.age << endl;
            cout << "Password: " << printout->registry.password << endl;
            cout << "Bank account: " << printout->registry.money << endl;

            printout = printout->next;
            count += 1;
        }
    }
}

/*------------------------------------------*/
int insertTheRow(Queue *queue, head registry)
{
    if (queue == NULL)
    {
        cout << "Data is empty, error ! Try again. " << endl;
        return 0;
    }
    else
    {
        cout << "Data stored\n" << endl;

        slotInforQ *insert = (slotInforQ *)malloc(sizeof(slotInforQ));

        if(insert == NULL){
            return 0;
        }
        insert->registry = registry;
        insert->next = NULL;
        if(queue->begin == NULL){
            queue->begin = insert;
        }else{
            queue->final->next = insert;//irá apontar para o novo valor;
        }
        queue->final = insert;
        return 1;
    }
}

void removeTheRow(Queue *queue)
{
}
