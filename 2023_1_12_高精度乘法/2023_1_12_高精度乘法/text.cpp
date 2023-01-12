#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;

vector<int>mul(vector<int>& A, int& B)
{
	int t = 0;
	vector<int>C;
	for (int i = 0; i < A.size(); i++)
	{
		t = A[i] * B;
		C.push_back(t % 10);
		t /= 10;
	}
	if (t)
		C.push_back(t);
	return C;
}
int main()
{
	int B;
	string a;
	cin >> a >> B;
	vector<int>A, C;
	for (int i = (int)a.size() - 1; i >= 0; i--)
	{
		A.push_back(a[i] - '0');
	}
	C = mul(A, B);
	for (int i = (int)C.size() - 1; i >= 0; i--)
	{
		cout << C[i];
	}
	return 0;
}