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
#define count asdasdfcoutn
typedef long long LL;
typedef pair<int, int> PII;
typedef vector<LL> VI;
typedef pair<LL, LL> PLL;

const int INF = 1000 * 1000 * 1000;
const LL LINF = 1LL * INF * INF;
const int MAX = 100010;
const long double PI = acos(-1.);
const double EPS = 1e-6;
const LL mod = INF + 6;
const int MAXPR = 2750160;
bool pr[MAXPR];
vector<int> prime;
void gen()
{
	pr[0] = 1; pr[1] = 1;
	FOR(i, 2, MAXPR)
	{
		if (pr[i])
			continue;
		prime.PB(i);
		LL j = 1LL * i * i;
		while (j < MAXPR)
		{
			pr[j] = 1;
			j += i;
		}
	}
}

int n;
int b[400005];
int cnt[MAXPR];
int count[MAXPR];

int minDiv(int x)
{
	if (pr[x] == 0)
		return 1;
	FOR(i, 0, prime.size())
	{
		if (x % prime[i] == 0)
		{
			return prime[i];
		}
	}
}

int getY(int x)
{
	int y = x / minDiv(x);
	if (y == x)
		if (x - 1 < prime.size())
		{
			y = prime[x - 1];
		}
		else
		{
			return INF;
		}
	return y;
}

int main()
{
	ios_base::sync_with_stdio(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	gen();
	int n;
	cin >> n;
	FOR(i, 0, 2 * n)
	{
		cin >> b[i];
		count[b[i]]++;
	}

	FOR(i, 0, prime.size())
	{
		if (prime[i] > 200000)
		{
			break;
		}
		cnt[getY(prime[i])] = prime[i];
	}
	vector<int> ans;
	RFOR(i, MAXPR, 0)
	{
		int x = 0, y= 0;
		if (count[i])
			y = cnt[i];
		if (count[i] && pr[i] == 1)
			x = minDiv(i);
		while (count[i]--)
		{
			if (pr[i] != 0)
			{
				count[i/x]--;
				ans.PB(i);
			}
			else
			{
				count[y]--;
				ans.PB(y);
			}
		}
	}
	
	FOR(i, 0, ans.size())
	{
		cout << ans[i] << ' ';
	}






	return 0;
}