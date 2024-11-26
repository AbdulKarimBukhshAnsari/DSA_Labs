#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int findLHS(vector<int>& nums) {
    unordered_map<int, int> frequency;
    int maxLength = 0;
    for (int num : nums) {
        frequency[num]++;
    }
    for (const auto& pair : frequency) {
        int num = pair.first;
        if (frequency.count(num + 1)) {
            maxLength = max(maxLength, pair.second + frequency[num + 1]);
        }
    }
    return maxLength;
}
int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter the elements of the array:\n";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    int result = findLHS(nums);
    cout << "Length of the longest harmonious subsequence: " << result << endl;
    return 0;
}
