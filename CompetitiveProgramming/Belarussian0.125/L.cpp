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
//LL h, w, d;
//
//int main()
//{
//	ios_base::sync_with_stdio(0);
//	//freopen("input.txt", "r", stdin);
//	//freopen("output.txt", "w", stdout);
//	LL sum1 = 0;
//	LL sum2 = 0;
//	FOR(i, 0, 100000 * 10000)
//	{
//		sum1 += log10(i);
//		sum2 += sum1;
//		if (sum2 > 1e18)
//		{
//			cout << i << endl;
//			return 0;
//		}
//	}
//	string s;
//	getline(cin, s, 'x');
//	h = atoi(s.c_str());
//	cin >> s;
//	w = atoi(s.c_str());
//	cin >> s;
//	s.pop_back();
//	int yy = 0;
//	if (s.size() >= 2 && s[s.size() - 2] == '.')
//	{
//		yy = s.back() - '0';
//		s.pop_back();
//		s.pop_back();
//	}
//	d = atoi(s.c_str());
//	d *= 10;
//	d += yy;
//
//	long double verh = h * h + w * w;
//	long double nyz = d * d;
//	nyz /= 100.0;
//
//	LL value = (LL)(sqrt(verh / nyz) + 0.49999);
//	cout << value << endl;
//
//
//	return 0;
//}