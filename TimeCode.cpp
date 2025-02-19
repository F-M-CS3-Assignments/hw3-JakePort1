// Jacob Port 
// CPS 222 HW#3
// Implementation of TimeCode class 

#include<stdexcept>
using namespace std; 

#include "TimeCode.h"



    // constructor sets time as 0
    TimeCode::TimeCode(unsigned int hr, unsigned int min, unsigned long long int sec){
        /*
        Insert overflow fixes here: 
        */
        t = TimeCode::ComponentsToSeconds(hr,min,sec); 
   }; 

    //copy consturcotr: 

    // Other constuctor: 

    // set functions 
    void TimeCode::SetHours(unsigned int hours){
        t = ComponentsToSeconds(hours,GetMinutes(),GetSeconds());  
    }; 

    void TimeCode::SetMinutes(unsigned int minutes){
        t = ComponentsToSeconds(GetHours(),minutes,GetSeconds());
    }; 

    void TimeCode::setSeconds(unsigned int seconds){
        t = ComponentsToSeconds(GetHours(),GetMinutes(),seconds);
    }; 


    // getting components:
    unsigned int TimeCode::GetHours() const{
        return t / 3600; // integer division reveals # of hours
    }; 

    unsigned int TimeCode::GetMinutes() const{
        return ((t - (60 * GetHours())/ 60));  // subcract the hours worth of seconds from t, then use integer division to get the minutes 
    };

    unsigned int TimeCode::GetSeconds() const{
        return (t - (3600*GetHours() - (60 * GetMinutes()))); // whatever is left after subtracting out the seconds of the hours and minutes
    }


    //Acessing time in differnt ways:
        
    long long unsigned int TimeCode::ComponentsToSeconds(unsigned int hr, unsigned int min, unsigned int sec){
        return sec + (60 * min) + (3600 * hr); //just adds everythning together 
    }

    void GetComponents(unsigned int& hr, unsigned int& min, unsigned int& sec) const{
        /*
        Not yet sure how this is supposed to work lol 
        */
    }; 


    long long unsigned int TimeCode::GetTimeCodeAsSeconds() const {return t;};  //simply returns time 










    




