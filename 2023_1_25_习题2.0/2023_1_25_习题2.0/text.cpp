#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <queue>
using namespace std;
//queue<string>q;
//unordered_map<string, int>d;	//��״̬����ʼ״̬�ľ���
//
//int bfs(string start)
//{
//	string end = "12345678x";
//	//��ʼ��
//	q.push(start);
//	d[start] = 0;	//��ʼ״̬����ʼ״̬��0
//
//	int dx[4] = { 0,-1,0,1 }, dy[4] = {-1,0,1,0};
//
//	while (q.size())
//	{
//		string t = q.front();	//��ͷ����
//		q.pop();	//������ͷ
//		int distance = d[t];
//
//		if (t == end) return distance;
//
//		int k = t.find('x');	//��x��λ��
//		//��һάת��Ϊ3*3��λ��
//		int x = k / 3, y = k % 3;
//		for (int i = 0; i < 4; i++)
//		{
//			int a = x + dx[i], b = y + dy[i];
//			if (a >= 0 && a < 3 && b >= 0 && b < 3)
//			{
//				swap(t[k], t[a * 3 + b]);
//
//				if (d.count(t) == 0)	//δ��������
//				{
//					d[t] = distance + 1;	//��ǰ״̬��1
//					q.push(t);
//				}
//				//�ָ�ԭ״
//				swap(t[k], t[a * 3 + b]);
//			}
//		}
//	}
//	return -1;
//}
//
//int main()
//{
//	string start;
//	for (int i = 0; i < 9; i++)
//	{
//		char c;
//		cin >> c;
//		start += c;
//	}
//
//	cout << bfs(start) << endl;
//	return 0;
//}

#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5 + 10;

pair<int, int> a[N];
int n;
bool st[N];

int main()
{
    scanf("%d", &n);
    int k = n;
    while (k--)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        a[k] = { x, y };
    }
    sort(a, a + n);

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {

            if (a[i].second > a[j].second)
            {
                if (st[i] == true && st[j] == false)
                    ans++;
                if (st[i] == false && st[j] == false)
                {
                    st[i] = true;
                    st[j] = true;
                    ans += 2;
                }


            }

        }
    }

    cout << ans << endl;
}