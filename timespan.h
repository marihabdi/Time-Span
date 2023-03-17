#pragma once

#ifndef TIMESPAN_H
#define TIMESPAN_H
#include<iostream>
using namespace std;

class TimeSpan {

private:
	int s;
	int m;
	int h;

	int totalSeconds(double hDouble, double mDouble, double sDouble);

public:

	int returnHours() const;
	int returnMinutes() const;
	int returnSeconds() const;
	int returnMilliSeconds() const;

	TimeSpan setToTime(int total_seconds);

	TimeSpan setToInteger(int, int, int);
	TimeSpan setToInteger(int, int);
	TimeSpan setToInteger(int);

	TimeSpan(double, double, double);
	TimeSpan(double, double);
	TimeSpan(double);
	TimeSpan();

	bool operator <=(const TimeSpan&);
	bool operator >=(const TimeSpan&);
	bool operator <(const TimeSpan&);
	bool operator >(const TimeSpan&);

	bool operator ==(const TimeSpan& item); //
	bool operator !=(const TimeSpan&); //
	TimeSpan operator +=(const TimeSpan&);
	TimeSpan operator -=(const TimeSpan&);

	TimeSpan operator *(int x);
	TimeSpan operator +(const TimeSpan&);
	TimeSpan operator -(const TimeSpan&);
	TimeSpan operator- ();
	TimeSpan operator+ ();

	friend ostream& operator<<(ostream&, const TimeSpan&);
};

#endif