#include <iostream>
#include <queue>
using namespace std;

int n = 4;
struct node
{
	int level;
	int profit;
	int weight;
	float bounds;
};
float bound(node u, int W, int w[], int p[])
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
	priority_queue<node> PQ;
	node u, v;
	v.level = 0, v.profit = 0, v.weight = 0;
	maxprofit = 0;
	v.bounds = bound(v,W,w,p);
	PQ.push(v);

	while (!PQ.empty())
	{

		node temp = PQ.top();  PQ.pop();
		u.level = temp.level + 1;
		u.weight = temp.weight + w[u.level];
		u.profit = temp.profit + p[u.level];
		if (u.weight <= W && u.profit > maxprofit)
			maxprofit = u.profit;
		u.bounds = bound(u,W,w,p);
		if (u.bounds > maxprofit)
			PQ.push(u);
		u.weight = temp.weight;
		u.profit = temp.profit;
		u.bounds = bound(u,W,w,p);
		if (u.bounds > maxprofit)
			PQ.push(u);
	}
}
int main()
{
	int p[5], w[5];
	int W = 16;
	p[1] = 40, p[2] = 30, p[3] = 50, p[4] = 10;
	w[1] = 2, w[2] = 5, w[3] = 10, w[4] = 5;
	int maxprofit = 0;
	knapsack(n, p, w, W, maxprofit);

	cout << maxprofit;

	return 0;
}