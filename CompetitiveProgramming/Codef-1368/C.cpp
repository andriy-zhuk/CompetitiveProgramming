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
//
//int dx[] = {2, 2, 2, 2, 2, 3, 3, 3, 4, 4, 4, 4, 4, 5};
//int dy[] = {2, 1, 0, -1, -2, 2, 0, -2, 2, 1, 0, -1, -2, 0};
//
//
//int main()
//{
//	ios_base::sync_with_stdio(0);
//	//freopen("input.txt", "r", stdin);
//	//freopen("output.txt", "w", stdout);
//	int n;
//	cin >> n;
//	set<PII> foo;
//	foo.insert(MP(0, 0));
//	foo.insert(MP(1, 0));
//	foo.insert(MP(0, 1));
//	if (n % 2)
//	{
//		foo.insert(MP(-1, 0));
//		foo.insert(MP(0, -1));
//		foo.insert(MP(-1, 0));
//		foo.insert(MP(-2, 0));
//		foo.insert(MP(-2, -1));
//		foo.insert(MP(-2, -2));
//		foo.insert(MP(-1, -2));
//		foo.insert(MP(0, -2));
//		foo.insert(MP(0, -1));
//		n--;
//	}
//	n /= 2;
//	FOR(i, 0, n)
//	{
//		FOR(j, 0, 14)
//		{
//			foo.insert(MP(dx[j] + 4 * i, dy[j]));
//		}
//	}
//	foo.insert(MP(0, 2));
//	foo.insert(MP(0, 3));
//	foo.insert(MP(0, 4));
//	foo.insert(MP(1, 4));
//	FOR(i, 0, n)
//	{
//		FOR(j, 0, 4)
//			foo.insert(MP(2 + j + 4 * i, 4));
//	}
//	FOR(j, 0, 5)
//	{
//		foo.insert(MP(4 * n + 2, j ));
//	}
//
//	cout << foo.size() << endl;
//	for (auto& iter : foo)
//	{
//		cout << iter.first << ' ' << iter.second << endl;
//	}
//
//	/*int a[100][100];
//	FILL(a, 0);
//	for (auto& iter : foo)
//	{
//		a[2+iter.second][2 + iter.first] = 1;
//	}
//
//	FOR(i, 0, 22)
//	{
//		FOR(j, 0, 22)
//		{
//			cout << a[i][j] << ' ';
//		}
//		cout << endl;
//	}
//*/
//
//
//
//
//
//	return 0;
//}
//
