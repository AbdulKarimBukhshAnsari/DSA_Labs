#include <iostream>
#include <list>
using namespace std;

int findWinner(int n, int k) {
    list<int> friends;
    for (int i = 1; i <= n; i++) {
        friends.push_back(i);
    }

    auto it = friends.begin();
    while (friends.size() > 1) {
        // Move k-1 steps clockwise
        for (int i = 1; i < k; i++) {
            it++;
            if (it == friends.end()) {
                it = friends.begin(); // Wrap around
            }
        }
        
        // Remove the friend pointed by 'it'
        it = friends.erase(it);
        if (it == friends.end()) {
            it = friends.begin(); // Wrap around after deletion
        }
    }

    return *friends.begin();
}

int main() {
    int n, k;
    cout << "Enter the number of friends (n): ";
    cin >> n;
    cout << "Enter the count number (k): ";
    cin >> k;

    int winner = findWinner(n, k);
    cout << "The winner is friend number: " << winner << endl;

    return 0;
}
