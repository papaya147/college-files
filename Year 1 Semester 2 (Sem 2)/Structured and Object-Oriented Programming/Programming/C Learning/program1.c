#include <stdio.h>

main()
{
    int v1;
    int v2;
    printf("Enter v1: ");
    scanf("%d", &v1);
    printf("Enter v2: ");
    scanf("%d", &v2);
    int v3 = v1 + v2;
    printf("Integer Sum: %d \n", v3);

    float f1, f2, f3;
    printf("Enter f1 and f2: ");
    scanf("%f %f", &f1, &f2);
    f3 = f1 + f2;
    printf("Float sum: %f", f3);
}
