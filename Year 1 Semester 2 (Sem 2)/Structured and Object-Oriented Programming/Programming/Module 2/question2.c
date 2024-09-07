// 21BDS0340 Abhinav Dinesh Srivatsa

#include <stdio.h>

int main()
{
    char sen[50];
    scanf("%[^\n]s", sen);
    int count[26];
    int x = 0;
    while (x < 26)
    {
        count[x++] = 0;
    }
    x = 0;
    int ord;
    while (sen[x] != '\0')
    {
        ord = (int)sen[x++];
        if (ord <= 'Z' && ord >= 'A')
        {
            ord += 32;
        }
        if (ord != ' ')
        {
            count[ord - 'a']++;
        }
    }
    for (x = 0; x < 26; x++)
    {
        if (count[x] != 0)
        {
            printf("%c %d\n", x + 'a', count[x]);
        }
    }
}