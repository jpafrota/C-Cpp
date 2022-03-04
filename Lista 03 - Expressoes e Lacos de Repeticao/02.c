#include <stdio.h>

int main(){
	
	double b, h, s;
	double area;
	
	scanf("%lf%lf%lf", &b, &h, &s);
	
	b *= s;
	h *= s;
	
	area = (b * h) / 2;
	
	printf("%.2lf", area);
	
}