struct head{

    char name[50];
    char status[50];

    int age;
    int Register;

    float notes[2], averageTotal;

};
struct infor{//aqui vai ser armazenado cada nova informação
//estrutura aninhanda => é basicamente uma estrutura dentro de outra, isto é, uma estrutura contida em outra ou uma estrutura que pode ser acessada por outra. Há duas formas de implementar estruturas aninhadas
    head studentsInfor;
    list *next;

};
struct list{
    list *begin;
    list *top;
};

list createList();

void sizeOfList(list *list);

int beginOfList(list *list, head student);
//testa se com void funciona, o termo;
int finalOfList();