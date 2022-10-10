#include<stdio.h>

// truncate off till specified decimals
// Disadvantage it can't print variable point values stated by the user see at line no. 41

float truncate( float num , long long n ){

    long long c=1;
    while( n-- ){
        num = num*10;
        c*=10;
    }
    long long temp = (int)num;
    return (float)temp/c;
}

int main (){

    float num;
    printf("Enter the number : ");
    scanf("%f",&num);

    long long n;
    printf("Enter the decimals upto which you want truncate off : ");
    scanf("%d",&n);

    float result = truncate(num , n+1);
    
    printf("%.4f",result);
    return 0;
}