#line 2 "OnlySanta.cpp"
#include <string.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <functional>
#include <limits>
using namespace std;

string A = " SANTA";
string B = " SATAN";

int dp[1005][7][7];
struct PT {
	int i, j, k; char x;
	PT() {}
	PT(int i, int j, int k, char x) : i(i), j(j), k(k), x(x) {}
} C[1005][7][7];
const int L = 5;

class OnlySanta {
public:
	string solve(string S) {
		memset(dp, 0, sizeof(dp));
		memset(C, 0, sizeof(C));
		int N = S.size();
		S = " " + S;
		dp[0][0][0] = 1;
		C[0][0][0] = PT(-1, 0, 0, 0);
		for (int i = 0; i <= N; i++) {
			for (int j = 0; j <= 5; j++) {
				for (int k = 0; k <= 5; k++) {
					if (!dp[i][j][k]) continue;
					if (i + 1 <= N) {
						int jp = 0, kp = 0;
						if (j + 1 <= 5 && S[i + 1] == A[j + 1]) jp = 1;
						if (k + 1 <= 5 && S[i + 1] == B[k + 1]) kp = 1;
						dp[i + 1][j + jp][k + kp] = 1;
						C[i + 1][j + jp][k + kp] = PT(i, j, k, 0);
					}
					for (char x = 'A'; x <= 'Z'; x++) {
						int jp = 0, kp = 0;
						if (j + 1 <= 5 && x == A[j + 1]) jp = 1;
						if (k + 1 <= 5 && x == B[k + 1]) kp = 1;
						if (jp == 0 && kp == 0) continue;
						dp[i][j + jp][k + kp] = 1;
						C[i][j + jp][k + kp] = PT(i, j, k, x);
					}
				}
			}
		}
		string ans = "";
		for (int L = 0; L <= 4; L++) {
			if (dp[N][5][L]) {
				PT now = PT(N, 5, L, 0);
				while (now.i >= 0) {
					int i = now.i;
					int j = now.j;
					int k = now.k;
					if (C[i][j][k].x > 0) {
						ans += C[i][j][k].x;
					}
					else {
						if (i > 0) ans += S[i];
					}
					now = C[i][j][k];
				}
				reverse(ans.begin(), ans.end());
				break;
			}
		}
		return ans;
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
	freopen("output.txt", "w", stdout);
	argc = 0;
	if (argc == 1) 
	{
		cout << "Testing OnlySanta (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1515636142;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 250.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc = 0;
		//istringstream(argv[1]) >> _tc;
		OnlySanta _obj;
		string _expected, _received, _input;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string S = "ATANSATN";
				_input = S;
				_expected = "";
				_received = _obj.solve(S); break;
			}
			case 1:
			{
				string S = "STN";
				_input = S;
				_expected = "SANTNA";
				_received = _obj.solve(S); break;
			}
			case 2:
			{
				string S = "RATSNOOOA";
				_input = S;
				_expected = "DEARATSNOOOSANTA";
				_received = _obj.solve(S); break;
			}
			case 3:
			{
				string S = "SXAYNTA";
				_input = S;
				_expected = "OOOOSOXAYNTOOOOAOOO";
				_received = _obj.solve(S); break;
			}
			case 4:
			{
				string S = "SNTA";
				_input = S;
				_expected = "SANTA";
				_received = _obj.solve(S); break;
			}
			case 5:
			{
				string S = "ASNTA";
				_input = S;
				_expected = "SASNTAS";
				_received = _obj.solve(S); break;
			}
			case 6:
			{
				string S = "NIELATA";
				_input = S;
				_expected = "SANIELATAJA";
				_received = _obj.solve(S); break;
			}
			case 7:
			{
				string S = "X";
				_input = S;
				_expected = "SSAAXNNTTAA";
				_received = _obj.solve(S); break;
			}
			case 8:
			{
				string S = "SATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATASATA";
				_input = S;
				_expected = "";
				_received = _obj.solve(S); break;
			}
			/*case 9:
			{
				string S = ;
				_expected = ;
				_received = _obj.solve(S); break;
			}*/
			/*case 10:
			{
				string S = ;
				_expected = ;
				_received = _obj.solve(S); break;
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
			cout << "   Input: " << "\"" << _input << "\"" << endl;
			cout << "Expected: " << "\"" << _expected << "\"" << endl;
			cout << "Received: " << "\"" << _received << "\"" << endl;
		}
	}
}

// END CUT HERE
