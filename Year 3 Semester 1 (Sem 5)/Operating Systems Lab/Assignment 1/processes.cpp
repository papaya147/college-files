#include <iostream>
#include <cstdlib>
#include <time.h>
#include <stdbool.h>
using namespace std;

int getRandomId()
{
    srand(time(0));
    return rand() % 10000;
}

class Process
{
public:
    int id;
    Process *parent;
    bool sleeping;

    Process()
    {
        this->id = 0;
        this->parent = NULL;
        this->sleeping = false;
    }

    Process(int id)
    {
        this->id = id;
        this->parent = NULL;
        this->sleeping = false;
    }

    Process(int id, Process *parent)
    {
        this->id = id;
        this->parent = parent;
        this->sleeping = false;
    }
};

Process *createProcess()
{
    return new Process(getRandomId());
}

Process *fork(Process *parent)
{
    return new Process(getRandomId(), parent);
}

void remove(Process *process)
{
    free(process);
}

int main()
{
    int size = 50;
    Process *processes[size];

    int choice = 0;
    int i = 0;
    int parentId;
    bool flag = true;
    int id;
    while (flag)
    {
        cout << "Enter 1 to create process without parent\n";
        cout << "Enter 2 to create child process\n";
        cout << "Enter 3 to remove process and all children\n";
        cout << "Enter 4 to create zombie process\n";
        cout << "Enter 5 to display processes\n";
        cout << "Enter anything else to exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            processes[i++] = createProcess();
            break;

        case 2:
            cout << "Parent ID: ";
            cin >> parentId;
            Process *p;
            for (int x = 0; x < i; x++)
                if (processes[x]->id == parentId)
                    p = processes[x];
            processes[i++] = fork(p);
            break;

        case 3:
            cin >> parentId;
            for (int x = i - 1; x >= 0; x--)
                if (processes[x]->id == parentId || processes[x]->parent->id == parentId)
                {
                    remove(processes[x]);
                    processes[x] = new Process();
                }
            break;

        case 4:
            cin >> id;
            for (int x = 0; x < i; x++)
                if (processes[x]->id == id)
                    processes[x]->sleeping = true;
            break;

        case 5:
            for (int x = 0; x < i; x++)
            {
                if (processes[x]->id != 0)
                    cout << "My process ID is " << processes[x]->id;
                if (processes[x]->parent != NULL)
                    cout << " and my parent's ID is " << processes[x]->parent->id;
                if (processes[x]->sleeping)
                    cout << ", I am a zombie process";
                cout << "\n";
            }
            break;

        default:
            flag = false;
            break;
        }
        cout << "\n";
    }
}