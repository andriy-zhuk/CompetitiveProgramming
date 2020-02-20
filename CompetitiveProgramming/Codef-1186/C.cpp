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
//const LL mod = INF + 6;
//
//string s;
//string t;
//
//int pref[1000006];
//
//int par(int l, int r)
//{
//	int ans = pref[r];
//	if (l > 0)
//		ans ^= pref[l - 1];
//	return ans;
//}
//
//int main()
//{
//	ios_base::sync_with_stdio(0);
//	//freopen("input.txt", "r", stdin);
//	//freopen("output.txt", "w", stdout);
//	cin >> s >> t;
//	int tpar = 0;
//	FOR(i, 0, SZ(t))
//	{
//		tpar ^= t[i] - '0';
//	}
//	pref[0] = s[0] - '0';
//	FOR(i, 1, SZ(s))
//	{
//		pref[i] = pref[i - 1] ^ (s[i] - '0');
//	}
//	int ans = 0;
//	FOR(i, 0, SZ(s))
//	{
//		int r = i + SZ(t)-1;
//		if (r >= SZ(s))
//			break;
//		//cout << i << ' ' << r << ' ' << par(i,r) << endl;
//		if (par(i, r) == tpar)
//			ans++;
//	}
//	cout << ans << endl;
//
//
//	return 0;
//}