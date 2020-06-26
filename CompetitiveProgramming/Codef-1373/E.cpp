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
//int f[100000006 + 10];
//void calc(int x)
//{
//	int old = x;
//	while (x)
//	{
//		f[old] += x % 10;
//		x /= 10;
//	}
//}
//int brute(int n, int k)
//{
//	FOR(i, 0, 100 * 100000)
//	{
//		int sum = 0;
//		FOR(j, 0, k+1)
//		{
//			sum += f[i + j];
//		}
//		if (sum == n)
//		{
//			return i;
//		}
//	}
//	return -1;
//}
//
//int main()
//{
//	ios_base::sync_with_stdio(0);
//	//freopen("input.txt", "r", stdin);
//	//freopen("output.txt", "w", stdout);
//	FOR(i, 0, 100000006 + 10)
//	{
//		calc(i);
//	}
//	FOR(n, 1, 151)
//	{
//		FOR(k, 1, 10)
//		{
//			cout << brute(n, k) << ' ';
//		}
//		cout << endl;
//	}
//	return 0;
//}
//
