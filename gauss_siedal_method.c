#include<stdio.h>
#include<conio.h>
#include<math.h>

#define f1(x,y,z)  (17-y+2*z)/20
#define f2(x,y,z)  (-18-3*x+z)/20
#define f3(x,y,z)  (25-2*x+3*y)/20

int main (){

    float x0=0 ,y0=0, z0=0, x1, y1, z1, e1, e2, e3, e;
    int count=0;

    printf("Enter the tolerable error: ");
    scanf("%f",&e);

    do{
        x1 = f1(x0,y0,z0);
        y1 = f2(x1,y0,z0);
        z1 = f3(x1,y1,z0);
        printf("%d\t%0.4f\t%0.4f\t%0.4f\n",count,x1,y1,z1);

        e1 = fabs(x0-x1);
        e2 = fabs(y0-y1);
        e3 = fabs(z0-z1);

        x0 = x1;
        y0 = y1;
        z0 = z1;

        count++;
    }while( e1>e && e2>e && e3>e );

    printf("\nSolution: Iterations = %d\nx1=%0.4f\ny1=%0.4f\nz1=%0.4f",count,x1,y1,z1);
    getch();
    return 0;
}