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
string b;

PII L = MP(-INF, INF);
PII R = MP(-INF, INF);

int main()
{
	ios_base::sync_with_stdio(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> n;
	FOR(i, 0, n)
	{
		cin >> a[i];
	}
	cin >> b;
	FOR(i, 4, n)
	{
		if (b[i - 1] == '0' && b[i - 2] == '0' && b[i - 3] == '0' && b[i - 4] == '0')
		{
			int cur = a[i];
			FOR(j, -4, 0)
			{
				cur = max(cur, a[i + j]);
			}
			if (b[i] == '0')
			{
				L.second = min(L.second, cur);
			}
			else
			{
				L.first = max(L.first, cur+1);
			}
		}
		if (b[i - 1] == '1' && b[i - 2] == '1' && b[i - 3] == '1' && b[i - 4] == '1')
		{
			int cur = a[i];
			FOR(j, -4, 0)
			{
				cur = min(cur, a[i + j]);
			}
			if (b[i] == '0')
			{
				R.second = min(R.second, cur - 1);
			}
			else
			{
				R.first = max(R.first, cur);
			}
		}
	}
	cout << L.first << ' ' << R.second << endl;



	return 0;
}

