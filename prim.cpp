#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int n; // ������ ��
int W[100][100]; // �׷����� �������
vector<pair<int,int>> F; // ���: �׷��� MST�� ���� �������� ����
void prim() //�Ű������� ���� ����
{
	int vnear;
	int min;
	int e; //edge
	
	int* nearest = new int[n + 1]; // Y�� ���� ���� �� vi���� ���� ����� ���� �ε���
	int* distance = new int[n + 1];

	F.clear();
	for (int i = 2; i <= n; i++)
	{
		nearest[i] = 1; //vi���� ���� ����� ������ v1���� �ʱ�ȭ
		distance[i] = W[1][i]; //vi�� v1�� �մ� �������� ����ġ�� �ʱ�ȭ
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
		distance[vnear] = -1; //ã�� ��带 Y�� �߰�

		for (int i = 2; i <= n; i++)
		{
			if (W[i][vnear] < distance[i]) //Y�� ���� �� ��忡 ���� �� ����
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
�Է�(������ ���)

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