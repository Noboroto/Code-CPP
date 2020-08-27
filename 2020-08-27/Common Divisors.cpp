
#include <bits/stdc++.h>
using namespace std;

int findMaxGCD(int a[], int n)
{
	int high = 0;
	for (int i = 0; i < n; i++) high = max(high, a[i]);
	int count[high + 1] = {0};
	for (int i = 0; i < n; i++) count[a[i]]++;
	int counter = 0;
	for (int i = high; i >= 1; i--)
	{
		int j = i;
		counter = 0;
		while (j <= high)
		{
			if (count[j] >= 2)
				return j;
			else if (count[j] == 1)
				counter++;
			j += i;
			if (counter == 2)
				return i;
		}
	}
}

int main()
{
	const int N = 1e6 + 1;
	int a[N], n;
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> a[i];
	cout << findMaxGCD(a, n);
	return 0;
}
