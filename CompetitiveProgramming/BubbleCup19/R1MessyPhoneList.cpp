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

struct contact
{
	string code;
	string phone;
	string firstname;
	string lastname;
	bool operator<(const contact& c) const
	{
		if (lastname == c.lastname)
			return firstname < c.firstname;
		return lastname < c.lastname;
	}
	void print() const
	{
		cout << firstname << ' ' << lastname << ": " << code << '-' << phone << endl;
	}
};
string adamsCode;

bool checkLetters(const string& a, int l, int r)
{
	FOR(i, l, r)
	{
		if ((a[i] >= '0' && a[i] <= '9') || a[i] == '/' || a[i] == '-')
			return false;
	}
	return true;
}
bool checkDigits(const string& a, int l, int r)
{
	FOR(i, l, r)
	{
		if ((a[i] >= 'A' && a[i] <= 'Z')  ||  (a[i] >= 'a' && a[i] <= 'z') || a[i] == ',')
			return false;
	}
	return true;
}

pair<string, string> split(const string& s, char ch)
{
	pair<string, string> res = MP("", "");
	bool flag = true;
	FOR(i, 0, s.size())
	{
		if (s[i] == ch)
			flag = false;
		else
		{
			if (flag)
				res.f.PB(s[i]);
			else
				res.s.PB(s[i]);
		}
	}
	return res;
}

void normalizeName(string& s)
{
	FOR(i, 0, s.size())
	{
		if (s[i] >= 'A' && s[i] <= 'Z')
			s[i] = s[i] - 'A' + 'a';
	}
	s[0] = s[0] - 'a' + 'A';
}

void normalizeNumber(string& s)
{
	string t = "";
	FOR(i, 0, s.size())
	{
		if (s[i] != ' ')
			t += s[i];
	}
	s = t;
}

bool getNames(string s, string &firstname, string &lastname)
{
	FOR(i, 0, 2)
	{
		while (s.size() && s.back() == ' ')
			s.pop_back();
		reverse(ALL(s));
	} // delete first and last spaces
	int commacnt = 0;
	int spacecnt = 0;
	FOR(i, 0, s.size())
	{
		if (s[i] == ',')
			commacnt++;
		if (s[i] == ' ')
			spacecnt++;
	}
	if (commacnt + spacecnt != 1)
		return false;
	if (commacnt)
	{
		pair<string, string> cur = split(s, ',');
		firstname = cur.second;
		lastname = cur.first;
	}
	else
	{
		pair<string, string> cur = split(s, ' ');
		firstname = cur.first;
		lastname = cur.second;
	}
	normalizeName(firstname);
	normalizeName(lastname);
	return true;
}

bool getPhone(string s, string& code, string& number)
{
	int separators = 0;
	FOR(i, 0, s.size())
		if (s[i] == '-' || s[i] == '/')
			s[i] = '/', separators++;
	if (separators == 0)
	{
		code = adamsCode;
		number = s;
	}
	if (separators == 1)
	{
		pair<string, string> cur = split(s, '/');
		code = cur.first;
		number = cur.second;
	}
	if (separators > 1)
		return false;
	normalizeNumber(code);
	normalizeNumber(number);
	return true;
}


bool normalize(string s, contact &c)
{
	string n, p;
	c = { "", "", "", ""};
	bool flag = false;
	FOR(i, 0, s.size())
	{
		if (s[i] == ' ')
		{
			if (checkDigits(s, 0, i) && checkLetters(s, i, s.size()))
			{
				flag = true;
				n = s.substr(i, s.size() - i);
				p = s.substr(0, i);
				break;
			}
			if (checkLetters(s, 0, i) && checkDigits(s, i, s.size()))
			{
				flag = true;
				p = s.substr(i, s.size() - i);
				n = s.substr(0, i);
				break;
			}
		}
	}
	if (!flag)
		return false;

	if (!getNames(n, c.firstname, c.lastname))
		return false;
	if (!getPhone(p, c.code, c.phone))
		return false;
	return true;
}
void solve()
{
	set<contact> foo;
	set<pair<string, string>> used;
	int n;
	cin >> n >> adamsCode;
	string line;
	getline(cin, line);
	FOR(i, 0, n)
	{
		getline(cin, line);
		contact a;
		if (normalize(line, a))
		{
			bool ok = true;
			for (auto&iter: used)
			{
				if (a.code == iter.first && a.phone == iter.second)
				{
					bool found = true;
					for (auto& it : foo)
					{
						if (it.code == a.code && it.phone == a.phone && (it.firstname == a.firstname && it.lastname == a.lastname))
						{
							found = false;
							break;
						}
						if (it.code == a.code && it.phone == a.phone && not(it.firstname == a.firstname && it.lastname == a.lastname))
						{
							foo.erase(it);
							break;
						}
					}
					if (found)
						ok = false;
					break;
				}
			}
			if (!ok)
				continue;
			auto it = foo.lower_bound(a);
			if (it != foo.end() && it->firstname == a.firstname && it->lastname == a.lastname)
			{
				//used.erase(MP(it->code, it->phone));
				foo.erase(it);	
			}
			foo.insert(a);
			used.insert(MP(a.code, a.phone));
		}
		else
		{
			//cout << "BAD" << endl;
		}
	}
	cout << foo.size() << endl;
	for (auto& iter : foo)
	{
		iter.print();
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int tt;
	cin >> tt;
	while (tt--)
	{
		solve();
	}
	return 0;
}

