comp: 
	g++ -Wall TimeCode.cpp TimeCodeTests.cpp -o tct
	
run: 
	./tct

all: comp run 
