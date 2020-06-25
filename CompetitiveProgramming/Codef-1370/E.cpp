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
//string s, t;
//int n;
//
//
//int main()
//{
//	ios_base::sync_with_stdio(0);
//	//freopen("input.txt", "r", stdin);
//	//freopen("output.txt", "w", stdout);
//	cin >> n;
//	cin >> s >> t;
//	int c1 = 0;
//	int c2 = 0;
//	FOR(i, 0, n)
//	{
//		if (s[i] == '1')
//			c1++;
//		if (t[i] == '1')
//			c2++;
//	}
//	if (c1 != c2)
//	{
//		cout << -1 << endl;
//		return 0;
//	}
//	string q = "";
//	FOR(i, 0, n)
//	{
//		if (s[i] != t[i])
//		{
//			q += s[i];
//		}
//	}
//	if (q.size() == 0)
//	{
//		cout << 0 << endl;
//		return 0;
//	}
//	int best = 0;
//	int cur = 0;
//	int best2 = 0;
//	FOR(i, 0, q.size())
//	{
//		if (q[i] == '0')
//		{
//			cur--;
//		}
//		else
//		{
//			cur++;
//		}
//		best2 = min(best2, cur);
//		best = max(best, cur - best2);
//	}
//	cur = 0;
//	best2 = 0;
//	FOR(i, 0, q.size())
//	{
//		if (q[i] == '1')
//		{
//			cur--;
//		}
//		else
//		{
//			cur++;
//		}
//		best2 = min(best2, cur);
//		best = max(best, cur - best2);
//	}
//	cout << best << endl;
//	return 0;
//}
//
