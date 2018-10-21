/*
    Дан файл. Зашифровать байтовым ключом по модулю два. 
    Записать ключ в первый байт зашифрованного файла, 
    затем расшифруйте файл.
*/

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

void xor_crypto(FILE* f_in, FILE* f_out, char key)
{
    int key_count = 0;
    int encrypt_byte;

    while((encrypt_byte = fgetc(f_in)) != EOF)
        fputc(encrypt_byte ^ key, f_out);
}

void encrypt_data(FILE* f_in, FILE* f_out, char* key)
{
    fputc(key, f_out);
    xor_crypto(f_in, f_out, key);
}

void decrypt_data(FILE* f_in, FILE* f_out)
{
    char key;

    fscanf(f_in, "%c", &key);
    xor_crypto(f_in, f_out, key);
}

FILE* fopen_secure(const char fname[], const char mode[])
{
    f = fopen(fname, mode);
    if(f == NULL)
    {
        fclose(f);
        printf("Cannot open file %s with mode %s\n", fname, mode);
        exit(2);
    }
    return f;
}

int main()
{
    const char  f_in_name[]     = "file.in",
                f_out_name[]    = "file.out",
                f_test_name[]      = "file.t";
    srand(time(0));
    char        xormask         = (char)(rand()%256);

    FILE *f_in, *f_out, *f_test;

    f_in = fopen_secure(f_in_name, "r");
    f_out = fopen_secure(f_out_name, "w");
    f_test = fopen_secure(f_test_name, "w");

    encrypt_data(f_in, f_out, xormask);
    fclose(f_out);

    f_out = fopen(f_out_name, "r");
    decrypt_data(f_out, f_test);

    fcloseall();

    return 0;
}