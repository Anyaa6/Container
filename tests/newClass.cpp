#include "newClass.hpp"
#include <iostream>

newClass::newClass(int fraise, int poire)
	: poire(),
	  pomme()
{
	
}

newClass::newClass(int fraise)
	: fraise()
{
	fraise = 75;
	std::cout << fraise << std::endl;
}

newClass::newClass(newClass const &to_copy)
{
	
}

newClass::~newClass()
{
	
}

int newClass::haha(int index) {
	
}

int newClass::getFraise() {
	
}

void newClass::setFraise(int fraise) {
	
}

int newClass::getPoire() {
	
}

void newClass::setPoire(int poire) {
	
}
