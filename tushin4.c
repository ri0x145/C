#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define X 500

double randA() {
	int j = rand()%2;
	if(j == 0) { 
	 	return +1/sqrt(2);
	 }else {
	 	return -1/sqrt(2);
	 }
}

int main(void) {
	 FILE *data,*gp;
	 char *data_file;
	 int i,k,m;
	 double A[5],dx , x, y=0.0;
	 
	 data_file = "out2.dat" ;
	 data = fopen(data_file , "w");
	 
	 

for(int l=0;l<80;l++){
	 for(k= 0;k<5;k++){
	 	A[k] = randA();
	 }
	 
	 dx = 4*M_PI/X;
	 for(i=0;i<=X;i++) {
	 	y=0;
	 	x = -2*M_PI+i*dx;
	 	for(m = -2; m<3 ; m++){
	 		
	 		y += A[m+2]* pow(M_PI,2) * sin(M_PI*(x-m)) /(M_PI*(x-m))*cos(0.5*M_PI*(x-m))/(pow(M_PI,2)-4*pow(0.5,2)*pow(M_PI,2)*pow((x-m),2));
        }
	 fprintf(data,"%f %f\n",x,y);	 
	
     }
}
     fclose(data);
     

     gp = popen("/Applications/gnuplot.app/bin/gnuplot -persist","w");
     fprintf(gp,"set xrange [-4.5:4.5]\n");
	 fprintf(gp,"plot \"%s\" with lines linetype 1 title \"a=0.5\"\n",data_file);


	 pclose(gp);
	 
	
	 return 0;
}
