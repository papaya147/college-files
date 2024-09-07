// 21BDS0340 Abhinav Dinesh Srivatsa

#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int fact = 1;
    for(int x = 1; x <= n; x++){
        fact *= x;
    }
    printf("%d", fact);
}