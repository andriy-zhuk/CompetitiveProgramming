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
//const LL mod = INF + 6;
//
//int T;
//int n, m;
//int d[55][55];
//vector<pair<PII, int>> input;
//
//int main()
//{
//	ios_base::sync_with_stdio(0);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
//	cin >> T;
//	int tt = 1;
//	while (T--)
//	{
//		cin >> n >> m;
//		input.clear();
//		FOR(i, 0, 55)
//		{
//			FOR(j, 0, 55)
//			{
//				d[i][j] = INF;
//			}
//			d[i][i] = 0;
//		}
//		FOR(i, 0, m)
//		{
//			int x, y, z;
//			cin >> x >> y >> z;
//			x--, y--;
//			d[x][y] = d[y][x] = z;
//			input.PB(MP(MP(x, y), z));
//		}
//		FOR(k, 0, n)
//		{
//			FOR(i, 0, n)
//			{
//				FOR(j, 0, n)
//				{
//					d[i][j] = min(d[i][k] + d[k][j], d[i][j]);
//				}
//			}
//		}
//		bool ok = true;
//		FOR(i, 0, SZ(input))
//		{
//			if (d[input[i].first.first][input[i].first.second] != input[i].second)
//			{
//				ok = false;
//			}
//		}
//		cout << "Case #" << tt++ << ": ";
//		if (ok)
//		{
//			cout << SZ(input) << endl;
//			FOR(i, 0, SZ(input))
//			{
//				cout << input[i].first.first + 1 << ' ' << input[i].f.second + 1 << ' ' << input[i].second << endl;
//			}
//		}
//		else
//		{
//			cout << "Impossible" << endl;
//		}
//	}
//	return 0;
//}