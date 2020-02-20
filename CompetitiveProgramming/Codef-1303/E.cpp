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
//const LL MOD = INF + 7;
//
//string s, t;
//int cnt[26];
//
//bool ok(int n)
//{
//	int j = 0;
//	FOR(i, 0, n)
//	{
//		while (j < s.size() && s[j] != t[i])
//			j++;
//		if (j == s.size())
//			return false;
//		j++;
//	}
//	
//	return true;
//}
//
//int dpT[404][404];
//
//string l, r;
//int fst[26][404];
//bool go()
//{
//	FOR(i, 0, 404)
//	{
//		FOR(j, 0, 404)
//		{
//			dpT[i][j] = INF;
//		}
//	}
//	dpT[0][0] = 0;
//	FOR(i, 0, l.size()+1)
//	{
//		FOR(j, 0, r.size()+1)
//		{
//			if (i && dpT[i-1][j] != INF)
//			{
//				dpT[i][j] = min(dpT[i][j], fst[l[i - 1] - 'a'][dpT[i - 1][j]] + 1);
//			}
//			if (j && dpT[i][j - 1] != INF)
//			{
//				dpT[i][j] = min(dpT[i][j], fst[r[j - 1] - 'a'][dpT[i][j - 1]] + 1);
//			}
//		}
//	}
//	if (dpT[l.size()][r.size()] != INF)
//		return true;
//
//
//	return false;
//
//
//
//}
//
//void solve()
//{
//	cin >> s >> t;
//	FILL(cnt, 0);
//	FOR(i, 0, t.size())
//		cnt[t[i] - 'a']++;
//	FOR(i, 0, s.size())
//		cnt[s[i] - 'a']--;
//
//		
//	FOR(i, 0, 26)
//	{
//		if (cnt[i] > 0)
//		{
//			cout << "NO" << endl;
//			return;
//		}
//	}
//	
//	vector<int> foo[26];
//	FOR(i, 0, s.size())
//	{
//		foo[s[i] - 'a'].PB(i);
//	}
//	FOR(i, 0, 26) FOR(j, 0, 404) fst[i][j] = INF-1;
//	FOR(i, 0, 26)
//	{
//		FOR(j, 0, s.size()+1)
//		{
//			fst[i][j] = lower_bound(ALL(foo[i]), j) - foo[i].begin();
//			if (fst[i][j] == foo[i].size())
//				fst[i][j] = INF - 1;
//			else
//				fst[i][j] = foo[i][fst[i][j]];
//		}
//	}
//	FOR(i, 0, t.size())
//	{
//		l = r = "";
//		FOR(j, 0, i)
//			l += t[j];
//		FOR(j, i, t.size())
//			r += t[j];
//		//cout << l << ' ' << r << ' ' << endl;
//		
//		if (go())
//		{
//			cout << "YES" << endl;
//			return;
//		}
//	}
//	cout << "NO" << endl;
//
//}
//
//
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
//		solve();
//	}
//	return 0;
//}
//
