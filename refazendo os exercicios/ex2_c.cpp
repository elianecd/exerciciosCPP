/* O programa pede uma data como input e printa com os sufixos st, nd, rd, th e com o nome do mes.
Ele verifica se os dias correspondem ao mes e ao ano caso seja bisexto.
*/

#include <iostream>
//#include <cmath>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    int d, m, y;
    bool is_leap = false;
    bool valid_year = false;
    //bool valid_month = false;

    cout << "Digite uma data (dd mm yyyy): " << endl;
    cin >> d >> m >> y;

    if (y <= 3000)
    {
        valid_year = true;

        if (y % 400 == 0)
            is_leap = true;
        else if (y % 4 == 0 && y % 100 != 0)
            is_leap = true;
    }

    if ((m >= 1 && m <= 12) && valid_year)
    {
        if (d >= 1 && d <= 31)
        {
            if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
                if (d == 31)
                    cout << d << "st ";
            if (m == 2 && d <= 29)
                if (d == 29)
                    if (is_leap)
                        cout << d << "th ";
                    else
                        return 0;

            if (d == 1 || d == 21)
                cout << d << "st ";
            if (d == 2 || d == 22)
                cout << d << "nd ";
            if (d == 3 || d == 23)
                cout << d << "rd ";
            if (d != 29 && d != 31)
                cout << d << "th ";

            switch (m)
            {
                case 1:
                    cout << "January ";
                    break;

                case 2:
                    cout << "February ";
                    break;
                    
                case 3:
                    cout << "March ";
                    break;

                case 4:
                    cout << "April ";
                    break;

                case 5:
                    cout << "May ";
                    break;

                case 6:
                    cout << "June ";
                    break;

                case 7:
                    cout << "July ";
                    break;

                case 8:
                    cout << "August ";
                    break;
                
                case 9:
                    cout << "September ";
                    break;

                case 10:
                    cout << "October ";
                    break;
                
                case 11:
                    cout << "November ";
                    break;

                case 12:
                    cout << "December ";
                    break;
            }

            cout << y;
            cout << endl;
        }
    }
        
    return 0;
}