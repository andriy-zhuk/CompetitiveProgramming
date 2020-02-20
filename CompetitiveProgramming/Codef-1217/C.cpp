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
//
//string s;
//int n;
//int nxt[200005];
//int solve()
//{
//	cin >> s;
//	n = SZ(s);
//	int last = n;
//	RFOR(i, n, 0)
//	{
//		if (s[i] == '1')
//			last = i;
//		nxt[i] = last;
//	}
//	LL answer = 0;
//	FOR(i, 0, n)
//	{
//		int l = nxt[i];
//		if (l == n)
//			continue;
//		LL have = 0;
//		FOR(r, 0, 20)
//		{
//			if (r + l >= n)
//				break;
//			have *= 2;
//			if (s[l + r] == '1')
//			{
//				have += 1;
//			}
//			if ((l + r) - i + 1 == have)
//			{
//				answer++;
//			}
//		}
//	}
//	return answer;
//}
//
//
//int main()
//{
//	ios_base::sync_with_stdio(0);
//	//freopen("input.txt", "r", stdin);
//	//freopen("output.txt", "w", stdout);
//	int t;
//	cin >> t;
//	while (t--)
//	{
//		cout << solve() << endl;
//	}
//	return 0;
//}