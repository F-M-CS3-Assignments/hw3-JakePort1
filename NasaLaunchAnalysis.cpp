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


TimeCode parse_line(string){
    TimeCode x =  TimeCode(0,0,0);

    return x; //for testing 
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

    //opening file: 
    ifstream IF;
    IF.open("Space_Corrected_Short.csv");

    // tests if file is open: 
    if(!IF.is_open()){ 
        cout << "could not open the file!"; 
        return 1; // error 
    }

    string csvLine; 
    getline(IF, csvLine);
    vector<string> test = split(csvLine, ',');
    for(string s : test){
        cout << s;
    }



    //iterates through csv: 
    while(!IF.eof()){
        getline(IF,csvLine); //gets next line with every iteration 
        
        // split() splits line into a vector of strings based on delimiter ',' 

        //parse_line() sends the 5th index of the above vector made above (fifth index being the time column) and makes it a TimeCode object

        
    }


    //gets average from the vector of TimeCode objects: 



    
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