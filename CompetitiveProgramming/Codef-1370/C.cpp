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
//string a = "Ashishgup";
//string b = "FastestFinger";
//
//
//bool isp(int x)
//{
//	for (LL i = 2; i * i <= x; ++i)
//	{
//		if (x % i == 0 && i != x)
//			return false;
//	}
//	return true;
//}
//void solve()
//{
//	int n;
//	cin >> n;
//	if (n == 1)
//	{
//		cout << b << endl;
//		return;
//	}
//	if (n == 2)
//	{
//		cout << a << endl;
//		return;
//	}
//	if (n % 2)
//	{
//		cout << a << endl;
//		return;
//	}
//	int k = 0;
//	while (true)
//	{
//		if (n % 2)
//			break;
//		n /= 2;
//		k++;
//	}
//	if (n == 1)
//	{
//		cout << b << endl;
//		return;
//	}
//	if (k != 1)
//	{
//		cout << a << endl;
//		return;
//	}
//	if (isp(n))
//	{
//		cout << b << endl;
//	}
//	else
//	{
//		cout << a << endl;
//	}
//
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