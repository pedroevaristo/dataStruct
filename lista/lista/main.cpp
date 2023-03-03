#include <iostream>
#include <cstdlib>
#include "head.h"

using namespace std;

int main()
{
    head student;
    list *list;

   char betweenFromTheOptions;
    char choice;

    /*-------*/
    list  = createTheList();
    while (choice != 6)
    {
        cout << "Type between the options:" << endl;
        /*----------------------------------------*/
        cout << "1 . Enter a student's information;" << endl;
        cout << "2 . Take a student's grade or by position;" << endl;
        cout << "3 . Print the information;" << endl;
        cout << "4 . Taking off the specific information;" << endl;
        cout << "5 . Calculate the class's final average  " << endl;
        cout << "6 . Clear the memory and exit; " << endl;

        cin >> choice;

        switch (choice)
        {
        case '1':
            

            cout << "Would you like to put it in the: Beginner ( b ) or Final ( f ) or by the student's register ( r ): " << endl;
            cin >> betweenFromTheOptions;
            while (betweenFromTheOptions != 'b' && betweenFromTheOptions != 'f' && betweenFromTheOptions != 'r')
            {
                cout << "There isn't the option above, choice again" << endl;
                cin >> betweenFromTheOptions;
            }

            fflush(stdin);
            cout << "Write the name of student:" << endl;
            cin.getline(student.name, 50);

            cout << "The student's age" << endl;
            cin >> student.age;

            while (student.age < 10 || student.age > 80)
            {
                cout << "Doesn't exist this age, please write again" << endl;
                cin >> student.age;
            }
            cout << "Register: " << endl;
            cin >> student.Register;

            student.n1 = 0;
            student.n2 = 0;

            if (betweenFromTheOptions == 'b')
            {
                beginOfSlotInfor(list, student);
            }
            else if (betweenFromTheOptions == 'r')
            {
                byRegisterOfSlotInfor(list, student);
            }
            else if (betweenFromTheOptions == 'f')
            {
                finalOfSlotInfor(list, student);
            }

            break;
        case '2':
            char betweenFromTheOptions1;

            cout << "Would you like to take information from position( p ) or register( r )?" << endl;
            cin >> betweenFromTheOptions1;

            while (betweenFromTheOptions1 != 'p' && betweenFromTheOptions1 != 'r')
            {
                cout << "Please, something has wrong" << endl;

                cout << "Write again, there aren't options with this choice. " << endl;
                cin >> betweenFromTheOptions1;
            }
            if (betweenFromTheOptions1 == 'p')
            {
                searchByPosition(list);
            }
            else if (betweenFromTheOptions1 == 'r')
            {
                searchByRegister(list);
            }

            break;
        case '3':
            showTheList(list);

            break;
        case '4':
            // char choiceCase2;

            cout << "What are the options do you want?:\n remove by register ( r ) or \n remove from beginner ( b ) or final( f )?" << endl;
            cin >> choice;
            if (choice == 'r')
            {
                removeByRegister(list);
            }
            else if (choice == 'b')
            {
                removeFromBegin(list);
            }
            else if (choice == 'f')
            {
                removeFromFinal(list);
            }
            break;
        case '5':
            showTheAverageTotal(list);
            break;
        case '6':

            cout << "Thanks to use our service :)" << endl;
            freeTheList(list);
            exit(0);
            break;
        }
    }
}