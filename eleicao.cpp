#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    int num;
    int count1 = 0;
    int count2 = 0;
    int count3 = 0;
    int zero, votos_totais = 0;
    int nulo = 0;
    int branco = 0;
    
    cout << "Digite o numero do seu candidato: " << endl;
    cin >> num >> endl;
    
    while (num != 0)
    {
        if (num == 1)
        {
            cout << "Candidato  Antonio" << endl;
            count1++;
            break;
        }
        else if (num == 2)
        {
            cout << "Candidato  Jose" << endl;
            count2++;
            break;
        }
        else if (num == 3)
        {
            cout << "Candidato  Maria" << endl;
            count3++;
            break;
        }
        else if (num == 4)
        {
            cout << "Voto em Branco" << endl;
            branco++;
            break;
        }
       else
       {
           cout << "Voto Nulo" << endl;
           nulo++;
           break;
       }
    }
    
    cout << "Digite o zero para confirmar e finalizar" << endl;
    cin >> zero;
    
    votos_totais = nulo + branco + count3 + count2 + count1;
    
    if (count1 > count2 && count1 > count3)
    {
        cout << "Antonio Venceu com " << count1 << " votos." << endl;
        cout << "Jose ficou com " << count2 << " votos." << endl;
        cout << "Maria ficou com " << count3 << " votos." << endl;
        cout << "Numero total de votos foi " << votos_totais << endl;
    }
        
    else if (count2 > count1 && count2 > count3)
    {
        cout << "Jose Venceu com " << count2 << " votos." << endl;
        cout << "Antonio ficou com " << count1 << " votos." << endl;
        cout << "Maria ficou com " << count3 << " votos." << endl;
        cout << "Numero total de votos foi " << votos_totais << endl;
    }
    else if (count3 > count1 && count3 > count2)
    {
        cout << "Maria Venceu com " << count3 << " votos." << endl;
        cout << "Antonio ficou com " << count1 << " votos." << endl;
        cout << "Jose ficou com " << count2 << " votos." << endl;
        cout << "Numero total de votos foi " << votos_totais << endl;
    }
    else
    {
        cout << "Segundo turno." << endl;
        cout << "Antonio ficou com " << count1 << " votos." << endl;
        cout << "Jose ficou com " << count2 << " votos." << endl;
        cout << "Maria ficou com " << count3 << " votos." << endl;
        cout << "Numero total de votos foi " << votos_totais << endl;
    }
    //getchar();
    return 0;
}