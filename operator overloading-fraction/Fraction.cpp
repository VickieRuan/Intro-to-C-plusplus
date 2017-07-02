#include "Fraction.h"

using namespace std;

namespace sict{
	Fraction::Fraction(){
		denom =-1;              // safe empty state
	}

	Fraction::Fraction(int n, int d) // n: numerator, d: denominator
	{
		if(n >= 0 && d > 0){
			num = n;
			denom = d;
			reduce();
		}
		else
			denom =-1;              // set to safe empty state
	}

	int Fraction::gcd()                                        // returns the greatest common divisor of num and denom 
	{
		int mn = min();                                        // min of num and denom
		int mx = max();                                        // mX of num and denom

		for (int x=mn ; x > 0 ; x--)                           // find the greatest common divisor
			if( mx % x == 0 &&  mn % x == 0)
				return x;
		return 1;

	}

	void Fraction::reduce()                                         // simplify the Fraction number  
	{
		int tmp = gcd();
		num /= tmp;
		denom /= tmp;
	}

	int Fraction::max ()
	{
		return (num >= denom) ? num : denom;
	}

	int Fraction::min()
	{
		return (num >= denom) ? denom : num;
	}

	// TODO: Copy-paste the implementation of member isEmpty function from the in_lab part answer HERE
	bool Fraction::isEmpty()const {
		return denom == -1;
	}
	// TODO: Copy-paste the implementation of member display function from the in_ab part answer HERE
	void Fraction::display()const {
		if(denom == 1){
			cout << num;
		}else if(denom == -1){
			cout << "Invalid Fraction Object!";
		}else{
			cout << num << "/" << denom ;
		}
	}

	// TODO: Copy-paste the implementation of member operator+= function from the in_lab part answer HERE
	const Fraction& Fraction::operator+= (const Fraction& B){
		if(num == -1 || denom == -1 || B.num == -1 || B.denom == -1){
			denom = -1;

		}else{

			num = num * B.denom + denom * B.num ;
			denom = denom * B.denom;

			reduce();

		}

		return *this;
	}
	// TODO: Copy-paste the implementation of member operator+ function from the in_ab part answer HERE
	Fraction Fraction::operator+ (const Fraction& B) {
		Fraction res = *this;
		if(this->num == -1 || this->denom == -1 || B.num == -1 || B.denom == -1){
			res.denom = -1;

		}else{

			res.num = this->num * B.denom + this->denom * B.num ;
			res.denom = this->denom * B.denom;

			reduce();

		}

		return res;
	}
 
	// TODO: Copy-paste the implementation of member operator* function from the in_lab part answer HERE
	Fraction Fraction::operator* (const Fraction& B) {
		Fraction res = *this;
		if(num==-1 || denom == -1 || B.num == -1 || denom == -1){
			res.denom = -1;
		}else{
			res.num = num * B.num;
			res.denom = denom * B.denom;
			reduce();
		}
		return res;
	}

	// TODO: write the implementation of member operator== function HERE
	bool Fraction::operator== (const Fraction& B) const{
		bool res = false;
		if(num * B.denom == denom * B.num){
			res = true;
		}else if(num == -1 || denom == -1 || B.num == -1 || B.denom == -1){
			res = false;
		}
		return res;
	}

	// TODO: write the implementation of member operator!= function HERE
	bool Fraction::operator!= (const Fraction& B) const{
		bool res = false;
		if(num * B.denom != denom * B.num){
			res = true;
		}else if(num == -1 || denom == -1 || B.num == -1 || B.denom == -1){
			res = false;
		}
		return res;
	}

	// TODO: write the implementation of member operator double () function HERE
    Fraction::operator double() const{
	    double temp;
	    if(num == -1 || denom == -1){
		    temp = -1;
	    }else{
		    temp = (double)num/denom;
	    }
	    return temp;
    }
    Fraction::operator int() const{
	    int temp;
	    if(num == -1 || denom == -1){
		    temp = -1;
	    }else{
		    temp = num/denom;
	    }
	    return temp;	
    } 
	
 
}

