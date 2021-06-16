#include<iostream>
#include <string>
#include "wallet.h"

using namespace std;

wallet::wallet()
{
	index = 0;
	cate.price = 0;
	cate.paid_for = "";
}
void wallet::read(LinkedList<categories_expenses>& list)
{
	ifstream read;
	read.open("file.txt");
	categories_expenses cate;
	while (!read.eof()) {
		string cate_type, cate_name;
		int price;
		Date date;
		string wallet_type;
		read >> cate_name >> cate_type >> price >> date.day >> date.month >> wallet_type;
		cate.cate_name = cate_name;
		cate.paid_for = cate_type;
		cate.price = price;
		cate.date.day = date.day;
		cate.date.month = date.month;
		cate.wallet_type = wallet_type;
		list.Append(cate);
	}
	read.close();
}
void wallet::write(LinkedList<categories_expenses>& list)
{
	ofstream write;
	write.open("file.txt", ios::app);
	for (int i = 0; i < list.Length(); i++) {
		write << list.At(i).cate_name << endl << list.At(i).paid_for << endl <<
			list.At(i).price << endl << list.At(i).date.day << endl <<
			list.At(i).date.month << endl << list.At(i).wallet_type << endl;
	}

	write.close();
}
void wallet::display() {

	cout << "\n*********************************************\n\n";

	cout << "Press 1 to go Housing category" << endl;
	cout << "Press 2 to go Transportation category" << endl;
	cout << "Press 3 to go Food category" << endl;
	cout << "Press 4 to go Health & Beauty category" << endl;
	cout << "Press 5 to enter other expenses" << endl;
	cout << "Press 6 to Exit" << endl;
	cout << "Enter the Number: ";
	cin >> choice;

	cout << "Enter Today's Date (day then month)" << endl;
	cin >> cate.date.day >> cate.date.month;

	cout << "Enter Wallet's Type: ";
	cin >> cate.wallet_type;

	while (true)
	{
		if (choice == 1)
		{
			while (choice != 2 && choice != 3 && choice != 4 && choice != 5 && choice != 6 && choice != 7)
			{
				cout << "Enter the type: " << endl;
				cin >> cate.paid_for;
				cout << "Money paid:" << endl;
				cin >> cate.price;
				cate.cate_name = "Housing";
				list.Append(cate);
				cout << "Enter the Number: ";
				cin >> choice;

			}
		}

		if (choice == 2)
		{
			while (choice != 1 && choice != 3 && choice != 4 && choice != 5 && choice != 6 && choice != 7)
			{
				cout << "Enter the type: " << endl;
				cin >> cate.paid_for;
				cout << "Money paid:" << endl;
				cin >> cate.price;
				cate.cate_name = "Transportation";
				list.Append(cate);
				cout << "Enter the Number: ";
				cin >> choice;

			}
		}
		if (choice == 3)
		{
			while (choice != 1 && choice != 2 && choice != 4 && choice != 5 && choice != 6 && choice != 7)
			{

				cout << "Enter the type: " << endl;
				cin >> cate.paid_for;
				cout << "Money paid:" << endl;
				cin >> cate.price;
				cate.cate_name = "Food";
				list.Append(cate);
				cout << "Enter the Number: ";
				cin >> choice;

			}
		}
		if (choice == 4)
		{
			while (choice != 1 && choice != 2 && choice != 3 && choice != 5 && choice != 6 && choice != 7)
			{


				cout << "Enter the type: " << endl;
				cin >> cate.paid_for;
				cout << "Money paid:" << endl;
				cin >> cate.price;
				cate.cate_name = "Health";
				list.Append(cate);
				cout << "Enter the Number: ";
				cin >> choice;

			}
		}
		if (choice == 5)
		{
			while (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 6 && choice != 7)
			{

				cout << "Enter the type: " << endl;
				cin >> cate.paid_for;
				cout << "Money paid:" << endl;
				cin >> cate.price;
				cate.cate_name = "other";
				list.Append(cate);
				cout << "Enter the Number: ";
				cin >> choice;

			}
		}
		if (choice == 6) {
			write(list);
			break;
		}
	}

}


void wallet::getprice(int mon, double wal_income, string wal_name) {

	write(list);
	for (int j = 0; j < list.Length(); j++) {
		list.DeleteAt(j);
	}
	read(list);

	total_expenses = 0;
	double income = wal_income;

	for (int i = 0; i < list.Length() - 1; i++)
	{
		if (mon == list.At(i).date.month) {
			if (wal_name == "both") {
				total_expenses += list.At(i).price;
			}
			if (wal_name == list.At(i).wallet_type) {
				total_expenses += list.At(i).price;
			}
			else {
				continue;
			}
		}
		else
			continue;
	}
	if (total_expenses == 0) {
		cout << "No Expenses\n";
	}
	else {
		cout << "The total expenses is: " << total_expenses << endl;
		Remainder = income - total_expenses;
		cout << "The rest of the expenses: " << Remainder << endl;
	}

}

wallet::~wallet()
{
}