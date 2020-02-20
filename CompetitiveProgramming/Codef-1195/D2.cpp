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
//const LL mod = 998244353;
//
//int n;
//string s[100005];
//LL cnt[10];
//LL p10[100];
//string tt[10];
//
//LL f(const string &s, const string &t)
//{
//	int i1 = SZ(s) - 1;
//	int i2 = SZ(t) - 1;
//	int powar = 0;
//	LL res = 0;
//	bool flag = true;
//	while (i1 >= 0 || i2 >= 0)
//	{
//		if (flag)
//		{
//			if (i1 >= 0)
//			{
//				//cout << i1 << '-' << i2 << ' ' << powar << ' ' << p10[powar] << endl;
//				res += 1LL* (s[i1--] - '0') * p10[powar++] % mod;
//				res %= mod;
//			}
//		}
//		else
//		{
//			if (i2 >= 0)
//			{
//				//cout << i1 << '+' << i2 << ' ' << powar << ' ' << p10[powar] << endl;
//				res += 1LL * (t[i2--] - '0') * p10[powar++] % mod;
//				res %= mod;
//			}
//		}
//		flag = !flag;
//	}
//	return res;
//}
//
//int main()
//{
//	ios_base::sync_with_stdio(0);
//	//freopen("input.txt", "r", stdin);
//	//freopen("output.txt", "w", stdout);
//	cin >> n;
//	FOR(i, 0, n)
//	{
//		cin >> s[i];
//		cnt[SZ(s[i])-1]++;
//	}
//	p10[0] = 1;
//	tt[0] = "0";
//	FOR(i, 1, 10)
//	{
//		tt[i] = tt[i - 1];
//		tt[i] += '0';
//	}
//	FOR(i, 1, 100)
//	{
//		p10[i] = 1LL*p10[i - 1] * 10 % mod;
//	}
//	LL ans = 0;
//	FOR(i, 0, n)
//	{
//		FOR(j, 0, 10)
//		{
//			ans += 1LL * cnt[j] * f(s[i], tt[j]) % mod;
//			ans %= mod;
//			ans += 1LL * cnt[j] * f(tt[j], s[i]) % mod;
//			ans %= mod;
//		}
//	}
//	cout << ans << endl;
//
//
//	return 0;
//}