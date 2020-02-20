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
//#include <bitset>
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
//const LL mod = INF + 7;
//
//struct segm
//{
//	PII a, b;
//};
//
//vector<segm> a, b;
//int n;
//int x;
//vector<bitset<5000> > foo;
//
//bool inters(segm a, segm b)
//{
//	//cout << a.a.first << ' ' << a.b.first << endl;
//	if (a.a.first != a.b.first)
//		return 0;
////	cout << a.a.first << ' ' << b.a.first << ' ' << b.b.first << endl << b.a.second << ' ' << a.a.second << ' ' << a.b.second << endl << endl;
//	return (a.a.first <= b.b.first && b.a.first <= a.a.first && b.a.second <= a.b.second && a.a.second <= b.a.second);
//}
//
//
//int main()
//{
//	ios_base::sync_with_stdio(0);
//	//freopen("input.txt", "r", stdin);
//	//freopen("output.txt", "w", stdout);
//
//	cin >> n;
//	FOR(i, 0, n)
//	{
//		int x1, x2, y1, y2;
//		cin >> x1 >> y1 >> x2 >> y2;
//		if (y2 < y1)
//			swap(y1, y2);
//		if (x2 < x1)
//			swap(x1, x2);
//		if (x1 == x2)
//		{
//			a.PB({ MP(x1,y1), MP(x2, y2) });
//		}
//		else
//		{
//			b.PB({ MP(x1,y1), MP(x2, y2) });
//		}
//	}
//
//	if (a.size() > b.size())
//	{
//		swap(a, b);
//	}
//
//	foo.resize(a.size());
//	FOR(i, 0, SZ(a))
//	{
//		FOR(j, 0, SZ(b))
//		{
//			if (inters(a[i], b[j]) || inters(b[j], a[i]))
//			{
//				foo[i].set(j);
//			}
//		}
//	}
//	LL counta = 0;
//	FOR(i1, 0, SZ(a))
//	{
//		FOR(i2, i1 + 1, SZ(a))
//		{
//			int x =	(foo[i1] & foo[i2]).count();
//			counta += (x - 1) * x / 2;
//		}
//	}
//
//	cout << counta << endl;
//
//	return 0;
//}
