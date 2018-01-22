#line 2 "RememberWordsEasy.cpp"
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

typedef long long ll;

const string Yes = "Possible";
const string No = "Impossible";

class RememberWordsEasy {
public:
	ll fR(ll s, ll D) {
		ll e = s + D - 1;
		return (s + e)*D / 2;
	}
	ll fL(ll e, ll D) {
		ll s = max(0LL, e - (D - 1));
		return (s + e)*(e - s + 1) / 2;
	}
	ll Low(int D, int W) {
		ll v = (1LL << 30) - 1;
		for (int i = 29; i >= 0; i--) if (fR(v - (1LL << i), D) >= W) v -= 1LL << i;
		return v;
	}
	ll High(int D, int W) {
		ll v = 0;
		if (W == 0) return 0;
		for (int i = 29; i >= 0; i--) if (fL(v + (1LL << i), D) <= W) v += 1LL << i;
		return v;
	}
	string isPossible(int d1, int d2, int w1, int w2) {
		ll L1 = Low(d1, w1), R1 = High(d1, w1);
		ll L2 = Low(d2, w2), R2 = High(d2, w2);
		if (L1 > R1 || L2 > R2) return No;
		if (R1 + 1 == L2) return Yes;
		if (R2 + 1 == L1) return Yes;
		if (max(L1, L2) <= min(R1, R2)) return Yes;
		return No;
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
		cout << "Testing RememberWordsEasy (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1516615844;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 500.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc = 0;
		istringstream(argv[1]) >> _tc;
		RememberWordsEasy _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int d1 = 2;
				int d2 = 3;
				int w1 = 7;
				int w2 = 18;
				_expected = "Possible";
				_received = _obj.isPossible(d1, d2, w1, w2); break;
			}
			case 1:
			{
				int d1 = 1;
				int d2 = 1;
				int w1 = 3;
				int w2 = 5;
				_expected = "Impossible";
				_received = _obj.isPossible(d1, d2, w1, w2); break;
			}
			case 2:
			{
				int d1 = 3;
				int d2 = 5;
				int w1 = 300;
				int w2 = 500;
				_expected = "Possible";
				_received = _obj.isPossible(d1, d2, w1, w2); break;
			}
			case 3:
			{
				int d1 = 100;
				int d2 = 1;
				int w1 = 0;
				int w2 = 2;
				_expected = "Impossible";
				_received = _obj.isPossible(d1, d2, w1, w2); break;
			}
			case 4:
			{
				int d1 = 1000000;
				int d2 = 1000000;
				int w1 = 1000000;
				int w2 = 1000000;
				_expected = "Possible";
				_received = _obj.isPossible(d1, d2, w1, w2); break;
			}
			case 5:
			{
				int d1 = 5;
				int d2 = 3;
				int w1 = 12;
				int w2 = 0;
				_expected = "Possible";
				_received = _obj.isPossible(d1, d2, w1, w2); break;
			}
			/*case 6:
			{
				int d1 = ;
				int d2 = ;
				int w1 = ;
				int w2 = ;
				_expected = ;
				_received = _obj.isPossible(d1, d2, w1, w2); break;
			}*/
			/*case 7:
			{
				int d1 = ;
				int d2 = ;
				int w1 = ;
				int w2 = ;
				_expected = ;
				_received = _obj.isPossible(d1, d2, w1, w2); break;
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
