#include<iostream>
#include<fstream> 
#include<string> 
#include<sstream>
#include "TimeCode.h"
#include <vector>
using namespace std; 






/* 
    extract time values from ccvs, under datum header in format: 
          Fri Aug 07, 2020 05:12 UTC
    could do somehting like, if ':' in string, thne use that string, 


    then, make an average of all these times, coudl do this by averaging the raw time, or something similar, 


    I will also need to make a vector of all the times as objects, this will probably have to be some sort of dynamic thing 


*/


TimeCode parse_line(string s){
    TimeCode x =  TimeCode(0,0,0);
    string hour; 
    string min; 
    unsigned int sec = 0;  // times don't include seconds so can assume they're 0.

    istringstream iSS(s);
    //puts the hours and mins spereated by : into variables 
    getline(iSS, hour, ':');
    getline(iSS, min, ':');

    return TimeCode(stoi(hour), stoi(min), sec);
}



vector<string> split(string s, char delim){
    vector<string> vals;
    istringstream iSS(s); 

    string element;
    while(getline(iSS,element,delim)){
        vals.push_back(element);
    }


    return vals;
}


int main(){
    vector<TimeCode> Times; 

    //opening file: 
    ifstream IF;
    IF.open("Space_Corrected.csv");

    // tests if file is open: 
    if(!IF.is_open()){ 
        cout << "could not open the file!"; 
        return 1; // error 
    }

    string csvLine; 
    getline(IF, csvLine);

    //iterates through csv and creates vector of times objects:
    while(!IF.eof()){
        getline(IF,csvLine); //gets next line with every iteration 
        
        // split() splits line into a vector of strings based on delimiter ','
         vector<string> row = split(csvLine,' '); // use space as delimiter to make year and time in seperate indexes 

        //checks to see if the time value Datum of the above vector has a valid time: 
        for(string element : row){
            //str.find() will return string::npos if it can't find the character. Therefor, this code will parse if it finds an
            // element that has ":" in it 
            if(element.find(':') != string::npos){ //avoids rows that have no time value. 
                Times.push_back(parse_line(element));
            }
        }
    }


    //gets average from the vector of TimeCode objects. Does this by getting all of the raw t (seconds) values, adding them and average 
    // number of elements in Times vector. 
    unsigned int totalSeconds = 0; 
    for(TimeCode t : Times){
        totalSeconds += t.GetTimeCodeAsSeconds();
    }

    //averages the time 
    unsigned int avgTimeAsSeconds = totalSeconds / Times.size(); 

    //Creates TimeCode object that represents the average time: 
    TimeCode avg = TimeCode(avgTimeAsSeconds); // this uses the one parameter contructor I made for just a time value input 

    cout << Times.size() << " data points." << endl;
    cout<< "AVERAGE: " << avg.ToString() << endl; 
    // Outputs 4198 data points and an avergae time of 12:7:56 for "Space_Corrected.csv"

    
   
   IF.close();

    return 0;
}