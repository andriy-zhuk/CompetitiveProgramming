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
LL n, k;
string s, t;
vector<int> q;

void solve()
{
	cin >> n >> k >> s;
	q.clear();
	FOR(i, 0, n)
	{
		if (s[i] == '0')
		{
			q.PB(i);
		}
	}

	int left = 0;
	int doun = q.size();
	FOR(i, 0, q.size())
	{
		if (q[i] - left <= k)
		{
			k -= q[i] - left;
			left++;
		}
		else
		{
			doun = i;
			break;
		}
	}
	if (doun == q.size())
	{
		FOR(i, 0, q.size())
		{
			cout << '0';
		}
		FOR(i, 0, n - (int)q.size())
		{
			cout << '1';
		}
		cout << endl;
		return;
	}
	
	t = "";
	FOR(i, 0, doun)
	{
		t += '0';
	}
	int count = 0;
	FOR(i, 0, n)
	{
		if (s[i] == '0')
		{
			count++;
			if (count <= doun)
			{
				continue;
			}
		}
		t += s[i];
	}
	int p = q[doun];
	FOR(i, 0, k)
	{
		if (p != 0)
		{
			swap(t[p], t[p - 1]);
			p--;
		}
	}
	cout << t << endl;
	return;
}

int main()
{
	ios_base::sync_with_stdio(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int q;
	cin >> q;
	while (q--)
	{
		solve();
	}


	return 0;
}

