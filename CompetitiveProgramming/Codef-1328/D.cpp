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
#include <queue> 
using namespace std;

#define PB push_back
#define MP make_pair
#define f first
#define s second
#define FOR(i,a,b) for (int i = a; i < b; ++i)
#define RFOR(i, b, a) for (int i = b-1; i>=a; --i)
#define FILL(a, b) memset(a, b, sizeof a)
#define ALL(a) a.begin(), a.end()
#define SZ(a) (int)a.size()

typedef unsigned long long ULL;
typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;

const int INF = 1000 * 1000 * 1000;
const LL LINF = 1LL * INF * INF;
const int MAX = 100010;
const long double PI = acos(-1.);
const double EPS = 1e-6;
const LL MOD = INF + 7;
int n;
int a[200005];
int ans[200005];

void solve()
{
	cin >> n;
	set<int> foo;
	FOR(i, 0, n)
	{
		cin >> a[i];
		foo.insert(a[i]);
	}
	if (foo.size() == 1)
	{
		cout << 1 << endl;
		FOR(i, 0, n)
		{
			cout << 1 << ' ';
		}
		cout << endl;
		return;
	}
	int beg = 0;
	while (a[beg] == a[(beg + 1) % n])
		beg = (beg+1)%n;
	int cur = (beg + 1) % n;
	int tt = 1;
	while (cur != beg)
	{
		if (a[cur] != a[(cur + 1) % n])
		{
			tt++;
		}
		cur = (cur + 1) % n;
	}
	int kk;
	if (tt % 2 == 0)
	{
		kk = 2;
	}
	else
	{
		kk = 3;
	}
	cur = (beg + 1) % n;
	int col = 0;
	do
	{
		if (a[cur] != a[(cur + n-1) % n])
		{
			col = col + 1;
			col %= kk;
		}
		ans[cur] = col + 1;
		cur = (cur + 1) % n;
	} while (cur != beg+1);
	cout << kk << endl;
	FOR(i, 0, n)
	{
		cout << ans[i] << ' ';
	}
	cout << endl;
}

int main()
{
	ios_base::sync_with_stdio(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int t;
	cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}

