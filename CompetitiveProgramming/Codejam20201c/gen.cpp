////#pragma GCC optimize("Ofast")
////#define _CRT_SECURE_NO_WARNINGS
////
////#include <iostream>
////#include <vector>
////#include <set>
////#include <map>
////#include <algorithm>
////#include <iomanip>
////#include <string>
////#include <deque>
////#include <stack>
////#include <cmath>
////#include <iterator>
////#include <string.h>
////#include <queue> 
////#include <random>
////using namespace std;
////
////#define PB push_back
////#define MP make_pair
////#define f first
////#define s second
////#define FOR(i,a,b) for (int i = a; i < b; ++i)
////#define RFOR(i, b, a) for (int i = b-1; i>=a; --i)
////#define FILL(a, b) memset(a, b, sizeof a)
////#define ALL(a) a.begin(), a.end()
////#define SZ(a) (int)a.size()
////
////typedef unsigned long long ULL;
////typedef long long LL;
////typedef pair<int, int> PII;
////typedef vector<int> VI;
////
////const int INF = 1000 * 1000 * 1000;
////const LL LINF = 1LL * INF * INF;
////const int MAX = 100010;
////const long double PI = acos(-1.);
////const double EPS = 1e-6;
////const LL MOD = INF + 7;
////
////
////
////void solve()
////{
////	int u;
////	map<char, int> cnt;
////	cnt.clear();
////	cin >> u;
////	set<char> nonz;
////	FOR(i, 0, 10000)
////	{
////		string q, s;
////		cin >> q >> s;
////		nonz.insert(s[0]);
////		FOR(i, 0, s.size())
////		{
////			cnt[s[i]]++;
////		}
////	}
////	char zero = 'z';
////	vector<pair<int, char>> foo;
////	for (auto& it : cnt)
////	{
////		zero = it.first;
////		int old = nonz.size();
////		nonz.insert(zero);
////		if (nonz.size() != old)
////		{
////			cnt.erase(zero);
////			break;
////		}
////	}
////	for (auto& it : cnt)
////	{
////		foo.PB(MP(it.second, it.first));
////	}
////	sort(ALL(foo));
////	reverse(foo.begin(), foo.end());
////	cout << zero;
////	FOR(i, 0, foo.size())
////	{
////		cout << foo[i].second;
////	}
////	cout << endl;
////}
////
////
////int main()
////{
////	ios_base::sync_with_stdio(0);
////	//freopen("input.txt", "r", stdin);
////	freopen("input.txt", "w", stdout);
////
////	cout << 100 << endl;
////	FOR(i, 0, 100)
////	{
////		mt19937_64 rnd(i+10);
////		cout << 16 << endl;
////		string s = "QWERTYUIOP";
////		FOR(i, 0, 10000)
////		{
////			LL x = rnd()% (1LL * INF * 1000 * 1000 * 10) + 1;
////			LL y = rnd() % (x) + 1;
////			string t = "";
////			while (y)
////			{
////				t += s[y % 10];
////				y /= 10;
////			}
////			reverse(ALL(t));
////			cout << -1 << ' ' << t << endl;
////
////		}
////	}
////	return 0;
////}
////
