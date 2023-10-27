#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void Vigenere(char *, char *);
void Enkripsi();
void Dekripsi();

int main()
{
    int pilihan;

    while (1)
    {
        printf("\n\n1. Enkripsi");
        printf("\n2. Dekripsi");
        printf("\n3. Exit");
        printf("\nInputkan pilihan anda: ");
        scanf("%d", &pilihan);
        fflush(stdin);

        if (pilihan == 1)
        {
            Enkripsi();
        }
        else if (pilihan == 2)
        {
            Dekripsi();
        }
        else if (pilihan == 3)
        {
            exit(0);
        }
        else
        {
            printf("Maaf, inputan yang dimasukan salah.\n\n");
        }
    }
}

void Enkripsi()
{
    char input[257], kunci[33];
    printf("\nInputkan Teks yang akan dienkripsi [max 256 huruf]: ");
    gets(input);
    printf("\nInputkan kunci enkripsi [max 32 huruf]: ");
    gets(kunci);
    printf("\n");

    int a, b;
    for (a = 0, b = 0; a < strlen(input); a++, b++)
    {
        if (b >= strlen(kunci))
        {
            b = 0;
        }
        char encryptedChar = 65 + (((toupper(input[a]) - 65) + (toupper(kunci[b]) - 65)) % 26);
        printf("%c", encryptedChar);
    }
    printf("\n\n");
}

void Dekripsi()
{
    char input[257], kunci[33];
    printf("\nInputkan Teks yang akan diDekripsi [max 256 huruf]: ");
    gets(input);
    printf("\nInputkan kunci [max 32 huruf]: ");
    gets(kunci);
    printf("\n");

    int a, b, hasil;
    for (a = 0, b = 0; a < strlen(input); a++, b++)
    {
        if (b >= strlen(kunci))
        {
            b = 0;
        }
        hasil = (toupper(input[a]) - 64) - (toupper(kunci[b]) - 64);
        if (hasil < 0)
        {
            hasil = 26 + hasil;
        }
        char decryptedChar = 65 + (hasil % 26);
        printf("%c", decryptedChar);
    }
    printf("\n\n");
}
