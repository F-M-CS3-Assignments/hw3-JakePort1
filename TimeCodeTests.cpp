
#include <iostream>
#include <assert.h>
using namespace std;

#include "TimeCode.h"


void TestComponentsToSeconds(){
	cout << "Testing ComponentsToSeconds" << endl;
	
	// Random but "safe" inputs
	long long unsigned int t = TimeCode::ComponentsToSeconds(3, 17, 42);
	assert(t == 11862);
	
	// More tests go here!
	
	cout << "PASSED!" << endl << endl;
}


void TestDefaultConstructor(){
	cout << "Testing Default Constructor" << endl;
	TimeCode tc;
	
	//cout << "Testing ToString()" << endl;
	//cout << "tc: " << tc.ToString() << endl;
	assert(tc.ToString() == "0:0:0");
	
	cout << "PASSED!" << endl << endl;
}


void TestComponentConstructor(){
	cout << "Testing Component Constructor" << endl;
	TimeCode tc = TimeCode(0, 0, 0);
	//cout << "Testing ToString()" << endl;
	//cout << "tc: " << tc.ToString() << endl;
	assert(tc.ToString() == "0:0:0");
	
	// more tests go here!
	
	// Roll-over inputs
	TimeCode tc3 = TimeCode(3, 71, 3801);
	//cout << "tc3: " << tc3.ToString() << endl;
	assert(tc3.ToString() == "5:14:21");
	
	// More tests go here!
	
	cout << "PASSED!" << endl << endl;
}


void TestGetComponents(){
	cout << "Testing GetComponents" << endl;
	
	unsigned int h;
	unsigned int m;
	unsigned int s;
	
	// Regular values
	TimeCode tc = TimeCode(5, 2, 18);
	tc.GetComponents(h, m, s);
	assert(h == 5 && m == 2 && s == 18);
	
	// More tests go here!
	
	cout << "PASSED!" << endl << endl;
}


void TestSubtract(){
	cout << "Testing Subtract" << endl;
	TimeCode tc1 = TimeCode(1, 0, 0);
	TimeCode tc2 = TimeCode(0, 50, 0);
	TimeCode tc3 = tc1 - tc2;
	assert(tc3.ToString() == "0:10:0");
	
	
	TimeCode tc4 = TimeCode(1, 15, 45);
	try{
		TimeCode tc5 = tc1 - tc4;
		cout << "tc5: " << tc5.ToString() << endl;
		assert(false);
	}
	catch(const invalid_argument& e){
		// just leave this empty
		// and keep doing more tests
	}

	// more tests
	
	cout << "PASSED!" << endl << endl;
}


void TestSetMinutes()
{
	cout << "Testing SetMinutes" << endl;

	TimeCode tc = TimeCode(8, 5, 9);
	tc.SetMinutes(15); // test valid change
	assert(tc.ToString() == "8:15:9");

	try
	{
		tc.SetMinutes(80);  // test invalid change
		assert(false);
	}
	catch (const invalid_argument &e)
	{
		// cout << e.what() << endl;
	}

	assert(tc.ToString() == "8:15:9");

	cout << "PASSED!" << endl << endl;
}


void Tests1(){

	//tests overflow
	TimeCode t1 = TimeCode(0,0,61);
	assert(t1.ToString() == "0:1:1");

	//tests mins overflow 
	TimeCode t2 = TimeCode(0,61,1);
	assert(t2.ToString() == "1:1:1");

	// tests adding properties: 
	TimeCode add1 = TimeCode(2,59,0);
	TimeCode add2 =  TimeCode(0,1,0);
	TimeCode t3 = add1 + add2; 	
	assert(t3.ToString() == "3:0:0");

	// tests substraction with the same timecode objects from before:
	TimeCode t4 = add1 - add2; 
	assert(t4.ToString()=="2:58:0");

	//Tests division and multiplication: 
	TimeCode forMult = TimeCode(1,2,3); 
	forMult = forMult * 2; 
	assert(forMult.ToString() == "2:4:6");

	TimeCode forDiv = TimeCode(2,4,6); 
	forDiv = forDiv / 2; 
	assert(forDiv.ToString() == "1:2:3");

	TimeCode x = TimeCode(999,999,999);
	TimeCode y = TimeCode(1,1,1);
	assert(x>y);
	assert(x>=y);
	assert(y<x);
	assert(y<=x);

	TimeCode j = TimeCode(1,1,1); 
	assert(j == y); //tests for eqaulity between j and y--which is also 1:1:1
	
	assert(j!=x); // j is 1:1:1, x is larger, 

	assert(j.GetHours() == 1); 

	TimeCode t6 = TimeCode(99,9,9); 
	unsigned int I, J, K; 
	t6.GetComponents(I,J,K); 
	assert(I == 99); 
	assert(K == 9); 
	assert(K = 9); 	
}
	
int main(){

	cout << "Starting initial tests: " << endl;
	TestComponentsToSeconds();
	TestDefaultConstructor();
	TestComponentConstructor();
	TestGetComponents();
	cout << "All initial tests passed!  " << endl << endl; 
	cout << "Starting new tests: " << endl; 

	Tests1();

	// Many othere test functions...
	cout << "PASSED ALL TESTS!!!" << endl;
	return 0;
}
