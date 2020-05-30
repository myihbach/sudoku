#include<cmath>
#include"position.h"
#include"sudoku.h"

sudoku::sudoku( int ** a, int dim){
	
	currentPosition=0;
	
	this->dim=dim;
	
	matrice = new int* [dim];
	
	for( int i=0 ; i < dim ; i++ ) matrice[i] = new int [dim] ;
	
	for(int i = 0 ; i < dim ; i++ ){
		
		for(int j = 0 ; j < dim ; j++ ){
			
			matrice[i][j]=a[i][j];
			
		}
	}
	
	//recuperer les positions vides
	getEmpty();
}

//sudoku :: ~sudoku(){
//	
//	for(int i = 0 ; i< dim ; i ++ )
//	
//		delete matrice[i];
//		
//	delete matrice;
//}

void sudoku::printSudoku(){
	
	int racince = sqrt(dim);
	
	cout<<endl;
	
	for (int i = 0 ; i < dim; i++ ){
		
		for(int j = 0 ; j < dim ; j++ ){
			
			if( j == (dim-1) ) 	cout << matrice[i][j] << endl;
			
			else if( (j+1)%racince == 0 ) 	cout << matrice[i][j] << "    ";
			
			else 	cout << matrice[i][j] << "  ";
			
			
		}
		
		if( (i+1)%racince == 0)	  cout << endl;
	}
	
}
	 
void sudoku::getEmpty(){
	
	for (int i = 0 ; i < dim ; i++ ){
	
		for(int j = 0 ; j < dim ; j++ ){
	
			if( matrice[i][j] == 0 ){
	
				listEmpty.push_back(position(i,j));
	
			}
		}
	}
}

void sudoku::printEmpty(){
	for(int i=0 ; i < listEmpty.size() ; i++ )    listEmpty[i].affiche();
}



bool sudoku::isOk( position p , int val ){

	for(int i = 0 ; i < dim ; i++ ){
            
			if( matrice[p.getX()][i] == val )
            
                return false;
        }

        for(int i = 0 ; i < dim; i++ ) 
			if( matrice[i][p.getY()] == val )
				return false;
				
        int racince = sqrt(dim);
        
        int xBox = (p.getX()/racince )*racince;
        
        int yBox = (p.getY()/racince )*racince;

        for( int i = 0 ; i < racince ; i++ )
        
            for( int j = 0 ; j < racince ; j++ )
            
                if( matrice[xBox+i][yBox+j] == val )
                
                    return false;
                
        return true;
        
}

void sudoku::solve(){
		
	
	for(int i=currentPosition;i<listEmpty.size();i++){
		
		for(int n=listEmpty[i].getLastValue()+1;n<=dim;n++){
			
			if(isOk(listEmpty[i],n) && listEmpty[i].getChecked()==false){
				
				matrice[listEmpty[i].getX()][listEmpty[i].getY()]=n;
				
				listEmpty[i].setLastValue(n);
				
				currentPosition++;
				
				listEmpty[i].setChecked(true);
				
				solve();
			}
			if(listEmpty[i].getChecked()==false && n==dim){
				
				listEmpty[i].setLastValue(0);
				
				matrice[listEmpty[i].getX()][listEmpty[i].getY()]=0;
				
				if(listEmpty[i-1].getLastValue()==dim) listEmpty[i-1].setLastValue(listEmpty[i-1].getLastValue()-1);
				
				listEmpty[i-1].setChecked(false);
				
				currentPosition--;
				
				solve();
			}
		}
//		// 
//		for(int i=0;i<listEmpty.size();i++)
//			if(listEmpty[i].getChecked()==false) return false;
//		return true;
			
				
	}
}
	 
	
