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
//const LL MOD = INF + 7;
//
//LL binpow(LL x, LL n)
//{
//	LL res = 1;
//	while (n)
//	{
//		if (n % 2)
//		{
//			res = (res * x) % MOD;
//		}
//		x = (x * x) % MOD;
//		n /= 2;
//	}
//	return res;
//}
//
//LL fact[1000];
//LL ober[1000];
//
//LL n, k;
//
//LL C(int n, int k)
//{
//	return fact[n] * ober[k] % MOD * ober[n - k] % MOD;
//}
//
//int main()
//{
//	ios_base::sync_with_stdio(0);
//	//freopen("input.txt", "r", stdin);
//	//freopen("output.txt", "w", stdout);
//
//	cin >> n >> k;
//
//	fact[0] = 1;
//	ober[0] = 1;
//	FOR(i, 1, 1000)
//	{
//		fact[i] = (fact[i - 1] * i) % MOD;
//		ober[i] = binpow(fact[i], MOD - 2);
//	}
//
//	LL answer = 0;
//	FOR(i, 0, n+1)
//	{
//		FOR(j, 0, n+1)
//		{
//			LL cur = 1;
//			if ((j + i) % 2 == 1)
//				cur = MOD - 1;
//			cur = cur * C(n, i) % MOD * C(n, j) % MOD * binpow(k - 1, n * i + (n - i) * j) % MOD * binpow(k, n * n - n * i - (n - i) * j);
//		//	cout << cur << endl;
//			answer = answer + cur;
//			answer %= MOD;
//		}
//	}
//	cout << answer << endl;
//
//
//	return 0;
//}
//
