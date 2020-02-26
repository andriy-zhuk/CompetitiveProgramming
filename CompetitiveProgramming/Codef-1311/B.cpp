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
//int n,m;
//int a[202];
//bool can[202];
//
//void solve()
//{
//	FILL(can, 0);
//	cin >> n >> m;
//	FOR(i, 0, n)
//	{
//		cin >> a[i];
//	}
//	FOR(j, 0, m)
//	{
//		int x;
//		cin >> x;
//		can[x - 1] = true;
//	}
//	FOR(i, 0, n - 1)
//	{
//		FOR(j, 0, n - i - 1)
//		{
//			if (a[j] > a[j + 1] && can[j])
//			{
//				swap(a[j], a[j + 1]);
//			}
//		}
//	}
//	FOR(i, 0, n - 1)
//	{
//		if (a[i] > a[i + 1])
//		{
//			cout << "NO" << endl; return;
//		}
//	}
//	cout << "YES" << endl;
//
//
//}
//
//int main()
//{
//	ios_base::sync_with_stdio(0);
//	//freopen("input.txt", "r", stdin);
//	//freopen("output.txt", "w", stdout);
//	int t;
//	cin >> t;
//	while (t--)
//	{
//		solve();
//	}
//	return 0;
//}
//