#include "VeloCity.h"

VeloCity::VeloCity(){
}

VeloCity::VeloCity(int x, int y, int rotate){
	this->x = x;
	this->y = y;
	this->rotate = rotate;
}

VeloCity::~VeloCity(){
}

void VeloCity::SetX(int x){
	this->x += x;
}

void VeloCity::SetY(int y){
	this->y += y;
}

void VeloCity::SetRotate(int rotate){
	this->rotate += rotate;
}

int VeloCity::GetX(){
	return x;
}

int VeloCity::GetY(){
	return y;
}

int VeloCity::GetRotate(){
	return rotate;
}
