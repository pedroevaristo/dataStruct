#include "head.h"
#include<iostream>
#include<cstdlib>

using namespace std;
//fazer como se fosse uma fila do supermercado;


int main(){
    head registry, *registryQueue;
    Queue *queue;

    registryQueue = &registry;

    char choice;

    int loopWhile = 1;

    queue = createQueue();
    cout<<"initiate the queue...\n"<<endl;
    while(loopWhile != 0){

        cout<<"inform what would you like to do !"<<endl;
        
        cout<<"0 - Exit and clear the memory; "<<endl;

        cout<<"1 - Consult size of the row; "<<endl;

        cout<<"2 - Print out the row; "<<endl;

        cout<<"3 - Insert the person with information; "<<endl;

        cout<<"4 - Verify if the row is empty; "<<endl;
        
        cout<<"5 - Remove person from queue;  "<<endl;
        
        cout<<"6 - Consult the person from queue; "<<endl;
       

        cin>>choice;

        switch(choice){
            case '0':

            
            break;
            case '1': 
            
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

