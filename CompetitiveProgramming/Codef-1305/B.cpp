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
//typedef vector<int> VI;
//
//const int INF = 1000 * 1000 * 1000;
//const LL LINF = 1LL * INF * INF;
//const int MAX = 100010;
//const long double PI = acos(-1.);
//const double EPS = 1e-6;
//const LL MOD = INF + 7;
//
//int n;
//string s;
//
//vector<int> ans;
//
//int main()
//{
//	ios_base::sync_with_stdio(0);
//	//freopen("input.txt", "r", stdin);
//	//freopen("output.txt", "w", stdout);
//	cin >> s;
//	n = s.size();
//	int l = 0;
//	int r = n - 1;
//	while (l < r)
//	{
//		if (s[l] == '(' && s[r] == ')')
//		{
//			ans.PB(l);
//			ans.PB(r);
//			r--;
//			l++;
//			continue;
//		}
//		if (s[l] == ')')
//			l++;
//		if (s[r] == '(')
//			r--;
//	}
//	sort(ALL(ans));
//	if (!ans.size())
//	{
//		cout << 0 << endl;
//		return 0;
//	}
//	cout << 1 << endl;
//	cout << ans.size() << endl;
//	FOR(i, 0, SZ(ans))
//	{
//		cout << ans[i] + 1 << ' ';
//	}
//	cout << endl;
//
//	return 0;
//}
//
