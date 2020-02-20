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
//int n, m;
//vector<pair<int, PII>> foo;
//int pref[2000];
//int a[2000];
//int arr[2000];
//
//
//bool check(int len)
//{
//	bool ok = true;
//	FOR(i, 0, m)
//	{
//		bool flag = true;
//		FOR(j, foo[i].second.first + 1, min(foo[i].second.second + 1, len))
//		{
//			if (arr[j] != arr[j - 1])
//				flag = false;
//		}
//		if (foo[i].first == 1)
//		{
//			if (!flag)
//			{
//				ok = false;
//				break;
//			}
//		}
//		else
//		{
//			if (flag && foo[i].second.second +1 <= len)
//			{
//				ok = false;
//				break;
//			}
//		}
//	}
//	return ok;
//}
//int main()
//{
//	ios_base::sync_with_stdio(0);
//	//freopen("input.txt", "r", stdin);
//	//freopen("output.txt", "w", stdout);
//	cin >> n >> m;
//	FOR(i, 0, m)
//	{
//		int x, y, z;
//		cin >> x >> y >> z;
//		foo.PB(MP(x, MP(y-1, z-1)));
//	}
//	int cur = 0;
//	int value = INF - 2;
//	FOR(i, 0, n)
//	{
//		arr[i] = value-1;
//		if (check(i + 1) == false)
//		{
//			arr[i]++;
//		}
//		else
//		{
//			value--;
//		}
//	}
//
//	bool ok = check(n);
//	if (ok)
//	{
//		cout << "YES" << endl;
//		FOR(i, 0, n)
//		{
//			cout << arr[i] << ' ';
//		}
//	}
//	else
//	{
//		cout << "NO" << endl;
//	}
//	
//	return 0;
//}