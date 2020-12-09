#include <iostream>
#include <vector>
#include <string>
using namespace std;

int n = 3, W = 14;
int maxprofit, numbest;
string bestset;
int p[4], w[4];

bool promising(int i,int profit,int weight)
{
	int j, k;
	int totweight;
	float bound;

	if (weight >= W)
		return false;
	else
	{
		j = i + 1;
		bound = profit;
		totweight = weight;

		while (j <= n && totweight + w[j] <= W)
		{
			totweight = totweight + w[j];
			bound = bound + p[j];
			j++;
		}
		k = j;
		if (k <= n)
			bound = bound + (W - totweight)*p[k] / w[k];
		cout << i << " " <<profit<<" "<< bound << endl;
		return bound > maxprofit;
	}
}
void knapsack(int i, int profit, int weight, string include)
{
	if (i == 1)
		cout << promising(i, profit, weight);
	if (weight <= W && profit > maxprofit)
	{
		maxprofit = profit;
		numbest = i;
		bestset = include;
	}
	if (promising(i,profit,weight))
	{
		knapsack(i + 1, profit + p[i + 1], weight + w[i + 1],include+'y');
		knapsack(i + 1, profit, weight,include+'n');
	}
}
int main()
{
	p[1] = 30, p[2] = 35, p[3] = 40;
	w[1] = 3, w[2] = 7, w[3] = 10;

	knapsack(0, 0, 0,"");
	cout << maxprofit << endl;

	cout << bestset;

	return 0;
}