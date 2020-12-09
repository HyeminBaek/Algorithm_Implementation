#include <iostream>
#include <queue>
using namespace std;

int n = 3;
struct node
{
	int level;
	int profit;
	int weight;
};
float bound(node u,int W,int w[],int p[])
{
	int j, k;
	int totweight;
	float result;

	if (u.weight >= W) return 0;
	else
	{
		result = u.profit;
		j = u.level + 1;
		totweight = u.weight;
		while (j <= n && totweight + w[j] <= W)
		{
			totweight = totweight + w[j];
			result = result + p[j];
			j++;
		}
		k = j;
		if (k <= n)
			result = result + (W - totweight)*(p[k] / w[k]);
		return result;
	}
}
void knapsack(int n, int p[], int w[], int W, int& maxprofit)
{
	queue<node> Q;
	node u, v;
	v.level = 0, v.profit = 0, v.weight = 0;
	maxprofit = 0;
	Q.push(v);

	while (!Q.empty())
	{

		node temp = Q.front();  Q.pop();
		u.level = temp.level + 1;
		u.weight = temp.weight + w[u.level];
		u.profit = temp.profit + p[u.level];
		if (u.weight <= W && u.profit > maxprofit)
			maxprofit = u.profit;
		if (bound(u,W,w,p) > maxprofit)
			Q.push(u);
		u.weight = temp.weight;
		u.profit = temp.profit;
		if (bound(u,W,w,p) > maxprofit)
			Q.push(u);
	}
}
int main()
{
	int p[4], w[4];
	int W = 14;
	p[1] = 30, p[2] = 35, p[3] = 40;
	w[1] = 3, w[2] = 7, w[3] = 10;
	int maxprofit = 0;
	knapsack(n, p, w, W, maxprofit);

	cout << maxprofit;

	return 0;
}