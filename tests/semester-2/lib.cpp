//функции библиотеки 

// копирует строку s от символа i до символа j в строку w
void copy_w (char s[], char w[], int i, int j)
{
    int k=0;
    while (i<j) w[k++]=s[i++];
    w[k]=0;
}

// возращает индекс разделителя следущий после i
int let (char s[], int i)
{
    int n=strlen(s);
    while (i<n && s[i]!=' ' && s[i]!=',' && s[i]!='_' && s[i]!='.') i++;
    return i;
}
 //возращает следущий после i индецс не разделителя
int nolet (char s[], int i)
{
    int n=strlen(s);
    while (i<n && (s[i]==' ' || s[i]==',' || s[i]=='_' || s[i]=='.')) i++;
    return i;
}

// копирует в строку символы без повторений (т.е. если есть повторение, он его не записывает)
void ch_set (char s[],char b[])
{
    int n_s, n_b=0, i, j;
    n_s=strlen(s);
    for (i=0;i<=n_s;i++)
    {
        j=0;
        while (j<n_b && s[i]!=b[j]) j++;
        if (j==n_b) {b[j]=s[i]; n_b++;}
    }
    b[n_b]=0;
}

// находит одинаковые символы в строках и выписывает в отдельную строку
void int_set(char s1[],char s2[], char s[])
{
    int i,j,n1,n2,n=0;
    char s3[50];
    ch_set(s1,s3);
    n1=strlen(s3);
    n2=strlen(s2);
    for (i=0;i<n1;i++)
    {
        j=0;
        while (j<n2 && s3[i]!=s2[j]) j++;
        if (j!=n2) s[n++]=s3[i];
    }
    s[n]=0;
}

// удаляет заменой элементов. Элемент k начало удаления, i шаг удаления элементов
void del(char s[], int k, int i)
{
    while(s[k+i]!=0)
    {
        s[k]=s[k+i];
        ++k;
    }
    s[k]=0;
}