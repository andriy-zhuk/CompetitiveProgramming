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
//int n;
//int a[100005];
//int b[100005];
//
//namespace FEN
//{
//	int n = 100005;
//	vector<int> t(100005, 0);
//	int sum(int r)
//	{
//		int result = 0;
//		for (; r >= 0; r = (r & (r + 1)) - 1)
//			result += t[r];
//		return result;
//	}
//
//	void inc(int i, int delta)
//	{
//		for (; i < n; i = (i | (i + 1)))
//			t[i] += delta;
//	}
//}
//
//int main()
//{
//	ios_base::sync_with_stdio(0);
//	//freopen("input.txt", "r", stdin);
//	//freopen("output.txt", "w", stdout);
//	int suma = 0;
//	cin >> n;
//	FOR(i, 0, n)
//	{
//		int x;
//		cin >> x;
//		x--;
//		a[x] = i;
//	}
//	FOR(i, 0, n)
//	{
//		int y;
//		cin >> y;
//		y--;
//		b[i] = a[y];
//	}
//	int ans = 0;
//	FOR(i, 0, n)
//	{
//		int x = FEN::sum(b[i]);
//		if (x != b[i])
//		{
//			ans++;
//		}
//		FEN::inc(b[i], 1);
//	}
//	cout << ans << endl;
//
//	return 0;
//}
//
