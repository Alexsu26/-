#include <iostream>
using namespace std;

bool IsUsed(int a[], int len, int x)
{

	for (int i = 0; i <= len; i++)

		if (a[i] == x)

			return true;

	return false;

}


int FindMain(int a[], int len)
{

	int used[len], lenUsed = 0;

	int flag = 0, mainfactor;

	for (int i = 0; i <= len / 2; i++)

	{

		if (IsUsed(used, lenUsed, a[i]))

			continue;

		else

		{

			used[lenUsed] = a[i];

			lenUsed++;

			int count = 1;

			mainfactor = a[i];

			for (int j = i + 1; j < len; j++)

			{

				if (a[j] == mainfactor)

					count++;

			}

			if (count > len / 2)

			{

				flag = 1;

				break;

			}

		}

	}

	if (flag)

		return mainfactor;

	else

		return -1;

}
int main()
{
	int a[] = {5,5,5,5,5,3,3,3};
	cout << FindMain(a, 8);
	return 0;
}