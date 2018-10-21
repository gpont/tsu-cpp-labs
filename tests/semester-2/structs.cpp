/*
 В массиве структур заданы результаты сессии
 по 3 экзаменам. Вывести фамилии студентов,
 сдавших все 3 экзамена до 25 января 2016.
 Использовать структуры fio, predmet, ball,
 написать функцию сравнения двух дат.
 */

/*
 В этом проекте неправильно реализованы структуры,
 я зачет получил, но Голубева может что-нибудь
 заподозрить при повторном приеме от другого человека. :\
 */

#include <cstdio>
#include <cstdlib>
#include <cstring>

struct fio
{
    char f[50];
    char i[50];
    char o[50];
};

struct date
{
    int day;
    int month;
    int year;
};

struct ball
{
    int ball;
    int day;
    char month[15];
    int year;
};

struct predmet
{
    char name[50];
    ball predmet_ball;
};

struct ex
{
    fio ex_fio;
    predmet ex_predmet[3];
};

bool datescmp(date first, date second)
{
    if(first.year > second.year)
        return true;
    else if (first.year < second.year)
        return false;
    else
        if (first.month > second.month)
        {
            return true;
        }

    return 1;
}

int getdata(const char filename[], ex *data, const int data_l, const int predmet_c)
{
    FILE *f = fopen(filename, "r");

    if(!f)
    {
        printf("Cannot open %s.", filename);
        return 1;
    }

    for(int i = 0; i < data_l && !feof(f); ++i)
    {
        fscanf(f, "%s %s %s",
            &data[i].ex_fio.f,
            &data[i].ex_fio.i,
            &data[i].ex_fio.o
        );
        for(int j = 0; j < predmet_c; ++j)
            fscanf(f, " %s %d %d %s %d",
                   &data[i].ex_predmet[j].name,
                   &data[i].ex_predmet[j].predmet_ball.ball,
                   &data[i].ex_predmet[j].predmet_ball.day,
                   &data[i].ex_predmet[j].predmet_ball.month,
                   &data[i].ex_predmet[j].predmet_ball.year
            );
    }

    return 0;
}

int main()
{
    const int data_l = 3;
    const int predmet_c = 3;

    int counter = 0;

    ex data[data_l];

    ball s_date = {
        0,
        25,
        "Январь",
        2016
    };

    getdata("db.txt", data, data_l, predmet_c);

    for(int i = 0; i < data_l; ++i)
    {
        for(counter = 0;
            (counter < predmet_c) && (data[i].ex_predmet[counter].predmet_ball.day != 0) &&
                !datescmp(s_date, data[i].ex_predmet[counter].predmet_ball) &&
                (data[i].ex_predmet[counter].predmet_ball.ball > 2);
            ++counter);

        if(counter == predmet_c)
            printf("%s\n", data[i].ex_fio.f);
    }

    return 0;
}