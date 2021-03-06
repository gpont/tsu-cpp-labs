#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "lib.cpp"

int main()
{		
	char s[50], w[50], d[50], g[50];
	int i, k, r1, r2;
    fgets(s, 100, stdin);
    
	k = nolet(s, 0); //проходит разделители, останавливается на начале следующего слова и возвращает к индексу первого слова
	i = let(s, k); //останавливается на разделители и запоминает индекс окончания слова
	copy_w(s, w, k, i); //выделение части строки в новую строку, k-начало, i-конец
	while(i < strlen(s))
	{
		k = nolet(s, i);//в K проходит все разделители 
		i = let(s, k);//i записывает индекс след. разделителя 
		copy_w(s, d, k, i);// от k до i копирует в строку из s в d 
		int_set(w, d, g); //находит одинаковые символы в строках и выписывает в отдельную строку
		r1 = strlen(g);//в r1 записывает длину g 
		ch_set(d, g); //копирует в строку символы без повторений (т.е. если есть повторение, он его не записывает)
		r2 = strlen(g);
		if(r1 == r2)
		{
			del(s, k, i-k); //удаляет заменой элементов. Элемент k начало удаления, i-k шаг удаления элементов
			i -= i-k;
		}
	}
	puts(s);
    return 0;
}