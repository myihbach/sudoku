//#ifndef sudoku
//#define sudoku

#include<iostream>
#include<vector>
using namespace std;
class sudoku{
 
		int **matrice;
		
		vector<position> listEmpty;
		
		int currentPosition;
		
		int dim;
	
	public :
	
		 sudoku(int**,int);
		 
		 void printSudoku();
		 
		 void solve();
		 
		 void getEmpty();
		 
		 bool isOk(position,int);
		 
		 void printEmpty();
		 
		 ~sudoku(){
	
				for(int i = 0 ; i< dim ; i ++ )
				
					delete matrice[i];
					
				delete matrice;
			}
	 
	
	
};

//#endif
