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
//#define FOR(i,a,b) for (LL i = (a); i< (b); ++i)
//#define RFOR(i,a,b) for (LL i = (a-1); i>= (b); --i)
//#define FILL(a, val) memset(a, val, sizeof(a))
//
//#define SZ(a) (LL)a.size()
//#define ALL(a) a.begin(), a.end()
//#define PB push_back
//#define MP make_pair
//#define f first
//#define s second
//
//typedef long long LL;
//typedef vector<LL> VI;
//typedef pair<LL, LL> PII;
//typedef vector<LL> VLL;
//typedef pair<LL, LL> PLL;
//
//const double PI = acos(-1.0);
//const LL INF = 1000 * 1000 * 1000;
//const LL LINF = 1LL * INF * INF;
//const LL maxn = 100 * 1000 + 5;
//const LL MOD = 998244353;
//const LL mod = 998244353;
//
//
//const LL MAXN = 1000 * 100 + 7;
//
//LL x[maxn];
//LL pref[maxn];
//LL suf[maxn];
//LL fact[maxn], invfact[maxn];
//
//LL binpowmod(LL a, LL n, LL mo)
//{
//	LL res = 1;
//	while (n)
//	{
//		if (n % 2)
//		{
//			res = res * a;
//			res %= mo;
//		}
//		a = a * a;
//		a %= mo;
//		n >>= 1;
//	}
//	return res;
//}
//
//
//LL coef(const vector<LL>& vec, LL n)
//{
//	pref[0] = 1;
//	suf[SZ(vec) + 1] = 1;
//	FOR(i, 1, SZ(vec) + 1)
//	{
//		pref[i] = 1LL * (n - i + mod) % mod * pref[i - 1] % mod;
//	}
//	RFOR(i, SZ(vec) + 1, 0)
//	{
//		suf[i] = 1LL * (n - i + mod) % mod * suf[i + 1] % mod;
//	}
//
//	LL one = 1;
//	if ((SZ(vec) - 1) % 2 == 1)
//		one *= (mod - 1);
//	LL ans = 0;
//	FOR(i, 1, SZ(vec) + 1)
//	{
//		LL pp = pref[i - 1];
//		LL ss = suf[i + 1];
//		ans += vec[i - 1] * one % mod * pp % mod * ss % mod * invfact[i - 1] % mod * invfact[SZ(vec) - i] % mod;
//		ans %= mod;
//		one = one * (mod - 1) % mod;
//	}
//	return ans;
//}
//void init()
//{
//	fact[0] = 1;
//	FOR(i, 1, maxn)
//	{
//		fact[i] = fact[i - 1] * (LL)i % mod;
//	}
//
//	invfact[maxn - 1] = binpowmod(fact[maxn - 1], mod - 2, mod);
//
//	RFOR(i, maxn - 1, 0)
//	{
//		invfact[i] = (i + 1) * (LL)invfact[i + 1] % mod;
//	}
//
//}
//inline LL C(LL n, LL k)
//{
//	if (n == -1 && k == -1)
//		return 0;
//	if (n == -1 || k == -1)
//	  return 0;
//	return fact[n] * invfact[n - k] % MOD * invfact[k] % MOD;
//}
//LL C1(LL n, LL m)
//{
//	LL res = 1;
//	FOR(i, 0, m)
//	{
//		res = (res * (LL)(n - i)) % mod;
//	}
//	res = res * invfact[m] % mod;
//	return res;
//}
//
//LL calcTupo(int n, int s, int i)
//{
//	LL res = 0;
//	FOR(x, 1, s / n + 1)
//	{
//		res += C(s - i * x - 1, n - i - 1);
//		res %= MOD;
//	}
//	return res;
//}
//
//
//LL findS(LL s,LL j , LL i, LL n)
//{
//	LL res = 0;
//
//	LL last = min(j, s / i) + 1;
//
//	FOR(x, 1, last)
//	{
//		LL cur2 = C(s - i * x - 1, n - i - 1);
//		LL cur = C1(s - i * x - 1, n - i - 1);
//		res += cur2;
//		if (res >= MOD)
//			res -= MOD;
//	}
//	return res;
//}
//
//
//LL solve(LL s, LL n)
//{
//	if (s == n || n == 1)
//		return 1;
//
//	LL one = 1;
//	LL suma = 0;
//	FOR(i, 1, n+1)
//	{
//		if (i == n)
//		{
//			if (s % n == 0)
//			{
//				suma += 1LL * one;
//				if (suma >= MOD)
//					suma -= MOD;
//			}
//			one = one * (MOD - 1) % MOD;
//			break;
//		}
//
//		vector<LL> foo;
//		FOR(ss, 1, n - i + 7)
//		{
//			LL cur = findS(s, ss, i, n);
//			if (!foo.size())
//				foo.PB(cur);
//			else
//				foo.PB((foo.back() + cur) % MOD);
//		}
//	
//		
//		LL val = C(n, i) * one % MOD;
//		cout << val << '*' << findS(s, s / i, i, n) << endl;
//		//cout << val << '*' << calcTupo(n, s, i) << endl;
//
//		//suma += val * coef(foo, s/i) % MOD;	
//		suma += val * findS(s, s / i, i, n) % mod;
//		//suma += val * calcTupo(n, s, i) % mod;
//		if (suma >= MOD)
//			suma -= MOD;
//
//		one = one * (MOD - 1) % MOD;
//	}
//	
//	return suma;
//}
//
//int main()
//{
//	ios_base::sync_with_stdio(0);
//	//freopen("input.txt", "r", stdin);
//	//freopen("output.txt", "w", stdout);
//	init();
//	//cout << solve(10, 2) << endl;
//	//cout << solve(3, 2) << endl;
//	LL n, s;
//	cin >> s >> n;
//	cout << solve(s, n);
//	return 0;
//	FOR(n, 2, 50)
//	{
//		cout << "n:" << n << endl;
//		FOR(s, n, 50)
//		{
//			if (solve(s, n) < 0)
//			{
//				cout << "GOVNOOOOOO" << s << ' ' << n << endl;
//				return 0;
//			}
//		//	cout << solve(s, n) << ' ';
//			//if (solve(s, n) != broot(s, n))
//			//{
//				//cout << s << " " << n << endl;
//				//cout << broot(s, n) << " " << solve(s, n);
//				//return 0;
//			//}
//		}
//		//cout << endl;
//	}
//
//
//	return 0;
//}