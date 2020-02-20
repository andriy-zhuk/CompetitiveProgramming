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
//typedef unsigned long long ULL;
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
//int n;
//PII a[2][100005];
//
//struct ev
//{
//	int x;
//	int open;
//	int id;
//	ev(int _x, int _o, int _id)
//	{
//		x = _x;
//		open = _o;
//		id = _id;
//	}
//	bool operator < (const ev& e)
//	{
//		return MP(x, MP(open, id)) < MP(e.x, MP(e.open, e.id));
//	}
//};
//
//void go()
//{
//	vector<ev> events; // point, open(1)/close(0), id
//
//	FOR(i, 0, n)
//	{
//		int l = a[0][i].first;
//		int r = a[0][i].second;
//		events.PB(ev(l, 1, i));
//		events.PB(ev(r+1, 0, i));
//	}
//	sort(ALL(events));
//	multiset<int> begins;
//	multiset<int> ends;
//	FOR(i, 0, events.size())
//	{
//		int l = a[1][events[i].id].first;
//		int r = a[1][events[i].id].second;
//		if (events[i].open == 0)
//		{
//			begins.erase(begins.lower_bound(l));
//			ends.erase(ends.lower_bound(r));			
//		}
//		else
//		{
//			if (begins.size())
//			{
//				int L = *(--begins.end());
//				int R = *ends.begin();
//				//cout << l << ' ' << r << '+' << L << ' ' << R << endl;
//				if ( not(max(l,L) <= min(r, R)))
//				{
//					cout << "NO" << endl;
//					exit(0);
//				}
//			}
//			begins.insert(l);
//			ends.insert(r);
//		}
//	}
//
//
//}
//
//
//int main()
//{
//	ios_base::sync_with_stdio(0);
//	//freopen("input.txt", "r", stdin);
//	//freopen("output.txt", "w", stdout);
//	cin >> n;
//	vector<PII> foo;
//	FOR(i, 0, n)
//	{
//		cin >> a[0][i].first >> a[0][i].second >> a[1][i].first >> a[1][i].second;
//	}
//	go();
//	FOR(i, 0, n)
//	{
//		swap(a[0][i], a[1][i]);
//	}
//	go();
//	
//	cout << "YES" << endl;
//
//
//
//	return 0;
//}
//
