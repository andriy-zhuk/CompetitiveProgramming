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
//
//int n;
//set<int> g[1003];
//
//int bad[1003];
//int used[1003];
//int ask(int a, int b)
//{
//	cout << "? " << a + 1 << ' ' << b + 1 << endl;
//	int x;
//	cin >> x;
//	return x-1;
//}
//void print(int x)
//{
//	cout << "! " << x + 1 << endl;
//}
//bool find(int a, int& b, int& c)
//{
//	for (auto &iter:g[a])
//	{
//		if (SZ(g[iter]) == 1)
//		{
//			continue;
//		}
//		else
//		{
//			b = iter;
//			for (auto& iter2 : g[b])
//			{
//				if (iter2 == a)
//					continue;
//				c = iter2;
//				return true;
//			}
//		}
//	}
//	return false;
//}
//
//
//vector<int> todel;
//void dfs(int u)
//{
//	if (used[u])
//		return;
//	used[u] = 1;
//	todel.PB(u);
//	for (auto &v:g[u])
//	{
//		if (!used[v])
//		{
//			dfs(v);
//		}
//	}
//}
//void deleteAll(int u)
//{
//	for (auto& v : g[u])
//	{
//		g[v].erase(u);
//	}
//	g[u].clear();
//}
//
//int main()
//{
//	ios_base::sync_with_stdio(0);
//	//freopen("input.txt", "r", stdin);
//	//freopen("output.txt", "w", stdout);
//	cin >> n;
//	int good = n;
//	FOR(i, 0, n-1)
//	{
//		int x, y;
//		cin >> x >> y;
//		x--, y--;
//		g[x].insert(y);
//		g[y].insert(x);
//	}
//	while (good >= 3)
//	{
//		int b, c;
//		b = -1;
//		c = -1;
//		FOR(a, 0, n+1)
//		{
//			if (bad[a])
//			{
//				continue;
//			}
//			if (find(a, b, c))
//			{
//				int w = ask(a, c);
//				used[w] = 2;
//				todel.clear();
//				dfs(a);
//				dfs(b);
//				dfs(c);
//				used[w] = 0;
//				good -= todel.size();
//				FOR(i, 0, todel.size())
//				{
//					int u = todel[i];
//					bad[u] = true;
//					deleteAll(u);
//				}
//				break;
//			}
//		}
//	}
//
//	vector<int> setik;
//	FOR(i, 0, n)
//	{
//		if (!bad[i])
//		{
//			setik.PB(i);
//		}
//	}
//	if (!setik.size())
//	{
//		return -1;
//	}
//	if (setik.size() == 1)
//	{
//		print(setik.back());
//		return 0;
//	}
//	int w = ask(setik[0], setik[1]);
//	print(w);
//	return 0;
//}
//
