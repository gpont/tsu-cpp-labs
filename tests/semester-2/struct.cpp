/***
 * В массиве структур заданы результаты сессии
 * по 3 экзаменам. Вывести фамилии студентов,
 * сдавших все 3 экзамена до 25 января 2016.
 * Написать функцию сравнения двух дат.
 */

#include <cstdio>
#include <cstdlib>
#include <cstring>

struct Date
{
	int day;
	int month;
	int year;
};

struct Ex
{
	char name[256];
	char ex[256];
	int b;
	struct Date date;
};

bool dates_cmp(Date first, Date second)
{
	int first_date  = first.year*10000+first.month*100+first.day;
	int second_date = second.year*10000+second.month*100+second.day;

    if(first_date >= second_date)
		return true;
    return false;
}

int get_data(const char filename[], Ex *exs)
{
    FILE *f = fopen(filename, "r");
	

    if(!f)
    {
        printf("ERROR: Cannot open %s.", filename);
        exit(1);
    }

    int i = 0;
    while(!feof(f))
    {
		fscanf(f, "%s %s %d %d.%d.%d",
            &(exs[i].name),
            &(exs[i].ex),
			&(exs[i].b),
            &(exs[i].date.day),
			&(exs[i].date.month),
			&(exs[i].date.year)
        );
        ++i;
    }
    return i;
}

int exs_cmp(const void *r1, const void *r2)
{
	Ex *r_local_1 = (Ex*)r1;
	Ex *r_local_2 = (Ex*)r2;
	return strcmp(r_local_1->name, r_local_2->name);
}

void print_structs(Ex *exs, int ex_count)
{
	for (int i = 0; i < ex_count; ++i)
		printf("%s\n", exs[i].name);
}

int main()
{
	Ex exs[100];
	int ex_count = get_data("db", exs);
	
	qsort(exs, ex_count, sizeof(Ex), exs_cmp);
	//print_structs(exs, ex_count);

	Date test_date = {25,01,2016};

	int i = 0;
	while(i < ex_count)
	{
		char test_name[100];
		strcpy(test_name, exs[i].name);
		int test_ex[] = {0, 0, 0};
		
		while(strcmp(exs[i].name, test_name) == 0 && i < ex_count)
		{
			if(strcmp(exs[i].ex, "Ex1") && dates_cmp(test_date, exs[i].date) && exs[i].b > test_ex[0])
				test_ex[0] = exs[i].b;
			if(strcmp(exs[i].ex, "Ex2") && dates_cmp(test_date, exs[i].date) && exs[i].b > test_ex[1])
				test_ex[1] = exs[i].b;
			if(strcmp(exs[i].ex, "Ex3") && dates_cmp(test_date, exs[i].date) && exs[i].b > test_ex[2])
				test_ex[2] = exs[i].b;
			++i;
		}
		printf("%s %d %d %d\n", test_name, test_ex[0], test_ex[1], test_ex[2]);
		if(test_ex[0] > 2 && test_ex[1] > 2 && test_ex[2] > 2)
			printf("%s\n", test_name);
	}

	fcloseall();

	return 0;
}

