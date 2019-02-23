#include <stdio.h>
#include<iostream>
#include<vector>
#include<string>
#include <conio.h>
#include "List.h" //Single linked list that contains members with a value and a pointer to the address of the next member.

using namespace std;

void CheckInput(int &);
void PressToCont();
void RefreshAddress(vector <List> &); //Vector changes places in the memory every time a member gets added or removed from it, so the pointers to the address of vector members need to be updated.
void AddMemberToList(vector <List> &); //Asks the user for the value of the new member and adds it to the vector.
void CheckValue(string &, vector <List>);
void RemoveMemberFromList(vector <List> &); //Deletes a member from the vector depending on the value the user has inputted.
void ShowAllMembers(vector <List> &); //Shows all memebers of the list and their value and pointers to the next member.
void Exit(bool &);

int main()
{
	bool exit_choice = true;;
	int menu_choice;
	vector <List> list;
	while (exit_choice)
	{
		cout << "Single linked list application." << endl << endl;
		cout << "What would you like to do:" << endl;
		cout << "(1) Add a member to the list." << endl;
		cout << "(2) Remove member from the list." << endl;
		cout << "(3) Show all members of the list." << endl;
		cout << "(4) Exit the program." << endl << endl;
		CheckInput(menu_choice);
		switch (menu_choice)
		{
		case(1) :
		{
			AddMemberToList(list);
			break;
		}
		case(2) :
		{
			RemoveMemberFromList(list);
			break;
		}
		case(3) :
		{
			ShowAllMembers(list);
			break;
		}
		case(4) :
		{
			Exit(exit_choice);
			break;
		}
		default:
		{
			break;
		}
		}
		system("cls");
	}
}

void CheckInput(int & menu_choice)
{
	string temp;
	cout << "Your input: ";
	getline(cin, temp);
	while (temp.size() > 1 || !(temp[0] >= '1' && temp[0] <= '4'))
	{
		cout << "Wrong input, please input a single number from 1 to 4: ";
		getline(cin, temp);
	}
	menu_choice = stoi(temp);
}

void RefreshAddress(vector <List> & list)
{
	if (list.size() > 1)
	{
		for (int i = 0; i < list.size() - 1; i++)
		{
			List * temp = &list[i + 1];
			list[i].SetPoint(temp);
		}
	}
}

void PressToCont()
{
	cout << "Press any key to continue.";
	_getch();
}

void AddMemberToList(vector <List> & list)
{
	bool duplicate;
	List member;
	string temp;
	cout << "Input value of member: ";
	getline(cin, temp);
	CheckValue(temp, list);
	member.SetValue(temp);
	list.push_back(member);
	RefreshAddress(list);
	cout << "Member with the value \"" << temp << "\" has been added to the list." << endl;
	PressToCont();
}

void CheckValue(string & temp, vector <List> list)
{
	bool duplicate;
	if (temp.size() == 0)
	{
		cout << "Wrong input, please input a value of member: ";
		getline(cin, temp);
		CheckValue(temp, list);
	}
	else
	{
		for (int i = 0; i < list.size(); i++)
		{
			if (temp == list[i].RtrnValue())
			{
				cout << "You have inputed a duplicate value, please input another different value for the member: ";
				getline(cin, temp);
				CheckValue(temp, list);
				break;
			}
		}
	}
}

void RemoveMemberFromList(vector <List> & list)
{
	string temp;
	bool found = false;
	if (list.size() == 0)
		cout << "There are no members in the list to remove." << endl;
	else
	{
		cout << "Input value of member you wish to remove: ";
		getline(cin, temp);
		for (int i = 0; i < list.size(); i++)
		{
			if (temp == list[i].RtrnValue())
			{
				if (i == list.size() - 1 && list.size() > 1) //The removed member was the last in the list, so now the second to last member is last and it's pointer points to NULL.
					list[list.size() - 2].SetPoint(NULL); //This will become a problem if there is only one member in the list so that's why squares.size() > 1.
				list.erase(list.begin() + i);
				RefreshAddress(list);
				found = true;
				break;
			}
		}
		if (found)
			cout << "The member with the value \"" << temp << "\" has been removed from the list." << endl;
		else
			cout << "The member with the value \"" << temp << "\" has not been found." << endl;
	}
	PressToCont();
}

void ShowAllMembers(vector <List> & list)
{
	if (list.size() == 0)
		cout << "There are no members in the list to show." << endl;
	else
	{
		for (int i = 0; i < list.size(); i++)
		{
			if (i == 0)
				cout << "Head of the list: " << &list[i] << endl;
			else
				cout << "Address of " << i + 1 << ". member of the list: " << &list[i] << endl;
			cout << "Value of the " << i + 1 << ". member of the list: \"" << list[i].RtrnValue() << "\"" << endl;
			if (list[i].RtrnPoint() != 0)
				cout << "Pointer to the address of " << i + 2 << ". member of the list: " << list[i].RtrnPoint() << endl;
			else
				cout << "End of the list: " << list[i].RtrnPoint() << endl;
			cout << endl;
		}
	}
	PressToCont();
}

void Exit(bool & exit_choice)
{
	string temp;
	cout << "Would you like the program to end? Y/y for yes or any other key for no: ";
	getline(cin, temp);
	if (temp[0] == 'y' || temp[0] == 'Y')
		exit_choice = false;
}


