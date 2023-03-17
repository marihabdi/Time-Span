

#include "timespan.h"
#include <iostream>
#include <functional>

using namespace std;

TimeSpan::TimeSpan(double hDouble, double mDouble, double sDouble) {
	this->h = hDouble;
	this->m = mDouble;
	this->s = sDouble;

	int answer = TimeSpan::totalSeconds(hDouble, mDouble, sDouble);
	
	h = answer / 3600;
	m = (answer % 3600) / 60.0;
	s = answer % 60;
	
	std::cout << h << m << s << std::endl;
	
}
TimeSpan::TimeSpan(double m, double s) {
	TimeSpan time;
	h = 0.0;

	int answer = (time.h * 3600.0) + (time.m * 60.0) + time.s;

	h = answer / 3600;
	m = (answer % 3600) / 60.0;
	s = answer % 60;
}
TimeSpan::TimeSpan(double s) {
	TimeSpan time;
	h = 0.0;
	m = 0.0;

	int answer = (time.h * 3600) + (time.m * 60) + time.s;

	h = answer / 3600;
	m = (answer % 3600) / 60.0;
	s = answer % 60;
}
TimeSpan::TimeSpan() {
	h = 0;
	m = 0;
	s = 0;
}

//getters

int TimeSpan::returnSeconds() const {
	return s;
}
int TimeSpan::returnMinutes() const {
	return m;
}
int TimeSpan::returnHours() const {
	return h;
}

int TimeSpan::returnMilliSeconds() const {
	return h;
}

TimeSpan TimeSpan::setToInteger(int h, int m, int s) {
	TimeSpan time;
	time.s = s;
	time.m = m;
	time.h = h;
	
	return time;
}

TimeSpan TimeSpan::setToInteger(int m, int s) {

	TimeSpan time;
	time.s = s;
	time.m = m;
	
	return time;
}

TimeSpan TimeSpan::setToInteger(int s) {
	TimeSpan time;
	time.s = s;
	
	return time;
}

//this function turns the times into seconds so it's easier to calculate
int TimeSpan::totalSeconds(double hDouble, double mDouble, double sDouble) {
	int totalSeconds = (hDouble * 3600) + (mDouble * 60) + sDouble;

	return totalSeconds;	
}

//This is basically the simplify function but to fit my way of coding this
//This sets the time back to hms format after totalSeconds function is called
TimeSpan TimeSpan::setToTime(int total_seconds) {
	TimeSpan time;
	time.h = total_seconds / 3600;
	time.m = (total_seconds % 3600) / 60.0;
	time.s = total_seconds % 60;

	return time;
}


TimeSpan TimeSpan :: operator +=(const TimeSpan& item) {
	int answer1 = TimeSpan::totalSeconds(this->h, this->m, this->s);
	int answer2 = TimeSpan::totalSeconds(item.h, item.m, item.s);

	int answer = answer1 + answer2;
	TimeSpan added = TimeSpan::setToTime(answer);

	return added;
}

TimeSpan TimeSpan :: operator -=(const TimeSpan& item) {
	int answer1 = TimeSpan::totalSeconds(this->h, this->m, this->s);
	int answer2 = TimeSpan::totalSeconds(item.h, item.m, item.s);

	int answer = answer1 - answer2;
	TimeSpan subtracted = TimeSpan::setToTime(answer);

	return subtracted;
}
//should i use this way instead on the way for + and - operators?
//make a function for converting seconds

TimeSpan TimeSpan :: operator *(int x) {
	int answer1 = TimeSpan::totalSeconds(this->h, this->m, this->s);
	int answer2 = x;

	int answer = answer1 * answer2;
	TimeSpan multiplied = TimeSpan::setToTime(answer);

	return multiplied;
}
// did teacher want plus and subtraction? ask if this is it
TimeSpan TimeSpan :: operator +(const TimeSpan& item) {
	int answer1 = TimeSpan::totalSeconds(this->h, this->m, this->s);
	int answer2 = TimeSpan::totalSeconds(item.h, item.m, item.s);

	int answer = answer1 + answer2;
	TimeSpan added = TimeSpan::setToTime(answer);

	return added;
}

TimeSpan TimeSpan :: operator -(const TimeSpan& item) {
	int answer1 = TimeSpan::totalSeconds(this->h, this->m, this->s);
	int answer2 = TimeSpan::totalSeconds(item.h, item.m, item.s);

	int answer = answer1 - answer2;
	TimeSpan subtracted = TimeSpan::setToTime(answer);

	return subtracted;
}

bool TimeSpan :: operator <(const TimeSpan& item) {
	int addedSecondsTime = (h * 3600) + (m * 60) + s;
	int addedSecondsItem = (item.h * 3600) + (item.m * 60) + item.s;

	return (addedSecondsTime < addedSecondsItem);
}

bool TimeSpan :: operator >(const TimeSpan& item) {
	int addedSecondsTime = (h * 3600) + (m * 60) + s;
	int addedSecondsItem = (item.h * 3600) + (item.m * 60) + item.s;

	return (addedSecondsTime > addedSecondsItem);	
}

bool TimeSpan :: operator <=(const TimeSpan& item) {
	int addedSecondsTime = (h * 3600) + (m * 60) + s;
	int addedSecondsItem = (item.h * 3600) + (item.m * 60) + item.s;

	return (addedSecondsTime <= addedSecondsItem);	
}

bool TimeSpan :: operator >=(const TimeSpan& item) {
	int addedSecondsTime = (h * 3600) + (m * 60) + s;
	int addedSecondsItem = (item.h * 3600) + (item.m * 60) + item.s;

	return (addedSecondsTime >= addedSecondsItem);	
}

bool TimeSpan :: operator ==(const TimeSpan& item) {
	TimeSpan time;

	int addedSecondsTime = (h * 3600) + (m * 60) + s;
	int addedSecondsItem = (item.h * 3600) + (item.m * 60) + item.s;

	return (addedSecondsTime == addedSecondsItem);
}

bool TimeSpan :: operator !=(const TimeSpan& item) {
	TimeSpan time;
	int addedSecondsTime = (h * 3600) + (m * 60) + s;
	int addedSecondsItem = (item.h * 3600) + (item.m * 60) + item.s;

	return (addedSecondsTime != addedSecondsItem);
		
}

TimeSpan TimeSpan :: operator+ () {
	m = m;
	s = s;
	h = h;
	return TimeSpan(h, m, s);
}

ostream& operator<<(ostream& stream, const TimeSpan& item) {
	char s[30];
	sprintf_s(s, "%d:%02d:%02d", (int)abs(item.h), (int)abs(item.m), (int)abs(item.s));
	stream << s;

	return stream;
}
