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
//int n;
//LL a[7005];
//LL a2[7005];
//LL b[7005];
//
//LL inv(LL x)
//{
//	LL res = 0;
//	FOR(i, 0, 60)
//	{
//		if (x & (1LL << i))
//		{
//			
//		}
//		else
//		{
//			res ^= (1LL << i);
//		}
//	}
//	return res;
//}
//
//bool ok[7005];
//int q[70005];
//int qh = 0;
//int qt = 0;
//int in[7005];
//vector<int> g[7005];
//int main()
//{
//	ios_base::sync_with_stdio(0);
//	//freopen("input.txt", "r", stdin);
//	//freopen("output.txt", "w", stdout);
//
//	cin >> n;
//	FOR(i, 0, n)
//	{
//		cin >> a[i];
//		a2[i] = inv(a[i]);
//	}
//
//	LL suma = 0;
//	FOR(i, 0, n)
//	{
//		cin >> b[i];
//		ok[i] = true;
//	}
//	FOR(i, 0, n)
//	{
//		FOR(j, 0, n)
//		{
//			if (i == j)continue;
//			if (a[i] & a2[j]); 
//			else
//			{
//				g[j].PB(i);
//				in[i]++;
//			}
//		}
//	}
//	
//	FOR(i, 0, n)
//	{
//		if (in[i] == 0)
//		{
//			ok[i] = false;
//			q[qh++] = i;
//		}
//	}
//	
//	while (qh != qt)
//	{
//		int u = q[qt++];
//		FOR(i, 0, g[u].size())
//		{
//			int v = g[u][i];
//			if (ok[v])
//			{
//				in[v]--;
//				if (in[v] == 0)
//				{
//					ok[v] = false;
//					q[qh++] = v;
//				}
//			}
//		}
//	}
//	int cnt = 0;
//	
//	FOR(i, 0, n)
//	{
//		if (ok[i])
//		{
//			cnt++;
//			suma += b[i];
//		}
//	}
//	cout << suma * (cnt >= 2) << endl;
//
//
//	return 0;
//}