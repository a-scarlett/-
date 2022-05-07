#include <iostream>
#include <cmath>
using namespace std;

struct subspace {
    int dim;
    double x1, y1, z1;
    //если dim==1, то храним направляющий вектор
    //если dim==2, то храним перпендикуляр
};

subspace operator*(subspace a, subspace b) {
    if (a.dim == 0 || b.dim == 0) return { 0, 0, 0,0 };
    if (a.dim == 1 && b.dim == 1) {
        if (a.x1 * b.y1 == b.x1 * a.y1) return a;
        else return { 0,0,0,0 };
    }
    if (a.dim == 1 && b.dim == 2) {
        if (a.x1 * b.x1 + a.y1 * b.y1 + a.z1 * b.z1 < pow(10, -5)) return a;
        else return { 0,0,0,0 };
    }
    if (a.dim == 2 && b.dim == 1) return b * a;

    if (a.dim == 2 && b.dim == 2) {
        if (a.x1 * b.x1 + a.y1 * b.y1 + a.z1 * b.z1 < pow(10, -5)) return a;
        else return { 1, a.y1 * b.z1 - a.z1 * b.y1, a.x1 * b.z1 - a.z1 * b.x1, a.x1 * b.y1 - a.y1 * b.x1 };
    }
    if (a.dim == 3) return b;
    if (b.dim == 3) return a;
    exit(EXIT_FAILURE);
}

subspace operator-(subspace a) {
    if (a.dim == 0) return { 3, 0, 0 ,0 };
    if (a.dim == 1) return { 2, a.x1, a.y1, a.z1 };
    if (a.dim == 2) return { 1, a.x1, a.y1, a.z1 };
    if (a.dim == 3) return { 0, 0, 0, 0 };
    exit(EXIT_FAILURE);
}

subspace operator+ (subspace a, subspace b) {
    return -(-a * -b);
}


int main() {
    int n;
    double x, y, z;
    cout << "Enter dim1 and vector1 (guide or normal): " << endl;
    cin >> n >> x >> y >> z;
    subspace a = { n, x, y, z };
    cout << "Enter dim2 and vector2 (guide or normal): " << endl;
    cin >> n >> x >> y >> z;
    subspace b = { n, x, y, z };
    cout << "a*b = " << (a * b).dim <<" "<< (a * b).x1 << " " << (a * b).y1 << " " << (a * b).z1 << endl;
    cout << "a+b = " << (a + b).dim << " " << (a + b).x1 << " " << (a + b).y1 << " " << (a + b).z1 << endl;
    return 0;
}