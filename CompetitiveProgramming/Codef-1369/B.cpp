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
//using namespace std;
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
//typedef vector<int> VI;
//
//const int INF = 1000 * 1000 * 1000;
//const LL LINF = 1LL * INF * INF;
//const int MAX = 100010;
//const long double PI = acos(-1.);
//const double EPS = 1e-6;
//const LL MOD = INF + 7;
//void solve()
//{
//	int n;
//	string s;
//	cin >> n >> s;
//	int z = 0;
//	FOR(i, 0, n)
//	{
//		if (s[i] == '1')
//			break;
//		z++;
//	}
//	int o = 0;
//	RFOR(i, n, 0)
//	{
//		if (s[i] == '0')
//			break;
//		o++;
//	}
//	if (z + o == n)
//	{
//		cout << s << endl;
//		return;
//	}
//	if (z + o == 0)
//	{
//		cout << '0' << endl;
//		return;
//	}
//	FOR(i,0,z)
//	{
//		cout << '0';
//	}
//	cout << '0';
//	FOR(i, 0, o)
//	{
//		cout << '1';
//	}
//	cout << endl;
//}
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
