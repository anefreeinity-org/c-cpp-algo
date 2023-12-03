#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void MakeNewArrEntry(int* isNewArrElement, char*** splitedStrArr, int* splitedStrArrSize, char** splitedStr, int* isNewElement, int* splitedStrSize, int* isFirstElement)
{
    if(!(*isFirstElement)) return;
    if(*isNewArrElement)
    {
        *splitedStrArr = (char**) malloc(sizeof(char*));
        *isNewArrElement = 0;
    }
    else
    {
        *splitedStrArr = (char**) realloc(*splitedStrArr, sizeof(char*));
    }
    *(*splitedStrArr + *splitedStrArrSize) = *splitedStr;
    *splitedStrArrSize += 1;
    *isNewElement = 1;
    *splitedStrSize = 0;
}

void MakeElement(int* isNewElement, char** splitedStr, int* splitedStrSize, const char** str, int* i, int* isFirstElement)
{
    if(*isNewElement)
    {
        *splitedStr = (char*) malloc(sizeof(char));
        *isNewElement = 0;
    }
    else
    {
        *splitedStr = (char*) realloc(*splitedStr, sizeof(char));
    }

    *(*splitedStr + *splitedStrSize) = *(*str + *i);
    *splitedStrSize += 1;
    *isFirstElement = 1;
}

char** Split(const char* str, char delimiter)
{
    int i = 0; 
    int splitedStrSize = 0;
    int splitedStrArrSize = 0;
    int isNewElement = 1;
    int isNewArrElement = 1;
    int isFirstElement = 0;
    char* splitedStr = NULL;
    char** splitedStrArr = NULL;

    if(!str)
    {
        splitedStrArr = (char**) malloc(sizeof(char*));
        *splitedStrArr = NULL;
        return splitedStrArr;
    }

    while( *(str+i) != '\0' )
    {
        if(*(str+i) == delimiter && (*(str+i+1) == '\0' || *(str+i+1) == delimiter))
        {
            if(*(str+i+1) == '\0')
            {
                MakeNewArrEntry(&isNewArrElement, &splitedStrArr, &splitedStrArrSize, &splitedStr, &isNewElement, &splitedStrSize, &isFirstElement);
            }
            i++;
            continue;
        }

        if( *(str+i) != delimiter )
        {
            MakeElement(&isNewElement, &splitedStr, &splitedStrSize, &str, &i, &isFirstElement);
        }
        else
        {
            MakeNewArrEntry(&isNewArrElement, &splitedStrArr, &splitedStrArrSize, &splitedStr, &isNewElement, &splitedStrSize, &isFirstElement);
        }

        if(*(str+i+1) == '\0')
        {
            MakeNewArrEntry(&isNewArrElement, &splitedStrArr, &splitedStrArrSize, &splitedStr, &isNewElement, &splitedStrSize, &isFirstElement);
        }
        i++;
    }

    if(splitedStrArr)
    {
        splitedStrArr = (char**) realloc(splitedStrArr, sizeof(char*));
        *(splitedStrArr + splitedStrArrSize) = NULL;
    }
    else
    {
        splitedStrArr = (char**) malloc(sizeof(char*));
        *(splitedStrArr + splitedStrArrSize) = NULL;
    }
    return splitedStrArr;
}

int main()
{
	char** resArr = Split("36,34,45,program,9.8,admin@1999", ',');
    int i = 0;
    while(*(resArr+i))
    {
        printf("%s\n", *(resArr+i));
        i++;
    }
}
