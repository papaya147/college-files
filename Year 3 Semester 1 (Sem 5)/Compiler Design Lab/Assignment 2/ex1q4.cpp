#include <iostream>
#include <string>
using namespace std;

bool checkKeyword(string ch)
{
    string keywords[32] = {"auto", "break", "case", "char", "const", "continue", "default",
                           "do", "double", "else", "enum", "extern", "float", "for", "goto",
                           "if", "int", "long", "register", "return", "short", "signed",
                           "sizeof", "static", "struct", "switch", "typedef", "union",
                           "unsigned", "void", "volatile", "while"};
    for (int x = 0; x < 32; x++)
        if (ch == keywords[x])
            return true;
    return false;
}

int main()
{
    string input;
    cin >> input;
    if (checkKeyword(input))
        cout << input << " is a keyword\n";
    else
        cout << input << " is not a keyword\n";
}