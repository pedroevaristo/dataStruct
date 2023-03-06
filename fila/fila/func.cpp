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
        while(sizeOf != NULL){
            count+=1;
            sizeOf = sizeOf->next;
        }
    }
}

void freeQueue(Queue *queue)
{
}

int statusOfTheQueue(Queue *queue)
{
    return 0;
}

