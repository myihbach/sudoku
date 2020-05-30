#include <iostream>
#include"position.h"
#include"sudoku.h"
#include"sudokuGenerator.h"
using namespace std;
#define N  9

int ** fromStaticToDynamic(int tab[][N]);

int matrice[9][9]={{2, 0, 0, 0, 0, 0, 0, 0, 8},  
                   {7, 0, 0, 0, 9, 0, 0, 0, 0},  
                   {6, 0, 5, 0, 3, 0, 0, 0, 0},  
                   {3, 0, 0, 0, 0, 0, 6, 0, 0},  
                   {0, 0, 8, 4, 0, 7, 9, 0, 0},  
                   {1, 0, 0, 6, 8, 0, 0, 0, 0},  
                   {0, 0, 3, 2, 0, 0, 0, 0, 1},  
                   {0, 5, 0, 0, 0, 0, 0, 0, 6},  
                   {0, 0, 0, 8, 0, 0, 0, 4, 0}};
//                      
//int matrice[4][4]={{4, 0, 0, 1}, 
//         			 {0, 3, 0, 0}, 
//         			 {0, 0, 0, 0}, 
//        			 {2, 0, 0, 0}};
                      

int main() {
	// the second parameter is the diffuclty which represent the % of filled cases
	// the more closer to 1 the more longer to be generated 
	
//	sudokuGenerator sg(N,0.3); 
//	cout<<"The generated Grid "<<endl;
//	sudoku s(sg.getGrid(),N);
	sudoku s(fromStaticToDynamic(matrice),N);
	s.printSudoku();
	s.solve();
	cout<<"Sudoku well solved (; "<<endl;	
	s.printSudoku();
	
	return 0;
}



int ** fromStaticToDynamic(int tab[][N]){
	//Allocation
	int ** tmp;
	tmp = new int* [N];
	for(int i=0;i<N;i++)
		tmp[i]= new int[N];
	// initialisation
	for(int i = 0 ; i < N ; i++ )
		for(int j = 0 ; j < N ; j++ )
			tmp[i][j]= tab[i][j];
	return tmp;
}




