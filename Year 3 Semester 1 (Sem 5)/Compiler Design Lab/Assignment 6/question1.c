#include <stdio.h>
#include <string.h>

int main()
{
    char input[100];
    printf("Enter a string: ");
    scanf("%s", input);

    int num_a = 0;
    int num_b = 0;
    int i = 0;

    while (input[i] == 'a')
    {
        num_a++;
        i++;
    }

    while (input[i] == 'b')
    {
        num_b++;
        i++;
    }

    if (num_a > 0 && num_a == num_b && input[i] == '\0')
    {
        printf("String is in the form a^n.b^n\n");
    }
    else
    {
        printf("String is not in the form a^n.b^n\n");
    }
}
