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

bool checkReal(string ch)
{
    if (ch == "")
        return false;
    if (ch[0] == '.')
        return false;
    for (int x = 0; x < ch.length(); x++)
        if (!(48 <= ch[x] && ch[x] <= 57))
            return false;
    return true;
}

bool checkOperator(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '=' ||
        ch == '>' || ch == '<' || ch == '!' || ch == '|' || ch == '&')
        return true;
    return false;
}

bool checkSpecial(char ch)
{
    if (ch == ',' || ch == ';' || ch == '(' || ch == ')' ||
        ch == '{' || ch == '}' || ch == '[' || ch == ']' ||
        ch == ' ' || ch == '\n')
        return true;
    return false;
}

int main()
{
    string code = "if (a == b) c = a;";

    string str = "";
    for (int x = 0; x < code.length(); x++)
    {
        char c = code[x];
        if (checkOperator(c))
        {
            if (checkReal(str))
            {
                str = "";
                continue;
            }
            if (checkKeyword(str))
            {
                str = "";
                continue;
            }
            if (!(str == ""))
                cout << str << " is an identifier\n";
            str = "";
            continue;
        }
        if (checkSpecial(c))
        {
            if (!(c == ' ' || c == '\n'))
                if (checkReal(str))
                {
                    str = "";
                    continue;
                }
            if (checkKeyword(str))
            {
                str = "";
                continue;
            }
            if (!(str == ""))
                cout << str << " is an identifier\n";
            str = "";
            continue;
        }
        str.push_back(c);
    }
}