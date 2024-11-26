#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void flip(vector<int>& arr, int k) {
    reverse(arr.begin(), arr.begin() + k);
}
vector<int> pancakeSort(vector<int>& arr) {
    vector<int> flips;
    int n = arr.size();
    for (int curr_size = n; curr_size > 1; --curr_size) {
        int max_index = max_element(arr.begin(), arr.begin() + curr_size) - arr.begin();


        if (max_index != curr_size - 1) {
            if (max_index > 0) {
                flip(arr, max_index + 1);
                flips.push_back(max_index + 1);
            }
            flip(arr, curr_size);
            flips.push_back(curr_size);
        }
    }
    return flips;
}

int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;
    vector<int> arr(size);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
    vector<int> result = pancakeSort(arr);
    cout << "Sorted array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << "\nSequence of flips: ";
    for (int flip : result) {
        cout << flip << " ";
    }
    cout << endl;
    return 0;
}
