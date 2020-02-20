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
//int n, m, k;
//int a[105][105];
//int ans[105][105];
//
//char get(int i)
//{
//	if (i <= 25)
//	{
//		return char('a' + i);
//	}
//	i -= 26;
//	if (i <= 25)
//	{
//		return char('A' + i);
//	}
//	i -= 26;
//	return char('0' + i);
//}
//void solve()
//{
//	cin >> n >> m >> k;
//	int suma = 0;
//	FOR(i, 0, n)
//	{
//		string s;
//		cin >> s;
//
//		FOR(j, 0, m)
//		{
//			if (s[j] == '.')
//			{
//				a[i][j] = 0;
//			}
//			else
//			{
//				a[i][j] = 1;
//			}
//			suma += a[i][j];
//			ans[i][j] = -1;
//		}
//	}
//
//	int cur = 0;
//	int need = suma / k;
//
//	int col = 0;
//	FOR(i, 0, n)
//	{
//		if (i%2)
//		{
//			RFOR(j, m, 0)
//			{
//				cur += a[i][j];
//				ans[i][j] = col;
//				if (col != k-1 && cur == need)
//				{
//					suma -= cur;
//					cur = 0;
//					col++;
//					need = suma / (k-col);
//				}
//			}
//		}
//		else
//		{
//			FOR(j, 0, m)
//			{
//				cur += a[i][j];
//				ans[i][j] = col;
//				if (col != k-1 && cur == need)
//				{
//					suma -= cur;
//					cur = 0;
//					col++;
//					need = suma / (k-col);
//				}
//			}
//		}
//	}
//
//	FOR(i, 0, n)
//	{
//		FOR(j, 0, m)
//		{
//			cout << get(ans[i][j]);
//		}
//		cout << endl;
//	}
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
