// 21BDS0340 Abhinav Dinesh Srivatsa

#include <iostream>
#include <string.h>
using namespace std;

class Job
{
    int id;
    char name;
    int time, space;

public:
    void readData()
    {
        cin >> id >> name >> time >> space;
    }

    int getTime()
    {
        return time;
    }

    int getSpace()
    {
        return space;
    }

    int getId()
    {
        return id;
    }
};

class OS
{
public:
    void sortTime(int n, Job *j)
    {
        Job temp;
        for (int x = 0; x < n; x++)
            for (int y = x + 1; y < n; y++)
                if (j[x].getTime() > j[y].getTime())
                {
                    temp = j[x];
                    j[x] = j[y];
                    j[y] = temp;
                }
    }

    void sortSpace(int n, Job *j)
    {
        Job temp;
        for (int x = 0; x < n; x++)
            for (int y = x + 1; y < n; y++)
                if (j[x].getSpace() > j[y].getSpace())
                {
                    temp = j[x];
                    j[x] = j[y];
                    j[y] = temp;
                }
    }
};

int main()
{
    int n;
    char sort_type[10];
    cin >> n >> sort_type;
    Job j[n];
    for (int x = 0; x < n; x++)
        j[x].readData();
    OS OS1_X;
    if (strcmp(sort_type, "Time") == 0)
        OS1_X.sortTime(n, j);
    else if (strcmp(sort_type, "Space") == 0)
        OS1_X.sortSpace(n, j);
    for (int x = 0; x < n; x++)
        cout << j[x].getId() << "\n";
}