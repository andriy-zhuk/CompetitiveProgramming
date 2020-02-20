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
//int n;
//
//int a[1000];
//
//int main()
//{
//	ios_base::sync_with_stdio(0);
//	//freopen("input.txt", "r", stdin);
//	//freopen("output.txt", "w", stdout);
//	cin >> n;
//
//	FOR(i, 0, n)
//	{
//		cin >> a[i];
//	}
//	sort(a, a + n);
//
//	int best = 0;
//
//	multiset<int> foo;
//	FOR(i, 1, n)
//	{
//		foo.insert(2*(a[i] - a[i - 1]));
//	}
//	foo.insert(2*(360 - a[n - 1] + a[0]));
//
//	best = *(--foo.end());
//	foo.erase(--foo.end());
//	foo.insert(best / 2);
//	foo.insert(best / 2);
//
//
//	best = *(--foo.end());
//	cout << best / 2;
//	if (best % 2 == 0)
//	{
//		cout << ".0" << endl;
//	}
//	else
//	{
//		cout << ".5" << endl;
//	}
//
//
//
//	return 0;
//}
//
