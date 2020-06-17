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
//using namespace std;
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
//
//int dx[] = { 1, -1, 0, 0 };
//int dy[] = { 0, 0, 1, -1 };
//
//string abc = "EWNS";
//
//void solve()
//{
//	int tx, ty;
//	cin >> tx >> ty;
//	string s;
//	cin >> s;
//	int n = s.size();
//	int best = n;
//	int x = tx;
//	int y = ty;
//	FOR(i, 0, n - 1)
//	{
//		FOR(k, 0, 4)
//		{
//			if (s[i] == abc[k])
//			{
//				x += dx[k];
//				y += dy[k];
//			}
//		}
//		int dst = abs(x) + abs(y);
//		if (dst <= i + 1)
//		{
//			cout << dst << endl;
//			return;
//		}
//	}
//	cout << "IMPOSSIBLE" << endl;
//}
//int main()
//{
//	ios_base::sync_with_stdio(0);
//	//freopen("input.txt", "r", stdin);
//	//freopen("output.txt", "w", stdout);
//	int t;
//	cin >> t;
//	int tt = 1;
//	while (t--)
//	{
//		cout << "Case #" << tt++ << ": ";
//		solve();
//	}
//	return 0;
//}
//
