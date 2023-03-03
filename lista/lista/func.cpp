#include "head.h"
#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

list *createTheList()
{
    list *create = (list *)malloc(sizeof(list));
    if (create != NULL)
    {
        create->begin = NULL;
        create->top = NULL;
    }
    else
    {
        cout << "Error to create the list!" << endl;
    }
    return create;
}

int sizeOfTheList(list *list)
{
    if (list == NULL || list->begin == NULL)
    {
        cout << "This list is empty" << endl;
        return 0;
    }
    else
    {
        int count = 0;
        slotInfor *sizeOf = list->begin;
        while (sizeOf != NULL) // aquele slot tiver alguma informação passará direto, até o fim.
        {
            count += 1;
            sizeOf = sizeOf->next;
            
        }
        cout<<"\nSize of: "<<count<<endl;
        return count;
    }
}

void freeTheList(list *list)
{
    if (list != NULL)
    {

        slotInfor *freeL;

        while (list->begin != NULL)
        {
            freeL = list->begin;
            list->begin = list->begin->next;
            free(freeL);
        }
        free(list);
    }
}
void showTheAverageTotal(list *list)
{
    system("cls");
    if (statusOfTheList(list))
    {
        cout << "The list is empty" << endl;
    }
    else
    {
        int count = 0;
        float averageTotal = 0;

        slotInfor *average = list->begin;

        while (average != NULL)
        {
            averageTotal += average->data.averageTotal;
            count += 1;
            average = average->next;
        }
        averageTotal /= count;

        cout << "Average of the class: " << averageTotal << endl;
    }
}
/*-------------------------------------------------------------------------------------------------------*/
int beginOfSlotInfor(list *list, head student)
{
    if (list == NULL)
        return 0;

    else
    {
        slotInfor *begin = (slotInfor *)malloc(sizeof(slotInfor));
        if (begin == NULL)
        {
            return 0;
        }
        begin->data = student;
        begin->next = NULL;
        if (list->begin == NULL)
        {
            list->begin = begin;
            list->top = begin;
        }
        else /*Caso tenha uma informação existente vou pegar informação inicial e colocar na proxima posição, e enquanto a outra informação é o novo início*/
        {
            begin->next = list->begin;
            list->begin = begin;
        }
    }
}

void byRegisterOfSlotInfor(list *list, head student)
{
    slotInfor *order = (slotInfor *)malloc(sizeof(slotInfor));

    order->data = student;
    if (list->begin == NULL)
    {
        list->begin = order;
        order->next = NULL;
        list->top = order;
    }
    else
    {
        /*Enquanto a informação for menor que a matricula digitada, a informação atual armazena numa lugar antes dele*/

        slotInfor *before, *present = list->begin;
        while (present != NULL && present->data.Register < student.Register)
        {
            before = present;
            present = present->next;
        }
        /*Se a informação da matricula for igual a do início, informação inicial passa adianta/ proximo slot, e a informação atual é colocado no lugar*/

        if (present == list->begin)
        {
            order->next = list->begin;
            list->begin = order;
        }
        /*A informação que é atual é passada para slot a seguir e as informações analisadas estão conectadas aos intens anteriores.*/
        else
        {
            order->next = present;
            before->next = order;
        }
    }
}

int finalOfSlotInfor(list *list, head student)
{
    if (list == NULL)
    {
        return 0;
    }
    else
    {
        slotInfor *final = (slotInfor *)malloc(sizeof(slotInfor));
        if (final == NULL)
        {
            return 0;
        }
        final->data = student;
        final->next = NULL;
        if (list->top == NULL)
        {

            list->begin = final;
            list->top = final;
        }
        else
        {
            list->top->next = final;
            list->top = final;
        }
    }
}

void removeByRegister(list *list)
{
    int byRegister;
    cout << "\nWrite what is the student's register: " << endl;
    cin >> byRegister;

    slotInfor *before = list->begin;
    slotInfor *remove = list->begin;

    int loopWhile = 0;
    /*Ao colocar o numero da matricula, o while vai comparar se for diferente aos que são buscado no dados.matricula*/

    while (before->data.Register != byRegister)
    {
        /*Se o a soma do loop for igual do tamanho da lista, ela sai de operação*/

        if (loopWhile == sizeOfTheList(list) - 1)
        {
            cout << "It doesn't exist"<< byRegister << endl;
            return;
        }
        /*Caso contrário, continua a somar. E a informação inicial irá subtituir com 'before'( o valor da variavel armazenado), e vai buscar o próximo item por meio do remove->next*/

        else
        {
            loopWhile += 1;
            before = remove;
            remove = remove->next;
        }

        /*o que tiver na frente dele, o item proximo( já que foi deletado), pega e e colocar na antiga posição do item deletado.*/
    }
    before->next = remove->next;

    free(remove);

    cout << "\nRegister removed" << endl;
}

void removeFromBegin(list *list)
{
    int sizeToRemove = 0;

    sizeToRemove = sizeOfTheList(list);
    if (sizeToRemove == 1)
    {

        free(list->begin);
        list->begin = NULL;
        list->top = NULL;
    }
    else if (sizeToRemove >= 2)
    {
        slotInfor *toRemove = list->begin;
        list->begin = toRemove->next;
        free(toRemove);
        cout << "Element was deleted. " << endl;
    }
}

void removeFromFinal(list *list)
{
    int sizeToRemove = 0;
    sizeToRemove = sizeOfTheList(list);

    if (sizeToRemove == 1)
    {
        free(list->begin);
        list->begin = NULL;
        list->top = NULL;
    }
    else if (sizeToRemove >= 2)
    {
        slotInfor *toRemove = list->begin;

        while (toRemove->next->next != NULL)
        {
            toRemove = toRemove->next;
        }
        free(toRemove->next);

        toRemove->next = NULL;

        list->top = toRemove;
        cout << "The final element was deleted " << endl;
    }
}

/*-----------------------------------------------------------------------------*/

int statusOfTheList(list *list)
{
    if (list == NULL || list->begin == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void showTheList(list *list)
{
    system("cls");
    if (statusOfTheList(list))
    {
        cout << "The list is empty" << endl;
    }
    else
    {
        int count = 0;
        slotInfor *show = list->begin;

        while (show != NULL)
        {
            
            cout << "Position of this person: " << count + 1 << endl;
            
            cout << "The student's name: " << show->data.name << endl;
            cout << "Age: " << show->data.age << endl;
            cout << "Register: " << show->data.Register << endl;
            cout << "Grade 1: " << show->data.n1 << endl;
            cout << "Grade 2: " << show->data.n2 << endl;
            cout << "The total average: " << show->data.averageTotal << endl;

            cout<<"\n"<<endl;

            if (show->data.n1 == 0 && show->data.n2 == 0)
            {
                cout << "The grades are empty\n" << endl;
            }
            else
            {
                cout << "Status of student: " << show->data.status <<"\n"<< endl;
            }
            
            show = show->next;

            count += 1;
        }
    }
}
/*-----------------------------------------------------------------------------------*/

void searchByRegister(list *list)
{
    int Register;
    cout << "Register: " << endl;
    cin >> Register;

    slotInfor *searchR = list->begin;

    while (searchR->data.Register != Register)
    {
        if (searchR->next == NULL)
        {
            cout << "This register doesn't exist in the list. " << endl;
            return;
        }
        else
        {
            searchR = searchR->next;
        }
    }
    char choice;

    cout << "Would like to add the grade? Yes( y ) or No( n )" << endl;
    cin >> choice;

    if (choice == 'n')
    {
        return;
    }
    else if (choice == 'y')
    {
        cout << " - N1: ";

        cin >> searchR->data.n1;

        while (searchR->data.n1 < 0 && searchR->data.n1 < 10)
        {
            cout << "Write again, please." << endl;
            cin >> searchR->data.n1;
        }

        cout << "\n- N2: ";

        cin >> searchR->data.n2;

        while (searchR->data.n2 < 0 && searchR->data.n2 < 10)
        {
            cout << "Write again, please." << endl;
            cin >> searchR->data.n2;
        }

        searchR->data.averageTotal = ((searchR->data.n1 * (0.4)) + (searchR->data.n2 * (0.6)));

        if (searchR->data.averageTotal >= 6)
        {
            strcpy(searchR->data.status, "Aprovado"); // com esse strcpy é dividida por uma vírgula a qual deixa dois espaços para preencher
        }
        else
        {
            strcpy(searchR->data.status, "Reprovado");
        }

        cout << "\nRegister found! " << endl;

        cout << "Name: " << searchR->data.name << endl;

        cout << "Age: " << searchR->data.age << endl;

        cout << "Registration: " << searchR->data.Register << endl;

        cout << "N1: " << searchR->data.n1 << endl;

        cout << "N2: " << searchR->data.n2 << endl;

        cout << "Status of the student: " << searchR->data.status << endl;
    }
}

void searchByPosition(list *list)
{
    int position;

    cout << "Type the position you would like " << sizeOfTheList(list) << endl;

    cin >> position;

readPosition:

    if (position > sizeOfTheList(list))
    {

        cout << "Please, write again the number between the quantity of the list" << endl;
        goto readPosition;
    }

    slotInfor *searchP = list->begin;

    for (int loop = 1; loop < position; loop++)
    {
        searchP = searchP->next;
    }

    char choice;

    cout << "Would like to add the grade? Yes( y ) or No( n )" << endl;
    cin >> choice;

    if (choice == 'n')
    {
        return;
    }
    else if (choice == 'y')
    {
        cout << " - N1: ";

        cin >> searchP->data.n1;

        while (searchP->data.n1 < 0 && searchP->data.n1 < 10)
        {
            cout << "Write again, please." << endl;
            cin >> searchP->data.n1;
        }

        cout << "\n- N2: ";

        cin >> searchP->data.n2;

        while (searchP->data.n2 < 0 && searchP->data.n2 < 10)
        {
            cout << "Write again, please." << endl;
            cin >> searchP->data.n2;
        }

        searchP->data.averageTotal = ((searchP->data.n1 * (0.4)) + (searchP->data.n2 * (0.6)));

        if (searchP->data.averageTotal >= 6)
        {
            strcpy(searchP->data.status, "Aprovado"); // com esse strcpy é dividida por uma vírgula a qual deixa dois espaços para preencher
        }
        else
        {
            strcpy(searchP->data.status, "Reprovado");
        }

        cout << "\nRegister found! " << endl;

        cout << "Name: " << searchP->data.name << endl;

        cout << "Age: " << searchP->data.age << endl;

        cout << "Registration: " << searchP->data.Register << endl;

        cout << "N1: " << searchP->data.n1 << endl;

        cout << "N2: " << searchP->data.n2 << endl;

        cout << "Status of the student: " << searchP->data.status << endl;
    }
}
/*--------------------------------------------------------*/
