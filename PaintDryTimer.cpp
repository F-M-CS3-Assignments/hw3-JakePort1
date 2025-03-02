


#include <ctime> // for time(0)
#include <iostream> // for cin and cout
#include <cmath> // for M_PI and others
#include<vector>
#include <vector> // for vectors (duh)
#include <cstdlib> // for random
#include <cassert> // for assert in the tests() function
#include "TimeCode.h" // for timecode's (duh)

using namespace std;




struct DryingSnapShot {
	// This is a struct, it's like an object
	// that doesn't have any methods.
	// You can read more about them in the ZyBook
	// just search for "struct"
	string name;
	time_t startTime;
	TimeCode *timeToDry;
};


long long int get_time_remaining(DryingSnapShot &dss){
	// Replace with your code
	time_t currTime = time(0); 
	time_t timePassed = currTime - dss.startTime;
	time_t timeRemaining = dss.timeToDry->GetTimeCodeAsSeconds() - timePassed;
	return timeRemaining;
}


string drying_snap_shot_to_string(DryingSnapShot dss){
	// Replace with your code
	int timeRemaining = get_time_remaining(dss);
	string SnapShot = ""; 
	if(timeRemaining > 0){
		 SnapShot = dss.name + ": Takes " + dss.timeToDry->ToString() + ". Time pase remaining: " + to_string(get_time_remaining(dss));
	}else{
		 SnapShot = dss.name + ": Takes " + dss.timeToDry->ToString() + ". Time pase remaining: 00:00:00)";
	}
	return SnapShot;
}


double get_sphere_sa(double rad){
	// replace with your code
	return 4 * 3.14 * (pow(rad,2)); // returns 4 pi r^2, the formula for SA of a sphere 
}


TimeCode *compute_time_code(double surfaceArea){
	TimeCode *tc = new TimeCode(surfaceArea); //uses raw time in seconds constructor 
	return tc;
}


void tests(){
	// get_time_remaining
	DryingSnapShot dss;
	dss.startTime = time(0);
	TimeCode tc = TimeCode(0, 0, 7);
	dss.timeToDry = &tc;
	long long int ans = get_time_remaining(dss);
	assert(ans > 6 && ans < 8);
	// add more tests here


	// get_sphere_sa
	double sa = get_sphere_sa(2.0);
	assert (50.2654 < sa && sa < 50.2655);
	// add more tests here


	// compute_time_code
	TimeCode *tc2 = compute_time_code(1.0);
	//cout << "tc: " << tc.GetTimeCodeAsSeconds() << endl;
	assert(tc2->GetTimeCodeAsSeconds() == 1);
	delete tc2;


	// add more tests here


	cout << "ALL TESTS PASSED!" << endl;

}


int main(){
	vector<TimeCode> times; // will save all the time code objects that are made here 
	vector<DryingSnapShot*> batches; // will track all the batches 


	time_t start = time(0); 

	/* 
	1. get the radius 
	2. convert to time it will take, 
	3. get current time, (time(0))
	4. while cur time != zero, keep the program runniing, such that if the user inputs view or add, it will keep the program goign 
	5. figure out how the batch Id thing works;
	
	*/

	cout << "Choose an option: (A)dd, (V)iew Current Items, (Q)uit: a" << endl;
	bool quit = false; 
	string status; 


	while(true){
		cin >> status; 
		if(status == "q" || status == "Q"){
			break;
		}else if(status == "A" || status == "a"){
			//gets radius
			cout << "radius: "; 
			double radius; string RadAsString; 
			cin >> RadAsString; 
			radius = stoi(RadAsString);



			//gets time code and 
			TimeCode TimeToDry = TimeCode(get_sphere_sa(radius));

			// creates the DryignSnapshot Struct 
			DryingSnapShot *snapshot = new DryingSnapShot; 
			snapshot->name = "batch name"; 
			snapshot->startTime = time(0); 
			snapshot->timeToDry = &TimeToDry; 
			batches.push_back(snapshot); // pushes the struct back to the vector 

			cout << "Batch Number: " << "(takes " << TimeToDry.ToString() << " to dry. Time remaining: " <<  TimeToDry.ToString() << endl;


		}else if (status == "v" || status == "V"){
			for(DryingSnapShot* s : batches){
				double timeRemaining = get_time_remaining(*s);
				cout << drying_snap_shot_to_string(*s) << endl;
			}
			cout << "there are " << batches.size() << " being tracked. " << endl;


		}else{
			cout << "Please choose a valid option: (A)dd, (V)iew Current Items, (Q)uit:" << endl;
			continue; 
		}



	}
	








	time_t end = time(0); 

	time_t duration = (end - start); // gives duration from start to end in seconds.
	return 0;
}