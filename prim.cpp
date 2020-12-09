#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int n; // 정점의 수
int W[100][100]; // 그래프의 인접행렬
vector<pair<int,int>> F; // 출력: 그래프 MST에 속한 이음선의 집합
void prim() //매개변수를 따로 뺐음
{
	int vnear;
	int min;
	int e; //edge
	
	int* nearest = new int[n + 1]; // Y에 속한 마디 중 vi에서 가장 가까운 마디 인덱스
	int* distance = new int[n + 1];

	F.clear();
	for (int i = 2; i <= n; i++)
	{
		nearest[i] = 1; //vi에서 가장 가까운 정점을 v1으로 초기화
		distance[i] = W[1][i]; //vi와 v1을 잇는 이음선의 가중치로 초기화
	}
	for (int i = 1; i <= n - 1; i++)
	{
		min = 10000000;
		for (int j = 2; j <= n; j++)
		{
			if (0 <= distance[j] && distance[j] <= min)
			{
				min = distance[j];
				vnear = j;
			}
		}
		F.push_back({ vnear,nearest[vnear] });
		distance[vnear] = -1; //찾은 노드를 Y에 추가

		for (int i = 2; i <= n; i++)
		{
			if (W[i][vnear] < distance[i]) //Y에 없는 각 노드에 대해 값 갱신
			{
				distance[i] = W[i][vnear]; 
				nearest[i] = vnear;
			}
		}
	}
}
int main()
{
	cin >> n;
/*
입력(전공서 기반)

8
0 5 1000 1000 8 1000 1000 1000
5 0 3 1000 1000 1000 1000 1000
1000 3 0 15 1000 1000 12 14
1000 1000 15 0 1000 1000 1000 6
8 4 1000 1000 0 2 1000 1000
1000 14 1000 1000 2 0 6 1000
1000 7 12 1000 1000 6 0 10
1000 1000 14 6 1000 1000 10 0
*/
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			cin >> W[i][j];
	}

	prim();
	for (int i = 0; i < F.size(); i++)
	{
		cout << F[i].first << " " << F[i].second << endl;
	}

	return 0;
}