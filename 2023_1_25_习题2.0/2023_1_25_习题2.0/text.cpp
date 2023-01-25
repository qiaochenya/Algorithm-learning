#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <queue>
using namespace std;
queue<string>q;
unordered_map<string, int>d;	//��״̬����ʼ״̬�ľ���

int bfs(string start)
{
	string end = "12345678x";
	//��ʼ��
	q.push(start);
	d[start] = 0;	//��ʼ״̬����ʼ״̬��0

	int dx[4] = { 0,-1,0,1 }, dy[4] = {-1,0,1,0};

	while (q.size())
	{
		string t = q.front();	//��ͷ����
		q.pop();	//������ͷ
		int distance = d[t];

		if (t == end) return distance;

		int k = t.find('x');	//��x��λ��
		//��һάת��Ϊ3*3��λ��
		int x = k / 3, y = k % 3;
		for (int i = 0; i < 4; i++)
		{
			int a = x + dx[i], b = y + dy[i];
			if (a >= 0 && a < 3 && b >= 0 && b < 3)
			{
				swap(t[k], t[a * 3 + b]);

				if (d.count(t) == 0)	//δ��������
				{
					d[t] = distance + 1;	//��ǰ״̬��1
					q.push(t);
				}
				//�ָ�ԭ״
				swap(t[k], t[a * 3 + b]);
			}
		}
	}
	return -1;
}

int main()
{
	string start;
	for (int i = 0; i < 9; i++)
	{
		char c;
		cin >> c;
		start += c;
	}

	cout << bfs(start) << endl;
	return 0;
}