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
//namespace ST
//{
//	int K = 20;
//	int N;
//	PII st[MAX][20];
//	int log[MAX + 1];
//	
//	void init(int *a)
//	{
//		log[1] = 0;
//		for (int i = 2; i <= MAX; i++)
//			log[i] = log[i / 2] + 1;
//		FOR(i,0,MAX)
//			FOR(k, 0, 20)
//				st[i][k] = MP(-INF, -1);
//		for (int i = 0; i < N; i++)
//			st[i][0] = MP(a[i], i);
//		for (int j = 1; j <= K; j++)
//			for (int i = 0; i + (1 << j) <= N; i++)
//				st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
//	}
//
//	PII get(int l, int r)
//	{
//		int j = log[r - l + 1];
//		return max(st[l][j], st[r - (1 << j) + 1][j]);
//	}
//};
//int n, q;
//int a[MAX];
//int b[MAX];
//
//LL go(int l, int r)
//{
//	if (l >= r)
//	{
//		return 0;
//	}
//	PII mx = ST::get(l, r - 1); // MP(value, pos)
//	LL cur = 1LL * (mx.second - l + 1) * (r - mx.second) * mx.first;
//	return cur + go(l, mx.second) + go(mx.second + 1, r);
//}
//
//int main()
//{
//	ios_base::sync_with_stdio(0);
//	//freopen("input.txt", "r", stdin);
//	//freopen("output.txt", "w", stdout);
//
//	cin >> n >> q;
//	FOR(i, 0, n)
//	{
//		cin >> a[i];
//	}
//	FOR(i, 0, n - 1)
//	{
//		b[i] = abs(a[i + 1] - a[i]);
//	}
//	ST::N = n - 1;
//	ST::init(b);
//
//	while (q--)
//	{
//		int l, r;
//		cin >> l >> r;
//		l--, r--;
//		cout << go(l, r) << endl;
//	}
//
//
//	return 0;
//}
//
