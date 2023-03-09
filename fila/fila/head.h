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
struct queue{
    slotInforQ *begin;//é nescessário ter esse "slotInforQ" para que as informações passem para a struct dele
    slotInforQ *final;

};

queue *create();
/*-------------------------------*/

int sizeOfTheQueue(queue *queue);
void freeQueue(queue *queue);
int statusOfTheQueue(queue *queue);

/*-------------------------*/

void printOutTheRow(queue *queue);

/*----------------------------*/

int insertTheRow(queue *queue, head registry);
int removeTheRow(queue *queue);

/*----------------------------*/
int consultThePerson(queue *queue, head *registry);