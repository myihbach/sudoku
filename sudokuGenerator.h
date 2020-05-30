#include<iostream>
#include<vector>
using namespace std;

class sudokuGenerator{
	
	int ** grid;
	int dim;
	float difficulty;
	int filled;
	
	public:
		
		sudokuGenerator(int,float);
		~sudokuGenerator();
		bool isOk(position,int);
		int ** getGrid();
		void printGrid();
};
