#include "stdafx.h"
#include "Contacts.h"

Contacts::Contacts()
{
	abonents = new Abonent[capasity];
	count = -1;
}
Contacts::~Contacts()
{
	delete []abonents;
	count = -1;
}
int Contacts::add(Abonent &ab)
{
	if (count == capasity-1) {
		Abonent *temp = new Abonent[capasity * 2];
		for (size_t i = 0; i <= count; i++)
		{
			temp[i] = abonents[i];
		}
		delete[] abonents;
		abonents = temp;
	}
	 abonents[++count] = ab;
	 return count;
}

Abonent *Contacts::getAbonent(int i)
{
	if (i <= count)
	return &abonents[i];
	else return nullptr;
}

bool Contacts::update(int i, Abonent &ab)
{
	if(i <=count){
	abonents[i] = ab;
	return true;
	}
	return false;
}

bool Contacts::deleteByMobilePhone(char *mobilePhone) {
	return deleteByIndex(findByMobilePhone(mobilePhone));
}
bool Contacts::deleteByIndex(int index) {
	    if (index < 0 || index > count) return false;
		if (index<=count){
			for (size_t i = index; i <count; i++){
			abonents[i] = abonents[i + 1];			
		}		
		count--;
		return true;
	}
	return false;
}
int Contacts::findByMobilePhone(char* mobilePhone) {

	for (int i = 0; i <= count; i++)
	{
		if (abonents[i] == mobilePhone) {
			return i;
		}
	}
	return -1;
}

void Contacts::showAllAbonents() {
	for (size_t i = 0; i <= count; i++)
	{
		cout << abonents[i];
	}
}

int Contacts::size()
{
	return count+1;
}
