#include <iostream>
#include <vector>
using namespace std;

vector<int> tree[5];
int col[5];

bool promising(int i)
{
	bool Switch = true;
	int k = 1;
	while (k < i&&Switch)
	{
		if (col[i] == col[k] || abs(col[i] - col[k]) == i - k)
			Switch = false;
		k++;
	}
	return Switch;
}
void queens(int i)
{
	if (promising(i))
	{
		if (i == 4)
		{
			for (int j = 1; j <= 4; j++)
				cout << col[j] << " ";
			cout << endl;
		}
		else
		{
			for (int j = 1; j <= 4; j++)
			{
				col[i + 1] = j;
				queens(i + 1);
			}
		}
	}
}
void expand(int v)
{
	for (int i = 0; i < tree[v].size(); i++)
	{
		if (promising(v))
		{
			/*
			if(해가 있으면) 해를 써라
			else
			*/
			expand(tree[v][i]);
		}
	}
}
void checknode(int v)
{
	if (promising(v))
	{
		/*
		if(해가 있으면) 해를 써라
		else
		*/
		for (int i = 0; i < tree[v].size(); i++)
			checknode(tree[v][i]);
	}
}
int main()
{
	queens(0);

	return 0;
}