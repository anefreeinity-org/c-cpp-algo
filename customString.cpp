#include <stdlib.h>
#include <stdio.h>

struct String
{
    char* name;
    String(const char* name)
    {
        int i = 0;
        int isFirst = 1;

        while(name[i] != '\0')
        {
            if(isFirst)
            {
                isFirst = 0;
                this->name = (char*) malloc(sizeof(char));
                this->name[i] = name[i];
            }
            else
            {
                this->name = (char*) realloc(this->name, sizeof(char));
                this->name[i] = name[i];
            }
            i++;
        }

        if(name[0] == '\0')
        {
            this->name = (char*)"";
        }
    }
};

int main()
{
    String name = "malloc";
    int i = 0;
    while(name.name[i] != '\0')
    {
        printf("%c", name.name[i]);
        i++;
    }
    printf("\n");
}
