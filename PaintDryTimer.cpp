// Jacob Port 
// Homework 3 part 2 


#include <ctime> // for time(0)
#include <iostream> // for cin and cout
#include <cmath> // for M_PI and others
#include<vector>
#include <vector> // for vectors (duh)
#include <cstdlib> // for random
#include <cassert> // for assert in the tests() function
#include "TimeCode.h" // for timecode's (duh)

using namespace std;

//helper function to make the names 
string BatchNumGenerator(){
	srand(time(0)); 
	return "Batch-" + to_string(rand());
}

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
	TimeCode tc = TimeCode(get_time_remaining(dss)); 
	if(timeRemaining > 0){
		 SnapShot = dss.name + ": Takes " + dss.timeToDry->ToString() + ". Time pase remaining: " + tc.ToString() + ")";
	}else{
		 SnapShot = dss.name + ": Takes " + dss.timeToDry->ToString() + ". DONE!" + ")";
	}
	return SnapShot;
}

double get_sphere_sa(double rad){
	// replace with your code
	return 4.0 * 3.14 * (pow(rad,2)); // returns 4 pi r^2, the formula for SA of a sphere 
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
			double radius; 
			string RadAsString; 
			cin >> RadAsString; 
			radius = stod(RadAsString);

			//gets time code and 
			TimeCode TimeToDry = TimeCode(get_sphere_sa(radius));

			// creates the DryignSnapshot Struct 
			DryingSnapShot *snapshot = new DryingSnapShot; 
			snapshot->name = BatchNumGenerator();
			snapshot->startTime = time(0); 
			snapshot->timeToDry = new TimeCode(get_sphere_sa(radius)); 

			batches.push_back(snapshot); // pushes the struct back to the vector 

			cout << snapshot->name << "(takes " << TimeToDry.ToString() << " to dry. Time remaining: " <<  TimeToDry.ToString() << ")" << endl;

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

		for(DryingSnapShot *s : batches){
			
			delete s->timeToDry;
			delete s;
		}

	}

	return 0;
}