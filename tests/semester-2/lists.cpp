/*
    Сформировать список.
    Найти первый и последний нули, удалить узлы между ними.
 */

#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <string.h>

//две переменные объединяются в одно имя(элемент списка мы называем узлами node)
struct Node {
    int num;//число
    Node *next;//указатель на след. узел (адрес) 
};

Node *add_to_list(Node *lnode, int num)//функция добавления элементов в список(принимает на вход указатель на посл. эл спискаи число)
{
    Node *newel = new Node, *l = lnode;//создаем (переменную которая видна только внутри функции и не видна из вне)указатель на новый элемент
//создаем локальный указатель на последний элемент списка
    newel->num = num;//через стрелку обращаемся к переменным, то самое число которое передали функции
    newel->next = NULL;//в качестве указателя на след. элемент написали ноль

    if(!lnode)//если список пуст
        return newel;//возв.новый элемент

    while(l->next)//пока есть след. элемент 
        l = l->next;//переходим на него

    l->next = newel;//добавим новый элемент в список

    return lnode;//вернем первый элемент списка
}

void del_list(Node *lnode)//функция очищающая список 
{
    Node *p_s = lnode;//создаем указатель на список
    Node *p_tmp = p_s;//создаем указатель на текущий элемент

    while(p_s)//пока список не пуст
    {
        p_s = p_s->next;//переходим на след. элемент
        delete p_tmp;//удаляем текущий
        p_tmp = p_s;
    }
}

char* list_to_str(Node *l)//функция преобразующая список в строку
{
    char *str = new char[256];//созжаем строку буфер(хрень куда я буду что0то записывать)массив символов
    for(; l; l = l->next)//пока текущий эл-т не пуст
    {
        char* buf = new char[256];
        sprintf(buf, "%d", l->num);
        strcat(buf, " ");
        strcat(str, buf);//приобраз. число в строку добавив пробел и записываем в буфер
    }
    return str;//возв. буфер
}

int main()
{
    int n, buff;//задаем переменные 

    srand(time(0));//инициализируем генератор случайных чисел

    Node *z1 = NULL;//создаем два списка
    Node *z2 = NULL;

    Node *lnode_i;//создаем еще три списка
    Node *buff1;
    Node *buff2;

    Node *lnode = NULL;//создаем еще один список

    printf("N: ");//ГЕНЕРИРУЕМ СПИСОК(70-76)
    scanf("%d", &n);
    for(int i = 0; i < n; ++i)
    {
        buff = rand()%10;
        lnode = add_to_list(lnode, buff);
    }

    printf("Input: %s\n", list_to_str(lnode));// выводим список

    lnode_i = lnode;//присваиваем указателю lnodei адрес списка
    while(lnode_i)//пока список не пууст
    {
        if(lnode_i->num == 0 && z1 == NULL)//если число ноль и первый ноль не найден
            z1 = lnode_i;//заносим адрес текущего элементта
        else if(lnode_i->num == 0 && z1 != NULL)//если текущий элемент ноль и первый ноль найден
            z2 = lnode_i;//запоминаем адрес текущего элемента

        lnode_i = lnode_i->next;//переходи к след. элементу
    }

    if(z1 == NULL)//если z1 имеет значение 0(ничего не занесли)
    {
        printf("ERROR: First zero was not found!\n");//выводим и удаляем список
        del_list(lnode);
        return 1;
    }
    if(z2 == NULL)
    {
        printf("ERROR: Second zero was not found!\n");
        del_list(lnode);
        return 2;
    }

    buff1 = z1->next;//заносим адрес найденного нуля
    buff2 = buff1;
    while(buff1 < z2)//пока адрес меньше конца списка
    {
        buff1 = buff1->next;//удаляем элемент
        delete buff2;
        buff2 = buff1;
    }
    z1->next = z2;//чиним список

    printf("Output: %s\n", list_to_str(lnode));//выводим список

    del_list(lnode);

    return 0;
}