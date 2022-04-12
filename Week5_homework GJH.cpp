#include <stdio.h>  
#include <stdlib.h>  
#include <malloc.h>   

#define DEF_LINE_MAX 100   

char** nField;

void CreateField(int, int);        // 필드 생성 함수.  
void MineSweeping(int, int);
void PrintField(int, int);

void main()
{
    int nMX, nMY;

    printf("X값 Y값 입력 (1 - 100) : ");
    scanf_s("%d %d", &nMX, &nMY);

    if ((nMX * nMY) <= 0 || nMX > DEF_LINE_MAX || nMY > DEF_LINE_MAX) return;

    CreateField(nMX, nMY);
    MineSweeping(nMX, nMY);
    PrintField(nMX, nMY);
}

void CreateField(int x, int y)
{
    int i, j;

    nField = (char**)malloc(sizeof(char) * y);
    for (i = 0; i < y; ++i)
    {
        *(nField + i) = (char*)malloc(sizeof(char) * x);
    }

    printf("Period(.) 혹은 Asterisk(*) 기호 외에는\n");
    printf("미입력 처리됩니다.\n");
    printf("필드 입력\n-----------------\n");
    for (i = 0; i < y; ++i)
    {
        for (j = 0; j < x; ++j)
        {
            scanf_s("%c", &nField[i][j]);
            if (nField[i][j] != '.' && nField[i][j] != '*') --j;
            if (nField[i][j] == '.') nField[i][j] = '0';
        }
    }
}

void MineSweeping(int x, int y)
{
    int i, j, ti, tj;

    for (i = 0; i < y; ++i)
    {
        for (j = 0; j < x; ++j)
        {
            if (nField[i][j] == '*')
            {
                for (ti = i - 1; ti <= i + 1; ++ti)
                {
                    if (ti < 0 || ti >= y) continue;
                    for (tj = j - 1; tj <= j + 1; ++tj)
                    {
                        if (tj < 0 || tj >= x) continue;
                        if (nField[ti][tj] != '*')
                            ++nField[ti][tj];
                    }
                }
            }
        }
    }
}

void PrintField(int x, int y)
{
    int i, j;

    for (i = 0; i < y; ++i)
    {
        for (j = 0; j < x; ++j)
        {
            printf("%c", nField[i][j]);
        }
        printf("\n");
    }
}


