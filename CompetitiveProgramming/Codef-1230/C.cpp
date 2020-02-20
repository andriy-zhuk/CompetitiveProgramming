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
//const LL mod = INF + 7;
//
//int n, m;
//vector<PII> arr;
//vector<int> used;
//vector<PII> e;
//int best = 0;
//int p[10];
//void rec(int n)
//{
//	if (n == 7)
//	{
//		int cur = 0;
//		FOR(i, 0, used.size())
//		{
//			used[i] = false;
//		}
//		FOR(i, 0, e.size())
//		{
//			FOR(j, 0, arr.size())
//			{
//				if (arr[j] == MP(p[e[i].first], p[e[i].second]) && used[j] == false)
//				{
//					used[j] = true;
//					cur++;
//				}
//			}
//		}
//		best = max(best, cur);
//		return;
//	}
//	FOR(i, 0, 6)
//	{
//		p[n] = i;
//		rec(n + 1);
//	}
//}
//
//int main()
//{
//	ios_base::sync_with_stdio(0);
//	//freopen("input.txt", "r", stdin);
//	//freopen("output.txt", "w", stdout);
//
//	cin >> n >> m;
//	if (n <= 6)
//	{
//		cout << m << endl;
//		return 0;
//	}
//
//	FOR(i, 0, m)
//	{
//		int x, y;
//		cin >> x >> y;
//		x--, y--;
//		e.emplace_back(min(x, y), max(x,y));
//	}
//
//	FOR(i, 1, 7)
//	{
//		FOR(j, i, 7)
//		{
//			arr.emplace_back(i-1, j-1);
//			used.PB(0);
//		}
//	}
//
//	rec(0);
//	cout << best << endl;
//	
//
//
//	return 0;
//}
//
