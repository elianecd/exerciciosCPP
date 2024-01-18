/* O programa pede 4 numeros de input para o usuario
e conta a quantidade de numeros pares, impares, positivos, negativos e zeros.
*/

#include <iostream>
//#include <cmath>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    int num[4];
    int count_even = 0, count_odd = 0, count_zero = 0, 
        count_positive = 0, count_negative = 0;

    cout << "Digite 4 numeros: " << endl;

    for (int i = 0; i < 4; i++)
    {
        cin >> num[i];

        if (num[i] > 0)
        {
            count_positive++;

            if (num[i] % 2 == 0)
                count_even++;
            else
                count_odd++;
        }
        else if (num[i] < 0)
        {
            count_negative++;

            if (num[i] % 2 == 0)
                count_even++;
            else
                count_odd++;
        }
        else
            count_zero++;
    }

    cout << "Quantidade de numeros pares: " << count_even << " e impares: " << count_odd << endl;
    cout << "Quantidade de numeros positivos: " << count_positive << ", negativos: " 
         << count_negative << " e zeros: " << count_zero << endl;

    return 0;
}