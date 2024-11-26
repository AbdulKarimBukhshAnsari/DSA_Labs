#include <iostream>
#include <vector>
#include <string>
#include <algorithm>   
using namespace std;
class Sort {
public:
    void bubble_sort(vector<int>& arr, int &comparisons, int &swaps) {
        int n = arr.size();
        comparisons = 0;
        swaps = 0;
        for (int i = 0; i < n - 1; i++) {
            bool swapped = false;
            for (int j = 0; j < n - i - 1; j++) {
                comparisons++;
                if (arr[j] > arr[j + 1]) {
                    swap(arr[j], arr[j + 1]);
                    swaps++;
                    swapped = true;
                }
            }
            if (!swapped) break;
        }
    }
    void insertion_sort(vector<int>& arr, int &comparisons, int &swaps) {
        int n = arr.size();
        comparisons = 0;
        swaps = 0;  // No actual swaps in insertion sort
        for (int i = 1; i < n; i++) {
            int key = arr[i];
            int j = i - 1;

            comparisons++;
            while (j >= 0 && arr[j] > key) {
                comparisons++;
                arr[j + 1] = arr[j];  // Shift the element
                j--;
            }
            arr[j + 1] = key;  
        }
    }
    void selection_sort(vector<int>& arr, int &comparisons, int &swaps) {
        int n = arr.size();
        comparisons = 0;
        swaps = 0;
        for (int i = 0; i < n - 1; i++) {
            int min_index = i;
            for (int j = i + 1; j < n; j++) {
                comparisons++;
                if (arr[j] < arr[min_index]) {
                    min_index = j;
                }
            }
            if (min_index != i) {
                swap(arr[i], arr[min_index]);
                swaps++;
            }
        }
    }

    // Function to choose the sorting technique based on user input
    void sort_array(vector<int>& arr, const string& technique, int &comparisons, int &swaps) {
        if (technique == "bubble") {
            bubble_sort(arr, comparisons, swaps);
        } else if (technique == "insertion") {
            insertion_sort(arr, comparisons, swaps);
        } else if (technique == "selection") {
            selection_sort(arr, comparisons, swaps);
        } else {
            cout << "Invalid sorting technique chosen!" << endl;
        }
    }

    // Generate a random unique array
    vector<int> generate_random_array(int size, int min_val, int max_val) {
        vector<int> arr;
        for (int i = min_val; i <= max_val; i++) {
            arr.push_back(i);
        }
        random_shuffle(arr.begin(), arr.end());
        arr.resize(size);  // Resize the array to the required size
        return arr;
    }
};

int main() {
    Sort sorter;
    int size, min_val, max_val;
    cout << "Enter the size of the array: ";
    cin >> size;
    cout << "Enter the minimum value of the range: ";
    cin >> min_val;
    cout << "Enter the maximum value of the range: ";
    cin >> max_val;
    vector<int> random_array = sorter.generate_random_array(size, min_val, max_val);

    // Perform sorting using all techniques and store results
    vector<string> techniques = { "bubble", "insertion", "selection" };
    vector<int> comparisons(3), swaps(3);
    vector<vector<int>> sorted_arrays(3, random_array);  
    for (int i = 0; i < 3; i++) {
        sorted_arrays[i] = random_array; 
        sorter.sort_array(sorted_arrays[i], techniques[i], comparisons[i], swaps[i]);
    }
    cout << "\nSorting Analysis:\n";
    for (int i = 0; i < 3; i++) {
        cout << techniques[i] << " sort -> Comparisons: " << comparisons[i]
             << ", Swaps: " << swaps[i] << endl;
    }
    int min_comp = min_element(comparisons.begin(), comparisons.end()) - comparisons.begin();
    int max_comp = max_element(comparisons.begin(), comparisons.end()) - comparisons.begin();
    cout << "\nBest technique (minimum comparisons): " << techniques[min_comp] << endl;
    cout << "Worst technique (maximum comparisons): " << techniques[max_comp] << endl;

    return 0;
}
