comp: 
	g++ -g -Wall TimeCode.cpp TimeCodeTests.cpp -o tct
	g++ -g -Wall TimeCode.cpp NasaLaunchAnalysis.cpp -o nasa

run: 
	./tct
	./nasa

all: comp run 
