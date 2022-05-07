#include <iostream>
#include <string>

using namespace std;

bool isIP(string& s) {
    int num = 0;
    string rec;
    bool exit = 0;
    for (char& x : s) {
        if (x >= '0' and x <= '9') {
            rec += x;
        }
        else if (x == '.') {
            if (rec.empty()) return 0;
            (stoi(rec) >= 0 && stoi(rec) <= 255 ? num++ : exit = 1);
            rec.clear();
            if (exit == 1) return 0;
        }
        else return 0;
        if (num > 4) return 0;
    }
    if (rec.empty()) return 0;
    (stoi(rec) >= 0 && stoi(rec) <= 255 ? num++ : exit = 1);
    if (exit == 1) return 0;
    if (num != 4) return 0;
    return 1;
}
int main() {
    string s;
    getline(cin, s);
    cout << isIP(s);
}