#include "head.h"
#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;
// fazer como se fosse uma fila do banco, pra o novo cadastro do cliente;

int main()
{
    head registry, *registryQueue;
    Queue *queue;

    registryQueue = &registry;

    char choice;

    int loopWhile = 1;

    queue = createQueue();
    cout << "initiate the queue...\n"
         << endl;
    while (loopWhile != 0)
    {

        cout << "inform what would you like to do !" << endl;

        cout << "0 - Exit and clear the memory; " << endl;

        cout << "1 - Consult size of the row; " << endl;

        cout << "2 - Print out the row; " << endl;

        cout << "3 - Insert the person with information; " << endl;

        cout << "4 - Verify if the row is empty; " << endl;

        cout << "5 - Remove person from queue;  " << endl;

        cout << "6 - Consult the person from queue; " << endl;

        cin >> choice;

        switch (choice)
        {
        case '0':

            freeQueue(queue);

            break;
        case '1':

            sizeOfTheQueue(queue);

            break;
        case '2':

            printOutTheRow(queue);

            break;
        case '3':

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
        case '4':

            statusOfTheQueue(queue);

            break;
        case '5':

            break;
        case '6':

            break;
        }
    }
}
