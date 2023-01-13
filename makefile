stb_impro : stb_impro.cpp
	g++ -o stb_impro stb_impro.cpp
main : main.cpp Image.h
	g++ -o main main.cpp 
