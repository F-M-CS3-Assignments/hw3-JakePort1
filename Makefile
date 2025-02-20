comp: 
	g++ -Wall TimeCode.cpp -o TimeCode
	
run: 
	./TimeCode

all: comp run 

test: 
	g++ -Wall -v TimeCode.cpp TimeCodeTests.cpp -o tct
	./tct
	 