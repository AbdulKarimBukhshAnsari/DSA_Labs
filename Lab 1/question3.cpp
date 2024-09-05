#include <iostream>
#include <iomanip>

using namespace std;

class MedianFinder {
private:
    int* data;
    int current_size;
    int current_capacity;

public:
    MedianFinder() {
        current_size = 0;
        current_capacity = 1;
        data = new int[current_capacity];
    }

    ~MedianFinder() {
        delete[] data;
    }

    void addnum(int num) {
        if (current_size == current_capacity) {
            int* temp = new int[current_capacity * 2];
            current_capacity *= 2;

            for (int i = 0; i < current_size; i++) {
                temp[i] = data[i];
            }

            delete[] data;
            data = temp;
        }

        int i = current_size - 1;
        while (i >= 0 && data[i] > num) {
            data[i + 1] = data[i];
            i--;
        }
        data[i + 1] = num;
        current_size++;
    }

    double findmedian() {
        if (current_size % 2 == 0) {
            return (data[current_size / 2 - 1] + data[current_size / 2]) / 2.0;
        } else {
            return data[current_size / 2];
        }
    }
};

int main() {
    MedianFinder medianfinder;

    int num_operations;
    cout << "Enter the number of operations: ";
    cin >> num_operations;

    for (int i = 0; i < num_operations; ++i) {
        string operation;
        cout << "Enter operation (addnum/findmedian): ";
        cin >> operation;

        if (operation == "addnum") {
            int num;
            cout << "Enter number to add: ";
            cin >> num;
            medianfinder.addnum(num);
        } else if (operation == "findmedian") {
            cout << fixed << setprecision(1) << "Median: " << medianfinder.findmedian() << endl;
        } else {
            cerr << "Invalid operation" << endl;
        }
    }

    return 0;
}
