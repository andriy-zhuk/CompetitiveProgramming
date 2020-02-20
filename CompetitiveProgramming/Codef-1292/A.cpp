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
//int n, q;
//
//
//int used[2][100005];
//
//int ok(int x, int y)
//{
//	if (x >= 0 && x < 2 && y >= 0 && y < n)
//		return used[x][y] == 0;
//	else
//		return 1;
//}
//int flag[100005];
//bool check(int x, int y) // naoborot, xd
//{
//	if (y == 0 && ok(0, x - 1) && ok(0, x) && ok(0, x + 1))
//	{
//		return true;
//	}
//	if (y == 1 && ok(1, x - 1) && ok(1, x) && ok(1, x + 1))
//	{
//		return true;
//	}
//	if (ok(0, x - 1) && ok(0, x) && ok(1, x) && ok(1, x + 1))
//	{
//		return true;
//	}
//	if (ok(1, x - 1) && ok(1, x) && ok(0, x) && ok(0, x + 1))
//	{
//		return true;
//	}
//	return false;
//}
//
//int open;
//void upd(int x, int y, bool change)
//{
//	if (y >= n || y < 0)
//		return;
//	if (used[x][y] == 0)
//	{
//		if (change)
//			used[x][y] = 1;
//		
//	}
//	else
//	{
//		if (change)
//			used[x][y] = 0;
//	}
//	if (!check(y, x) && !check(y, 1-x))
//	{
//		if (flag[y] == 0)
//		{
//			flag[y] = 1;
//			open--;
//		}
//	}
//	if (check(y, 1 - x) || check(y, x))
//	{
//		if (flag[y] == 1)
//		{
//			flag[y] = 0; // nwal == 1;
//			open++;
//		}
//	}
//}
//
//int main()
//{
//	ios_base::sync_with_stdio(0);
//	//freopen("input.txt", "r", stdin);
//	//freopen("output.txt", "w", stdout);
//	cin >> n >> q;
//	open = n;
//	FOR(i, 0, q)
//	{
//		int x, y;
//		cin >> x >> y;
//		x--, y--;
//		upd(x, y, true);
//		upd(x, y - 1, false);
//		upd(x, y + 1, false);
//	
//		if (open == n)
//		{
//			cout << "YES" << endl;
//		}
//		else
//		{
//			cout << "NO" << endl;
//		}
//	}
//
//
//
//
//	return 0;
//}
//
