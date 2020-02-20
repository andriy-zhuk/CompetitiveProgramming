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
//string s[1505];
//int n, k;
//set<string> t[1505];
//
//string make(string s, string t)
//{
//	string res = "";
//	FOR(i, 0, s.size())
//	{
//		if (s[i] == t[i])
//		{
//			res += s[i];
//		}
//		else
//		{
//			string tt = "SET";
//			FOR(k, 0, 3)
//			{
//				if (tt[k] != s[i] && tt[k] != t[i])
//				{
//					res += tt[k];
//				}
//			}
//		}
//	}
//	return res;
//}
//int main()
//{
//	ios_base::sync_with_stdio(0);
//	//freopen("input.txt", "r", stdin);
//	//freopen("output.txt", "w", stdout);
//
//	cin >> n >> k;
//	FOR(i, 0, n)
//	{
//		cin >> s[i];
//		FOR(j, 0, i)
//		{
//			t[j].insert(s[i]);
//		}
//	}
//	int ans = 0;
//	FOR(i, 0, n)
//	{
//		FOR(j, i + 1, n)
//		{
//			string cur = make(s[i], s[j]);
//			if (t[j].find(cur) != t[j].end())
//				ans++;
//		}
//
//	}
//
//	cout << ans << endl;
//	return 0;
//}
//
