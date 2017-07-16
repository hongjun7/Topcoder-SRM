#line 2 "InterleavingParenthesis.cpp"
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
const int mod = 1e9 + 7;
int dp[2505][2505], a[2505], b[2505];
class InterleavingParenthesis {
	public:
	int countWays(string s1, string s2) {
		int n = s1.size(), m = s2.size();
		s1 = " " + s1;
		s2 = " " + s2;
		memset(dp, 0, sizeof(dp));
		for (int i = 1; i <= n; i++) {
			a[i] = a[i - 1] + (s1[i] == '(' ? 1 : -1);
		}
		for (int i = 1; i <= m; i++) {
			b[i] = b[i - 1] + (s2[i] == '(' ? 1 : -1);
		}
		dp[0][0] = 1;
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= m; j++) {
				if (!dp[i][j]) continue;
				if (i + 1 <= n) {
					if (a[i + 1] + b[j] >= 0) {
						dp[i + 1][j] += dp[i][j];
						dp[i + 1][j] %= mod;
					}
				}
				if (j + 1 <= m) {
					if (a[i] + b[j + 1] >= 0) {
						dp[i][j + 1] += dp[i][j];
						dp[i][j + 1] %= mod;
					}
				}
			}
		}
		if (a[n] + b[m] == 0) return dp[n][m];
		return 0;
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
//	argc = 0;
	if (argc == 1) 
	{
		cout << "Testing InterleavingParenthesis (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1499907603;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 250.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc;
		//_tc = 0;
		istringstream(argv[1]) >> _tc;
		InterleavingParenthesis _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string s1 = "(()";
				string s2 = "())";
				_expected = 19;
				_received = _obj.countWays(s1, s2); break;
			}
			case 1:
			{
				string s1 = ")";
				string s2 = "(";
				_expected = 1;
				_received = _obj.countWays(s1, s2); break;
			}
			case 2:
			{
				string s1 = "(((((";
				string s2 = ")))))";
				_expected = 42;
				_received = _obj.countWays(s1, s2); break;
			}
			case 3:
			{
				string s1 = "()(()";
				string s2 = "))((())";
				_expected = 10;
				_received = _obj.countWays(s1, s2); break;
			}
			case 4:
			{
				string s1 = "()()()()()()()()()()()()()()()()()()()()";
				string s2 = "()()()()()()()()()()()()()()()()()";
				_expected = 487340184;
				_received = _obj.countWays(s1, s2); break;
			}
			case 5:
			{
				string s1 = "(())())))";
				string s2 = "(())()";
				_expected = 0;
				_received = _obj.countWays(s1, s2); break;
			}
			/*case 6:
			{
				string s1 = ;
				string s2 = ;
				_expected = ;
				_received = _obj.countWays(s1, s2); break;
			}*/
			/*case 7:
			{
				string s1 = ;
				string s2 = ;
				_expected = ;
				_received = _obj.countWays(s1, s2); break;
			}*/
			/*case 8:
			{
				string s1 = ;
				string s2 = ;
				_expected = ;
				_received = _obj.countWays(s1, s2); break;
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
