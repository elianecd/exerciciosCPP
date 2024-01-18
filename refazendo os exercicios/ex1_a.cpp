/* O programa recebe 3 numeros inteiros do input e printa:
#1 - #1       #1 - #2       #1 - #3
#2 - #1       #2 - #2       #2 - #3
#3 - #1       #3 - #2       #3 - #3
*/

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    int a, b, c;

    cout << "Digite 3 numeros: " << endl;
    cin >> a >> b >> c;

    cout << a << "-" << a << " " << a << "-" << b << " " << a << "-" << c << endl;
    cout << b << "-" << a << " " << b << "-" << b << " " << b << "-" << c << endl;
    cout << c << "-" << a << " " << c << "-" << b << " " << c << "-" << c << endl;

    return 0;
}