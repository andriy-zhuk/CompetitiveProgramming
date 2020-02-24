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
//LL l, r;
//
//int brute()
//{
//	LL ret = 0;
//	FOR(i, l, r + 1)
//	{
//		FOR(j, i, r + 1)
//		{
//			ret = max(ret, 1LL*(i ^ j));
//		}
//	}
//	return ret;
//
//}
//
//int main()
//{
//	ios_base::sync_with_stdio(0);
//	//freopen("input.txt", "r", stdin);
//	//freopen("output.txt", "w", stdout);
//	cin >> l >> r;
//
//	PLL a = MP(l, r);
//	PLL b = MP(l, r);
//	int i = 61;
//	while (i >= 0)
//	{
//		LL x = l & (1LL << i);
//		LL y = r & (1LL << i);
//		if (x == y)
//			i--;
//		else
//			break;
//	}
//	cout << (1LL << (i + 1)) - 1 << endl;
//	//cout << brute() << endl;
//
//	return 0;
//}
//
