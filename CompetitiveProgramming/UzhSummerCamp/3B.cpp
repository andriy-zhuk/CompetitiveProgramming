//#pragma GCC optimize("Ofast")
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
//
//using namespace std;
//
//#define FOR(i,a,b) for (int i = (a); i< (b); ++i)
//#define RFOR(i,a,b) for (int i = (a-1); i>= (b); --i)
//#define FILL(a, val) memset(a, val, sizeof(a))
//
//#define SZ(a) (int)a.size()
//#define ALL(a) a.begin(), a.end()
//#define PB push_back
//#define MP make_pair
//#define f first
//#define s second
//
//typedef long long LL;
//typedef vector<int> VI;
//typedef pair<int, int> PII;
//typedef vector<LL> VLL;
//typedef pair<LL, LL> PLL;
//
//const double PI = acos(-1.0);
//const int INF = 1000 * 1000 * 1000;
//const LL LINF = 1LL * INF * INF;
//const int maxn = 100 * 1000 + 5;
//const LL MOD = 998244353;
//
//const int MAXN = 1000 * 1000 * 10 + 7;
//
//LL fact[MAXN], invfact[MAXN];
//int phi[MAXN];
//
//LL binpow(LL a, LL n)
//{
//	LL res = 1;
//	while (n)
//	{
//		if (n % 2)
//		{
//			res = res * a;
//			res %= MOD;
//		}
//		a = a * a;
//		a %= MOD;
//		n >>= 1;
//	}
//	return res;
//}
//
//inline LL C(int n, int k)
//{
//	return fact[n] * invfact[n - k] % MOD * invfact[k] % MOD;
//}
//
//void init()
//{
//	fact[0] = 1;
//	FOR(i, 1, MAXN)
//	{
//		fact[i] = fact[i - 1] * i;
//		fact[i] %= MOD;
//	}
//
//	invfact[MAXN - 1] = binpow(fact[MAXN - 1], MOD - 2);
//	RFOR(i, MAXN - 1, 0)
//	{
//		invfact[i] = (i + 1);
//		invfact[i] *= invfact[i + 1];
//		invfact[i] %= MOD;
//	}
//}
//int d[MAXN];
//void sieve()
//{
//	phi[1] = 1;
//	FOR(i, 2, MAXN)
//	{
//		if (d[i] == 0)
//		{
//			d[i] = 1;
//			phi[i] = i - 1;
//		}
//		else
//		{
//			if ((i / d[i]) % d[i] == 0)
//			{
//				phi[i] = phi[i / d[i]] * d[i];
//			}
//			else
//			{
//				phi[i] = phi[i / d[i]] * (d[i] - 1);
//			}
//			continue;
//		}
//		LL j = 1LL * i * i;
//		while (j < MAXN)
//		{
//			d[j] = i;
//			j += i;
//		}
//	}
//}
//int n, l;
//
//LL get(int d)
//{
//	LL res = 1;
//	res *= phi[n / d]; 
//	res %= MOD;
//	if (l % (n / d) == 0)
//	{
//		res *= C(d + l / (n / d) - 1, d - 1);
//		res %= MOD;
//		return res;
//	}
//	return 0;
//}
//
//LL easy()
//{
//	LL res = 0;
//	for (LL d = 1; d * d <= n; ++d)
//	{
//		if (n % d == 0)
//		{
//			res += get(d);
//			if (res >= MOD)
//				res -= MOD;
//			if (n / d != d)
//			{
//				res += get(n / d);
//				if (res >= MOD)
//					res -= MOD;
//			}
//		}
//	}
//	return res;
//}
//
//LL hard()
//{
//	if (n % 2)
//	{
//		LL res = 0;
//		FOR(m1, 0, 2)
//		{
//			if ((l - m1) % 2 == 0 && l - m1 >= 0)
//			{
//				res += C(n / 2 + (l - m1) / 2, n / 2) * n % MOD;
//				res %= MOD;
//			}
//		}
//		return res;
//	}
//	else
//	{
//		LL res = 0;
//		if (l % 2 == 0)
//		{
//			res += 1LL * (n / 2) * C(n / 2 + l / 2 - 1, n / 2 - 1) % MOD;
//			res %= MOD;
//		}
//		FOR(m1, 0, 2)
//		{
//			FOR(m2, 0, 2)
//			{
//				int nl = l - m1 - m2;
//				if (nl >= 0 && nl % 2 == 0)
//				{
//					res += 1LL * (n / 2) * C(nl / 2 + n / 2, n / 2) % MOD;
//					res %= MOD;
//				}
//			}
//		}
//		return res;
//	}
//}
//
//
//int main()
//{
//	ios_base::sync_with_stdio(0);
//	//freopen("input.txt", "r", stdin);
//	//freopen("output.txt", "w", stdout);
//	init();
//	sieve(); 
//	FOR(i, 0, 100)
//	{
//	//	cout << phi[i] << ' ';
//	}
//	//cout << endl << endl;
//	int t;
//	cin >> t;
//	while (t--)
//	{
//		cin >> l >> n;
//		l -= n;
//		cout << (easy() + hard())%MOD * binpow( 2 * n % MOD, MOD-2) % MOD << endl;
//	}
//
//	return 0;
//}
//
