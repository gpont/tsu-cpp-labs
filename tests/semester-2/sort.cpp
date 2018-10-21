#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void vstavka(int n,int a[]) //объявление функции
{ 
	int c,i,j,b[10000];//объявление переменных
	for (i=0;i<n;i++) b[i]=a[i];//копируем в б массив а (пробегаемся по массиву и пока I меньше N увеличиваем I)
	for (i=0;i<n;i++)//мы крутые можем его изменять 
	{
		c=b[i];//сохраняем значение i-ого элемента
		for (j=i-1;(j>=0)&&(c<b[j]);j--)//находим в первой половине массива элемент больше i 
			b[j+1]=b[j];//и сдвигаем от i до него вправо
		b[j+1]=c;//кладем i-ый элемент на место элемента большего i
	}
	printf ("\n vstavka: \n");
	for (i=0;i<n;i++) printf ("%d ",b[i]);//выводим массив
}

void puzr(int n,int a[])
{
	int i,c,j,b[10000];
	printf("\n");
	for (i=0;i<n;i++) b[i]=a[i];

	for (i=0;i<n-1;i++)
		for (j=0;j<n-1;j++)//пробегается по массиву не затрагивая последний элемент
		{
			if (b[j]>b[j+1])//сравнивает текущий со след.
			{
				//если он больше меняет их местами
				c=b[j];
				b[j]=b[j+1];
				b[j+1]=c;
			}
		}
	printf ("\n puzr: \n");
	for (i=0;i<n;i++) printf ("%d ",b[i]);
}

void vbr (int n,int a[])
{
	int c,i,j,b[10000],p,min;
	for (i=0;i<n;i++) b[i]=a[i];
	for (i=0;i<n;i++) 
	{
		min=b[i]; 
		c=i;//сохр. i минимума
		for (j=i+1;j<n;j++) //от след. до конца ищет минимум
		{
			if (b[j]<min) 
			{
				min=b[j];
				c=j;
			}
		}
		// меняет минимальный и текущий местами
		p=b[i];
		b[i]=min;
		b[c]=p;
	}
	printf ("\n vbr: \n");
	for (i=0;i<n;i++) printf ("%d ",b[i]);
}

int main ()
{
	const int n=10;//количество элментов в мвссиве
	int a[n],t,i;
	clock();//включает таймер
	clock_t t1,t2;//объявляет переменные
	srand(time(0));//вкл. генератор случ. чисел

	for (i=0;i<n;i++)
	{ //создается массив случ. чисел
		a[i] = rand()%10;
		printf("%d ",a[i]);
	}

	t1 = clock();// запоминается время до
	vstavka(n,a);//вызов функции вставка
	t2 = clock();// время после
	printf("\n\nvstavka t= %d\n\n",(t2-t1));//вывод время до - время после

	t1=clock();
	puzr(n,a);
	t2=clock();
	printf("\n\npuzr t= %d\n\n",(t2-t1));

	t1=clock();
	vbr(n,a);
	t2=clock();
	printf("\n\nvbr t= %d\n\n",(t2-t1));
	return 0;
}