#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

template <typename T>
void enlarge (vector<T>& v)
{
    typename std::vector <T>::iterator i;
    for (i = v.begin(); (i+1) != v.end(); i++) {
        i = v.insert(i + 1, (*i + *(i + 1)) / 2);
    }
}

template <typename T>
void del(vector<T>& v)
{
    typename std::vector <T>::iterator i;
    for (i = v.begin(); i != v.end(); i++) {
        i = v.erase(i);
        if (i == v.end()) break;
    }
}

template <typename T>
vector <T> concat(vector <T> &v1, vector <T> &v2) 
{
        vector <T> v(v1.size() + v2.size());
        copy(v1.begin(), v1.end(), v.begin());
        copy(v2.begin(), v2.end(), v.begin() + v1.size());
        return v;
}

template <typename T>
vector <T> repeat(vector <T> v1, int n) {
        vector <T> v(v1.size() * n);
        for (int i = 0; i < n; i++) {
            copy(v1.begin(), v1.end(), v.begin() + i * v1.size());
        }
        return v;
    }

template <typename T>
vector <T>::iterator second_occure(vector <T> &v, int n) {
    typename std::vector <T>::iterator it = find(v.begin(), v.end(), n);
    if (it != v.end()) {
        return find(it + 1, v.end(), n);
    }
    else return v.end();
    }

template <typename T>
vector <T>::iterator last_occure(vector <T> &v, int n) {
    auto curr = v.begin();
    auto prev = v.begin();
    while (curr != v.end()) {
        prev = curr;
        curr = find(curr + 1, v.end(), n);
    }
    return prev;
}

template <typename T>
bool subseq(vector <T> &v, vector <T> &subv) {
    typename std::vector <T>::iterator curr = v.begin();
    for (auto i = 0; i < subv.size(); i++) {
        curr = find(curr + 1, v.end(), subv[i]);
        if (curr == v.end()) break;
    }
    if (curr == v.end()) return 0;
    else return 1;
    }

int f1(vector <int>& v, int x) {
    auto k = upper_bound(v.begin(), v.end(), x);
    if (k != v.end() && find(v.begin(),v.end(), x)!=v.end() ) 
    {
        return k - v.begin() - 1;
        }
    else return -1;
}

void f2(vector <double>& v, double x, int& i, int& j) {
    if (find(v.begin(),v.end(),x) != v.end() ) {
        i = lower_bound(v.begin(), v.end(), x) - v.begin();
        j = upper_bound(v.begin(), v.end(), x) - v.begin()-1;
        return;
    }
    j = lower_bound(v.begin(), v.end(), x) - v.begin();
    if (j == 0) {
        i = j;
        return;
    }
    i = j - 1;
}

int main() {
    vector <double> v1 = { 1, 3, 5 }, v2 = { 1, 2, 3, 4, 5 }, v;
    cout <<"enlarge v1= " << endl;
    enlarge(v1);
    for (auto i = v1.begin(); i != v1.end(); i++) {
        cout << *i<<" ";
    }
    cout << endl;
    cout << "del v2= " << endl;
    del(v2);
    for (auto i = v2.begin(); i != v2.end(); i++) {
        cout << *i << " ";
    }
    cout << endl;
    cout << "concat v1 and v2= " << endl;
    v = concat(v1, v2);
    for (auto i = v.begin(); i != v.end(); i++) {
        cout << *i << " ";
    }
    cout << endl;
    cout << "repeat" << endl;
    v = repeat(v, 2);
    for (auto i = v.begin(); i != v.end(); i++) {
        cout << *i << " ";
    }
    cout << endl;
    cout << "until second_occure 1" << endl;
    for (auto i = v.begin(); i != second_occure(v, 1); i++) {
        cout << *i << " ";
    }
    cout << endl;
    cout << "until last_occure 1" << endl;
    for (auto i = v.begin(); i != last_occure(v, 1); i++) {
        cout << *i << " ";
    }
    cout << endl;
    cout << "subseq v1 in v: "<< subseq(v,v1) << endl;

    vector <int> k = { 1, 2, 3, 3, 4, 5 };
    cout <<"f1 "<< f1(k, 3) << endl;
    vector <double> g = { 1, 2, 3, 3, 4, 5 };
    int i=0, j=0;
    f2(g, 3.5, i, j);
    cout <<i<< " " << j << endl;

    int a[6];
    copy(k.begin(), k.end(), a);
    for (int w = 0; w < 6; w++) {
        cout << a[w];
    }
}