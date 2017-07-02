#include "Account.h"

using namespace std;

namespace ict{

    // constructor
    Account::Account(double bal){
	if(bal >= 0){
	    setBalance(bal);
	}else{
	    setBalance(1.0);
	}
    }



    // credit (add) an amount to the account balance
    void Account::credit(double val){
	balance += val;
    }


    // debit (subtract) an amount from the account balance return bool
    bool Account::debit(double val){
	bool validate = true;
	if(val <= getBalance()){
	    balance -= val;
	}else{
	    validate = false;
	}
	return validate;
    }

    double Account::getBalance() const
    {
	return balance;
    }

    void Account::setBalance( double newBalance )
    {
	balance = newBalance;
    }
}
