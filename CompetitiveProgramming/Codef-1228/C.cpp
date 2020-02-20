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
//LL x, n;
//
//vector<pair<LL, int> > foo;
//
//LL gcd(LL a, LL b)
//{
//	if (!a)
//		return b;
//	return gcd(b % a, a);
//}
//
//
//int main()
//{
//	ios_base::sync_with_stdio(0);
//	//freopen("input.txt", "r", stdin);
//	//freopen("output.txt", "w", stdout);
//	cin >> x >> n;
//	LL xx = x;
//	for (LL i = 2; i * i <= xx; ++i)
//	{
//		if (xx % i == 0)
//		{
//			int cnt = 0;
//			while (xx % i == 0)
//			{
//				xx /= i;
//				cnt++;
//			}
//			foo.PB(MP(i, cnt));
//		}
//	}
//	if (xx != 1)
//	{
//		foo.PB(MP(xx, 1));
//	}
//
//	LL ans = 1;
//
//	FOR(i, 0, foo.size())
//	{
//		LL suma = 0;
//		unsigned long long cur = foo[i].first;
//		double curva = foo[i].first;
//		while(true)
//		{
//			if (curva > 1e19)
//			{
//				break;
//			}
//			if (cur > n)
//			{
//				break;
//			}
//			suma += n / cur;
//			cur *= foo[i].first;
//			curva *= foo[i].first;
//		}
//
//		ans = ans * binpow(foo[i].first, suma) % MOD;
//	}
//
//	cout << ans << endl;
//	
//	return 0;
//}
//
