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
#include <sstream>

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

class EllysNumbers
{
public:
	LL n;
	vector<int> a;
	int mask[505];
	vector<PII> foo[505];
	set<int> primes;
	vector<int> p;
	LL dpT[2][1 << 15];


	~ EllysNumbers()
	{
		p.clear();
		a.clear();
		FOR(i, 0, 505)
			foo[i].clear();
	}
	vector<pair<int, int> > factorize(int x)
	{
		vector<PII> ans;
		for (LL i = 2; i * i <= x; ++i)
		{
			if (x % i == 0)
			{
				int cnt = 1;
				while (x % i == 0)
				{
					cnt *= i;
					x /= i;
				}
				ans.PB(MP(i, cnt));
			}
		}
		if (x != 1)
		{
			ans.PB(MP(x, x));
		}
		return ans;
	}
	bool check() // if primes is full
	{
		LL nn = n;
		for (auto& iter : primes)
		{
			while (nn % iter == 0)
				nn /= iter;
		}
		return nn == 1;
	}
	LL dp()
	{
		dpT[a.size() % 2][(1 << p.size()) - 1] = 1;
		RFOR(i, a.size(), 0)
		{
			FOR(m, 0, (1 << p.size()))
			{
				dpT[i % 2][m] = dpT[1 - i % 2][m];
				if (mask[i] != -1 && (m & mask[i]) == 0)
				{
					dpT[i % 2][m] += dpT[1 - i % 2][m ^ mask[i]];
				}
			}
		}
		return dpT[0][0];
	}

	LL getSubsets(LL _n, vector<string> ss)
	{
		string s;
		FOR(i, 0, ss.size())
		{
			s += ss[i];
		}
		n = _n;
		int x;
		stringstream ins;
		ins.str(s.c_str());
		while (ins >> x)
		{
			a.PB(x);
		}
		FOR(i, 0, a.size())
		{
			foo[i] = factorize(a[i]);

			FOR(j, 0, foo[i].size())
			{
				if (n % foo[i][j].second == 0 && (n / foo[i][j].second) % foo[i][j].first != 0) // n : p_j^k, k->max
				{
					primes.insert(foo[i][j].first);
				}
			}
		}
		if (!check())
		{
			return 0;
		}
		for (auto& iter : primes)
		{
			p.PB(iter);
		}

		FOR(i, 0, SZ(a))
		{
			int cur = 0;
			int ok2 = (n % a[i]) == 0;
			FOR(k, 0, p.size())
			{
				int ok = 0;
				FOR(j, 0, foo[i].size())
				{
					if (foo[i][j].first != p[k])
						continue;
					if (n % foo[i][j].second == 0 && (n / foo[i][j].second) % foo[i][j].first != 0)
					{
						ok = 1;
					}
					else
					{
						ok2 = 0;
					}
				}
				cur ^= (ok << k);
			}
			mask[i] = cur;
			if (!ok2)
				mask[i] = -1;
		}
		FILL(dpT, 0);
		return dp();
	}
};


vector<string> arr = { "4 2 5 6 3" };

int main()
{
	ios_base::sync_with_stdio(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	EllysNumbers e;
	cout << e.getSubsets(12, arr) << endl;
	
	return 0;
}

