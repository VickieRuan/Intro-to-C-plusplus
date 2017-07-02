// OOP244 Workshop 2:Dynamic Memory
// File kingdom.cpp
// Version 1.0
// Date Jan 23, 2017
// Author Jing Lin Ruan

// TODO: include the necessary headers
#include <iostream>
#include <cstring>
#include "kingdom.h"
using namespace std;
// TODO: the westeros namespace
namespace westeros{
	// TODO:definition for display(...) 
	void display(Kingdom& pk){

	        cout<< pk.m_name << ", population " << pk.m_population<<endl;
	}
    void display(Kingdom* pk, int num){
	        int sum = 0;
	        int i = 0;
	        cout<<"------------------------------"<<endl;
	        cout<<"Kingdoms of Westeros"<<endl;
	        cout<<"------------------------------"<<endl;
	        for(i = 0; i < num; i++){
		            cout<<i+1<<". "<<pk[i].m_name<<", population "<< pk[i].m_population<<endl;
		            sum += pk[i].m_population;
		    }
		    cout<<"------------------------------"<<endl;
		    cout<<"Total population of Westeros: "<< sum << endl;
		    cout<<"------------------------------"<<endl; 
    } 
    void display(Kingdom* pk, int num, int min){
	        int i = 0;
	        cout<<"------------------------------"<<endl;
	        cout<<"Kingdoms of Westeros with more than "<<min<<" people"<<endl;
	        cout<<"------------------------------"<<endl;
	        for(i=0;i<num;i++){
		            if(pk[i].m_population>=min){
			                cout<<pk[i].m_name<<", population "<< pk[i].m_population<<endl;
		            }
	        }
	        cout<<"------------------------------"<<endl;
    }  
    void display(Kingdom* pk, int num, const char* Kname){  // or const char Kname[]
	        int i = 0;
	        int j = 0;
	        int flag = 0;
            cout<<"------------------------------"<<endl;
            cout<<"Searching for kingdom "<< Kname<<" in Westeros"<<endl;
            cout<<"------------------------------"<<endl;
            for(i=0;i<num;i++){
	                if(strcmp(pk[i].m_name,Kname)==0){    //if two strings are equal
		                    flag = 1;
		                    j = i; //store the index for matched name into j
	                }	   
            }  
            if(flag == 0){
	                cout<<Kname<<" is not part of Westeros."<<endl;
	                cout<<"------------------------------"<<endl;
                    cout<<endl;
            }else if(flag == 1){
	                cout<< Kname<<", population "<<pk[j].m_population << endl;
	                cout<<"------------------------------"<<endl;
	     
            }
            
    }
}
	          

	