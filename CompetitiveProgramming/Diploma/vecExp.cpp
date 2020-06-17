//#define _CRT_SECURE_NO_WARNINGS
//
//#include <iostream>
//#include <vector>
//#include <set>
//#include <map>
//#include <algorithm>
//#include <iomanip>
//#include <string>
//#include <deque>
//#include <stack>
//#include <cmath>
//#include <iterator>
//#include <string.h>
//#include <queue> 
//
//using namespace std;
//const int MOD = 10007;
//
//struct vec
//{
//	vector <long long> m;
//	vector <long long> base;
//	int n;
//	vec()
//	{
//		n = 1;
//		m.resize(1, 0);
//	}
//
//	vec(int _n, const vector<long long> & _base)
//	{
//		n = _n;
//		m.resize(n, 0);
//		base = _base;
//	}
//
//	vec(const vec& a)
//	{
//		n = a.n;
//		m = a.m;
//		base = a.base;
//	}
//
//	vec operator* (const vec& a) const
//	{
//		vec ret(2*n-1, base);
//		for (int i = 0; i < n; ++i)
//		{
//			for (int j = 0; j < a.n; ++j)
//			{
//				ret.m[i + j] += m[i] * a.m[j];
//			}
//		}
//		while (ret.m.size() > n)
//		{
//			for (int i = 0; i < n; ++i)
//			{
//				int j = ret.m.size() - 2 - i;
//				ret.m[j] += base[i] * ret.m.back();
//			}
//			ret.m.pop_back();
//		}
//		ret.n = n;
//		return ret;
//	}
//
//	vec operator *= (vec& a)
//	{
//		*this = this->operator*(a);
//		return *this;
//	}
//
//
//	vec& operator = (const vec& a)
//	{
//		this->m = a.m;
//		this->n = a.n;
//		this->base = a.base;
//		return *this;
//	}
//};
//
//int dp[2000];
//vec binpow(vec a, int k)
//{
//	long long pw = 1;
//	vec ret(a.n, a.base);
//	ret.m[0] = 1;
//	while (k)
//	{
//		if (pw < a.n)
//		{
//			a.m.clear();
//			a.m.resize(a.n, 0);
//			a.m[pw] = 1;
//		}
//		if (k % 2)
//		{
//			ret *= a;
//		}
//		a *= a;
//		k /= 2;
//		pw *= 2;
//	}
//	return ret;
//}
//
//vec prec()
//{
//	vector<long long> base;
//	base.push_back(1);
//	base.push_back(2);
//	base.push_back(3);
//	vec ret(3, base);
//	ret.m[0] = 1;
//	return ret;
//}
//
//int calculate(int n)
//{
//	vec a = prec();
//	int res = 0;
//	vec m = binpow(a, n);
//	for (int i = 0; i < a.n; ++i)
//	{
//		res += m.m[i] * dp[i];
//	}
//	return res;
//}
//
//
//int brute(int x)
//{
//	for (int i = 3; i < 1995; ++i)
//	{
//		dp[i] = (1ll * dp[i - 1] + 2ll * dp[i - 2] + 3ll*dp[i-3]) % MOD;
//	}
//	return dp[x];
//}
//
//int main()
//{
//	dp[0] = 1;
//	dp[1] = 1;
//	dp[2] = 1;
//	brute(2);
//
//	for (int i = 3; i < 1995; ++i)
//	{
//		int res = calculate(i);
//		cout << i << ' ' << res << ' ' << dp[i] << endl;
//	}
//
//
//
//
//}
//
