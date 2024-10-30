NextGreaterPermutation: NextGreaterPermutation.o
	g++ -g -o NextGreaterPermutation.exe NextGreaterPermutation.o -pthread    

NextGreaterPermutation.o: NextGreaterPermutation/NextGreaterPermutation.cpp
	g++ -g  -c -pthread NextGreaterPermutation/NextGreaterPermutation.cpp
