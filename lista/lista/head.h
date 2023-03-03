struct head
{
    char name[50];
    char status[20];
    /*------*/
    int age;
    int Register;
    float n1, n2, averageTotal;
};
struct slotInfor
{
    head data;
    slotInfor *next;
};
struct list
{
    slotInfor *begin;
    slotInfor *top;
};

list *createTheList();

int sizeOfTheList(list *list);

void freeTheList(list *list);

void showTheAverageTotal(list *list);
/*--------------------------------------------------*/

int beginOfSlotInfor(list *list, head student);

void byRegisterOfSlotInfor(list *list, head student);

int finalOfSlotInfor(list *list, head student);
/*----------------------------------------------------*/

void removeByRegister(list *list);

void  removeFromBegin(list *list);

void removeFromFinal(list *list);

/*----------------------------------------------------*/
int statusOfTheList(list *list);

void showTheList(list *list);
/*-----------------------------------------------------*/

void searchByRegister(list *list);

void searchByPosition(list * list);

