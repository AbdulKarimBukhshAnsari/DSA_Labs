// MergeIntervals.cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>> mergeIntervals(vector<vector<int>>& intervals) {
    if (intervals.empty()) return {};
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> merged;
    for (const auto& interval : intervals) {
        if (merged.empty() || merged.back()[1] < interval[0]) {
            merged.push_back(interval);
        } else {
            merged.back()[1] = max(merged.back()[1], interval[1]);
        }
    }
    return merged;
}
int main() {
    int n;
    cout << "Enter the number of intervals: ";
    cin >> n;
    vector<vector<int>> intervals(n, vector<int>(2)); 
    cout << "Enter the intervals (start and end values):\n";
    for (int i = 0; i < n; ++i) {
        cin >> intervals[i][0] >> intervals[i][1];  
    }
    vector<vector<int>> result = mergeIntervals(intervals);

    cout << "Merged intervals: ";
    for (const auto& interval : result) {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    cout << endl;
    return 0;
}
