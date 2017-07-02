// OOP244 Workshop 2:Dynamic Memory
// File kingdom.h
// Version 1.0
// Date Jan 23, 2017
// Author Jing Lin Ruan

// TODO: header safeguards
#ifndef WESTEROS_KINGDOM_H_
#define WESTEROS_KINGDOM_H_

// TODO: westeros namespace
namespace westeros{

// TODO: define the class Kingdom in the westeros namespace
    struct Kingdom{
	    char m_name[32];
	    int m_population;
	};
// TODO: add the declaration for the function display(...),
//         also in the westeros namespace
    void display(Kingdom& pk);
    void display(Kingdom* pk, int num);
    void display(Kingdom* pk, int num, int min);
    void display(Kingdom* pk, int num, const char* Kname); //or const char Kname[]

}
#endif