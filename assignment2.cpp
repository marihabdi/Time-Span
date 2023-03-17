#include <iostream>
#include <sstream>
#include <cassert>
#include "timespan.h"
using namespace std;
// testing constructor
void test1() {
	TimeSpan ts(1, 20, 30);
	stringstream ss;
	ss << ts;
	std::cout << "1st: " << ts << '\n';
	//assert(ss.str() == "1:20:30"); //assert will check if true or false
	TimeSpan ts2(4, -20, -90);
	ss.str("");
	ss << ts2;
	//assert(ss.str() == "3:38:30");
	std::cout << "2nd: " << ss.str() << '\n';

	TimeSpan ts3(1.5, 30.5, -90);
	ss.str("");
	ss << ts3;
	//assert(ss.str() == "1:59:00");
	std::cout << "3rd: " << ss.str() << '\n';

	TimeSpan ts4(0, 0.07, 0);
	ss.str("");
	ss << ts4;
	//assert(ss.str() == "0:00:04");
	std::cout << "4th: " << ss.str() << '\n';
}
// testing equality, addition, subtraction, multiplication
void test2() {
	TimeSpan ts(1, 20, 30);
	TimeSpan ts2(1, 20, 30);
	TimeSpan ts3(0, 0, 0);
	//assert(ts == ts2);
	std::cout << "5th: " << ts << "is it equal?: " << ts2 << '\n';
	//assert(!(ts != ts2));
	std::cout << "6th: " << ts << "is it not equal?: " << ts2 << '\n';
	//assert(ts != ts3);
	std::cout << "7th: " << ts << "is it not equal?: " << ts3 << '\n';
	assert((ts + ts + ts) == (ts2 * 3));
	std::cout << "8th: " << ts + ts + ts << "is it equal?: " << ts2 * 3 << '\n';
	//assert((ts * 5) == (ts2 * 4) + ts2);
	std::cout << "9th: " << ts * 5 << "is it equal?: " << (ts2 * 4) + ts2 << '\n';
	//assert((ts * 5) == (ts2 * 6) - ts2);
	std::cout << "10th: " << ts * 5 << "is it equal?: " << (ts2 * 6) - ts2 << '\n';
	//assert((ts + ts - ts) == ((ts2 * 2) - ts));
	std::cout << "11th: " << ts + ts - ts << "is it equal ? : " << (ts2 * 2) - ts << '\n';
	//assert((ts - ts2) == ts3);
	std::cout << "12th: " << ts - ts2 << "is it equal?: " << ts3 << '\n';
	//assert((ts3 * 5) == ts3);
	std::cout << "13th: " << ts3 * 5 << "is it equal?: " << ts3 << '\n';
}
//mine
void test3() {
	TimeSpan ts(1, 20, 30);
	TimeSpan ts2(1, 20, 30);
	TimeSpan ts3(0, 0, 0);
	TimeSpan ts4(0, 50, 200);

	assert(ts >= ts3);
	std::cout << "14th: " << (ts2 += ts2) << "is it equal?: " << ts3 << '\n';
	std::cout << "15th" << (ts -= ts4) << '\n';
	std::cout << "16th" << (ts - ts4) << '\n';
	std::cout << "17th" << (ts += ts4) << '\n';
	std::cout << "18th" << (ts + ts4) << '\n';

}
void testAll() {
	test1();
	test2();
	test3();
}
int main() {
	testAll();
	cout << "Done." << std::endl;
	return 0;
}

