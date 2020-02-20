
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
LL l, r;

vector<int> L, R;

int cnt[10];
int answer = 0;

bool dp(int pos, int moreL, int lessR)
{
	//cout << pos << ' ' << moreL << ' ' << lessR << endl;
	if (moreL && lessR)
		return 1;
	if (pos == SZ(L))
		return 1;

	if (!moreL && !lessR)
	{
		if (L[pos] == R[pos])
		{
			if (cnt[L[pos]])
			{
				cnt[L[pos]]--;
				if (dp(pos + 1, 0, 0))
				{
					cnt[L[pos]]++;
					return 1;
				}
				cnt[L[pos]]++;
			}
			return 0;
		}
		FOR(i, L[pos] + 1, R[pos])
		{
			if (cnt[i])
				return 1;
		}
		if (cnt[L[pos]])
		{
			cnt[L[pos]]--;
			if (dp(pos + 1, 0, 1))
			{
				cnt[L[pos]]++;
				return 1;
			}
			cnt[L[pos]]++;
		}
		if (cnt[R[pos]])
		{
			cnt[R[pos]]--;
			if (dp(pos + 1, 1, 0))
			{
				cnt[R[pos]]++;
				return 1;
			}
			cnt[R[pos]]++;
		}
		return 0;
	} 

	if (moreL)
	{
		FOR(i, 0, R[pos])
		{
			if (cnt[i])
				return 1;
		}
		if (cnt[R[pos]])
		{
			cnt[R[pos]]--;
			if (dp(pos + 1, 1, 0))
			{
				cnt[R[pos]]++;
				return 1;
			}
			cnt[R[pos]]++;
			return 0;
		}
		return 0;
	}

	if (lessR)
	{
		FOR(i, L[pos] + 1, 10)
		{
			if (cnt[i])
				return 1;
		}
		if (cnt[L[pos]])
		{
			cnt[L[pos]]--;
			if (dp(pos + 1, 0, 1))
			{
				cnt[L[pos]]++;
				return 1;
			}
			cnt[L[pos]]++;
		}
		return 0;
	}
}
void gen(int sz, int last)
{
	if (sz == SZ(L))
	{
		if (dp(0, 0, 0))
		{
			answer++;
		}
		return;
	}
	FOR(i, last, 10)
	{
		cnt[i]++;
		gen(sz + 1, i);
		cnt[i]--;
	}
}


int main()
{
	ios_base::sync_with_stdio(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	cin >> l >> r;

	while (l)
	{
		L.PB(l % 10);
		l /= 10;
	}
	while (r)
	{
		R.PB(r % 10);
		r /= 10;
	}

	while (L.size() < max(SZ(L), SZ(R)))
		L.PB(0);
	while (R.size() < max(SZ(L), SZ(R)))
		R.PB(0);
	reverse(ALL(L));
	reverse(ALL(R));
	gen(0, 0);
	cout << answer << endl;
	return 0;
}