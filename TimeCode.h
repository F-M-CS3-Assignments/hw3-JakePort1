// Jacob Port 
// CPS 222 HW#3
// Header for TimeCode class 


#ifndef TIMECODE_H
#define TIMECODE_H

#include <iostream> 
using namespace std; 

class TimeCode{ 

    public: 
        TimeCode(unsigned int hr = 0, unsigned int min = 0, unsigned long long int sec = 0); 
        TimeCode(const TimeCode& tc); 
        ~TimeCode(){}; 

        void SetHours(unsigned int hours); 
        void SetMinutes(unsigned int minutes); 
        void setSeconds(unsigned int seconds); 

        void reset(); 

        unsigned int GetHours() const; 
        unsigned int GetMinutes(unsigned int minutes) const;
        unsigned int GetSeconds(unsigned int seconds) const; 

        long long unsigned int GetTimeCodeAsSeconds() const {return t;}; 
        void GetComponents(unsigned int& hr, unsigned int& min, unsigned int& sec) const; 
        static long long unsigned int ComponentsToSeconds(unsigned int hr, unsigned int min, unsigned int sec); 

        string ToString() const; 

        TimeCode operator+(const TimeCode& other) const; 
        TimeCode operator-(const TimeCode& other) const; 
        TimeCode operator*(double a) const; 
        TimeCode operator/(double a) const; 

        bool operator == (const TimeCode& other) const; 
        bool operator != (const TimeCode& other) const; 
        
        bool operator < (const TimeCode& other) const; 
        bool operator <= (const TimeCode& other) const; 

        bool operator > (const TimeCode& other) const; 
        bool operator >= (const TimeCode& other) const; 

        private: 
            long long unsigned int t = 0;
};

#endif