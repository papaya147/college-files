#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isGrammarValid(char *str)
{
    int len = strlen(str);
    int i = 0;

    while (i < len && str[i] == 'a')
    {
        i++;
    }

    if (i == len && str[i] == 'b')
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    char input[100];
    printf("Enter a string: ");
    scanf("%s", input);

    if (isGrammarValid(input))
    {
        printf("String follows the grammar a^n.b\n");
    }
    else
    {
        printf("String does not follow the grammar a^n.b\n");
    }
}
