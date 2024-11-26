#include <iostream>
#include <vector>
using namespace std;

class Abdul_Karim_Lab04
{
public:
    vector<int> &v;
    int n;
    Abdul_Karim_Lab04(vector<int> &array) : v(array)
    {
        n = v.size();
    }

    void bubble_sort_custom()
    {
        bool check = false;
        for (int i = 0; i < n - 1; i++)
        {
            check = false;
            for (int j = 0; j < n - i - 1; j++)
            {
                if (v[j] > v[j + 1])
                {
                    swap(v[j], v[j + 1]);
                    check = true;
                }
            }
            if (!check)
                break;
        }
    }

    void insertion_sort_custom()
    {
        for (int i = 1; i < n; i++)
        {
            int j = i - 1;
            int temp = v[i];
            while (j >= 0 && temp < v[j])
            {
                v[j + 1] = v[j];
                j--;
            }
            v[j + 1] = temp;
        }
    }

    void selection_sort_custom()
    {
        for (int i = 0; i < n - 1; i++)
        {
            int min = i;
            for (int j = i + 1; j < n; j++)
            {
                if (v[min] > v[j])
                    min = j;
            }
            swap(v[min], v[i]);
        }
    }
};
