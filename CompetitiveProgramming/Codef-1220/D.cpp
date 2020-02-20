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
//int n;
//LL a[200005];
//LL gcd(LL a, LL b)
//{
//	if (!a)
//		return b;
//	return gcd(b % a, a);
//}
//int main()
//{
//	ios_base::sync_with_stdio(0);
//	//freopen("input.txt", "r", stdin);
//	//freopen("output.txt", "w", stdout);
//	cin >> n;
//	FOR(i, 0, n)
//	{
//		cin >> a[i];
//	}
//	pair<int, int> ans;
//	ans = MP(n - 1, 1);
//	FOR(pw, 0, 61)
//	{
//		int res = 0;
//		FOR(i, 0, n)
//		{
//			if (a[i] % (1LL << pw) == 0 && (a[i]/(1LL<<pw))%2 == 1)
//			{
//				continue;
//			}
//			else
//			{
//				res++;
//			}
//		}
//		ans = min(ans, MP(res, pw));
//	}
//	cout << ans.first << endl;
//	if (ans.first == n - 1)
//	{
//		FOR(i, 0, n - 1)
//		{
//			cout << a[i] << ' ';
//		}
//		return 0;
//	}
//	
//	int pw = ans.second;
//	int res = 0;
//	FOR(i, 0, n)
//	{
//		if (a[i] % (1LL << pw) == 0 && (a[i] / (1LL << pw)) % 2 == 1)
//		{
//			continue;
//		}
//		else
//		{
//			cout << a[i] << ' ';
//		}
//	}
//	
//	
//
//	return 0;
//}