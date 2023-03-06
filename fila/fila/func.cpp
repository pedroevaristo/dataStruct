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
    if(queue != NULL){
        slotInforQ *freeQ;
        while(queue->begin != NULL){
            freeQ = queue->begin;
            queue->begin = queue->begin->next;//proxima informação a frente de le, será o novo início.
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
