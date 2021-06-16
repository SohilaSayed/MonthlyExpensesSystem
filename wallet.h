#pragma once
#include <string>
#include"LinkedList.cpp"
#include <string>
#include<fstream>

using namespace std;
struct Date
{
	int day;
	int month;
};
struct wallet_income {
	string name;
	double income;
};
struct categories_expenses
{
	string cate_name;
	string paid_for;
	int price;
	Date date;
	string wallet_type;
};
class wallet
{
private:

	categories_expenses cate;
	double Remainder = 0;
	double total_expenses = 0;
	int choice;
public:
	LinkedList<categories_expenses> list;
	int index;
public:
	wallet();
	void read(LinkedList<categories_expenses> &list);
	void write(LinkedList<categories_expenses> &list);
	void display();
	void getprice(int mon, double wal_income, string wal_name);

	~wallet();
};