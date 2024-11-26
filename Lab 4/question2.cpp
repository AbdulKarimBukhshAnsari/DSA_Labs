#include <iostream>
#include <vector>
#include "Abdul_Karim_Lab4.cpp" 
using namespace std;
int max_toys(vector<int> &array, int k, int n)
{
    Abdul_Karim_Lab04 arr(array);
    arr.bubble_sort_custom(); 
    int i = 0;
    int result = 0;
    while (i < n && k >= array[i])
    {
        result++;
        k -= array[i];
        i++;
    }
    return result;
}

int main()
{
    int k, n;
    cout << "Enter the value of K: ";
    cin >> k;
    cout << "Enter the value of number of toys: ";
    cin >> n;
    vector<int> array(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }
    int res = max_toys(array, k, n);
    cout << "The Maximum toys which can be bought is: " << res << endl;
    return 0;
}
