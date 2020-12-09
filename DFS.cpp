#include <iostream>
#include <vector>
using namespace std;

bool visited[11];
vector<int> tree[11];

void dfs(int v)
{
	visited[v] = true;
	for (int i = 0; i < tree[v].size(); i++)
		dfs(tree[v][i]);
}
int main()
{
	int n; cin >> n; //마디 개수
	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;

		tree[x].push_back(y);
	}

	return 0;
}