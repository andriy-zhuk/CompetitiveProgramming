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
//using namespace std;
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
//typedef vector<int> VI;
//
//const int INF = 1000 * 1000 * 1000;
//const LL LINF = 1LL * INF * INF;
//const int MAX = 100010;
//const long double PI = acos(-1.);
//const double EPS = 1e-6;
//const LL MOD = INF + 7;
//LL a, b;
//
//namespace DP
//{
//	LL dpT[20][2][20][20];
//	vector<int> foo;
//	LL dp(int bit, int sm, int four, int seven)
//	{
//		if (bit < 0)
//		{
//			if (four == seven)
//			{
//				return 1;
//			}
//			else
//			{
//				return 0;
//			}
//		}
//		if (-1 != dpT[bit][sm][four][seven])
//		{
//			return dpT[bit][sm][four][seven];
//		}
//		LL cur = 0;
//		int s1 = 0;
//		int s2 = 0;
//		if (sm)
//		{
//			FOR(i, 0, 10)
//			{	
//				if (i == 4)
//				{
//					s1 = 1;
//				}
//				if (i == 7)
//				{
//					s2 = 1;
//				}
//				cur += dp(bit - 1, sm, four + s1, seven + s2);
//				s1 = s2 = 0;
//			}
//		}
//		else
//		{
//			int i = foo[bit];
//			if (i == 4)
//			{
//				s1 = 1;
//			}
//			if (i == 7)
//			{
//				s2 = 1;
//			}
//			cur += dp(bit - 1, 0, four + s1, seven + s2);
//			s1 = s2 = 0;
//			FOR(i, 0, foo[bit])
//			{
//				if (i == 4)
//				{
//					s1 = 1;
//				}
//				if (i == 7)
//				{
//					s2 = 1;
//				}
//				cur += dp(bit - 1, 1, four + s1, seven + s2);
//				s1 = s2 = 0;
//			}
//		}
//		return dpT[bit][sm][four][seven] = cur;
//	}
//}
//
//LL make(LL x)
//{
//	vector<int> cur;
//	while (x)
//	{
//		cur.PB(x % 10);
//		x /= 10;
//	}
//
//	while (cur.size() < 20)
//	{
//		cur.PB(0);
//	}
//	FILL(DP::dpT, -1);
//	DP::foo = cur;
//
//	return DP::dp(19, 0, 0, 0);
//}
//
//
//
//int main()
//{
//	ios_base::sync_with_stdio(0);
//	//freopen("input.txt", "r", stdin);
//	//freopen("output.txt", "w", stdout);
//	cin >> a >> b;
//
//	cout << make(b) - make(a - 1) << endl;
//
//
//
//	return 0;
//}
//
