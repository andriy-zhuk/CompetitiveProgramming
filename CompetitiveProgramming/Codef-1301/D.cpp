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
//int n, m, k;
//
//string add(int k, char ch)
//{
//	string res = "";
//	FOR(i, 0, k)
//		res += ch;
//	return res;
//}
//
//string get()
//{
//	string res;
//	FOR(i, 0, n - 1)
//	{
//		res += 'D';
//		res += add(m - 1, 'R');
//		res += add(m - 1, 'L');
//	}
//	res += add(n - 1, 'U');
//	FOR(i, 0, m-1)
//	{
//		res += 'R';
//		res += add(n - 1, 'D');
//		res += add(n - 1, 'U');
//	}
//	res += add(m - 1, 'L');
//	return res;
//}
//
//
//int main()
//{
//	ios_base::sync_with_stdio(0);
//	//freopen("input.txt", "r", stdin);
//	//freopen("output.txt", "w", stdout);
//
//	cin >> n >> m >> k;
//	int all = 4 * n * m - 2 * n - 2 * m;
//	if (k > all)
//	{
//		cout << "NO" << endl;
//		return 0;
//	}
//
//	string s = get();
//	if (s.size() < k)
//	{
//		cout << "NO" << endl;
//		return 0;
//	}
//	while (s.size() > k)
//		s.pop_back();
//	cout << "YES" << endl;
//	
//	vector<pair<char, int> > foo;
//	FOR(i, 0, s.size())
//	{
//		int j = i;
//		while (s[j] == s[i]) j++;
//		foo.PB(MP(s[i], j - i));
//		i = j - 1;
//	}
//	cout << foo.size() << endl;
//	FOR(i, 0, foo.size())
//	{
//		cout << foo[i].s << ' ' << foo[i].f << endl;
//	}
//	cout << endl;
//	return 0;
//}
//
