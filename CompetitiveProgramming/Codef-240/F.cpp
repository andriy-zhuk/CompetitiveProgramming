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

int n, m;

int l, r;
struct ST
{
	int t[4*MAX];
	int col[4*MAX];

	void push(int v)
	{
		if (col[v] != -1)
		{
			col[v + v] = col[v + v + 1] = col[v];
		}
		col[v] = -1;
	}

	int getVal(int v, int tl, int tr)
	{
		if (col[v] == -1)
		{
			return t[v];
		}
		return (tr - tl + 1) * col[v];
	}

	void upd(int v, int tl, int tr, int l, int r, int c)
	{
		if (l > r)
			return;
		if (tl == l && r == tr)
		{
			col[v] = c;
			return;
		}
		int tm = (tl + tr) >> 1;
		push(v);
		upd(v + v, tl, tm, l, min(r, tm), c);
		upd(v + v + 1, tm + 1, tr, max(l, tm + 1), r, c);
		t[v] = getVal(v + v, tl, tm) + getVal(v + v + 1, tm + 1, tr);
	}

	int get(int v, int tl, int tr, int l, int r)
	{
		if (l > r)
			return 0;
		if (tl == l && r == tr)
		{
			return getVal(v, tl, tr);
		}
		push(v);
		int tm = (tl + tr) >> 1;
		t[v] = getVal(v + v, tl, tm) + getVal(v + v + 1, tm + 1, tr);
		return get(v + v, tl, tm, l, min(r, tm)) + get(v + v + 1, tm + 1, tr, max(l, tm + 1), r);
	}
} foo[26];
int cnt[26];

int main()
{
	ios_base::sync_with_stdio(0);
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	FOR(i, 0, 26)
	{
		FILL(foo[i].col, -1);
	}
	int n, m;
	cin >> n >> m;
	string s;

	cin >> s;
	FOR(i, 0, SZ(s))
	{
		foo[s[i] - 'a'].upd(1, 0, n - 1, i, i, 1);
	}
	while (m--)
	{
		FILL(cnt, 0);
		cin >> l >> r;
		l--, r--;
		int nep = 0;
		/*FOR(i, 0, 26)
		{
			FOR(j, l, r + 1)
			{
				if (s[j] - 'a' == i)
					cnt[i]++;
			}
			if (cnt[i] % 2 == 1)
				nep++;
			cout << cnt[i] << ' ';
		}*/
		FOR(i, 0, 26)
		{
			cnt[i] = foo[i].get(1, 0, n - 1, l, r);
			if (cnt[i] % 2 == 1)
				nep++;
		}
		if (nep >= 2)
			continue;
		int ll = l, rr = r;
		FOR(i, 0, 26)
		{
			foo[i].upd(1, 0, n - 1, ll, rr, 0);
			if (cnt[i] % 2 == 1)
			{
				foo[i].upd(1, 0, n - 1, (ll + rr) / 2, (ll + rr) / 2, 1);
				cnt[i]--;
			}
			foo[i].upd(1, 0, n - 1, l, l + cnt[i] / 2 - 1, 1);
			foo[i].upd(1, 0, n - 1, r - cnt[i] / 2 + 1, r, 1);
			l += cnt[i] / 2;
			r -= cnt[i] / 2;
		}
	}
	FOR(i, 0, SZ(s))
	{
		FOR(k, 0, 26)
		{
			if (foo[k].get(1, 0, n - 1, i, i))
			{
				cout << char(k + 'a');
				break;
			}
		}
	}



	return 0;
}
//
//500 10
//dhlvqqddhqqllqhdllddhdvllqdlvhlqvvvvlvlddlqqvqlvvdhhvqhvhdlqvhqvvlvlqhvdqdhvldqvqqhlhhdhqlhvqvvdqvlvqqhqdvldvvvddldqvllqhdvhldlhvlhllhqddddlhhlvhqhhvqvvdhhvdhhqdlhhdlqqvhlddhhhvvdvhddqhhvdqddqqqdllqqdllvhdqdhlqllqvvdlhqvlvhdvhdlvdldqdldqdqvhqvlvqvldvvdddvldldllldqdhhqqqdqqqlhlhqdlqqqldlhqqlldhlhvhhhvqlvlvdlqhvddqvhqhqhqdldddhhhqllhhlvdvvdhhdlqlhqqqdvhhhdhhldvllvqhqqlqqhdqlhlvqqlqlhlhhvhlhllqhdhhldhdqldqlvvdvlqhqqhqlvvdvqvqvlqvqvlqddlqhvhhlhqhvqqlddhldqldvqvldqlqhhhqqllvqdvddqdqqvhvvhhdddlqlqqqql
//180 221
//263 446
//110 141
//69 318
//328 357
//271 304
//25 380
//80 209
//182 409
//357 377


//500 1
//dhlvqqddhqqllqhdllddhdvllqdlvhlqvvvvlvlddlqqvqlvvdhhvqhvhdlqvhqvvlvlqhvdqdhvldqvqqhlhhdhqlhvqvvdqvlvqqhqdvldvvvddldqvllqhdvhldlhvlhllhqddddlhhlvhqhhvqvvdhhvdhhqdlhhdlqqvhlddhhhvvdvhddqhhvdqddqqqdllqqdllvhdqdhlqllqvvdlhqvlvhdvhdlvdldqdldqdqvhqvlvqvldvvdddvldldllldqdhhqqqdqqqlhlhqdlqqqldlhqqlldhlhvhhhvqlvlvdlqhvddqvhqhqhqdldddhhhqllhhlvdvvdhhdlqlhqqqdvhhhdhhldvllvqhqqlqqhdqlhlvqqlqlhlhhvhlhllqhdhhldhdqldqlvvdvlqhqqhqlvvdvqvqvlqvqvlqddlqhvhhlhqhvqqlddhldqldvqvldqlqhhhqqllvqdvddqdqqvhvvhhdddlqlqqqql
//25 380

