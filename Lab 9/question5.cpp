#include <iostream>
#include <string>
using namespace std;

class BrowserHistory {
    struct Node {
        string url;
        Node* prev;
        Node* next;
        Node(string u) : url(u), prev(nullptr), next(nullptr) {}
    };

    Node* current;

public:
    BrowserHistory(string homepage) {
        current = new Node(homepage);
    }

    void visit(string url) {
        Node* newNode = new Node(url);
        current->next = newNode;
        newNode->prev = current;
        current = newNode;
    }

    string back(int steps) {
        while (steps > 0 && current->prev != nullptr) {
            current = current->prev;
            steps--;
        }
        return current->url;
    }

    string forward(int steps) {
        while (steps > 0 && current->next != nullptr) {
            current = current->next;
            steps--;
        }
        return current->url;
    }
};

int main() {
    BrowserHistory* browserHistory = new BrowserHistory("leetcode.com");
    browserHistory->visit("google.com");
    browserHistory->visit("facebook.com");
    browserHistory->visit("youtube.com");
    cout << browserHistory->back(1) << endl;      // facebook.com
    cout << browserHistory->back(1) << endl;      // google.com
    cout << browserHistory->forward(1) << endl;   // facebook.com
    browserHistory->visit("linkedin.com");
    cout << browserHistory->forward(2) << endl;   // linkedin.com
    cout << browserHistory->back(2) << endl;      // google.com
    cout << browserHistory->back(7) << endl;      // leetcode.com
    return 0;
}
