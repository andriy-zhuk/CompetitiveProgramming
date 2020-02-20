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
//#include <queue> 
//
//using namespace std;
//#ifndef DEBUGING
//ostream cnull(NULL);
//#define cerr cnull
//#endif // !DEBUGING
//
//#define PB push_back
//#define MP make_pair
//#define f first
//#define s second
//#define FOR(i,a,b) for (int i = a; i < b; ++i)
//#define RFOR(i, b, a) for (int i = b-1; i>=a; --i)
//#define FILL(a, b) memset(a, b, sizeof a)
//#define ALL(a) a.begin(), a.end()
//#define SZ(a) (int)a.size()
//
//typedef unsigned long long ULL;
//typedef long long LL;
//typedef pair<int, int> PII;
//typedef vector<LL> VI;
//typedef pair<LL, LL> PLL;
//
//const int INF = 1000 * 1000 * 1000;
//const LL LINF = 1LL * INF * INF;
//const int MAX = 100010;
//const long double PI = acos(-1.);
//const double EPS = 1e-6;
//const LL MOD = 998244353;
//
//
//int n, k;
//
//LL fact[1003];
//LL ober[1003];
//
//LL binpow(LL x, int n)
//{
//	LL res = 1;
//	while (n)
//	{
//		if (n % 2)
//			res = res * x % MOD;
//		x = x * x % MOD;
//		n /= 2;
//	}
//	return res;
//}
//
//
//LL C(int n, int k)
//{
//	return fact[n] * ober[n - k] % MOD * ober[k] % MOD;
//}
//
//LL dpT[1003][1003];
//LL val[1003];
//
//LL dp(int pos, int x)
//{
//	if (pos == n)
//	{
//		return (x==k);
//	}
//	if (dpT[pos][x] != -1)
//		return dpT[pos][x];
//	LL res = 0;
//	res = dp(pos + 1, x);
//	if (x != k)
//		res = res + dp(pos + 1, x + 1) * val[pos]%MOD;
//	if (res >= MOD)
//		res -= MOD;
//	return dpT[pos][x] = res;
//}
//
//
//
//int main()
//{
//	ios_base::sync_with_stdio(0);
//	//freopen("input.txt", "r", stdin);
//	//freopen("output.txt", "w", stdout);
//
//	map<LL, LL> a;
//	cin >> n >> k;
//	FOR(i, 0, n)
//	{
//		int x;
//		cin >> x;
//		a[x]++;
//	}
//
//	fact[0] = 1;
//	ober[0] = 1;
//
//	FOR(i, 1, 1003)
//	{
//		fact[i] = fact[i - 1] * i % MOD;
//		ober[i] = binpow(fact[i], MOD - 2);
//	}
//	
//	if (a.size() < k)
//	{
//		cout << 0 << endl;
//		return 0;
//	}
//
//	FILL(dpT, -1);
//	n = 0;
//	for (auto& iter : a)
//	{
//		val[n++] = iter.second;
//	}
//	cout << dp(0, 0) << endl;
//
//
//
//	return 0;
//}
//
