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
    /*
    Implement here: 
    */
    


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
        return (  (t-(GetHours()*3600)) / 60   );
          // subcract the hours worth of seconds from t, then use integer division to get the minutes 
    };

    unsigned int TimeCode::GetSeconds() const{
        return t % 60; // whatever is left after subtracting out the seconds of the hours and minutes
    };

    // long long unsigned int TimeCode::GetTimeCodeAsSeconds() const{
    //     return t; 
    // }

    //Acessing time in differnt ways:
        
    long long unsigned int TimeCode::ComponentsToSeconds(unsigned int hr, unsigned int min, unsigned int sec){
        return sec + (60 * min) + (3600 * hr); //just adds everythning together 
    };

    // void TimeCode::GetComponents(unsigned int& hr, unsigned int& min, unsigned int& sec) { //was having issues with "const", check this again later 
    //     /*
    //     Not yet sure how this is supposed to work lol 
    //     */
    // }; 


    string TimeCode::ToString() const{
        return to_string(GetHours()) + ":" + to_string(GetMinutes()) + ":" + to_string(GetSeconds()); //converst numbers to a string
        }; 

    //dealing with the operators now: 

    TimeCode TimeCode::operator+(const TimeCode& other) const{ 
        unsigned int total_seconds = TimeCode::ComponentsToSeconds(other.GetHours(),other.GetMinutes(),other.GetSeconds());
        total_seconds += this->GetTimeCodeAsSeconds();

        unsigned int hours = total_seconds / 3600; 
        unsigned int mins = (total_seconds - (3600 * hours)/ 60);
        unsigned int secs = total_seconds % 60;
        return TimeCode(hours,mins,secs); 
    }; 
    //NOTE TO SELF: what happens if they substract a time so that it goes negative? Throw an excpetion?
    TimeCode TimeCode::operator-(const TimeCode& other) const{ 
        unsigned int total_seconds = TimeCode::ComponentsToSeconds(other.GetHours(),other.GetMinutes(),other.GetSeconds());

        if(total_seconds < this->GetTimeCodeAsSeconds()){ //checks to make sure will not go negative, throws excpetions otherwise 
            throw runtime_error("You cannot substract a larger time from a smaller time! You cannot have a negative time!");
        }

        total_seconds -= this->GetTimeCodeAsSeconds();
        unsigned int hours = total_seconds % 3600; 
        unsigned int mins = (total_seconds - (60 * hours)/ 60);
        unsigned int secs = (total_seconds - (3600*hours - (60 * mins)));
        return TimeCode(hours,mins,secs); 
    }; 

    TimeCode TimeCode::operator*(double a) const{ 
        unsigned int total_seconds = this->GetTimeCodeAsSeconds(); 
        total_seconds *= a; 
        unsigned int hours = total_seconds % 3600; 
        unsigned int mins = (total_seconds - (60 * hours)/ 60);
        unsigned int secs = (total_seconds - (3600*hours - (60 * mins)));
        return TimeCode(hours,mins,secs);
        }

    TimeCode TimeCode::operator/(double a) const{ 
        unsigned int total_seconds = this->GetTimeCodeAsSeconds(); 
        total_seconds /= a; 
        unsigned int hours = total_seconds % 3600; 
        unsigned int mins = (total_seconds - (60 * hours)/ 60);
        unsigned int secs = (total_seconds - (3600*hours - (60 * mins)));
        return TimeCode(hours,mins,secs);
        }
   

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


int main(){

    TimeCode time; 
    time = TimeCode(12,35,30);
    TimeCode temp = TimeCode(1,1,1);
    
    TimeCode x = time.operator+(temp);

    cout << time.ToString() << endl << endl;
    cout << x.ToString();

    return 0; 
}

