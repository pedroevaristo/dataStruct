#include <iostream>
#include <cstdlib>

#include "head.h"

usign namespace std;

int main()
{
    head refeer;
    list *list;
    /*---------------*/
    char option;
    char optionBetween;
    int loopWhile = 1;
    int auxiliarFunction = 0;
    /*----------------*/
    while(loopWhile != 0){

        cout<<"What want to you do? "<<endl;
        cout<<"1 - Put new item; "<<endl;
        cout<<"2 - Remove item; "<<endl;
        cout<<"3 - Search student by registration or position; "<<endl;
        cout<<"4 - Calculate the final average; "<<endl;
        cout<<"5 - Show the list; "<<endl;
        cout<<"6 - Exit the program; "<<endl;


        switch(option){
            case '1':
            cout<<"Do you want put the student's information from beginner(b) or final(f) or by registration(r)?"<<endl;
            cin>> auxiliarFunction;
            while(auxiliarFunction != 'b' || auxiliarFunction != 'f' ||auxiliarFunction != 'r'){
                cout<<"Write down again! "<<endl;

                cin>>auxiliarFunction;
            }

            fflush(stdin);
            cout<<"provide the name of student: "<<endl;
            cin.getline(refeer.name, 50);

            cout<<"the student's age: "<<endl;
            cin>>refeer.age;

            while(refeer.age < 0 || refeer.age > 80){
                cout<<"Incomum age. Type it again"<<endl;

                cin>>refeer.age;
            }
            cout<<"Put the register of the student: "<<endl;
            cin>>refeer.Register;
            int doWhileLoop = 0;

            cout<<"Type the notes"<<endl;
            do{
                cin>>refeer.notes[doWhileLoop];
                doWhileLoop++;}while(doWhileLoop < 2);

            if(auxiliarFunction == 'b'){
                beginOfList(list, refeer);
            }else if(auxiliarFunction == 'f'){
                finalOfList(list, refeer);
            }else if(auxiliarFunction == 'r'){

            }

            break;
            case '2':
            break;
            case '3':
            break;
            case '4':
            break;
            case '5':
            break;
            case '6':
            break;
        }
    }
}