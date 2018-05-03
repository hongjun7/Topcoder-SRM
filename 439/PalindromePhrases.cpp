#line 2 "PalindromePhrases.cpp"
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <string>
#include <string.h>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef pair<int,int> pii; 
typedef long long ll;
typedef unsigned long long ull;
#define sz(a) int((a).size()) 
#define all(c) (c).begin(),(c).end() 

int N;
string W[2][13];
long long dp[1 << 13][13][2][14];

class PalindromePhrases {
public:
	bool ispalin(string s) {
		int i = 0, j = s.size() - 1;
		while (i < j) {
			if (s[i] != s[j]) return 0;
			i++; j--;
		}
		return 1;
	}
	int common(const string &ls, const string &rs) {
		int ret = 0;
		for (int i = 0; i < ls.size() && i < rs.size(); i++) {
			if (ls[i] == rs[i]) ++ret;
		}
		return ret;
	}
	long long go(int msk, int k, int side, int len) {
		long long &cur = dp[msk][k][side][len];
		if (cur != -1) return cur;
		auto prv = W[!side][k];
		prv = prv.substr(prv.size() - len, len);
		cur = ispalin(prv);
		for (int i = 0; i < N; i++) {
			if ((1 << i)&msk) continue;
			int nxt = msk | (1 << i);
			string s1 = prv;
			string s2 = W[side][i];
			int L = common(s1, s2);
			if (L == s1.size()) cur += go(nxt, i, !side, s2.size() - L);
			else if (L == s2.size()) cur += go(nxt, k, side, len - L);
		}
		return cur;
	}
	long long getAmount(vector <string> words) {
		N = words.size();
		for (int i = 0; i < N; i++) {
			W[0][i] = W[1][i] = words[i];
			reverse(W[1][i].begin(), W[1][i].end());
		}
		memset(dp, -1, sizeof(dp));
		return go(0, 0, 0, 0) - 1;
	}
};
// BEGIN CUT HERE
#include <ctime>
#include <cmath>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char* argv[])
{
	if (argc == 1) 
	{
		cout << "Testing PalindromePhrases (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1525354026;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 500.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc;
		istringstream(argv[1]) >> _tc;
		PalindromePhrases _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string words[] = {"a","ba"};
				_expected = 2LL;
				_received = _obj.getAmount(vector <string>(words, words+sizeof(words)/sizeof(string))); break;
			}
			case 1:
			{
				string words[] = {"ab","bcd","efg"};
				_expected = 0LL;
				_received = _obj.getAmount(vector <string>(words, words+sizeof(words)/sizeof(string))); break;
			}
			case 2:
			{
				string words[] = {"a", "bba", "abb"};
				_expected = 7LL;
				_received = _obj.getAmount(vector <string>(words, words+sizeof(words)/sizeof(string))); break;
			}
			case 3:
			{
				string words[] = {"aabccc", "ccbbca", "a", "acaabb", "aaa", "aab", "c", "babb", "aacaa", "b"};
				_expected = 47LL;
				_received = _obj.getAmount(vector <string>(words, words+sizeof(words)/sizeof(string))); break;
			}
			/*case 4:
			{
				string words[] = ;
				_expected = LL;
				_received = _obj.getAmount(vector <string>(words, words+sizeof(words)/sizeof(string))); break;
			}*/
			/*case 5:
			{
				string words[] = ;
				_expected = LL;
				_received = _obj.getAmount(vector <string>(words, words+sizeof(words)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string words[] = ;
				_expected = LL;
				_received = _obj.getAmount(vector <string>(words, words+sizeof(words)/sizeof(string))); break;
			}*/
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		double _elapsed = (double)(clock()-_start)/CLOCKS_PER_SEC;
		if (_received == _expected)
			cout << "#" << _tc << ": Passed (" << _elapsed << " secs)" << endl;
		else
		{
			cout << "#" << _tc << ": Failed (" << _elapsed << " secs)" << endl;
			cout << "           Expected: " << _expected << endl;
			cout << "           Received: " << _received << endl;
		}
	}
}

// END CUT HERE
