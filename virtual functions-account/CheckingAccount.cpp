#include "CheckingAccount.h"
#include <iomanip>

using namespace std;

namespace ict
{

  // TODO: define CheckingAccount class member functions here
  CheckingAccount::CheckingAccount (double bal, double fee):Account (bal),
    transactionFee (fee)
  {
    if (fee < 0)
      {
	transactionFee = 0;

      }
  }
  void CheckingAccount::chargeFee ()
  {
    double newBal;
    newBal = getBalance () - transactionFee;
    setBalance (newBal);
  }
  bool CheckingAccount::debit (double val)
  {
    bool ifSuccessful = true;
    if ((val + transactionFee) <= getBalance ())
      {
	Account::debit (val);
	chargeFee ();
      }
    else
      {
	ifSuccessful = false;
      }
    return ifSuccessful;

  }
  void CheckingAccount::credit (double val)
  {
    Account::credit (val);
    chargeFee ();
  }
  ostream & CheckingAccount::display (ostream & os) const
  {
    os << fixed << setprecision (2) << "Account type: Checking" << endl;
    os << "Balance: $ " << getBalance () << endl;
    os << "Transaction Fee: " << transactionFee << endl;
    return os;
  }
}
