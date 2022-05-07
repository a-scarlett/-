#include <iostream>
#include<numeric>
using namespace std;

struct frac {
    int num, den;
    frac(int a, int b) :num(a), den(b)
    {
        if (gcd(a, b) != 0) {
            den = den / gcd(a, b);
            num = num / gcd(a, b);
            if (den < 0) {
                den = -1 * den;
                num = -1 * num;
            }
        }
        else
            num = 0;
            den = 1;
    }
};

frac operator+ (frac a, frac b) {
    int den = a.den * b.den;
    int num = a.den * b.num + b.den * a.num;
    return { num, den };
}

frac operator- (frac a, frac b) {
    b.num = -1 * b.num;
    return a + b;
}

frac operator*(frac a, frac b) {
    int num = a.num * b.num;
    int den = a.den * b.den;
    return { num, den };
}

frac operator/(frac a, frac b) {
    frac c = { b.den, b.num };
    return a*c;
}

bool operator==(frac a, frac b) {
    return a.den * b.num == b.den * a.num;
}

bool operator!=(frac a, frac b) {
    return !(a == b);
}

bool operator<(frac a, frac b) {
    return (a.den * b.num < b.den* a.num ? 1 : 0);
}

bool operator>=(frac a, frac b) {
    return !(a < b);
}
bool operator>(frac a, frac b) {
    return (a >= b) && (a != b);
}
bool operator <=(frac a, frac b) {
    return !(a > b);
}

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    frac x = { a, b };
    frac y = { c, d };
    cout <<"x==y? "<<(x==y) << endl;
    cout << "x<y? " << (x < y) << endl;
    cout << "x+y? " << (x + y).num << '/' << (x + y).den << endl;
    cout << "x*y? " << (x * y).num <<'/'<< (x * y).den << endl;
    return 0;
}