#include <iostream>
using namespace std;

class Item
{
public:
    char index;
    double weight;
    double price;
    double ppw; // price per weight

    Item()
    {
        index = 0;
        weight = 0;
        price = 0;
        ppw = 0;
    }

    void set(int i, double w, double p)
    {
        this->index = 65 + i;
        this->weight = w;
        this->price = p;
        this->ppw = p / w;
    }
};

template <typename T>
void swap(T *x, T *y)
{
    T temp = *x;
    *x = *y;
    *y = temp;
}

void sort(int n, Item *item)
{
    for (int x = 0; x < n - 1; x++)
        for (int y = x + 1; y < n; y++)
            if (item[x].ppw < item[y].ppw)
                swap(item + x, item + y);
}

int main()
{
    int n;
    double total_weight;
    cin >> n >> total_weight;
    Item *item = new Item[n];
    double weight, price;
    for (int x = 0; x < n; x++)
    {
        cin >> price >> weight;
        item[x].set(x, weight, price);
    }
    sort(n, item);
    price = 0;
    for (int x = 0; x < n; x++)
        if (total_weight != 0)
        {
            if (item[x].weight > total_weight)
            {
                price += item[x].ppw * total_weight;
                cout << "Item: " << item[x].index << ", weight: " << total_weight << ", total price: " << price << "\n";
                total_weight = 0;
            }
            else
            {
                price += item[x].price;
                cout << "Item: " << item[x].index << ", weight: " << item[x].weight << ", total price: " << price << "\n";
                total_weight -= item[x].weight;
            }
        }
    free(item);
}