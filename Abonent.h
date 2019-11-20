#pragma once
#include <iostream>
using namespace std;
class Abonent {
private:
	char firstName[64];
	char lastName[64];
	char mobilePhone[64];
	char nativeTown[64];
	char post[256];
	struct { unsigned int year = 0, month = 0, day = 0; } birthday;

	int Strlength(char* str);
	int strcopy(char* str1, char* str2);	
	int countDay(int month, int year);
	bool isEquals(char* str1, char * str2);
	
public:
	Abonent(char* firstName, char* lastName, char* mobilePhone, char* nativeTown, char* post, int year, int month, int day);
	Abonent();
	~Abonent();
	void setFirstName(char* firstName);
	char* getFirstName();
	void setLastName(char* lastName);
	char* getLastName();
	void setMobilePhone(char* mobilePhone);
	char* getMobilePhone();
	void setNativeTown(char* nativeTown);
	char* getNativeTown();
	void setPost(char* post);
	char* getPost();
	void setYear(int year);
	int getYear();
	void setMonth(int month);
	int getMonth();
	void setDay(int day);
	int getDay();

	friend ostream & operator<<(ostream & out, Abonent & ab);
	friend bool operator==(Abonent & ab, char* mobilePhone);
	friend bool operator!=(Abonent & ab, char* mobilePhone);

	friend bool isNameCorrect(char* name);
	friend bool isTownCorrect(char* name);
	friend bool isMobilePhoneCorrect(char* mobilePhone);
	friend bool isDateCorrect(int a, int b, int curDate);
	friend int strlength(char* str);
};

inline ostream & operator<<(ostream & out, Abonent & ab)
{
	return out << ab.firstName << ", " << ab.lastName << ", " << ab.mobilePhone << ", " << ab.nativeTown << ", " << ab.post << ", " << ab.birthday.year << ", " << ab.birthday.month << ", " << ab.birthday.day;

}

inline bool operator==(Abonent & ab, char * mobilePhone)
{
	return ab.isEquals(ab.mobilePhone, mobilePhone);
}

inline bool operator!=(Abonent & ab, char * mobilePhone)
{
	return !ab.isEquals(ab.mobilePhone, mobilePhone);
}

inline int strlength(char* str)
{
	int i = 0;
	while (str[i] != '\0' && str[i] > 0) i++;
	return i;
}

inline bool isDateCorrect(int a, int b, int curDate)
{
	if (curDate == 0 || curDate < a || curDate > b)
	{
		cout << "Verify day, month and year!" << endl;
		if (cin.fail()) {
			cout << "Incorrect Date Input!" << endl;
			cin.clear(); cin.ignore(32767, '\n');
		}
		return false;
	}
	return true;
}

inline bool isNameCorrect(char* name)
{
	if (strlength(name) == 0) return false;
	for (int i = 0; i < strlength(name); i++)
		if (!isalpha(name[i]))
		{
			cout << "Incorrect Name Input!" << endl;
			return false;
		}
	return true;
}

inline bool isTownCorrect(char* name)
{
	if (strlength(name) == 0) return false;
	for (int i = 0; i < strlength(name); i++)
		if (!isalpha(name[i]))
		{
			cout << "Incorrect Town Input!" << endl;
			return false;
		}
	return true;
}

inline bool isMobilePhoneCorrect(char* mobilePhone)
{
	if (strlength(mobilePhone) == 0) return false;
	for (int i = 0; i < strlength(mobilePhone); i++)
	{
		if (!isdigit(mobilePhone[i]) && mobilePhone[i] != '+')
		{
			cout << "Incorrect Phone Input!" << endl;
			return false;
		}
	}
	return true;
}

