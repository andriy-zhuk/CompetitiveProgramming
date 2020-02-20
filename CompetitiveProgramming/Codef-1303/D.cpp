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
//typedef unsigned long long ULL;
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
//const LL MOD = INF + 7;
//
//LL n, m;
//LL a[200005];
//int need[61];
//LL val[61];
//
//void solve()
//{
//	cin >> n >> m;
//	FILL(need, 0);
//	FILL(val, 0);
//	FOR(i, 0, 61)
//	{
//		if (n & (1LL << i))
//		{
//			need[i] = 1;
//		}
//	}
//	multiset<LL> foo;
//	LL suma = 0;
//	FOR(i, 0, m)
//	{
//		cin >> a[i];
//		suma += a[i];
//		FOR(j, 0, 61)
//		{
//			if (a[i] == 1LL << j)
//			{
//				if (need[j] == 1)
//				{
//					need[j] = 0;
//					suma -= a[i];
//					n -= a[i];
//					break;
//				}
//				foo.insert(j);
//				val[j]++;
//				break;
//			}
//		}
//	}
//	if (n > suma)
//	{
//		cout << -1 << endl;
//		return;
//	}
//	
//	int divs = 0;
//	LL sum = 0;
//	FOR(i, 0, 61)
//	{
//		if (!need[i])
//		{
//			sum += val[i]<<i;
//			continue;
//		}
//		
//		auto it = foo.lower_bound(i);
//		if (*it == i)
//		{
//			val[i]--;
//			sum += val[i] << i;
//		}
//		else if (it == foo.end())
//		{
//			sum -= 1LL << i;
//		}
//		else
//		{
//			int j = *it;
//			if (sum >= 1LL << i)
//			{
//				sum -= 1LL << i;
//				continue;
//			}
//			divs += (j - i);
//			sum += 1LL << i;
//			val[j]--;
//			foo.erase(it);
//			FOR(k, i, j)
//			{
//				foo.insert(k);
//				val[k]++;
//			}
//		}
//	}
//	
//	cout << divs << endl;
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
//
//	}
//	return 0;
//}
//
