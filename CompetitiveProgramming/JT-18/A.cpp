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
//#define y0 sdfsdfsdfy0
//#define y1 sdfsdfsdfy1
//
//LL a, b, x0, x1, y0, y1;
//
//int main()
//{
//	ios_base::sync_with_stdio(0);
//	//freopen("input.txt", "r", stdin);
//	//freopen("output.txt", "w", stdout);
//
//	cin >> a >> b >> x0 >> y0 >> x1 >> y1;
//	
//
//	LL nx0, ny0;
//	LL d = (x0 + y0) % (2 * a) + (2 * a);
//	LL g = 2*b - (x0 - y0) % (2 * b) ;
//	d %= (2 * a);
//	g %= (2 * b);
//	nx0 = x0 + (-d + g) / 2;
//	ny0 = y0 - (d + g) / 2;
//	LL nx1, ny1;
//	d = (x1 + y1) % (2 * a) + 2 * a;
//	g = 2*b - (x1 - y1) % (2 * b);
//	d %= (2 * a);
//	g %= (2 * b);
//	nx1 = x1 + (-d + g) / 2;
//	ny1 = y1 - (d + g) / 2;
//	//cout << nx0 << ' ' << ny0 << endl;
//	//cout << nx1 << ' ' << ny1 << endl;
//
//	LL i = (nx1 - nx0 + ny1 - ny0);
//	//cout << i << ' ' << 2 * a << endl;
//	if (i % (2 * a))
//		return -1;
//	i /= (2 * a);
//	LL j = nx1 - nx0 - a * i;
//	//cout << j << ' ' << b << endl;
//	if (j % (b))
//		return -1;
//	j /= b;
//	cout << max(abs(i) , abs(j)) << endl;
//	
//	return 0;
//}