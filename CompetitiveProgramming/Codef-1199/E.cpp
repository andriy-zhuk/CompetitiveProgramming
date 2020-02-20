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
//int T;
//int n, m;
//int ans[100005];
//int nn;
//int used[300005];
//
//int main()
//{
//	ios_base::sync_with_stdio(0);
//	cin.tie(NULL);
//	//freopen("input.txt", "r", stdin);
//	//freopen("output.txt", "w", stdout);
//
//	cin >> T;
//
//	while (T--)
//	{
//		nn = 0;
//		cin >> n >> m;
//		FOR(i, 0, m)
//		{
//			int x, y;
//			cin >> x >> y;
//			x--, y--;
//			if (x > y)
//				swap(x, y);
//			if (!used[x] && !used[y] && nn < n)
//			{
//				ans[nn++] = i + 1;
//				used[x] = 1;
//				used[y] = 1;
//			}
//		}
//		if (nn == n)
//		{
//			cout << "Matching" << endl;
//			FOR(i, 0, n)
//			{
//				cout << ans[i] << ' ';
//			}
//			cout << endl;
//		}
//		else
//		{
//			int nn = 0;
//			cout << "IndSet" << endl;
//			FOR(i, 0, 3 * n)
//			{
//				if (!used[i] && nn < n)
//				{
//					nn++;
//					cout << i + 1 << ' ';
//				}
//			}
//			cout << endl;
//		}
//		FOR(i, 0, 3 * n)
//		{
//			used[i] = 0;
//		}
//	}
//
//
//
//
//	return 0;
//}