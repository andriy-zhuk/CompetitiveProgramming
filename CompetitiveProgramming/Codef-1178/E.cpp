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
//string s, t;
//char mid = '0';
//int main()
//{
//	ios_base::sync_with_stdio(0);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
//
//	cin >> s;
//	int l = 0;
//	int r = SZ(s) - 1;
//
//	while (r - l >= 3)
//	{
//		int l1 = l;
//		int r1 = r;
//		bool ok = 0;
//		FOR(i, l, l + 2)
//		{
//			if (ok)
//				break;
//			FOR(j, r - 1, r + 1)
//			{
//				if (s[i] == s[j])
//				{
//					l1 = i, r1 = j;
//					ok = 1;
//					break;
//				}
//			}
//		}
//		t += s[l1];
//		l += 2;
//		r -= 2;
//	}
//	if (r - l >= 0)
//	{
//		mid = s[l];
//	}
//
//	cout << t;
//	if (mid != '0')
//		cout << mid;
//	reverse(ALL(t));
//	cout << t << endl;
//
//	return 0;
//}