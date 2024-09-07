// 21BDS0340 Abhinav Dinesh Srivatsa

#include <iostream>
#include <string.h>
using namespace std;

class Coach
{
    char coachNumber[3];
    char coachClass[20];
    bool ac;
    int capacity;

    void getCoach()
    {
        char isAC[6];
        cin >> this->coachNumber >> this->coachClass >> isAC >> this->capacity;
        if (strcmp(isAC, "True"))
            this->ac = true;
        else
            this->ac = false;
    }

    void printCoachInfo()
    {
        char isAC[4];
        if (this->ac)
            strcpy(isAC, "");
        else
            strcpy(isAC, "Not");
        cout << this->coachNumber << "\n" << this->coachClass << "\n" << isAC << " AC\n" << this->capacity << "\n";
    }

    friend class Train;
};

class Train
{
    int trainNumber;
    Coach coaches[10];

public:
    static int NumberOfCoaches;

    void getTrain()
    {
        cin >> this->trainNumber;
    }

    void printTrainInfo()
    {
        cout << this->trainNumber << "\n" << NumberOfCoaches << "\n";
    }

    void addCoach()
    {
        coaches[NumberOfCoaches].getCoach();
        NumberOfCoaches++;
    }

    int getCapacity()
    {
        int capacity = 0;
        for (int x = 0; x < NumberOfCoaches; x++)
            capacity += this->coaches[x].capacity;
        return capacity;
    }
};

int Train::NumberOfCoaches = 0;

int main()
{
    Train t;
    t.getTrain();
    t.addCoach();
    t.addCoach();
    cout << t.NumberOfCoaches << "\n"
         << t.getCapacity();
}