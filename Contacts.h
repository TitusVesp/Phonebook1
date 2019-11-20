#pragma once
#include "Abonent.h"

class Contacts {
private:
	int capasity = 10;
	Abonent *abonents;
	int count;
public:
	Contacts();
	~Contacts();
	int add(Abonent &ab);
	Abonent* getAbonent(int i);
	bool update(int i, Abonent &ab);
	bool deleteByMobilePhone(char* mobilePhone);
	bool deleteByIndex(int i);
	int findByMobilePhone(char* mobilePhone);	
	void showAllAbonents();
	int size();
	

};



