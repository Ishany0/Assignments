#include <iostream>
#include <queue>
#include <unordered_map>
#include <sstream>
using namespace std;

int main() {
    string line;
    getline(cin, line);
    stringstream ss(line);
    string ch;
    queue<char> q;
    unordered_map<char, int> freq;

    while (ss >> ch) {
        char c = ch[0];
        freq[c]++;
        q.push(c);

        while (!q.empty() && freq[q.front()] > 1) {
            q.pop();
        }

        if (!q.empty())
            cout << q.front() << " ";
        else
            cout << "-1 ";
    }
    cout << endl;
    return 0;
}
