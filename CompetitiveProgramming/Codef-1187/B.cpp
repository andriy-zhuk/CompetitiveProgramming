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
//int n, m;
//string s;
//int pref[26][200000];
//int cnt[26];
//
//int main()
//{
//	ios_base::sync_with_stdio(0);
//	//freopen("input.txt", "r", stdin);
//	//freopen("output.txt", "w", stdout);
//
//	int n, m;
//	cin >> n;
//	string s;
//	cin >> s;
//	cin >> m;
//	FOR(i, 0, SZ(s))
//	{
//		pref[s[i] - 'a'][i] = 1;
//		FOR(j, 0, 26)
//		{
//			if (i)
//				pref[j][i] += pref[j][i - 1];
//		}
//	}
//	FOR(i, 0, m)
//	{
//		string t;
//		cin >> t;
//		FILL(cnt, 0);
//		FOR(i, 0, SZ(t))
//		{
//			cnt[t[i] - 'a']++;
//		}
//		int answer = 0;
//		FOR(i, 0, 26)
//		{
//			int cur = lower_bound(pref[i], pref[i] + SZ(s), cnt[i]) - pref[i] + 1;
//			answer = max(answer, cur);
//		}
//		cout << answer << endl;
//	}
//
//	return 0;
//}