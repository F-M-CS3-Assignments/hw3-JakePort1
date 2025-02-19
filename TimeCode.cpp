// Jacob Port 
// CPS 222 HW#3
// Implementation of TimeCode class 

#include<stdexcept>
using namespace std; 

#include "TimeCode.h"



    // constructor sets time as 0
    TimeCode::TimeCode(unsigned int hr = 0, unsigned int min = 0, unsigned long long int sec = 0){
        t = TimeCode::ComponentsToSeconds(hr,min,sec);
   }; 

    //copy consturcotr: 

    // Other constuctor: 


    void SetHours(unsigned int hours){
        unsigned int min = t + 3600;
        unsigned int seconds = t % 60; 



        t = t + (3600 * hours);
    }; 

    void SetMinutes(unsigned int minutes){
        this->t += (minutes * 60);
    }; 


    void setSeconds(unsigned int seconds); 






        
    long long unsigned int TimeCode::ComponentsToSeconds(unsigned int hr, unsigned int min, unsigned int sec){
        
        return sec + (60 * min) + (3600 * hr);
    
    }






    




