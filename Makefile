comp: 
	g++ -g -Wall TimeCode.cpp TimeCodeTests.cpp -o tct
	g++ -g -Wall TimeCode.cpp NasaLaunchAnalysis.cpp -o nasa
	g++ -Wall TimeCode.cpp PaintDryTimer.cpp -o pdt

run: 
	./tct
	./nasa
	./pdt

all: comp run 
