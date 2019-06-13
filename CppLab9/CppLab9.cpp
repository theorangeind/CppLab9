#include <iostream>
#include <ctime>

using namespace std;

//вариант 8 (ср. уровень)

struct Train
{
	int number;

	time_t departureTime;
	time_t arrivalTime;

	string departureStation;
	string arrivalStation;
};

char* timeToString(tm* time)
{
	int length = 20;
	char* c = new char[length];
	strftime(c, length, "%d.%m.%Y %I:%M:%S", time);
	return c;
}

bool setTime(tm* t, int h, int m)
{
	if (h > 23 || h < 0 || m > 59 || m < 0) return false;
	t->tm_hour = h;
	t->tm_min = m;
	t->tm_sec = 0;
	return true;
}

bool setDate(tm* t, int d, int m, int y)
{
	if (d < 1 || d > 31 || m < 1 || m > 12 || y < 1900 || y > 9999) return false;
	t->tm_mday = d;
	t->tm_mon = m - 1;
	t->tm_year = y - 1900;
	return true;
}

tm* currentTime()
{
	time_t* pt = new time_t;
	tm* ptm = new tm;

	time(pt);
	localtime_s(ptm, pt);

	return ptm;
}

int main()
{
	tm* t = currentTime();
	setDate(t, 4, 1, 2000);
	setTime(t, 0, 0);

	cout << timeToString(t) << endl;

	cout << timeToString(currentTime());
}