#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *strcatM (char *s1, char *s2)
{
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int i = 0, p = 0;
    char *aux = malloc(len1 + len2 + 1);

    for(i = 0; s1[i] != '\0'; i++)
    {
        aux[i] = s1[i];
    }

    for(int p = 0; s2[p] != '\0'; p++)
    {
        aux[i + p] = s2[p];
    }
    aux[len1 + len2] = '\0';
    strcpy(s1, aux);
    free(aux);
    
    return s1;
}

int main()
    {
        char string1[10] = "Ab";
        char string2[] = "elha";

        char *result = strcatM(string1, string2);
        printf("%s", result);
    }