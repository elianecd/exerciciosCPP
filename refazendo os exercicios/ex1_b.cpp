/* O programa recebe do usuario os 3 lados de um triangulo e calcula
a area e o perimetro do mesmo. */

#include <iostream>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    double a, b, c;
    double s, perimetro, area_parte1, area_parte2;

    cout << "Digite os lados de um triangulo: " << endl;
    cin >> a >> b >> c;

    s = (a + b + c); 
    perimetro = s / 2; //calculando a metade do perimetro

    //usamos a formula de heron
    area_parte1 = s*(s-a)*(s-b)*(s-c);
    area_parte2 = sqrt (area_parte1);

    cout << "A area do triangulo eh: " << area_parte2 << endl;
    cout << "E o perimetro eh: " << perimetro << endl;

    return 0;
}