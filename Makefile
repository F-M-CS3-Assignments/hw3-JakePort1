comp: 
	g++ -Wall TimeCode.cpp NasaLaunchAnalysis.cpp -o nasa
	
run: 
	./nasa

all: comp run 
