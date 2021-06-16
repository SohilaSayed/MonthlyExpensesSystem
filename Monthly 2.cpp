#include "filter.h"
#include<iostream>
#include<string>
#include<fstream>


using namespace std;
int main() {

	wallet_income wallet1, wallet2;

	ofstream income;

	cout << "\nWelcome to our Monthly Expenses Program \n\n";

	cout << "*********************************************\n\n";

	cout << "To Enter your monthly income Press 1\n" << "To Go to Program Page Press 2\n";

	int choice;
	cin >> choice;
	if (choice == 1) {
		cout << "How Many Wallets (1 or 2): ";
		int wal;
		cin >> wal;
		if (wal == 1) {
			cout << "Enter Wallet Type: ";
			cin >> wallet1.name;
			cout << "Enter Wallet Income: ";
			cin >> wallet1.income;
			income.open("income.txt");
			income << wallet1.income << endl << wallet1.name << endl;
			income.close();
		}
		if (wal == 2) {
			cout << "Enter Wallet 1 Type: ";
			cin >> wallet1.name;
			cout << "Enter Wallet 1 Income: ";
			cin >> wallet1.income;
			cout << "Enter Wallet 2 Type: ";
			cin >> wallet2.name;
			cout << "Enter Wallet 2 Income: ";
			cin >> wallet2.income;
			income.open("income.txt");
			income << wallet1.income << endl << wallet1.name << endl << wallet2.income << endl << wallet2.name << endl;
			income.close();
		}
	}
	while (true) {

		cout << "\n*********************************************\n\n";

		cout << "To Enter Daily Expenses Press 1\n"
			<< "To View Your Expenses Press 2\n" <<
			"To View the Remaining Money Press 3\n" <<
			"To Update Your Monthly Income Press 4\n" << "To Exit Press 5\n";

		int ch;
		cin >> ch;

		wallet w;

		if (ch == 1) {
			w.display();
		}
		else if (ch == 2) {
			int x;
			LinkedList<categories_expenses> list;

			w.read(list);
			filter f;
			cout << ">>>>>  Enter Your Choice  <<<<<<" << endl;
			cout << "Press 1 to show all expenses" << endl;
			cout << "Press 2 to filter by date" << endl;
			cout << "Press 3 to filter by category" << endl;
			cout << "Press 4 to filter by amount" << endl;
			cout << "Press 5 to use more than one filter at the same time" << endl;
			cin >> x;
			int am;
			if (x == 1) {
				f.AllExpenses(list);
			}
			else if (x == 2) {
				int dd, mm;
				cout << "Enter the date (d/m) : " << endl;
				cout << "Day : ";
				cin >> dd;
				cout << "Month : ";
				cin >> mm;
				f.fByDate(dd, mm, list);
			}
			else if (x == 3) {
				string catee;
				cout << "Enter the category : " << endl;
				cin >> catee;
				f.fByCategory(catee, list);
			}
			else if (x == 4) {
				cout << "*********************************************" << endl;
				cout << "Enter the price you want to know about : ";
				cin >> am;
				f.fByAmount(am, list);
			}
			else if (x == 5) {
				f.fByCommon(list);
			}
		}
		else if (ch == 3) {


			ifstream out;
			out.open("income.txt", ios::in);
			while (!out.eof()) {
				out >> wallet1.income >> wallet1.name >> wallet2.income >> wallet2.name;
			}
			out.close();

			while (true) {
				cout << "Enter the Month (1 to 12): ";
				int mon;
				cin >> mon;
				if (mon >= 1 && mon <= 12) {

					cout << "To View The Total Remaining Money Press 1\n"
						<< "To View The Remaining Money of Specific Wallet Press 2\n";
					int m;
					cin >> m;

					if (m == 1) {
						double total = wallet1.income + wallet2.income;
						w.getprice(mon, total, "both");
						cout << "\n*********************************************\n\n";
						break;
					}
					else if (m == 2) {
						while (true) {
							cout << "Enter Wallet Type ( " << wallet1.name << " or " << wallet2.name << " )\n";
							string name;
							cin >> name;
							if (name == wallet1.name) {
								w.getprice(mon, wallet1.income, wallet1.name);
								cout << "\n*********************************************\n\n";
								break;
							}
							else if (name == wallet2.name) {
								w.getprice(mon, wallet2.income, wallet2.name);
								cout << "\n*********************************************\n\n";
								break;
							}
							else {
								cout << "Please Enter a valid Type !";
							}
						}
						break;
					}

				}
				else {
					cout << "Please Enter the Right Month !!\n";
					continue;
				}
			}
		}
		else if (ch == 4) {
			cout << "How Many Wallets (1 or 2): ";
			int wal;
			cin >> wal;
			if (wal == 1) {
				cout << "Enter Wallet Type: ";
				cin >> wallet1.name;
				cout << "Enter Wallet Income: ";
				cin >> wallet1.income;
				income.open("income.txt");
				income << wallet1.income << endl << wallet1.name << endl;
				income.close();
			}
			if (wal == 2) {
				cout << "Enter Wallet 1 Type: ";
				cin >> wallet1.name;
				cout << "Enter Wallet 1 Income: ";
				cin >> wallet1.income;
				cout << "Enter Wallet 2 Type: ";
				cin >> wallet2.name;
				cout << "Enter Wallet 2 Income: ";
				cin >> wallet2.income;
				income.open("income.txt");
				income << wallet1.income << endl << wallet1.name << endl << wallet2.income << endl << wallet2.name << endl;
				income.close();
			}
		}
		else if (ch == 5) {
			break;
		}
	}
}
