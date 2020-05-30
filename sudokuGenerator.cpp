#include<cstdlib> //srand et rand
#include<ctime>  // time(0)
#include<cmath> // sqrt()
#include"position.h"
#include"sudokuGenerator.h"


sudokuGenerator::sudokuGenerator(int dim,float difficulty){
	
	this->dim=dim;
	
	this->filled=0;
	
	this->difficulty=difficulty;
	
	// Allocation 
	grid = new int*[dim];
	
	for(int i = 0 ; i < dim ; i++ ){
		
		grid[i]= new int[dim]; 
	
	}
	
	
	// initialisation 
	for(int i = 0 ; i < dim ; i++ )
	
		for(int j = 0 ; j < dim ; j++ )
	
			grid[i][j]=0;
}

sudokuGenerator::~sudokuGenerator(){
	
				for(int i = 0 ; i< dim ; i++ )
				
					delete grid[i];
					
				delete grid;

} 

void sudokuGenerator::printGrid(){
	
	int racince = sqrt(dim);
	
	cout<<endl;
		
	for (int i = 0 ; i < dim; i++ ){
		
		for(int j = 0 ; j < dim ; j++ ){
			
			if( j == (dim-1) ) 	cout << grid[i][j] << endl;
			
			else if( (j+1)%racince == 0 ) 	cout << grid[i][j] << "    ";
			
			else 	cout << grid[i][j] << "  ";
			
			
		}
		
		if( (i+1)%racince == 0)	  cout << endl;
	}
}

bool sudokuGenerator::isOk( position p , int val ){

	for(int i = 0 ; i < dim ; i++ ){
            
			if( grid[p.getX()][i] == val )
            
                return false;
        }

        for(int i = 0 ; i < dim; i++ ) 
        
			if( grid[i][p.getY()] == val )
			
				return false;
				
        int racince = sqrt(dim);
        
        int xBox = (p.getX()/racince )*racince;
        
        int yBox = (p.getY()/racince )*racince;

        for( int i = 0 ; i < racince ; i++ )
        
            for( int j = 0 ; j < racince ; j++ )
            
                if( grid[xBox+i][yBox+j] == val )
                
                    return false;
                
        return true;
        
}

int ** sudokuGenerator::getGrid(){
	
	int dim2= dim *dim ;
	
	
	
	while(filled < dim2 * difficulty ){
		
		srand(time(0));
		
		int x=rand() % dim ; // de 0 à dim-1 qui correspond aux indices de tableaux
		
		int y=rand() % dim ; // idm 
		
		if( grid[x][y] == 0 ){
			
			do{
				
				int val=rand() % dim +1 ;
				
				if( isOk( position(x,y) , val ) ) {
					
					grid[x][y]=val;
					
					filled++;
					
					//cout<<"insert"<<endl;
				}
				
			}while(grid[x][y] == 0 );
				
		}
		
		
	}
	
	return  grid;
	
}


