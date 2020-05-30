//#ifndef position
//#define position


class position{
	
		int x;
		
		int y;
		
		int lastValue;
		
		bool checked;
	
	public :	
		
		position(int, int);
		
		void affiche();
		
		int getX();
		
		int getY();
		
		void setX(int);
		
		void setY(int);
		
		int getLastValue();
		
		bool getChecked();
		
		void setLastValue(int);
		
		void setChecked(bool);
		
};

//#endif
