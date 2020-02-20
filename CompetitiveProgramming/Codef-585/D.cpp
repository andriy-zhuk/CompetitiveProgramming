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
#define int LL
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
int a[76][3];
map<pair<int, int>, pair<int, string> > foo;
int cheslo[15];
int p3[25];
string opt = "LMW";

pair<int, string> best = MP(-LINF, "template");

signed main()
{
	ios_base::sync_with_stdio(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	cin >> n;
	FOR(i, 0, n)
	{
		FOR(j, 0, 3)
		{
			cin >> a[i][j];
		}
	}

	int counta = 1;
	p3[0] = 1;
	FOR(i, 0, 24)
	{
		p3[i+1] = counta;
		counta *= 3;
	}
	string s;
	int x[3], t;

	t = p3[n / 2 + 1];
	FILL(cheslo, 0);
	x[0] = x[1] = x[2] = 0;
	s = "";
	FOR(i, 0, n / 2)
		s += 'L', x[1] += a[i][1], x[2] += a[i][2];
	while (t--)
	{
		if (foo.count(MP(x[1] - x[0], x[2] - x[0])) == 0)
		{
			foo[MP(x[1] - x[0], x[2] - x[0])] = MP(x[0], s);
		}
		else
		{
			foo[MP(x[1] - x[0], x[2] - x[0])] = max(foo[MP(x[1] - x[0], x[2] - x[0])], MP(x[0], s));
		}
		cheslo[0]++;
		if (cheslo[0] != 3)
		{
			x[cheslo[0] - 1] += a[0][cheslo[0] - 1];
			s[0] = opt[cheslo[0]];
			x[cheslo[0]] -= a[0][cheslo[0]];
		}
		else
		{
			for (int i = 0; i < s.size(); ++i)
			{
				x[cheslo[i] - 1] += a[i][cheslo[i] - 1];
				if (cheslo[i] == 3)
				{
					cheslo[i] = 0;
					cheslo[i + 1]++;
				}
				s[i] = opt[cheslo[i]];
				x[cheslo[i]] -= a[i][cheslo[i]];
				if (cheslo[i + 1] < 3)
				{
					if (i == s.size() - 1)
						break;
					s[i + 1] = opt[cheslo[i + 1]];
					x[cheslo[i + 1] - 1] += a[i + 1][cheslo[i + 1] - 1];
					x[cheslo[i + 1]] -= a[i + 1][cheslo[i + 1]];
					break;
				}
			}
		}
		
	}

	t = p3[(n+1) / 2 + 1];
	FILL(cheslo, 0);
	x[0] = x[1] = x[2] = 0;
	s = "";
	FOR(i, 0, (n+1) / 2)
		s += 'L', x[1] += a[i+n/2][1], x[2] += a[i+n/2][2];

	while (t--)
	{
		//cout << x[0] << ' ' << x[1] << ' ' << x[2] << ' ' << s << endl;
		if (foo.count(MP(x[0] - x[1], x[0] - x[2])))
		{
			pair<int, string> cur = foo[MP(x[0] - x[1], x[0] - x[2])];
			best = max(best, MP(x[0] + cur.first, cur.second + s));
		}

		cheslo[0]++;
		if (cheslo[0] != 3)
		{
			x[cheslo[0] - 1] += a[n / 2][cheslo[0] - 1];
			s[0] = opt[cheslo[0]];
			x[cheslo[0]] -= a[n / 2][cheslo[0]];
		}
		else
		{
			for (int i = 0; i < s.size(); ++i)
			{
				x[cheslo[i] - 1] += a[i + n / 2][cheslo[i] - 1];
				if (cheslo[i] == 3)
				{
					cheslo[i] = 0;
					cheslo[i + 1]++;
				}
				s[i] = opt[cheslo[i]];
				x[cheslo[i]] -= a[i + n / 2][cheslo[i]];
				if (cheslo[i + 1] < 3)
				{
					if (i == s.size() - 1)
						break;
					s[i + 1] = opt[cheslo[i + 1]];
					x[cheslo[i + 1] - 1] += a[i + 1 + n / 2][cheslo[i + 1] - 1];
					x[cheslo[i + 1]] -= a[i + 1 + n / 2][cheslo[i + 1]];
					break;
				}
			}
		}
	}

	if (best == MP(-LINF, string("template")))
	{
		cout << "Impossible" << endl;
	}
	else
	{
		FOR(i, 0, n)
		{
			FOR(j, 0, 3)
			{
				if (opt[j] != best.second[i])
				{
					cout << opt[j];
				}
			}
			cout << endl;
		}
	}


	return 0;
}

