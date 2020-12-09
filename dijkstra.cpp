#include <iostream>
#include <vector>
using namespace std;

int n;
int W[10][10];
vector<pair<int, int>> F;

void dijkstra()
{
	int vnear;

	int* touch = new int[n+1];
	int* length = new int[n+1];

	for (int i = 2; i <= n; i++)
	{
		touch[i] = 1;
		length[i] = W[1][i];
	}

	for (int i = 1; i <= n - 1; i++)
	{
		int min = 1000000;
		for (int j = 2; j <= n; j++)
		{
			if (0 <= length[j] && length[j] < min)
			{
				min = length[j];
				vnear = j;
			}
		}
		F.push_back({ touch[vnear],vnear });
		for (int j = 2; j <= n; j++)
		{
			if (length[vnear] + W[vnear][j] < length[j])
			{
				length[j] = length[vnear] + W[vnear][j];
				touch[j] = vnear;
			}
		}
		length[vnear] = -1;
	}
}
int main()
{
	cin >> n;
/*
입력(전공서 기반)

5
10000 7 4 6 1
10000 10000 10000 10000 10000
10000 2 10000 5 10000
10000 4 10000 10000 10000
10000 10000 10000 1 10000
*/
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			cin >> W[i][j];
	}

	dijkstra();
	for (int i = 0; i < F.size(); i++)
	{
		cout << F[i].first << " " << F[i].second << endl;
	}
	return 0;
}