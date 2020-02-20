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
//const int MAX = 100005;
//const long double PI = acos(-1.);
//const double EPS = 1e-6;
//const LL mod = INF + 7;
//
//struct point
//{
//	int x, y, z;
//};
//vector<point> pts;
//
//vector<pair<PII, int> > pet[100005];
//vector<PII> cur[100005];
//vector<int> ans;
//vector<int> trash;
//
//void act(vector<pair<PII, int> > &a)
//{
//	vector<int> t2;
//	t2.clear();
//	FOR(i, 0, a.size())
//	{
//		if (i != a.size() - 1 && a[i].first.first == a[i + 1].first.first)
//		{
//			ans.PB(a[i].second);
//			ans.PB(a[i + 1].second);
//			++i;
//		}
//		else
//		{
//			t2.PB(a[i].second);
//		}
//		if (t2.size() >= 2)
//		{
//			ans.PB(t2[0]);
//			ans.PB(t2[1]);
//			t2.clear();
//		}
//	}
//	if(t2.size())
//		trash.PB(t2[0]);
//	t2.clear();
//}
//
//
//
//int main()
//{
//	ios_base::sync_with_stdio(0);
//	//freopen("input.txt", "r", stdin);
//	//freopen("output.txt", "w", stdout);
//	int n;
//	cin >> n;
//	vector<PII> foo;
//	FOR(i, 0, n)
//	{
//		int x, y, z;
//		cin >> x >> y >> z;
//		pts.PB({ x,y,z });
//		foo.PB(MP(z, i));
//	}
//	int cur = 0;
//	sort(ALL(foo));
//	FOR(i, 0, n)
//	{
//		if (i && foo[i].f != foo[i - 1].first)
//		{
//			cur++;
//		}
//		pts[foo[i].s].z = cur;
//	}
//	
//	FOR(i, 0, n)
//	{
//		pet[pts[i].z].PB(MP(MP(pts[i].x, pts[i].y), i));
//	}
//
//	FOR(i, 0, MAX)
//	{
//		sort(ALL(pet[i]));
//	}
//	FOR(i, 0, MAX)
//	{
//		act(pet[i]);
//		if (trash.size() >= 2)
//		{
//			ans.PB(trash[0]);
//			ans.PB(trash[1]);
//			trash.clear();
//		}
//	}
//
//	
//	FOR(i, 0, n / 2)
//	{
//		cout << ans[2 * i] + 1 << ' ' << ans[2 * i + 1] + 1 << endl;
// 	}
//
//	return 0;
//}
//
