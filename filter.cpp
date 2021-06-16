#include "filter.h"
#include<string>
void filter::AllExpenses(LinkedList<categories_expenses>& list)
{
	cout << "**************************************" << endl;
	for (int i = 0; i < list.Length() - 1; i++) {
		cout << list.At(i).date.day << " / " << list.At(i).date.month << " ----> " << list.At(i).cate_name << " ----> " << list.At(i).paid_for << " ----> " << list.At(i).price << endl;
		cout << endl;
	}
	cout << "**************************************" << endl;
}
void filter::fByDate(int day, int month, LinkedList<categories_expenses>& list)
{
	cout << "**************************************" << endl;
	cout << "FILTER BY DATE : " << endl;
	for (int i = 0; i < list.Length() - 1; i++) {
		if (day == list.At(i).date.day && month == list.At(i).date.month) {
			cout << list.At(i).date.day << " / " << list.At(i).date.month << " ----> " << list.At(i).cate_name << " ----> " << list.At(i).paid_for << " ----> " << list.At(i).price << endl;
		}
	}
	cout << "**************************************" << endl;
}
void filter::fByCategory(string cat, LinkedList<categories_expenses>& list)
{
	for (int i = 0; i < list.Length() - 1; i++) {
		if (cat == list.At(i).cate_name) {
			cout << list.At(i).date.day << " / " << list.At(i).date.month << " ----> " << list.At(i).cate_name << " ----> " << list.At(i).paid_for << " ----> " << list.At(i).price << endl;
		}
	}
	cout << "**************************************" << endl;
}

void filter::fByAmount(int amount, LinkedList<categories_expenses>& list)
{
	for (int i = 0; i < list.Length() - 1; i++) {
		if (amount == list.At(i).price) {
			cout << list.At(i).date.day << " / " << list.At(i).date.month << " ----> " << list.At(i).cate_name << " ----> " << list.At(i).paid_for << " ----> " << list.At(i).price << endl;
		}
	}
	cout << "**************************************" << endl;
}

void filter::fByCommon(LinkedList<categories_expenses>& list)
{
	int y;
	int day, month, amount;
	string cat;
	cout << ">>>>>  Enter Your Choice  <<<<<<" << endl;
	cout << "  1 - Date & Category " << endl;
	cout << "  2 - Date & Amount " << endl;
	cout << "  3 - Amount & Category " << endl;
	cin >> y;
	cout << "**************************************" << endl;

	if (y == 1) {
		cout << "Enter the date (d/m) : " << endl;
		cout << "Day : ";
		cin >> day;
		cout << "Month : ";
		cin >> month;
		cout << "Enter the category : " << endl;
		cin >> cat;
		for (int i = 0; i < list.Length() - 1; i++) {
			if (day == list.At(i).date.day && month == list.At(i).date.month && cat == list.At(i).cate_name) {

				cout << list.At(i).date.day << " / " << list.At(i).date.month << " ----> " << list.At(i).cate_name << " ----> " << list.At(i).paid_for << " ----> " << list.At(i).price << endl;
			}
		}
		cout << "**************************************" << endl;
	}
	else if (y == 2) {
		cout << "Enter the date (d/m) : " << endl;
		cout << "Day : ";
		cin >> day;
		cout << "Month : ";
		cin >> month;
		cout << "Enter the price you want to know about : ";
		cin >> amount;
		for (int i = 0; i < list.Length() - 1; i++) {
			if (day == list.At(i).date.day && month == list.At(i).date.month &&amount == list.At(i).price) {
				cout << list.At(i).date.day << " / " << list.At(i).date.month << " ----> " << list.At(i).cate_name << " ----> " << list.At(i).paid_for << " ----> " << list.At(i).price << endl;
			}
		}
		cout << "**************************************" << endl;
	}
	else if (y == 3) {
		cout << "Enter the price you want to know about : ";
		cin >> amount;
		cout << "Enter the category : " << endl;
		cin >> cat;
		for (int i = 0; i < list.Length() - 1; i++) {
			if (amount == list.At(i).price&&cat == list.At(i).cate_name)
			{
				cout << list.At(i).date.day << " / " << list.At(i).date.month << " ----> " << list.At(i).cate_name << " ----> " << list.At(i).paid_for << " ----> " << list.At(i).price << endl;
			}

		}
		cout << "**************************************" << endl;
	}
}


