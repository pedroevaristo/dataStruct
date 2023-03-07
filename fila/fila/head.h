#define Max_Char 20 //Maximum value for a variable of type char.                
struct head{

    char name[Max_Char];
    int password, age;
    float money;

};

struct slotInforQ{
    head registry;
    slotInforQ *next;
};
struct Queue{
    slotInforQ *begin;//é nescessário ter esse "slotInforQ" para que as informações passem para a struct dele
    slotInforQ *final;

};

Queue *createQueue();

int sizeOfTheQueue(Queue *queue);

void freeQueue(Queue *queue);

int statusOfTheQueue(Queue *queue);

/*-------------------------*/

void printOutTheRow(Queue *queue);


/*----------------------------*/
int insertTheRow(Queue *queue, head registry);

void removeTheRow(Queue *queue);