#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

void showVector(const vector<int>& values) {
    cout << "[ ";
    for (size_t i = 0; i < values.size(); ++i) {
        cout << values[i];
        if (i + 1 < values.size()) cout << " ";
    }
    cout << " ]\n";
}

void bubbleSortDemo() {
    int n;
    cout << "How many numbers (1-30)? ";
    if (!(cin >> n) || n < 1 || n > 30) {
        cout << "Invalid size.\n";
        cin.clear();
        cin.ignore(10000, '\n');
        return;
    }
    vector<int> a(static_cast<size_t>(n));
    cout << "Enter " << n << " integers: ";
    for (int& x : a) {
        if (!(cin >> x)) {
            cout << "Invalid input.\n";
            cin.clear();
            cin.ignore(10000, '\n');
            return;
        }
    }
    cout << "Initial array: ";
    showVector(a);
    for (int i = 0; i < n - 1; ++i) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; ++j) {
            cout << "Compare " << a[j] << " and " << a[j + 1] << ": ";
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
                swapped = true;
                cout << "swap -> ";
            } else {
                cout << "no swap -> ";
            }
            showVector(a);
        }
        if (!swapped) break;
    }
    cout << "Sorted array: ";
    showVector(a);
}

void stackDemo() {
    stack<int> values;
    cout << "Enter 3 integers to push: ";
    for (int i = 0; i < 3; ++i) {
        int x;
        if (!(cin >> x)) {
            cout << "Invalid input.\n";
            cin.clear();
            cin.ignore(10000, '\n');
            return;
        }
        values.push(x);
        cout << "Pushed " << x << "; stack size = " << values.size() << '\n';
    }
    cout << "Pop order (LIFO): ";
    while (!values.empty()) {
        cout << values.top() << ' ';
        values.pop();
    }
    cout << '\n';
}

void queueDemo() {
    queue<int> values;
    cout << "Enter 3 integers to enqueue: ";
    for (int i = 0; i < 3; ++i) {
        int x;
        if (!(cin >> x)) {
            cout << "Invalid input.\n";
            cin.clear();
            cin.ignore(10000, '\n');
            return;
        }
        values.push(x);
        cout << "Enqueued " << x << "; queue size = " << values.size() << '\n';
    }
    cout << "Dequeue order (FIFO): ";
    while (!values.empty()) {
        cout << values.front() << ' ';
        values.pop();
    }
    cout << '\n';
}

int main() {
    while (true) {
        cout << "\n=== DSA Visualizer ===\n"
             << "1. Bubble sort step-by-step\n"
             << "2. Stack (LIFO) demo\n"
             << "3. Queue (FIFO) demo\n"
             << "0. Exit\nChoose: ";
        int choice;
        if (!(cin >> choice)) {
            cout << "Invalid input. Exiting.\n";
            return 0;
        }
        switch (choice) {
            case 1: bubbleSortDemo(); break;
            case 2: stackDemo(); break;
            case 3: queueDemo(); break;
            case 0: cout << "Goodbye!\n"; return 0;
            default: cout << "Choose 0, 1, 2, or 3.\n";
        }
    }
}
