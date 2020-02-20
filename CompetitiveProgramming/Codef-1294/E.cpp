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
//int n, m;
//vector<vector<int>> a;
//
//int cnt[200005];
//int shifts(int need, int cur)
//{
//	if (need == cur)
//		return 0;
//	if (need > cur)
//	{
//		return n + (cur - need);
//	}
//	return cur - need;
//}
//
//int solve(int j)
//{
//	int x = 0;
//	FOR(i, 0, n)
//	{
//		cnt[i] = 0;
//	}
//	FOR(i,0,n)
//	{
//		if (a[i][j] % m != j || a[i][j] >= n*m)
//		{
//			x++;
//			a[i][j] = -1;
//		}
//		else
//		{
//			
//			cnt[shifts(a[i][j] / m, i)]++;
//		}
//	}
//	int best = n;
//	FOR(i, 0, n)
//	{
//		best = min(best, n - x - cnt[i] + i);
//	}
//	return best+x;
//}
//
//int main()
//{
//	ios_base::sync_with_stdio(0);
//	//freopen("input.txt", "r", stdin);
//	//freopen("output.txt", "w", stdout);
//	cin >> n >> m;
//
//	FOR(i, 0, n)
//	{
//		a.PB(vector<int>(m, 0));
//		FOR(j, 0, m)
//		{
//			cin >> a[i][j];
//			a[i][j]--;
//		}
//	}
//	int ans = 0;
//	FOR(i, 0, m)
//	{
//		int cur = solve(i);
//	//	cout << cur << endl;
//		ans += cur;
//	}
//	cout << ans << endl;
//
//
//	return 0;
//}
//
