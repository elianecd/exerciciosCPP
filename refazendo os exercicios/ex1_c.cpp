/* O programa calcula a nota do curso conforme os seguinte criterios:
1. o primeiro exercicio vale 10% da nota total;
2. o peso do segundo exercicio vale 20% da nota total;
3. o valor da prova vale 70% da nota total.
*/

#include <iostream>
//#include <cmath>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    float ex1, ex2, prova;
    float av1, av2, nota_prova, media;

    cout << "Digite a nota do primeiro exercicio: " << endl;
    cin >> ex1;
    cout << "Digite a nota do segundo exercicio: " << endl;
    cin >> ex2;
    cout << "Digite a nota da prova: " << endl;
    cin >> prova;

    av1 = (ex1 / 100) * 10;
    av2 = (ex2 / 100) * 20;
    nota_prova = (prova / 100) * 70;

    media = av1 + av2 + nota_prova;

    cout << "A nota final do aluno eh: " << media << endl;

    return 0;
}