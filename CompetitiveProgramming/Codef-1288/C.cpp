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
//const LL MOD = INF + 7;
//
//int n, m;
//
//LL dpT[1005][1005][2];
//LL pref[1005][1005];
//
//LL add(LL x, LL y)
//{
//	x += y;
//	if (x >= MOD)
//		x -= MOD;
//	if (x < 0)
//		x += MOD;
//	return x;
//}
//
//void makePref(int id)
//{
//	FOR(i, 0, n)
//	{
//		FOR(j, 0, n)
//		{
//			pref[i][j] = dpT[i][j][id];
//			if (i > 0 && j > 0)
//			{
//				pref[i][j] = add(pref[i][j], -pref[i - 1][j - 1]);
//			}
//			if (i > 0)
//			{
//				pref[i][j] = add(pref[i][j], pref[i - 1][j]);
//			}
//			if (j > 0)
//			{
//				pref[i][j] = add(pref[i][j], pref[i][j - 1]);
//			}
//		}
//	}
//}
//
//LL getVal(int l, int r)
//{
//	LL res = 0;
//	res = add(res, pref[r][r]);
//	if (l > 0)
//		res = add(res, -pref[r][l - 1]);
//	if (l > 0)
//		res = add(res, -pref[l - 1][r]);
//	if (l > 0 && r > 0)
//		res = add(res, pref[l - 1][l - 1]);
//	return res;
//}
//
//
//int main()
//{
//	ios_base::sync_with_stdio(0);
//	//freopen("input.txt", "r", stdin);
//	//freopen("output.txt", "w", stdout);
//
//	cin >> n >> m;
//
//	FOR(i, 0, n)
//	{
//		FOR(j, 0, n) // i <= j
//		{
//			if (i > j)
//			{
//				dpT[i][j][1] = 0;
//			}
//			else
//			{
//				dpT[i][j][1] = 1LL * (j - i + 1) * (j - i + 2) / 2;
//			}
//		}
//	}
//	m--;
//	FOR(k, 0, m)
//	{
//		makePref(1-k%2);
//		FOR(i, 0, n)
//		{
//			FOR(j, 0, n)
//			{
//				if (i > j)
//				{
//					dpT[i][j][k%2] = 0;
//				}
//				else
//				{
//					dpT[i][j][k%2] = getVal(i, j);
//				}
//			}
//		}
//	}
//	cout << dpT[0][n-1][(m + 1)%2] << endl;
//
//	return 0;
//}
//
