#include "SavingsAccount.h"
#include <iomanip>
#include <iostream>

using namespace std;


namespace ict{

	// TODO: Implement SavingsAccount member functions here
	SavingsAccount::SavingsAccount(double bal , double ir) : Account(bal), interestRate(ir){
		if(ir < 0){
			interestRate = 0;
		}
	}
	double SavingsAccount::calculateInterest()const{
		return getBalance() * interestRate;
	}
	ostream& SavingsAccount::display(ostream& os)const{
		os << fixed << setprecision(2) << "Account type: Saving" << endl;
		os << "Balance: $ " << getBalance() << endl;
		os << "Interest Rate (%): " << interestRate * 100 << endl;
		return os;
	}

}
