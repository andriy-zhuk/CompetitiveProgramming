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
//const int MAX = 10000007;
//const long double PI = acos(-1.);
//const double EPS = 1e-6;
//const LL MOD = INF + 7;
//
//int a, b;
//int c, d;
//
//int lp[MAX];
//int p[MAX];
//vector<int> pr;
//
//void prec()
//{
//	FILL(lp, 0);
//	for (int i = 2; i < MAX; ++i) {
//		if (lp[i] == 0) {
//			lp[i] = i;
//			pr.push_back(i);
//		}
//		for (int j = 0; j < (int)pr.size() && pr[j] <= lp[i] && i * pr[j] < MAX; ++j)
//		{
//			lp[i * pr[j]] = pr[j];
//		}
//	}
//
//}
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
//	int n;
//	cin >> n;
//
//	prec();
//
//	
//	FOR(i, 4, MAX+1)
//	{
//		if (i % 2 == 1)
//		{
//			continue;
//		}
//		FOR(j, 0, pr.size())
//		{
//			if (pr[j] > i)
//				break;
//			int q = i - pr[j];
//			if (q < pr[j])
//				break;
//			if (lp[q] == q)
//			{
//				p[i] = pr[j];
//				break;
//			}
//		}
//	}
//	int cnt = 0;
//	while (n >= 4)
//	{
//		cnt++;
//		n = n - 2 * p[n];
//	}
//	cout << cnt << endl;
//
//
//
//
//
//	return 0;
//}
//
