#include<iostream>
#include<fstream> 
#include<string> 
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


TimeCode parse_line(string){
    TimeCode x =  TimeCode(0,0,0);

    return x; //for testing 
}



vector<string> split(string, char delim){

    vector<string> myVec;
    return myVec;
}


int main(){

    //opening file: 
    ifstream IF;
    IF.open("/Users/jacobport/Desktop/CPS 222/Homeworks /hw3-JakePort1/Space_Corrected_Short.csv");

    // tests if file is open: 
    if(!IF.is_open()){ 
        cout << "could not open the file!"; 
        return 1; // error 
    }

    string csvLine; 
    getline(IF, csvLine);
    cout << csvLine; 

/*
    Stucture: 

    Iteratre through lines of csv: 
        send to split, 
            if index 5 is not empty (""), send to parse_line to get a time code object, 
            send that time code object to list of vectors, 

    Take the list of vectors, and get their average time, lots of ways to do this. 

*/






   
   IF.close();


    return 0;
}