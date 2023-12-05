#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char* Trim(const char* string)
{
    char* trimmedStr = (char*) malloc(sizeof(char));
    int trimmedStrLen = 0;
    int isBfEl = 0;
    int i = 0;
    
    while(*(string + i) != '\0')
    {
        if(*(string + i) != ' ')
        {
            *(trimmedStr + trimmedStrLen) = *(string + i);
            trimmedStr = (char*) realloc(trimmedStr, sizeof(char));
            trimmedStrLen++;
            isBfEl = 1;
        }
        else if(isBfEl)
        {
            *(trimmedStr + trimmedStrLen) = *(string + i);
            trimmedStr = (char*) realloc(trimmedStr, sizeof(char));
            trimmedStrLen++;
            isBfEl = 0;
        }

        i++;
    }
    
    if(*(trimmedStr + trimmedStrLen - 1) == ' ')
    {
        *(trimmedStr + trimmedStrLen - 1) = '\0';
    }

    return trimmedStr;
}

int main()
{
    printf("%s", Trim("          ayan          bhattacharya               xyz          "));
    printf("|\n");
}
