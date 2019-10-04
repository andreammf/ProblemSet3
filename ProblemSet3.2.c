#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    if (argc !=2)
    {
        printf("missing command-line argument\n");
        return 1;
    }
    char str[100] = "Hello";
    
    int L = strlen(str);
   
    char *ciphertext = malloc(sizeof(char)*(L+1));
   
    int i, key = 1;
    
    for( i = 0 ; i < L ; i++)
    {
        if(isalpha(str[i])) ciphertext[i] = (toupper(str[i]) - 'A' + key)%26 + 'A';
        else ciphertext[i] = str[i];
    }
    ciphertext[i] = 0;
    
    char *plaintext2 = malloc(sizeof(char)*(L+1));

    for( i = 0 ; i < L ; i++)
    {
        if(isalpha(str[i])) plaintext2[i] = (toupper(ciphertext[i]) - 'A' + 26 - key)%26 + 'A';
        else plaintext2[i] = ciphertext[i];
    }
    plaintext2[i] = 0;
    
    printf("plaintext: %s\n", str);
    printf("cyphertext: %s\n", ciphertext);
    printf("decrpted: %s\n", plaintext2);

    return 0;
}