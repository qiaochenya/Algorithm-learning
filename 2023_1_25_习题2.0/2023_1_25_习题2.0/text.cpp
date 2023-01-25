#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <queue>
using namespace std;
queue<string>q;
unordered_map<string, int>d;	//存状态到开始状态的距离

int bfs(string start)
{
	string end = "12345678x";
	//初始化
	q.push(start);
	d[start] = 0;	//开始状态到开始状态是0

	int dx[4] = { 0,-1,0,1 }, dy[4] = {-1,0,1,0};

	while (q.size())
	{
		string t = q.front();	//队头赋予
		q.pop();	//弹出队头
		int distance = d[t];

		if (t == end) return distance;

		int k = t.find('x');	//找x的位置
		//将一维转化为3*3的位置
		int x = k / 3, y = k % 3;
		for (int i = 0; i < 4; i++)
		{
			int a = x + dx[i], b = y + dy[i];
			if (a >= 0 && a < 3 && b >= 0 && b < 3)
			{
				swap(t[k], t[a * 3 + b]);

				if (d.count(t) == 0)	//未被搜索过
				{
					d[t] = distance + 1;	//当前状态加1
					q.push(t);
				}
				//恢复原状
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