#include "wallet.h"
class filter :public wallet
{
public:
	void AllExpenses(LinkedList<categories_expenses>& list);
	void fByDate(int day, int month, LinkedList<categories_expenses>& list);
	void fByCategory(string cat, LinkedList<categories_expenses>& list);
	void fByAmount(int amount, LinkedList<categories_expenses>& list);
	void fByCommon(LinkedList<categories_expenses>& list);

};

