all:
	g++ .\CustomObject\Station.cpp .\CustomObject\Time.cpp .\CustomObject\Train.cpp .\Utils\Random.cpp .\Drivers\Driver.cpp .\main.cpp -o coursework

test:
	g++ .\CustomObject\Time.cpp .\CustomObject\Station.cpp .\CustomObject\Train.cpp .\Utils\Random.cpp .\main.cpp -o test