#include <stdio.h>
#include <stdlib.h>
#include <string.h>



struct data_t {
	int d;
	int m;
	int y;
};
/*
struct res {
	char fio[20];
	char predmet[10];
	int ball;
	data_t data;
};
*/
struct fio
{
    char f[50];
    char i[50];
    char o[50];
};
 
struct ball
{
    int b;
    data_t data;
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

void read_data(FILE *file,data_t *data){
	fscanf(file,"%d.%d.%d",&data->d,&data->m,&data->y);
}

void read_fio(FILE *file, fio *f){
	fscanf(file,"%s %s %s",&f->f,&f->i,&f->o);
}

void read_1_predmet(FILE *file, predmet *p){
	fscanf(file,"%s %d", p->name,&p->predmet_ball.b);
	read_data(file,&p->predmet_ball.data);
}

int read_rec(FILE* file,ex *rec){
	if(!feof(file)){
		read_fio(file,&rec->ex_fio);
		read_1_predmet(file,&rec->ex_predmet[0]);
		read_1_predmet(file,&rec->ex_predmet[1]);
		read_1_predmet(file,&rec->ex_predmet[2]);
		return 1;
	}else return 0;
}

int read_db(FILE *file,ex *db){
	int n=0;
	while(read_rec(file,&db[n]))++n;
	return n-1;
}
		

int is_that_data(data_t d1, data_t d2){
	if(d1.y<=d2.y && d1.m<=d2.m && d1.d<=d2.d) return 1;
	return 0;
}


int rescmp(const void *r1,const void *r2){
	ex *t1=(ex*)r1, *t2=(ex*)r2;
	return strcmp(t1->ex_fio.f,t2->ex_fio.f);
}

int is_that_student(ex stud){
	int suc=0;
	data_t data = {25,01,2016};
	for(int i=0; i<3; i++)
		if(is_that_data(data,stud.ex_predmet[i].predmet_ball.data) && (stud.ex_predmet[i].predmet_ball.b > 2))
			suc++;
	if(suc==3) return 1;
	else return 0;
}


int main(void){
	
	FILE *db_f;
	ex db[100];
	int n;
	if(!(db_f=fopen("db","r"))){
		puts("Error file");
		return 1;
	}
	n=read_db(db_f, db);
    qsort(db,n,sizeof(ex),rescmp);
	for(int i=0;i<n;++i){
		puts(db[i].ex_fio.f);
		putchar('\n');
	}
	
	getchar();
	
	return 0;
}

