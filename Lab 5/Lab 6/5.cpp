#include <iostream>
#include <vector>

using namespace std;

bool canCompleteTrips(vector<vector<int>>& trips, int capacity) {
    vector<int> change(1001, 0);

    for (const auto& trip : trips) {
        int numPassengers = trip[0];
        int from = trip[1];
        int to = trip[2];
        change[from] += numPassengers;
        change[to] -= numPassengers;
    }

    int currentPassengers = 0;
    for (int i = 0; i <= 1000; ++i) {
        currentPassengers += change[i];
        if (currentPassengers > capacity) {
            return false; 
        }
    }
    return true; 
}

int main() {
    int numTrips, capacity;   
    cout << "Enter the number of trips: ";
    cin >> numTrips;
    vector<vector<int>> trips(numTrips, vector<int>(3));
    cout << "Enter the trips (numPassengers, from, to):\n";
    for (int i = 0; i < numTrips; ++i) {
        cin >> trips[i][0] >> trips[i][1] >> trips[i][2];
    }
    cout << "Enter the capacity of the car: ";
    cin >> capacity;
    if (canCompleteTrips(trips, capacity)) {
        cout << "True: It is possible to complete all trips." << endl;
    } else {
        cout << "False: It is not possible to complete all trips." << endl;
    }
    return 0;
}
