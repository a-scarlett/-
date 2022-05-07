#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <deque>

using namespace std;

void f(string& s, string s1) {
    //find s1 in s
    int i = 0;
    int len = s1.size();
    int lens = s.size();
    while (s.find(s1, i) <= lens) {
        i = s.find(s1, i);
        s.insert(i, "(");
        s.insert(i + len + 1, ")");
        lens = lens + 2;
        if (s[lens - 1] == ')') return;
        i = i + len + 2;
    }
}

int main() {
    string s, s1;
    getline(cin, s);
    getline(cin, s1);
    f(s, s1);
    cout << s;
}