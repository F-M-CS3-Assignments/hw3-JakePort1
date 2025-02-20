comp: 
	g++ -Wall TimeCode.cpp -o TimeCode
	
run: 
	./TimeCode

all: comp run 

test: 
	g++ -Wall TimeCodeTests.cpp -o tct 
	comp 
	./tct


