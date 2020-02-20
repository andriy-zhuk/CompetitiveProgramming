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
//string s;
//int cnt[26];
//int tcnt[26];
//string t;
//
//int main()
//{
//	ios_base::sync_with_stdio(0);
//	//freopen("input.txt", "r", stdin);
//	//freopen("output.txt", "w", stdout);
//	cin >> s >> t;
//	FOR(i, 0, t.size())
//	{
//		tcnt[t[i] - 'a']++;
//	}
//	if (s.size() < t.size())
//	{
//		cout << 0;
//		return 0;
//	}
//	int answer = 0;
//	FOR(i, 0, t.size())
//	{
//		if (s[i] == '?')
//			continue;
//		cnt[s[i] - 'a']++;
//	}
//	for (int l = 0, r = l + t.size()-1; r < s.size(); ++l, ++r)
//	{
//		bool ok = true;
//		FOR(i, 0, 26)
//		{
//			if (cnt[i] > tcnt[i])
//			{
//				ok = false; break;
//			}
//		}
//		if (ok)
//		{
//			answer++;
//		}
//		if (r + 1 != s.size())
//		{
//			if (s[l] != '?')
//			{
//				cnt[s[l] - 'a']--;
//			}
//			if (s[r + 1] != '?')
//			{
//				cnt[s[r + 1] - 'a']++;
//			}
//		}
//	}
//	cout << answer << endl;
//	return 0;
//}