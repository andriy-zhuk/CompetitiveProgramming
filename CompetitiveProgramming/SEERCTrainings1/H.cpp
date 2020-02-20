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
//int a[200005];
//
//namespace MO
//{
//	const int magic = 450;
//	LL cnt[1000 * 1000 + 7];
//	LL suma = 0;
//	int l = 0, r = 0;
//	void INCL()
//	{
//		suma -= cnt[a[l]] * cnt[a[l]] * a[l];
//		cnt[a[l]]--;
//		suma += cnt[a[l]] * cnt[a[l]] * a[l];
//		l++;
//	}
//	void DECL()
//	{
//		l--;
//		suma -= cnt[a[l]] * cnt[a[l]] * a[l];
//		cnt[a[l]]++;
//		suma += cnt[a[l]] * cnt[a[l]] * a[l];
//	}
//	void INCR()
//	{
//		r++;
//		suma -= cnt[a[r]] * cnt[a[r]] * a[r];
//		cnt[a[r]]++;
//		suma += cnt[a[r]] * cnt[a[r]] * a[r];
//	}
//	void DECR()
//	{
//		suma -= cnt[a[r]] * cnt[a[r]] * a[r];
//		cnt[a[r]]--;
//		suma += cnt[a[r]] * cnt[a[r]] * a[r];
//		r--;
//	}
//	LL ans[200005];
//	vector<pair<pair<int, int>, int> > blocks[magic];
//	bool cmp(pair<PII, int>& a, pair<PII, int>& b)
//	{
//		if (a.first.second == b.first.second)
//			return a < b;
//		return a.first.second < b.first.second;
//	}
//	void calc()
//	{
//		FOR(i, 0, magic)
//		{
//			FOR(j, 0, blocks[i].size())
//			{
//				int curl = blocks[i][j].first.first;
//				int curr = blocks[i][j].first.second;
//				int id = blocks[i][j].second;
//				while (l < curl)
//				{
//					INCL();
//				}
//				while (l > curl)
//				{
//					DECL();
//				}
//				while (r < curr)
//				{
//					INCR();
//				}
//				while (r > curr)
//				{
//					DECR();
//				}
//				ans[id] = suma;
//			}
//		}
//
//	}
//
//}
//
//
//
//
//
//int main()
//{
//	ios_base::sync_with_stdio(0);
//	//freopen("input.txt", "r", stdin);
//	//freopen("output.txt", "w", stdout);
//
//	int n,m ;
//	cin >> n >> m;
//	FOR(i, 0, n)
//	{
//		cin >> a[i+1];
//	}
//	FOR(i, 0, m)
//	{
//		int l, r;
//		cin >> l >> r;
//		MO::blocks[l/MO::magic].PB(MP(MP(l, r), i));
//	}
//	FOR(i, 0, MO::magic)
//		sort(ALL(MO::blocks[i]), &MO::cmp);
//
//	MO::calc();
//
//	FOR(i, 0, m)
//	{
//		cout << MO::ans[i] << endl;
//	}
//	return 0;
//}
//
