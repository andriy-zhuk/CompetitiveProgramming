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
//int n;
//LL a[40];
//
//vector<LL> make(int l, int r)
//{
//	vector<LL> ret;
//	int n = r - l + 1;
//
//	FOR(i, 0, (1 << n))
//	{
//		LL suma = 0;
//		FOR(j, 0, n)
//		{
//			if (i & (1 << j))
//				suma += a[l + j];
//			else
//				suma -= a[l + j];
//		}
//		ret.PB(suma);
//	}
//	return ret;
//}
//
//int main()
//{
//	ios_base::sync_with_stdio(0);
//	//freopen("input.txt", "r", stdin);
//	//freopen("output.txt", "w", stdout);
//	cin >> n;
//	FOR(i, 0, n)
//	{
//		cin >> a[i];
//	}
//	vector<LL> a1 = make(0, n / 2);
//	vector<LL> a2 = make(n / 2 + 1, n - 1);
//	LL best = LINF;
//	sort(ALL(a2));
//	FOR(i, 0, a1.size())
//	{
//		int p = lower_bound(ALL(a2), -a1[i]) - a2.begin();
//
//		FOR(k, max(0, p - 2), min(p + 2, (int)a2.size()))
//		{
//			best = min(best, abs(a1[i] + a2[k]));
//		}
//	}
//	cout << best << endl;
//	return 0;
//}
//
