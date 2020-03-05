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
//typedef vector<int> VI;
//
//const int INF = 1000 * 1000 * 1000;
//const LL LINF = 1LL * INF * INF;
//const int MAX = 100010;
//const long double PI = acos(-1.);
//const double EPS = 1e-6;
//const LL MOD = INF + 7;
//int n, m, p;
//LL a[1000006];
//LL b[1000006];
//vector<LL> aa, bb;
//int main()
//{
//	ios_base::sync_with_stdio(0);
//	//freopen("input.txt", "r", stdin);
//	//freopen("output.txt", "w", stdout);
//	cin >> n >> m >> p;
//	FOR(i, 0, n)
//	{
//		cin >> a[i];
//		if (a[i] % p != 0)
//		{
//			aa.PB(i);
//		}
//	}
//	FOR(i, 0, m)
//	{
//		cin >> b[i];
//		if (b[i] % p != 0)
//		{
//			bb.PB(i);
//		}
//	}
//	int kk = aa[0] + bb[0];
//	FOR(i, 0, aa.size())
//	{
//		FOR(j, 0, bb.size())
//		{
//			LL cur = 0;
//			FOR(i, 0, n)
//			{
//				j = kk - i;
//				if (j >= 0 && j < m)
//				{
//					cur += a[i] * b[j] % p;
//					if (cur >= p)
//						cur -= p;
//				}
//			}
//			if (cur)
//			{
//				cout << kk << endl;
//				return 0;
//			}
//		}
//	}
//
//
//
//
//	return 0;
//}
//
