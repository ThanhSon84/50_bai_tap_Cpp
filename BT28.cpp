// BT28.cpp
#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // for std::swap

using namespace std;

// Function to find and print the next permutation in reverse lexicographical order
void hoanvi(vector<int>& v) {
    int N = v.size();
    bool swapped = false;

    for (int i = N - 2; i >= 0 && !swapped; --i) {
        for (int j = i + 1; j < N; ++j) {
            if (v[i] > v[j]) {
                swap(v[i], v[j]);
                swapped = true;
                break;
            }
        }
    }

    if (swapped) {
        for (int num : v) {
            cout << num;
        }
        cout << endl;
    } else {
        cout << -1 << endl;
    }
}

int main() {
    int testCases;
    cin >> testCases;
    cin.ignore(); // Ignore the newline after reading testCases

    while (testCases--) {
        string input;
        getline(cin, input);

        // Convert string input into a vector of integers
        vector<int> v;
        for (char ch : input) {
            v.push_back(ch - '0');
        }

        hoanvi(v);
    }

    return 0;
}
