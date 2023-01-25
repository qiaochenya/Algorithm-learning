#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
//���Թ����·����

int n, m;
#define N 110
int d[N][N], g[N][N];
pair<int, int>q[N * N], Prex[N][N];	//Prex������߹���·������������ӡ����

int bfs()
{
	int hh = 0, tt = 0;	//ttΪ0����Ϊһ��ʼ���ø�����������������Ͷ����Ѿ���ʼ�����
	int dx[4] = { -1,0,1,0 }, dy[4] = { 0,-1,0,1 };	//���������ĸ�λ����չ
	while (hh <= tt)
	{
		pair<int, int>t = q[hh++];
		//4��λ��
		for (int i = 0; i < 4; i++)
		{
			int x = t.first + dx[i], y = t.second + dy[i];
			if (x >= 0 && x < n && y >= 0 && y < m && g[x][y] == 0 && d[x][y] == -1)	//�ж��Ƿ�Խ����Ƿ�����ߺ��Ƿ��߹�
			{
				Prex[x][y] = t;	//��������Ӧ����һ������ʲô
				d[x][y] = d[t.first][t.second] + 1;	//����++
				q[++tt] = { x,y };	//���
			}
		}
	}
	int x = n - 1, y = m - 1;	//x��y�����һ���㿪ʼ
	while (x != 0 || y != 0)
	{
		cout << x << " " << y << endl;
		pair<int, int>t = Prex[x][y];	//��������һ����ȡ����
		x = t.first;
		y = t.second;
	}
	return d[n - 1][m - 1];	//����߲�������0
}
int main()
{
	cin >> n >> m;
	//�����Թ������0��1
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> g[i][j];
	//��ʼ��
	memset(d, -1, sizeof(d));	//�����ʼ����ָ��-1
	q[0] = { 0,0 };	//���г�ʼ��
	d[0][0] = 0;	//��㵽���ľ���Ϊ0

	cout << bfs() << endl;
	return 0;
}