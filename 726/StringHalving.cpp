#line 2 "StringHalving.cpp"
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

class StringHalving {
public:
	string lexsmallest(string s) {
		for (char x = 'a'; x <= 'z'; x++) {
			int chk[26] = { 0, };
			for (auto &y : s) {
				if (y == x) return string(1, x);
				if (++chk[y - 'a'] == 2) break;
			}
		}
		return "";
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
		cout << "Testing StringHalving (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1516018764;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 250.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		StringHalving _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string s = "baba";
				_expected = "a";
				_received = _obj.lexsmallest(s); break;
			}
			case 1:
			{
				string s = "bbaa";
				_expected = "b";
				_received = _obj.lexsmallest(s); break;
			}
			case 2:
			{
				string s = "zyiggiyssz";
				_expected = "g";
				_received = _obj.lexsmallest(s); break;
			}
			case 3:
			{
				string s = "topcodertpcder";
				_expected = "c";
				_received = _obj.lexsmallest(s); break;
			}
			case 4:
			{
				string s = "rvofqorvfq";
				_expected = "f";
				_received = _obj.lexsmallest(s); break;
			}
			/*case 5:
			{
				string s = ;
				_expected = ;
				_received = _obj.lexsmallest(s); break;
			}*/
			/*case 6:
			{
				string s = ;
				_expected = ;
				_received = _obj.lexsmallest(s); break;
			}*/
			/*case 7:
			{
				string s = ;
				_expected = ;
				_received = _obj.lexsmallest(s); break;
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
			cout << "           Expected: " << "\"" << _expected << "\"" << endl;
			cout << "           Received: " << "\"" << _received << "\"" << endl;
		}
	}
}

// END CUT HERE
