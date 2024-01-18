#include <iostream>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    float a, b, c, delta, x1, x2;

    cout << "Digite os coeficientes a, b, c na respectiva ordem:" << endl;
    cin >> a >> b >> c;

    delta = (b*b) - (4*a*c);

    x1 = (-b + sqrt(delta)) / (2*a);
    x2 = (-b - sqrt(delta)) / (2*a);

    cout << "As raizes sao: " << x1 << " " << x2 << endl;

    return 0;
}