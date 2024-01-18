#include <iostream>

using std::cout;
using std::endl;

int main()
{
    int a = 1;
    int b = 1;
    int fibo = 2;
    cout << a << " " << b << " " << fibo << " ";
    
    while (fibo > 0 and fibo < 1000)
    {
        a = b;
        b = fibo;
        fibo = a + b;
        
        cout << fibo << " " << endl;
    }
    return 0;
};