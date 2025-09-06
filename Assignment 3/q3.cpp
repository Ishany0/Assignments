#include <iostream>
#include <string>
using namespace std;

const int MAX = 1000;
char st[MAX];
int topIdx = -1;

bool isEmpty() { return topIdx == -1; }
bool isFull()  { return topIdx == MAX - 1; }

void push(char c) {
    if (!isFull()) st[++topIdx] = c;

}

char popc() {
    if (isEmpty()) return '\0'; 
    return st[topIdx--];
}

char topc() {
    if (isEmpty()) return '\0';
    return st[topIdx];
}
bool match(char open, char close) {
    return (open=='(' && close==')') ||
           (open=='{' && close=='}') ||
           (open=='[' && close==']');
}

int main() {
    cout << "Enter an expression: ";
    string s;
    getline(cin, s);   

    for (char c : s) {

        if (c=='(' || c=='{' || c=='[') {
            push(c);
        }
        
        else if (c==')' || c=='}' || c==']') {
            char t = popc();
            if (!match(t, c)) {          
                cout << "Not Balanced\n";
                return 0;
            }
        }

    }
    if (isEmpty()) cout << "Balanced\n";
    else           cout << "Not Balanced\n";

    return 0;
}
