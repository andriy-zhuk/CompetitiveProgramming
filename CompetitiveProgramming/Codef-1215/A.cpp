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
//int a1, a2, k1, k2, n;
//
//int f1(int a1, int a2, int k1, int k2, int n)
//{
//	n -= a1 * (k1 - 1);
//	n -= a2 * (k2 - 1);
//	if (n <= 0)
//		return 0;
//	return n;
//}
//
//int f2(int a1, int a2, int k1, int k2, int n)
//{
//	if (k1 > k2)
//	{
//		swap(a1, a2);
//		swap(k1, k2);
//	}
//	int x = n / k1;
//	if (x >= a1)
//	{
//		n -= a1 * k1;
//		x = a1 + n / k2;
//		return x;
//	}
//	else
//	{
//		return x;
//	}
//}
//
//
//int main()
//{
//	ios_base::sync_with_stdio(0);
//	//freopen("input.txt", "r", stdin);
//	//freopen("output.txt", "w", stdout);
//
//	cin >> a1 >> a2 >> k1 >> k2 >> n;
//
//	cout << f1(a1, a2,k1,k2,n) << ' ' << f2(a1,a2,k1,k2,n) << endl;
//
//
//
//	return 0;
//}