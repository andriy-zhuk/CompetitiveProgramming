#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <iomanip>
#include <string>
#include <deque>
#include <stack>
#include <cmath>
#include <iterator>
#include <string.h>
#include <queue> 

using namespace std;
const int MOD = 10007;

struct matrix
{
	vector<vector<int> > m;
	int n;

	matrix()
	{
		n = 1;
		m.resize(1, vector<int>(1, 1));
	}

	matrix(int _n)
	{
		n = _n;
		m.resize(n, vector<int>(n, 0));
		for (int i = 0; i < n; ++i)
		{
			m[i][i] = 1;
		}
	}

	matrix(const matrix& a) 
	{
		n = a.n;
		m = a.m;
	}

	matrix operator* (const matrix& a) const
	{
		matrix ret(n);
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				ret.m[i][j] = 0;
				for (int k = 0; k < n; ++k)
				{
					ret.m[i][j] += (long long)m[i][k] * a.m[k][j]%MOD;
					ret.m[i][j] %= MOD;
				}
			}
		}
		return ret;
	}

	matrix operator *= (matrix &a)
	{
		*this = this->operator*(a);
		return *this;
	}


	matrix& operator = (const matrix& a)
	{
		this->m = a.m;
		this->n = a.n;
		return *this;
	}
};


matrix binpow(matrix a, int k)
{
	matrix ret(a.n);
	while (k)
	{
		if (k % 2)
		{
			ret *= a;
		}
		a *= a;
		k /= 2;
	}
	return ret;
}

matrix prec()
{
	matrix ret(2);
	ret.m[0][0] = 3;
	ret.m[0][1] = 2;
	ret.m[1][0] = 1;
	ret.m[1][1] = 0;
	return ret;
}

int dpT[2000];
int brute(int x)
{
	dpT[0] = 1;
	dpT[1] = 1;
	for (int i = 2; i < 1995; ++i)
	{
		dpT[i] = (3ll * dpT[i - 1] + 2ll * dpT[i - 2]) % MOD;;
	}
	return dpT[x];
}

int calculate(int n)
{
	matrix a = prec();
	matrix m = binpow(a, n - 2 + 1);
	long long res = (long long)m.m[0][0] * dpT[1] % MOD + (long long)m.m[0][1] * dpT[0] % MOD;
	res %= MOD;
	return res;
}

int main()
{
	brute(2);

	for (int i = 2; i < 1995; ++i)
	{
		long long res = calculate(i);
		cout <<i << ' ' <<  res << ' ' << dpT[i] << endl;
	}




}

