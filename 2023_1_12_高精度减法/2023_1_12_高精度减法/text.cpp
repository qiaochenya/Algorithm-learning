#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;

bool cmp(vector<int>& A, vector<int>& B)
{
	if (A.size() != B.size())
		return A.size() > B.size();	//������ھ���1�����Ǿ���0
	for (int i = (int)A.size() - 1; i >= 0; i--)	//���������ͬ
	{
		if (A[i] != B[i])
			return A[i] > B[i];
	}
	//�������������
	return true;
}
vector<int>sub(vector<int>A, vector<int>B)
{
	vector<int>C;
	int t = 0;
	for (int i = 0; i < A.size(); i++)
	{
		t = A[i] - t;
		if (i < B.size())
			t = t - B[i];
		C.push_back((t + 10) % 10);	//���t��������ֱ�Ӽӵ����һλ��t�Ǹ������Ƚ�10
		if (t < 0)
			t = 1;
		else
			t = 0;
	}
	while (C.size() > 1 && C.back() == 0)
		C.pop_back();
	return C;

}
int main()
{
	string a, b;
	cin >> a >> b;
	vector<int>A, B ,C;
	for (int i = (int)a.size() - 1; i >= 0; i--)
	{
		A.push_back(a[i] - '0');
	}
	for (int i = (int)b.size() - 1; i >= 0; i--)
	{
		B.push_back(b[i] - '0');
	}
	if (cmp(A, B))	//�ж��Ƿ�A>=B
	{
		C = sub(A, B);
		for (int i = (int)C.size() - 1; i >= 0; i--) 
			cout << C[i];
	}
	else
	{
		C = sub(B, A);
		printf("-");
		for (int i = (int)C.size() - 1; i >= 0; i--) 
			cout << C[i];
	}
	return 0;
}