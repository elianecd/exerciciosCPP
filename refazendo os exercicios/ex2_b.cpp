/* O programa calculo o valor obtido entre 3 numeros tendo sempre q somar 2 numeros e multiplicar o resulto pelo
terceiro numero sobrando ou pode ser o processo inverso tbm de primeiro multiplicar 2 numeros e depois somar pelo
terceiro.
*/

#include <iostream>
//#include <cmath>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    int num1, num2, num3, hi;
    int sum, res;

    cout << "Digite 3 numeros: " << endl;
    cin >> num1 >> num2 >> num3;
    
    if (num1 > num2 && num1 > num3)
    {
        hi = num1;
        sum = num2 + num3;
        res = sum * hi;
    }     
    if (num2 > num1 && num2 > num3)
    {   
        hi = num2;
        sum = num1 + num3;
        res = sum * hi;
    }
    if (num3 > num1 && num3 > num2)
    {
        hi = num3;
        sum = num1 + num2;
        res = sum * hi;
    }
    
    cout << "O maior resultado entre os 3 numeros: " << res << endl;

    return 0;
}