#include<iostream>
#include"position.h"

using namespace std;

position::position( int x, int y ){
	
	this->x=x;
	
	this->y=y;
	
	this->lastValue=0;
	
	this->checked=false;
}

void position::affiche(){
	
		cout<<x<<" - "<<y<<endl;
		
		cout<<"last Value :"<<lastValue<<endl;
		
		cout<<"etat :"<< (checked != 0 ? "true" : "false")<<endl;
		
}

int position::getX(){
	return this->x;
}

int position::getY(){
	return this->y;
}

void position::setX(int x){
	this->x=x;
}

void position::setY(int y){
	this->y=y;
}

int position::getLastValue(){
	return this->lastValue;
}

bool position::getChecked(){
	return this->checked;
}
		
void position::setLastValue(int lastValue){
	this->lastValue=lastValue;
}

void position::setChecked(bool checked){
	this->checked=checked;
}
