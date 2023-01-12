#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;

const int N = (int)1e6 + 10;

vector<int>add(vector<int>& A, vector<int>& B)
{
	vector<int>C;
	int t = 0;	//存放进位信息
	for (int i = 0; i < A.size() || i < B.size(); i++)
	{
		if (i < A.size())
			t += A[i];
		if (i < B.size())
			t += B[i];
		C.push_back(t % 10);
		t /= 10;
	}
	if (t)
		C.push_back(1);
	return C;
}
int main()
{
	string a, b;
	vector<int>A, B, C;

	cin >> a >> b;
	for (int i = (int)a.size() - 1; i >= 0; i--)
	{
		A.push_back(a[i] - '0');
	}
	for (int i = (int)b.size() - 1; i >= 0; i--)
	{
		B.push_back(b[i] - '0');
	}
	C = add(A, B);
	for (int i = (int)C.size() - 1; i >= 0; i--)
	{
		cout << C[i];
	}
	return 0;
}