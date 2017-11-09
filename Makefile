#Rohith Reddy and Daniel McNeill

all: tester


tester:
	g++ TST.h tester.cpp -o tester

clean:
	rm -f *.o tester
