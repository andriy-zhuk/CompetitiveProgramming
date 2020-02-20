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
//int n;
//LL s[200005];
//priority_queue<pair<int, LL> > Q;
//map<LL, int> conv;
//vector<int> foo[200005];
//int cnt = 0;
//int a[200005];
//int ans[200005];
//int main()
//{
//	ios_base::sync_with_stdio(0);
//	//freopen("input.txt", "r", stdin);
//	//freopen("output.txt", "w", stdout);
//	cin >> n;
//	FOR(i, 0, n)
//	{
//		cin >> s[i];
//		if (s[i] == 0)
//		{
//			Q.push(MP(i, s[i]));
//		}
//		if (conv.count(s[i]) == 0)
//		{
//			conv[s[i]] = cnt++;
//		}
//		a[i] = conv[s[i]];
//		foo[a[i]].PB(i);
//	}
//	foo[0].clear();
//	int curNum = 1;
//	LL suma = 0;
//	FOR(i, 0, n)
//	{
//		if (s[i] == suma && ans[i] == 0)
//		{
//			while (foo[a[i]].size())
//			{
//				int pos = foo[a[i]].back();
//				Q.push(MP(pos, s[pos]));
//				foo[a[i]].pop_back();
//			}
//		}
//		while (Q.size())
//		{
//			pair<int, LL> cur = Q.top();
//			Q.pop();
//			ans[cur.first] = curNum;
//			LL x = cur.second + (curNum);
//			if (conv.count(x))
//			{
//				int y = conv[x];
//				while (foo[y].size() && foo[y].back() >= cur.first)
//				{
//					int pos = foo[y].back();
//					Q.push(MP(pos, s[pos]));
//					foo[y].pop_back();
//				}
//			}
//			curNum++;
//		}
//		suma += ans[i];
//	}
//
//	cout << curNum << endl;
//	FOR(i, 0, n)
//	{
//		cout << ans[i] << ' ' ;
//	}
//	
//
//
//
//
//	return 0;
//}