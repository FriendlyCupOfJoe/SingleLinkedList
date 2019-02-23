#pragma once
#include <stdio.h>
#include<iostream>
#include<vector>
#include<string>

using namespace std;

class List //Single linked list that contains members with a value and a pointer to the address of the next member.
{
private:
	string value;
	List * point;
public:
	List() {};
	~List() {};
	void SetValue(string value) { this->value = value; };
	string RtrnValue() { return this->value; };
	void SetPoint(List * point) { this->point = point; };
	List * RtrnPoint() { return this->point; };
};

