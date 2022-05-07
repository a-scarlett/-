#include <iostream>
#include <cmath>
#include <string>
#include <list>
#include <algorithm>

using namespace std;

class Polynomial {
public:
    int deg;
    double* arr_coef = new double[deg + 1];
public:
    Polynomial() : deg(0), arr_coef(new double[1]) {
        arr_coef[0] = 0;
    }

    Polynomial(int d) : deg(d) {
        arr_coef = new double[d + 1];
        fill(arr_coef, arr_coef + d + 1, 0);
    }

    Polynomial(double x) : deg(0), arr_coef(new double[1]) {
        arr_coef[0] = x;
    }

    Polynomial(Polynomial&& x) : deg(x.deg), arr_coef(x.arr_coef)//конструктор перемещения return move(y);
    {
        x.deg = 0;
        x.arr_coef = nullptr;
    }

    Polynomial(int d, double* c) : deg(d), arr_coef(c) {}

    Polynomial(const initializer_list<double>& t) : deg(t.size() - 1), arr_coef(new double[t.size()]) {
        copy(t.begin(), t.end(), arr_coef);
    }//конструктор инициализации

    Polynomial(const Polynomial& x)//constructor copy
    {
        deg = x.deg;
        arr_coef = new double[deg + 1];
        for (int i = 0; i < deg + 1; i++)
            arr_coef[i] = x.arr_coef[i];

    }

    double coef(int i) {
        if (deg < i) exit(EXIT_FAILURE);
        return arr_coef[i];
    };

    double value(double t) {
        double res = 0;
        for (int i = deg; i >= 0; i--) {
            res += pow(t, i) * arr_coef[i];
        }
        return res;
    }

    double operator()(double t) const {
        double res = 0;
        for (int i = deg; i >= 0; i--) {
            res += pow(t, i) * arr_coef[i];
        }
        return res;

    }

    Polynomial& operator = (const Polynomial& y) {
        if (this == &y)
            return *this;
        delete[] arr_coef;
        deg = y.deg;
        arr_coef = new double[deg + 1];
        for (int i = 0; i < deg + 1; i++) {
            arr_coef[i] = y.arr_coef[i];
        }
        return *this;
    }

    Polynomial& operator = (Polynomial&& y) {//перемещающая операция присваивания x=move(y);
        if (this == &y)
            return *this;
        delete[] arr_coef;
        swap(arr_coef, y.arr_coef);
        return *this;
    }

    double& operator [] (int i) {
        static double c = -1;
        if (i >= 0 && i < deg + 1) {
            return arr_coef[i];
        }
        else {
            cerr << " Deg of polynomial is lower" << endl;
            return c;
        }
    };
    ~Polynomial() {
        delete[] arr_coef;
    }
    friend Polynomial& operator* (Polynomial& p1, Polynomial& p2);

    friend Polynomial& operator*(Polynomial& p1, double val);

    friend Polynomial& operator+(Polynomial& p1, Polynomial& p2);

    friend Polynomial& operator-(Polynomial& p1, Polynomial& p2);

    friend Polynomial& operator/(Polynomial& p1, Polynomial& p2);

    friend Polynomial& operator%(Polynomial& p1, Polynomial& p2);
};
Polynomial& operator+(Polynomial& p1, Polynomial& p2){
    Polynomial* result = new Polynomial(max(p1.deg, p2.deg));
    for (int n = 0; n <= (*result).deg; ++n) {
        if (n <= p1.deg) (*result).arr_coef[n] += p1.arr_coef[n];
        if (n <= p2.deg) (*result).arr_coef[n] += p2.arr_coef[n];
    }
    return *result;
}
Polynomial& operator-(Polynomial& p1, Polynomial& p2) {
    return p1 + p2 * -1.0;
}
Polynomial& operator*(Polynomial& p1, Polynomial& p2) {
    Polynomial* result = new Polynomial(p1.deg + p2.deg);
    for (int n = 0; n <= (*result).deg; ++n) {
        int i = max(0, n - p2.deg), j = n - i;
        while (i <= p1.deg && j >= 0) {
            (*result).arr_coef[n] += p1.arr_coef[i] * p2.arr_coef[j];
            i++, j--;
        }
    }
    return *result;
}
Polynomial& operator*(Polynomial& p1, double val) {
    Polynomial* result = new Polynomial(p1.deg);
    for (int n = 0; n <= result->deg; ++n) {
        (*result).arr_coef[n] = p1.arr_coef[n] * val;
    }
    return *result;
}
Polynomial& operator/(Polynomial& p1, Polynomial& p2) {
    if (p1.deg < p2.deg)
        return *(new Polynomial(0));
    int deg = p1.deg;
    Polynomial* result = new Polynomial(p1.deg - p2.deg);
    Polynomial curr = p1;
    while (deg >= p2.deg) {
        if (curr.arr_coef[deg] == 0) {
            deg--;
            continue;
        }
        double coeff = curr.arr_coef[deg] / p2.arr_coef[p2.deg];
        (*result).arr_coef[deg - p2.deg] = coeff;
        Polynomial* multiplier = new Polynomial(deg - p2.deg);
        (*multiplier).arr_coef[deg - p2.deg] = coeff;
        curr = curr - (p2 * (*multiplier));
        deg--;
    }
    return *result;
}
Polynomial& operator % (Polynomial& p1, Polynomial& p2) {
    Polynomial divider = p1 / p2;
    Polynomial* result = new Polynomial(0);
    result = &(p1 - divider * p2);
    int cur_deg = 0;
    for (int i = (*result).deg; i >= 0; i--) {
        if ((*result).arr_coef[i] != 0) {
            cur_deg = i;
            break;
        }
    }
    (*result).deg = cur_deg;
    return *result;
}

int main() {
    Polynomial x{ 2.0, 3.0, 4.0 };
    Polynomial y{ 2.0, 3.0, 4.0, 5.0 };
 
    cout << x(0);
}