#include <iostream>
#include "Contact.h"
#include <cstring>

using namespace std;

namespace communication{
	Contact::Contact() {
		strcpy(m_name, "");
		m_phoneNumbers = nullptr;
		m_noOfPhoneNumbers = 0;
	}
	Contact::Contact(const char* name, const long long* pNumber, int no){
		int counter = 0, noValid = 0;
		long long temp = 0;
		strcpy(m_name, "");
		m_noOfPhoneNumbers = no;
		m_phoneNumbers = nullptr;
		if(name != nullptr ){
			strncpy(m_name,name,20);
			m_name[20] = '\0';
		}

		if(no>0){
			for(int i=0; i<no; i++) {
				counter = 0;
				temp = pNumber[i];
				while (temp) {
					temp = temp / 10;
					counter++;
				}
				if(counter == 11 || counter == 12){
					noValid++;
				}
			}
			m_noOfPhoneNumbers = noValid;

			m_phoneNumbers = new long long[noValid];
			for(int i=0,j=0; i<no && j<noValid;i++){
				counter = 0;
				temp = pNumber[i];
				while (temp) {
					temp = temp / 10;
					counter++;
				}
				if(counter == 11||counter == 12){
					m_phoneNumbers[j]=pNumber[i];
					j++;
				}
			}
		}
	}
	Contact::~Contact(){
		delete [] m_phoneNumbers;
	}


	void Contact::display() const {

		if (isEmpty()) {
			cout << "Empty contact!" << endl;
		}else{
			cout<<m_name<<endl;
	 
			 
			if(m_noOfPhoneNumbers>0){
			 
				for(int i=0; i<m_noOfPhoneNumbers; i++){
					cout<<"(+"<< m_phoneNumbers[i]/10000000000 << ") ";
					cout<< m_phoneNumbers[i]/10000000%1000 << " ";
					cout<< m_phoneNumbers[i]%10000000/10000 <<"-";
					cout<< m_phoneNumbers[i]%10000 << endl;
				}
			}
		 
		}
	}
	

	bool Contact::isEmpty() const{
		return m_noOfPhoneNumbers==0 && m_phoneNumbers==nullptr && !strcmp(m_name,"") ;
	}
	Contact::Contact(const Contact& other){
		strcpy(m_name,other.m_name);
		m_noOfPhoneNumbers = other.m_noOfPhoneNumbers;
		if(other.m_phoneNumbers != nullptr){
			m_phoneNumbers = new long long[m_noOfPhoneNumbers];
			for(int i=0; i<m_noOfPhoneNumbers;i++){
				m_phoneNumbers[i] = other.m_phoneNumbers[i];
			}
		}else{
			m_phoneNumbers = nullptr;
		} 
		
	}
	Contact& Contact::operator=(const Contact& other){
		if(this != &other){
			strcpy(m_name,other.m_name);
			m_noOfPhoneNumbers = other.m_noOfPhoneNumbers;
		    delete[] m_phoneNumbers;
		    if(other.m_phoneNumbers != nullptr){
			    m_phoneNumbers = new long long[m_noOfPhoneNumbers];
			    for(int i=0; i<m_noOfPhoneNumbers;i++){
				    m_phoneNumbers[i] = other.m_phoneNumbers[i];
			    }
		    }else{
			    m_phoneNumbers = nullptr;
		    }
	    }
	    return *this;
	} 
	void Contact::addPhoneNumber(long long phoneNumber){
		int counter = 0;
		long long temp = phoneNumber;
		
		while(temp){ //validate
			temp = temp/10;
			counter++;
		}
		 
		if(counter == 11 || counter == 12){
		
			if(m_noOfPhoneNumbers == 0){
				m_phoneNumbers = new long long[++m_noOfPhoneNumbers];
				m_phoneNumbers[m_noOfPhoneNumbers-1] = phoneNumber;
			}else if(m_noOfPhoneNumbers > 0){
				
	            Contact tempObj = *this;
				delete[] m_phoneNumbers;
				m_phoneNumbers = new long long[++m_noOfPhoneNumbers];
				for(int i=0; i<tempObj.m_noOfPhoneNumbers;i++){
					m_phoneNumbers[i] = tempObj.m_phoneNumbers[i];
				}
				m_phoneNumbers[m_noOfPhoneNumbers-1] = phoneNumber;
		    } 	      
     	}	
	}
}