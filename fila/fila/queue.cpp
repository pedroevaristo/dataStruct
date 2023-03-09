#include "head.h"
#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;
// fazer como se fosse uma fila do banco, pra o novo cadastro do cliente;

int main()
{
    head registry, *registry1;
    queue *queue;
    registry1 = &registry;

    char choice;

    int loopWhile = 1;
    int sizestatus = 0;
    int status = 0;

    create();
    cout << "initiate the queue...\n"
         << endl;
    while (loopWhile != 0)
    {

        cout << "inform what would you like to do !" << endl;

        cout << "0 - Exit and clear the memory; " << endl;
        cout << "1 - Insert the person with information; " << endl;
        cout << "2 - Remove person from queue; " << endl;
        cout << "3 - Consult size of the row;  " << endl;
        cout << "4 - Verify if the row is empty; " << endl;
        cout << "5 -  Print out the row; " << endl;
        cout << "6 - Consult the person from queue; " << endl;

        cin >> choice;

        switch (choice)
        {
        case '0':
            freeQueue(queue);
            exit(0);
            break;
        case '1':

            cout << "Type your information below: " << endl;

            cout << "Name: " << endl;
            fflush(stdin);
            cin.getline(registry.name, Max_Char);

            cout << "Age: " << endl;
            cin >> registry.age;

            cout << "Password: " << endl;
            cin >> registry.password;

            cout << "Money in the account: " << endl;
            cin >> registry.money;

            insertTheRow(queue, registry);

            break;
        case '2':
            removeTheRow(queue);

            break;
        case '3':

            sizestatus = sizeOfTheQueue(queue);

            cout << "This is siz" << sizestatus << endl;

            break;
        case '4':

            statusOfTheQueue(queue);

            break;

        case '5':
            printOutTheRow(queue);

            break;
        case '6':
            consultThePerson(queue, registry1);

            break;
        }
    }
}
