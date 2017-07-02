#ifndef COMMUNICATION_CONTACT_H
#define COMMUNICATION_CONTACT_H

namespace communication{
	class Contact {
		char m_name[21];
		long long *m_phoneNumbers; //dynamically allocated array of phone numbers
		int m_noOfPhoneNumbers;
	public:
		 
		Contact();
		Contact(const char* name, const long long* pNumber, int no);
		~Contact();
		void display() const;
		bool isEmpty() const;
	public:
		Contact(const Contact& other);
		Contact& operator=(const Contact& other); 
		void addPhoneNumber(long long phoneNumber); 
	};
}

#endif
