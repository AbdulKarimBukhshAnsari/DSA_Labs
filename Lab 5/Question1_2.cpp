#include <iostream>
#include <vector>
#include <stack>
#include <utility>
#include <algorithm>
using namespace std;
class Abdul_Karim_Lab5 {
public:
    void quickSort(vector<int>& arr) {
        stack<pair<int, int>> stack;
        stack.push({0, arr.size() - 1});

        while (!stack.empty()) {
            int left = stack.top().first;
            int right = stack.top().second;
            stack.pop();

            if (left >= right) continue;

            int pivot = partition(arr, left, right);

            stack.push({left, pivot - 1});
            stack.push({pivot + 1, right});
        }
    }
    void mergeSort(vector<int>& arr) {
        int n = arr.size();
        for (int curr_size = 1; curr_size <= n - 1; curr_size *= 2) {
            for (int left_start = 0; left_start < n - 1; left_start += 2 * curr_size) {
                int mid = min(left_start + curr_size - 1, n - 1);
                int right_end = min(left_start + 2 * curr_size - 1, n - 1);
                merge(arr, left_start, mid, right_end);
            }
        }
    }

private:
    int partition(vector<int>& arr, int low, int high) {
        int pivot = arr[high];
        int i = low - 1;
        for (int j = low; j < high; ++j) {
            if (arr[j] < pivot) {
                ++i;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
        return i + 1;
    }

    void merge(vector<int>& arr, int left, int mid, int right) {
        int n1 = mid - left + 1;
        int n2 = right - mid;

        vector<int> L(n1), R(n2);

        for (int i = 0; i < n1; i++)
            L[i] = arr[left + i];
        for (int i = 0; i < n2; i++)
            R[i] = arr[mid + 1 + i];

        int i = 0, j = 0, k = left;
        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                arr[k++] = L[i++];
            } else {
                arr[k++] = R[j++];
            }
        }

        while (i < n1) arr[k++] = L[i++];
        while (j < n2) arr[k++] = R[j++];
    }
};

int main() {
    int size;
    cout << "Enter the size of the array for Quick Sort: ";
    cin >> size;
    vector<int> arr1(size);  
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < size; i++) {
        cin >> arr1[i];
    }

    Abdul_Karim_Lab5 sorter;
    sorter.quickSort(arr1);
    cout << "Quick Sorted: ";
    for (int num : arr1) {
        cout << num << " ";
    }
    cout << endl;
    // Merge Sort
    cout << "Enter the size of the array for Merge Sort: ";
    cin >> size;
    vector<int> arr2(size);  
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < size; i++) {
        cin >> arr2[i];
    }
    sorter.mergeSort(arr2);
    cout << "Merge Sorted: ";
    for (int num : arr2) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
