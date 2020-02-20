#pragma GCC optimize("Ofast")
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <iomanip>
#include <string>
#include <deque>
#include <stack>
#include <cmath>
#include <iterator>
#include <string.h>

using namespace std;
#ifndef DEBUGING
ostream cnull(NULL);
#define cerr cnull
#endif // !DEBUGING

#define PB push_back
#define MP make_pair
#define f first
#define s second
#define FOR(i,a,b) for (int i = a; i < b; ++i)
#define RFOR(i, b, a) for (int i = b-1; i>=a; --i)
#define FILL(a, b) memset(a, b, sizeof a)
#define ALL(a) a.begin(), a.end()
#define SZ(a) (int)a.size()

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<LL> VI;
typedef pair<LL, LL> PLL;

const int INF = 1000 * 1000 * 1000;
const LL LINF = 1LL * INF * INF;
const int MAX = 100010;
const long double PI = acos(-1.);
const double EPS = 1e-6;
const LL mod = INF + 7;

int n;
PII a[100005];

set<PII> l;
set<PII, greater<PII> > r;
//11/42

int dist(int &x, int i)
{
	if (x >= a[i].first && x <= a[i].second)
	{
		return 0;
	}
	if (x > a[i].second)
	{
		int y = x - a[i].second;
		x = a[i].second;
		return y;
	}
	int y = a[i].first - x;
	x = a[i].first;
	return y;
}

int main()
{
	ios_base::sync_with_stdio(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> n;
	FOR(i, 0, n)
	{
		cin >> a[i].first >> a[i].second;
	}

	LL best = 0;
	FOR(i, 0, 2)
	{
		bool flag = (bool)i;
		LL ans = 0;
		int st = 0;
		FOR(i, 0, n)
		{
			l.insert(MP(a[i].second, i));
			r.insert(MP(a[i].first, i));
		}

		while (l.size())
		{
			if (flag)
			{
				int id = r.begin()->second;
				//cout << st << ' ' << a[id].first << ' ' << a[id].second << endl;
				int x = dist(st, id);
				ans += x;
				l.erase(MP(a[id].second, id));
				r.erase(MP(a[id].first, id));
			}
			else
			{
				int id = l.begin()->second;
				//cout << st << ' ' << a[id].first << ' ' << a[id].second << endl;
				int x = dist(st, id);
				ans += x;
				l.erase(MP(a[id].second, id));
				r.erase(MP(a[id].first, id));
			}
			flag ^= 1;
		}
		ans += abs(st);

		best = max(best, ans);


	}
	
	cout << best << endl;


	return 0;
}

