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
//typedef unsigned long long ULL;
//
//const int INF = 1000 * 1000 * 1000;
//const LL LINF = 1LL * INF * INF;
//const int MAX = 100010;
//const long double PI = acos(-1.);
//const double EPS = 1e-6;
//const LL mod = INF + 7;
//
//ULL pref[64];
//ULL suf[64];
//const int sizbts = 100064 / 64;
//
//void init()
//{
//	pref[0] = 1;
//	FOR(i, 1, 64)
//	{
//		pref[i] = pref[i - 1] | (1LL << i);
//	}
//	suf[0] = (1LL << 63);
//	RFOR(i, 63, 0)
//	{
//		suf[i] = suf[i + 1] | (1LL << i);
//	}
//}
//struct bts
//{
//	ULL a[sizbts];
//	void init()
//	{
//		FILL(a, 0);
//	}
//	void set(int l, int r)
//	{
//		while (l <= r && (l % 64 != 0))
//		{
//			a[l / 64] ^= (1LL << (63 - l % 64));
//			l++;
//		}
//		while (l <= r && (r % 64 != 63))
//		{
//			a[r / 64] ^= (1LL << (63 - r % 64));
//			r--;
//		}
//		while (l < r)
//		{
//			a[l / 64] ^= pref[63];
//			l += 64;
//		}
//	}
//
//
//	void print(int n)
//	{
//		FOR(i, 0, n)
//		{
//			if (a[i / 64] & (1LL << (63 - i % 64)))
//			{
//				cout << 1;
//			}
//			else
//			{
//				cout << 0;
//			}
//		}
//		cout << endl;
//	}
//	bool less(const bts& r)
//	{
//		FOR(i, 0, sizbts)
//		{
//			if (a[i]< r.a[i])
//			{
//				return true;
//			}
//			if (a[i] > r.a[i])
//			{
//				return false;
//			}
//		}
//		return false;
//	}
//	void assign(const bts& r)
//	{
//		FOR(i, 0, sizbts)
//		{
//			a[i] = r.a[i];
//		}
//	}
//};
//
//
//int main()
//{
//	ios_base::sync_with_stdio(0);
//	freopen("input.txt", "r", stdin);
//	//freopen("output.txt", "w", stdout);
//	init();
//	bts best;
//	best.init();
//	bts cur;
//	cur.init();
//
//	int n, m;
//	cin >> n >> m;
//	while (m--)
//	{
//		int l, r;
//		cin >> l >> r;
//		l--, r--;
//		cur.set(l, r);
//		if (best.less(cur))
//		{
//			best.assign(cur);
//		}
//	}
//	best.print(n);
//
//
//
//	return 0;
//}