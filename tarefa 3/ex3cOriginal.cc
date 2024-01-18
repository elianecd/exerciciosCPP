#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
	long long id;
	int counter = 1;
	int sum = 0;

	cin >> id;

	while (counter <= 9)
	{
		int digit = id % 10;
		id /= 10;

		if (counter % 2 == 0)
			digit *= 2;

		if (digit > 9)
		{
			int temp = 0;
			temp += digit % 10;
			digit /= 10;
			temp += digit;
			sum += temp;
		}
		else
			sum += digit;

		counter ++;
	}

	if (sum % 10 == 0 && id == 0)
		cout << "1";

	else
		cout << "0";

	return 0;
}