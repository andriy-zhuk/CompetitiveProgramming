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
//PII arr[2];
//
//PII chel;
//int dist(PII a, PII b)
//{
//	return abs(a.first - b.first) + abs(a.second - b.second);
//}
//int main()
//{
//	ios_base::sync_with_stdio(0);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
//
//	int T;
//	cin >> T;
//	FOR(t,1,T+1)
//	{
//		int n, m, k;
//		cin >> n >> m >> k;
//		cin >> chel.first >> chel.second;
//		FOR(i, 0, k)
//		{
//			cin >> arr[i].first >> arr[i].second;
//		}
//		cout << "Case #" << t << ": ";
//		if (k == 1)
//		{
//			cout << "N" << endl;
//			continue;
//		}
//		int d1 = dist(chel, arr[0]);
//		int d2 = dist(chel, arr[1]);
//		if (d1 % 2 == 0 && d2 % 2 == 0)
//		{
//			cout << "Y" << endl;
//		}
//		else
//		{
//			cout << "N" << endl;
//		}
//	}
//
//
//
//	return 0;
//}