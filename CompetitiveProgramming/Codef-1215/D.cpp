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
//int n;
//string s;
//void bi()
//{
//	cout << "Bicarp" << endl;
//	exit(0);
//}
//void mo()
//{
//	cout << "Monocarp" << endl;
//	exit(0);
//}
//
//
//int x = 0, y = 0, a = 0, b = 0;
//int main()
//{
//	ios_base::sync_with_stdio(0);
//	//freopen("input.txt", "r", stdin);
//	//freopen("output.txt", "w", stdout);
//	cin >> n;
//	cin >> s;
//	FOR(i, 0, n/2)
//	{
//		if (s[i] == '?')
//		{
//			a++;
//		}
//		else
//		{
//			x += s[i] - '0';
//		}
//	}
//	FOR(i, n / 2, n)
//	{
//		if (s[i] == '?')
//		{
//			b++;
//		}
//		else
//		{
//			y += s[i] - '0';
//		}
//	}
//
//	if (x == y)
//	{
//		if (a == b)
//		{
//			bi();
//		}
//		else
//		{
//			mo();
//		}
//	}
//	if (x > y)
//	{
//		swap(x, y);
//		swap(a, b);
//	}
//	if (a < b)
//	{
//		mo();
//	}
//	if (a == b)
//	{
//		mo();
//	}
//	int c = a - b;
//	if (y - x == 9 * (c / 2))
//	{
//		bi();
//	}
//	else
//	{
//		mo();
//	}
//	return 0;
//}