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

vector<int> ign;
pair<int, int> trash;
int n;
string s;

int ok()
{
	int bal = 0;
	FOR(i, 0, n)
	{
		if (ign.size() && i == ign[0])
			continue;
		if (ign.size() >= 2 && i == ign[1])
			continue;
		if (s[i] == '(')
		{
			bal++;
		}
		if (s[i] == ')')
		{
			bal--;
			if (bal < 0)
			{
				return i;
			}
		}
	}
	if (bal > 0)
		return n;
	return -1;
}

int c = 0;
int d = 0;
int main()
{
	ios_base::sync_with_stdio(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> n;
	cin >> s;
	FOR(i, 0, n)
	{
		if (s[i] == '(')
		{
			c++;
		}
		else
		{
			d++;
		}
	}
	if (c != d)
	{
		cout << "No";
		return 0;
	}
	int ans = ok();
	if (ans == -1)
	{
		cout << "Yes";
		return 0;
	}
	if (ans == n)
	{
		cout << "No";
		return 0;
	}
	ign.PB(ans);
	ans = ok();
	if (ans == n)
	{
		cout << "Yes";
		return 0;
	}
	cout << "No";
	return 0;
}