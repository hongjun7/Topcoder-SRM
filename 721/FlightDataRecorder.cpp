#line 2 "FlightDataRecorder.cpp"
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

const double pi = 3.1415926535897932384626433832795;

class FlightDataRecorder {
public:
	double getDistance(vector <int> heading, vector <int> distance) {
		int n = heading.size();
		double ans;
		double x = 0, y = 0;
		for (int i = 0; i < n; i++) {
			double t = 1.0*heading[i] / 360 * 2 * pi;
			double px = cos(t), py = sin(t);
			x += px * distance[i];
			y += py * distance[i];
		}
		return sqrt(x*x + y * y);
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
		cout << "Testing FlightDataRecorder (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1516615279;
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
		FlightDataRecorder _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int heading[] = {90,0};
				int distance[] = {3,4};
				_expected = 5.0;
				_received = _obj.getDistance(vector <int>(heading, heading+sizeof(heading)/sizeof(int)), vector <int>(distance, distance+sizeof(distance)/sizeof(int))); break;
			}
			case 1:
			{
				int heading[] = {37,37,37,37};
				int distance[] = {1,10,100,1000};
				_expected = 1111.0;
				_received = _obj.getDistance(vector <int>(heading, heading+sizeof(heading)/sizeof(int)), vector <int>(distance, distance+sizeof(distance)/sizeof(int))); break;
			}
			case 2:
			{
				int heading[] = {0,120,240,0,120,240};
				int distance[] = {999,999,999,999,999,999};
				_expected = 6.431098710768743E-13;
				_received = _obj.getDistance(vector <int>(heading, heading+sizeof(heading)/sizeof(int)), vector <int>(distance, distance+sizeof(distance)/sizeof(int))); break;
			}
			case 3:
			{
				int heading[] = {76,321,214,132,0,359,74,65,213};
				int distance[] = {621,235,698,1,35,658,154,426,965};
				_expected = 153.54881555325184;
				_received = _obj.getDistance(vector <int>(heading, heading+sizeof(heading)/sizeof(int)), vector <int>(distance, distance+sizeof(distance)/sizeof(int))); break;
			}
			case 4:
			{
				int heading[] = {0};
				int distance[] = {1};
				_expected = 1.0;
				_received = _obj.getDistance(vector <int>(heading, heading+sizeof(heading)/sizeof(int)), vector <int>(distance, distance+sizeof(distance)/sizeof(int))); break;
			}
			/*case 5:
			{
				int heading[] = ;
				int distance[] = ;
				_expected = ;
				_received = _obj.getDistance(vector <int>(heading, heading+sizeof(heading)/sizeof(int)), vector <int>(distance, distance+sizeof(distance)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int heading[] = ;
				int distance[] = ;
				_expected = ;
				_received = _obj.getDistance(vector <int>(heading, heading+sizeof(heading)/sizeof(int)), vector <int>(distance, distance+sizeof(distance)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int heading[] = ;
				int distance[] = ;
				_expected = ;
				_received = _obj.getDistance(vector <int>(heading, heading+sizeof(heading)/sizeof(int)), vector <int>(distance, distance+sizeof(distance)/sizeof(int))); break;
			}*/
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		double _elapsed = (double)(clock()-_start)/CLOCKS_PER_SEC;
		if (abs(_expected-_received) < 1e-9 || (_received > min(_expected*(1.0-1e-9), _expected*(1.0+1e-9)) && _received < max(_expected*(1.0-1e-9), _expected*(1.0+1e-9))))
			cout << "#" << _tc << ": Passed (" << _elapsed << " secs)" << endl;
		else
		{
			cout << "#" << _tc << ": Failed (" << _elapsed << " secs)" << endl;
			cout.precision(10);
			cout << "           Expected: " << _expected << endl;
			cout << "           Received: " << _received << endl;
		}
	}
}

// END CUT HERE
