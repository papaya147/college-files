#include <iostream>
#include <string>
using namespace std;

bool checkLetter(char c)
{
    if (c >= 'a' && c <= 'z')
        return true;
    if (c >= 'A' && c <= 'Z')
        return true;
    return false;
}

int main()
{
    string code = "if (a == b) c = a;";
    string str = "";
    int characters = code.length(), words = 0;
    for (int x = 0; x < code.length(); x++)
    {
        if (x == 0)
        {
            words++;
            continue;
        }
        if (checkLetter(code[x]) && !checkLetter(code[x - 1]))
            words++;
    }
    cout << "Characters: " << characters << "\nWords: " << words << "\n";
}