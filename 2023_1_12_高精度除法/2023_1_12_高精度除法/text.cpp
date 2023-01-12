#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void my_reverse(int* l, int* r)
{
	while (l < r)
	{
		int temp = *l;
		*l = *r;
		*r = temp;
		l++;
		r++;
	}
}

vector<int>div(vector<int>& A, int& B, int& r)
{
	vector<int>C;
	r = 0;
	for (int i = (int)A.size() - 1; i >= 0; i--)
	{
		r = r * 10 + A[i];
		C.push_back(r / B);
		r = r % B;
	}
	//my_reverse(&C[0], &C[C.size() - 1]);
	reverse(C.begin(), C.end());
	while (C.size() > 1 && C.back() == 0)
	{
		C.pop_back();
	}
	return C;
}
int main()
{
	string a;
	int B, r;
	cin >> a >> B;
	vector<int>A, C;
	for (int i = (int)a.size() - 1; i >= 0; i--)
	{
		A.push_back(a[i] - '0');
	}
	C = div(A, B, r);
	for (int i = (int)C.size() - 1; i >= 0; i--)
	{
		cout << C[i];
	}
	cout << endl << r << endl;
	return 0;
}