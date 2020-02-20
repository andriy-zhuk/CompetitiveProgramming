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
//const LL MOD = INF + 9;
//
//int b, k;
//LL p2[130];
//
//LL dpT[130][1001][130];
//
//LL dp(int pos, int m, int cnt)
//{
//	if (pos == b)
//	{
//		if (m != 0)
//			return 0;
//		return cnt;
//	}
//	if (dpT[pos][m][cnt] != -1)
//	{
//		return dpT[pos][m][cnt];
//	}
//	LL cur = 0;
//	
//	cur = cur + dp(pos + 1, (m + p2[pos]) % k, cnt + 1);
//	if (cur >= MOD)
//		cur -= MOD;
//	cur = cur + dp(pos + 1, m, cnt);
//	if (cur >= MOD)
//		cur -= MOD;
//	return dpT[pos][m][cnt] = cur;
//}
//
//int main()
//{
//	ios_base::sync_with_stdio(0);
//	//freopen("input.txt", "r", stdin);
//	//freopen("output.txt", "w", stdout);
//	cin >> k >> b;
//	p2[0] = 1;
//	FOR(i,1,b)
//	{
//		p2[i] = p2[i - 1] * 2 % k;
//	}
//	FILL(dpT, -1);
//	cout << dp(0, 0,0)<< endl;
//
//	return 0;
//}
//
