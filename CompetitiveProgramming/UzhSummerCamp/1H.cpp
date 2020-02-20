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
//
//int dpT[100005][1 << 8];
//int dp2[100005][1 << 8];
//vector<int> g[100005];
//int n, k;
//vector<int> sub[1<<8];
//
//int ober(int ms)
//{
//	int res = 0;
//	FOR(i, 0, k - 1)
//	{
//		if (ms & (1 << i))
//		{
//			res |= (1 << (k - 2 - i));
//		}
//	}
//	return res;
//}
//void prec()
//{
//	FOR(mask, 0, (1 << (k-1)))
//	{
//		for (int s = mask; ; s = (s - 1) & mask)
//		{
//			sub[mask].PB(s);
//			if (s == 0)  break;
//		}
//	}
//}
//
//int ones;
//void dp(int u, int p)
//{
//	if (p != -1 && g[u].size() == 1)
//	{
//		FOR(i, 0, (1 << k))
//			dpT[u][i] = i & 1;
//		return;
//	}
//	FOR(i, 0, SZ(g[u]))
//	{
//		int v = g[u][i];
//		if (v == p)
//			continue;
//		dp(v, u);
//	}
//	int prev = -1;
//	FOR(i, 0, SZ(g[u]))
//	{
//		int v = g[u][i];
//		if (v == p)
//			continue;
//		FOR(mask, 0, (1 << k))
//		{
//			int m = ober(mask >> 1) ^ ones;
//			if (prev == -1)
//			{
//				FOR(i, 0, sub[m].size())
//				{
//					int sm = sub[m][i];
//					int mn = (mask >> 1);
//					dp2[v][mn | sm] = max(dp2[v][mn|sm], dpT[v][sm]);
//					if (not(mask & 1))
//					{
//						mn |= (1 << (k - 1));
//						dp2[v][mn | sm] = max(dp2[v][mn | sm], dpT[v][sm]);
//						dp2[v][mn | sm] = max(dp2[v][mn | sm], dpT[v][sm | (1<<(k-1))]);
//
//					}
//				}
//			}
//			else
//			{
//				FOR(i, 0, sub[m].size())
//				{
//					int sm = sub[m][i];
//					int mn = (mask >> 1);
//	 				dp2[v][mn | sm] = max(dp2[v][mn|sm], dp2[prev][mn] + dpT[v][sm]);
//					if (not(mask & 1))
//					{
//						mn |= (1 << (k - 1));
//						dp2[v][mn | sm] = max(dp2[v][mn | sm], dp2[prev][mn] + dpT[v][sm]);
//						dp2[v][mn | sm] = max(dp2[v][mn | sm], dp2[prev][mn] + dpT[v][sm ^ (1 << (k - 1))]);
//					}
//				}
//			}
//		}
//		prev = v;
//	}
//	FOR(mask, 0, 1 << k)
//	{
//		int mm = mask >> 1;
//		dpT[u][mask] = dp2[prev][mm];
//		if (not (mask & 1))
//		{
//			mm |= (1 << (k - 1));
//			dpT[u][mask] = max(dpT[u][mask], dp2[prev][mm]);
//		}
//		dpT[u][mask] += (mask & 1);	
//	}
//}
//
//
//int main()
//{
//	ios_base::sync_with_stdio(0);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
//	cin >> n >> k;
//	FOR(i, 0, n - 1)
//	{
//		int a, b;
//		cin >> a >> b;
//		a--; b--;
//		g[a].PB(b);
//		g[b].PB(a);
//	}
//	FILL(dpT, -1);
//	ones = (1 << (k - 1)) - 1;
//	prec();
//
//	int res = 0;
//	dp(0, -1);
//	FOR(i, 0, (1 << k))
//	{
//		res = max(res, dpT[0][i]);
//	}
//	cout << res << endl;
//	return 0;
//
//
//
//}
//
//
//
//
//8 3
//1 2
//1 3
//3 4
//3 5
//3 6
//6 7
//6 8
//
//
