#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <cstring>


int main()
{
    char s[200]; 
    scanf("%[^\n]s", &s);
    char* p;
    char mat[30][30], re[30];
    int i = 0, j, m, v[30], aux;
    p = strtok(s, " ");
    while (p != NULL)
    {
        strcpy(mat[i], p);
        v[i] = strlen(mat[i]);
        i++;
        p = strtok(NULL, " ");
    }
    m = i - 1;
   

    for (i = 0; i < m; i++)
        for (j = i + 1; j <= m; j++)
            if (v[i] < v[j])
            {
                strcpy(re, mat[i]);
                mat[i][0] = NULL;
                strcpy(mat[i], mat[j]);
                mat[j][0] = NULL;
                strcpy(mat[j], re);

                aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }


    for (i = 0; i < m; i++)
        for (j = i + 1; j <= m; j++)
            if (v[i] == v[j] && strcmp(mat[i], mat[j]) > 0)
            {
                strcpy(re, mat[i]);
                mat[i][0] = NULL;
                strcpy(mat[i], mat[j]);
                mat[j][0] = NULL;
                strcpy(mat[j], re);

                aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }

    for (i = 0; i <= m; i++) { printf("%s\n", mat[i]); }
}