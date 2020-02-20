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
//typedef vector<LL> VI;
//typedef pair<LL, LL> PLL;
//
//const int INF = 1000 * 1000 * 1000;
//const LL LINF = 1LL * INF * INF;
//const int MAX = 100010;
//const long double PI = acos(-1.);
//const double EPS = 1e-6;
//const LL MOD = INF + 7;
//int n, m;
//int a[505][505];
//int cur[4];
//int nxtR[4][505][505];
//int nxtD[4][505][505];
//int pref[4][505][505];
//vector<pair<int, PII> > foo;
//int q;
//vector<pair<pair<PII, PII>, int> > zap;
//int p[505][505];
//
//int get(int col, PII a, PII b)
//{
//	int res = pref[col][b.first][b.second];
//	if (a.first)
//		res -= pref[col][a.first - 1][b.second];
//	if (a.second)
//		res -= pref[col][b.first][a.second - 1];
//	if (a.first && a.second)
//		res += pref[col][a.first - 1][a.second - 1];
//	return res;
//}
//
//int get(PII a, PII b)
//{
//	int res = p[b.first][b.second];
//	if (a.first)
//		res -= p[a.first - 1][b.second];
//	if (a.second)
//		res -= p[b.first][a.second - 1];
//	if (a.first && a.second)
//		res += p[a.first - 1][a.second - 1];
//	return res;
//}
//
//
//int main()
//{
//	ios_base::sync_with_stdio(0);
//	//freopen("input.txt", "r", stdin);
//	//freopen("output.txt", "w", stdout);
//	cin >> n >> m >> q;
//	FOR(i, 0, n)
//	{
//		string s;
//		cin >> s;
//		FOR(j, 0, m)
//		{
//			if (s[j] == 'R')
//			{
//				a[i][j] = 0;
//			}
//			if (s[j] == 'G')
//			{
//				a[i][j] = 1;
//			}
//			if (s[j] == 'Y')
//			{
//				a[i][j] = 3;
//			}
//			if (s[j] == 'B')
//			{
//				a[i][j] = 2;
//			}
//		}
//	}
//	// 0 1
//	// 3 2
//
//	FOR(i, 0, n)
//	{
//		FILL(cur, -1);
//		RFOR(j, m, 0)
//		{
//			FOR(k, 0, 4)
//			{
//				nxtR[k][i][j] = cur[k];
//			}
//			cur[a[i][j]] = j;
//		}
//	}
//	FOR(j, 0, m)
//	{
//		FILL(cur, -1);
//		RFOR(i, n, 0)
//		{
//			FOR(k, 0, 4)
//			{
//				nxtD[k][i][j] = cur[k];
//			}
//			cur[a[i][j]] = i;
//		}
//	}
//	FOR(i, 0, n)
//	{
//		FOR(j, 0, m)
//		{
//			FOR(k, 0, 4)
//			{
//				pref[k][i][j] += (k == a[i][j]);
//				if (i)
//					pref[k][i][j] += pref[k][i - 1][j];
//				if (j)
//					pref[k][i][j] += pref[k][i][j - 1];
//				if (i && j)
//					pref[k][i][j] -= pref[k][i - 1][j - 1];
//			}
//		}
//	}
//
//
//
//	FOR(i, 0, n)
//	{
//		FOR(j, 0, m)
//		{
//			if (a[i][j] == 0)
//			{
//				int g = nxtR[1][i][j];
//				int y = nxtD[3][i][j];
//				if (y == -1 || g == -1 || y-i != g-j)
//				{
//					continue;
//				}
//				int b = nxtR[2][y][j];
//				if (b == -1 || b != g)
//					continue;
//				int w = y - i;
//				if (get(0, MP(i, j), MP(i + w - 1, j + w - 1)) != w * w)
//					continue;
//				if (get(1, MP(i, j + w), MP(i + w - 1, j + 2 * w - 1)) != w * w)
//					continue;	
//				if (get(2, MP(i + w, j + w), MP(i + 2 * w - 1, j + 2 * w - 1)) != w * w)
//					continue;
//				if (get(3, MP(i + w, j), MP(i + 2 * w - 1, j + w - 1)) != w * w)
//					continue;
//				foo.PB(MP(2*w, MP(i, j)));
//			}
//		}
//	}
//	sort(ALL(foo));
//	while (q--)
//	{
//		PII a, b;
//		cin >> a.first >> a.second >> b.first >> b.second;
//		a.first--;
//		a.second--;
//		b.first--;
//		b.second--;
//		zap.PB(MP(MP(a, b), 0));
//	}
//	reverse(ALL(foo));
//	FILL(a, 0);
//	FILL(p, 0);
//	for (int d = 2; d <= 500; d += 2)
//	{
//		
//
//		int cnt = 0;
//		while (foo.size() && foo.back().first == d)
//		{
//			cnt++;
//			a[foo.back().second.first][foo.back().second.second] = 1;
//			foo.pop_back();
//		}
//		if (cnt == 0)
//			continue;
//
//		FOR(i, 0, n)
//		{
//			FOR(j, 0, m)
//			{
//				p[i][j] = a[i][j];
//				if (i)
//					p[i][j] += p[i - 1][j];
//				if (j)
//					p[i][j] += p[i][j - 1];
//				if (i && j)
//					p[i][j] -= p[i - 1][j - 1];
//			}
//		}
//
//		FOR(i, 0, zap.size())
//		{
//			PII a = zap[i].first.first;
//			PII b = zap[i].first.second;
//			b.first -= d-1;
//			b.second -= d-1;
//			if (a.first > b.first || a.second > b.second)
//				continue;
//			int x = get(a, b);
//			if (x)
//				zap[i].second = d;
//		}
//		FILL(a, 0);
//		FILL(p, 0);
//	}
//
//	FOR(i, 0, zap.size())
//	{
//		cout << zap[i].second*zap[i].second << endl;
//	}
//	
//
//
//
//
//
//
//	return 0;
//}
//
