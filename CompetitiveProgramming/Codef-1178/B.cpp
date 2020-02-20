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
//string s;
//vector<LL> a, b;
//
//
//
//int main()
//{
//	ios_base::sync_with_stdio(0);
//	//freopen("input.txt", "r", stdin);
//	//freopen("output.txt", "w", stdout);
//	cin >> s;
//	while (s.back() == 'o')
//		s.pop_back();
//	reverse(ALL(s));
//	while (s.back() == 'o')
//		s.pop_back();
//	reverse(ALL(s));
//	int c1 = 0, c2 = 0;
//	for (int i = 0; i<SZ(s);)
//	{
//		while (s[i] == 'v' && i < SZ(s))
//		{
//			c1++;
//			i++;
//		}
//		a.PB(c1 - 1);
//		c1 = 0;
//		while (s[i] == 'o')
//		{
//			c2++;
//			i++;
//		}
//		b.PB(c2);
//		c2 = 0;
//	}
//	if (a.size() < 2)
//	{
//		cout << 0 << endl;
//		return 0;
//	}
//	vector<LL> bb;
//	int all = 0;
//	if (a.size() > b.size())
//		all += a.back();
//	else
//	{
//		b.pop_back();
//		all += a.back();
//	}
//	RFOR(i, SZ(b), 0)
//	{
//		bb.PB(1LL * all * b[i] + (bb.size() != 0 ? bb.back() : 0));
//		all += a[i];
//	}
//	reverse(ALL(bb));
//
//	LL answer = 0;
//	FOR(i, 0, SZ(bb))
//	{
//		answer += 1LL * a[i] * bb[i];
//	}
//	cout << answer << endl;
//
//
//
//	return 0;
//}