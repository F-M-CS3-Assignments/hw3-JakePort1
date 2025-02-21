// Jacob Port 
// CPS 222 HW#3
// Implementation of TimeCode class 

#include<stdexcept>
using namespace std; 

#include "TimeCode.h"

    // constructor sets time as 0
    TimeCode::TimeCode(unsigned int T){ //operator for if I just want to input the raw time in seconds score 
        t = T;
    };

    TimeCode::TimeCode(unsigned int hr, unsigned int min, unsigned long long int sec){
        t = TimeCode::ComponentsToSeconds(hr,min,sec);
        ; //this account for overflow by converting everything to seconds 
   }; 


    TimeCode::TimeCode(const TimeCode& tc){
        t = tc.t; // copies the t value from the tc adress ans assignes it to the new object
    }; 

    // The set functions just reset "t" with the CompoenentsToSeconds function by imputting the changed hour/min/sec 
    void TimeCode::SetHours(unsigned int hours){
        t = ComponentsToSeconds(hours,GetMinutes(),GetSeconds());  
    }; 

    void TimeCode::SetMinutes(unsigned int minutes){
        t = ComponentsToSeconds(GetHours(),minutes,GetSeconds());
    }; 

    void TimeCode::SetSeconds(unsigned int seconds){
        t = ComponentsToSeconds(GetHours(),GetMinutes(),seconds);
    }; 

    // getting components:
    unsigned int TimeCode::GetHours() const{
        return t / 3600; // integer division reveals # of hours
    }; 

    unsigned int TimeCode::GetMinutes() const{
        return ((t/60)%60); //divides by hours and mods to find left over mis 
            };

    unsigned int TimeCode::GetSeconds() const{
        return t % 60; // whatever is left after subtracting out the seconds of the hours and minutes
    };

    //Acessing time in differnt ways:
    long long unsigned int TimeCode::ComponentsToSeconds(unsigned int hr, unsigned int min, unsigned int sec){
        return sec + (60 * min) + (3600 * hr); //just adds everythning together 
    };

    void TimeCode::GetComponents(unsigned int& hr, unsigned int& min, unsigned int& sec) const {
        // sets the adress to the inputted vars to be the proper nums; essentiall a heler function
        hr = GetHours();
        min = GetMinutes();
        sec = GetSeconds();
        } 
   
    string TimeCode::ToString() const{
        return to_string(GetHours()) + ":" + to_string(GetMinutes()) + ":" + to_string(GetSeconds()); //converst numbers to a string
        }; 

    //dealing with the operators now: 
    TimeCode TimeCode::operator+(const TimeCode& other) const{ 
        unsigned int total_seconds = TimeCode::ComponentsToSeconds(other.GetHours(),other.GetMinutes(),other.GetSeconds());
        total_seconds += this->GetTimeCodeAsSeconds();

        //CANNOT use GetComponents for this because I only have the raw time (t) of the answer, its not yet in object form; applies to other operators as well
        unsigned int hours = total_seconds / 3600;  
        unsigned int mins = ((total_seconds /60) % 60);
        unsigned int secs = total_seconds % 60;

        return TimeCode(hours,mins,secs); 
    }; 
    //NOTE TO SELF: what happens if they substract a time so that it goes negative? Throw an excpetion?
    TimeCode TimeCode::operator-(const TimeCode& other) const{  //NOTE: Object on the right of the '-' sign will be passed as the argument, 

        if(other.GetTimeCodeAsSeconds() > this->GetTimeCodeAsSeconds()){ //checks to make sure will not go negative, throws excpetions otherwise 
            throw runtime_error("---You cannot substract a larger time from a smaller time! You cannot have a negative time!---");
        }else{

        unsigned int total_seconds = this->GetTimeCodeAsSeconds() - other.GetTimeCodeAsSeconds();
        unsigned int hours = total_seconds / 3600; 
        unsigned int mins = ((total_seconds /60) % 60);
        unsigned int secs = total_seconds % 60;
        return TimeCode(hours,mins,secs);
        }
    }; 

    TimeCode TimeCode::operator*(double a) const{ 
        unsigned int total_seconds = this->GetTimeCodeAsSeconds(); 
        total_seconds *= a; 
         unsigned int hours = total_seconds / 3600; 
        unsigned int mins = ((total_seconds /60) % 60);
        unsigned int secs = total_seconds % 60;
        return TimeCode(hours,mins,secs);
        }

    TimeCode TimeCode::operator/(double a) const{ 
        unsigned int total_seconds = this->GetTimeCodeAsSeconds(); 
        total_seconds /= a; 
        unsigned int hours = total_seconds / 3600; 
        unsigned int mins = ((total_seconds /60) % 60);
        unsigned int secs = total_seconds % 60;
        return TimeCode(hours,mins,secs);
        }
   
    //defines conditions for ==, !=, >, >=, <, <= 
    bool TimeCode::operator==(const TimeCode& other) const{
        if(this->GetTimeCodeAsSeconds() == other.GetTimeCodeAsSeconds()){
            return true; 
        }else {return false;}
     }; 

    bool TimeCode::operator!=(const TimeCode& other) const{
        if(this->GetTimeCodeAsSeconds() != other.GetTimeCodeAsSeconds()){
            return true; 
        }else {return false;}
     }; 

    bool TimeCode::operator>(const TimeCode& other) const{
        if(this->GetTimeCodeAsSeconds() > other.GetTimeCodeAsSeconds()){
            return true; 
        }else {return false;}
     }; 

    bool TimeCode::operator>=(const TimeCode& other) const{
        if(this->GetTimeCodeAsSeconds() >= other.GetTimeCodeAsSeconds()){
            return true; 
        }else {return false;}
     }; 

     bool TimeCode::operator<(const TimeCode& other) const{
        if(this->GetTimeCodeAsSeconds() < other.GetTimeCodeAsSeconds()){
            return true; 
        }else {return false;}
     }; 

     bool TimeCode::operator<=(const TimeCode& other) const{
        if(this->GetTimeCodeAsSeconds() <= other.GetTimeCodeAsSeconds()){
            return true; 
        }else {return false;}
     }; 
