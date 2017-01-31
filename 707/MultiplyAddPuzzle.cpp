#line 2 "MultiplyAddPuzzle.cpp"
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
class MultiplyAddPuzzle {
	public:
	long long minimalSteps(long long s, long long t, long long a, long long b) {
		if (s == t) return 0;
		long long ans = 0;
		if (b == 0) {
			if (t == 0) return 1;
			if (a == 0) return -1;
			ans = -1;
			if (t % a == 0) ans = t / a + 1;
			if (t > s && (t - s) % a == 0) ans = (t - s) / a;
			return ans;
		}
		if (b == 1) {
			if (a == 0) return -1;
			if (t > s && (t - s) % a == 0) return (t - s) / a;
			return -1;
		}
		if (a == 0) {
			int cnt = 0;
			while (cnt <= 60) {
				if (s == t) return cnt;
				double lg = log10(s) + log10(b);
				if (lg > log10(t) + (1e-9)) break;
				s *= b;
				cnt++;
			}
			return -1;
		}
		long long pw[61] = { 0, }; int pn;
		pw[0] = 1; pn = 0;
		for (int i = 1; i <= 60; i++) {
			if (log10(pw[i - 1]) + log10(b) > log10(t) + (1e-9)) break;
			pw[i] = pw[i - 1] * b;
			pn = i;
		}
		int k = 0;
		ans = -1;
		long long i = s;
		while (k <= pn) {
			if (t < i) break;
			if ((t - i) % a == 0) {
				long long cnt = k;
				long long r = (t - i) / a;
				for (int i = k; i >= 0; i--) {
					cnt += r / pw[i];
					r %= pw[i];
				}
				if (ans < 0 || ans > cnt) ans = cnt;
			}
			if (i != 0) {
				double lg = log10(i) + log10(b);
				if (lg > log10(t) + (1e-9)) break;
				i *= b;
			}
			k++;
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
	if (argc == 1) 
	{
		cout << "Testing MultiplyAddPuzzle (450.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1485829783;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 450.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		MultiplyAddPuzzle _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				long long s = 0;
				long long t = 1000;
				long long a = 0;
				long long b = 2;
				_expected = -1LL;
				_received = _obj.minimalSteps(s, t, a, b); break;
			}
			case 1:
			{
				long long s = 10LL;
				long long t = 28LL;
				long long a = 4LL;
				long long b = 2LL;
				_expected = 2LL;
				_received = _obj.minimalSteps(s, t, a, b); break;
			}
			case 2:
			{
				long long s = 10LL;
				long long t = 99LL;
				long long a = 4LL;
				long long b = 2LL;
				_expected = -1LL;
				_received = _obj.minimalSteps(s, t, a, b); break;
			}
			case 3:
			{
				long long s = 345LL;
				long long t = 12345LL;
				long long a = 1LL;
				long long b = 10LL;
				_expected = 895LL;
				_received = _obj.minimalSteps(s, t, a, b); break;
			}
			case 4:
			{
				long long s = 1000000000000000000LL;
				long long t = 1000000000000000000LL;
				long long a = 1000000000000000000LL;
				long long b = 1000000000000000000LL;
				_expected = 0LL;
				_received = _obj.minimalSteps(s, t, a, b); break;
			}
			/*case 5:
			{
				long long s = LL;
				long long t = LL;
				long long a = LL;
				long long b = LL;
				_expected = LL;
				_received = _obj.minimalSteps(s, t, a, b); break;
			}*/
			/*case 6:
			{
				long long s = LL;
				long long t = LL;
				long long a = LL;
				long long b = LL;
				_expected = LL;
				_received = _obj.minimalSteps(s, t, a, b); break;
			}*/
			/*case 7:
			{
				long long s = LL;
				long long t = LL;
				long long a = LL;
				long long b = LL;
				_expected = LL;
				_received = _obj.minimalSteps(s, t, a, b); break;
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
