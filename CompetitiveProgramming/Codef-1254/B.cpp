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
int a[100005];

LL run(int k)
{
	if (k == 1)
	{
		return LINF;
	}
	int cur = 0;
	LL ans = 0;
	bool flag = true;
	if (k % 2 == 0)
	{
		FOR(i, 0, n)
		{
			if (flag)
			{
				ans += cur;
				cur += a[i];
				if (cur == k / 2)
				{
					flag = false;
					ans += cur;
				}
			}
			else
			{
				cur -= a[i];
				ans += cur;
				if (cur == 0)
				{
					flag = true;
				}
			}
		}
	}
	else
	{
		FOR(i, 0, n)
		{
			if (flag)
			{
				ans += cur;
				cur += a[i];
				if (cur == (k + 1) / 2)
				{
					flag = false;
					i--;
				}
			}
			else
			{
				cur -= a[i];
				ans += cur;
				if (cur == 0)
				{
					flag = true;
				}
			}
		}
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> n;
	int sum = 0;
	FOR(i, 0, n)
	{
		cin >> a[i];
		sum += a[i];
	}
	if (sum == 1)
	{
		cout << -1 << endl;
		return 0;
	}
	n++;
	LL best = LINF;
	for (int i = 1; i * i <= sum; ++i)
	{
		if (sum % i == 0)
		{
			best = min(best, run(i));
			best = min(best, run(sum / i));
		}
	}

	cout << best << endl;

	return 0;
}

