#include<stdio.h>

// round off till three decimal places
// Disadvantage it can't print variable point values stated by the user see at line no. 41

float roundoff( float num , long long n ){

    long long c=1;
    while( n-- ){
        num = num*10;
        c*=10;
    }
    c/=10;
    long long temp = (int)num;
    if( temp%10 > 5 ){
        temp = temp/10;
        temp++;
    }
    else if( temp%10 == 5 ){
        temp/=10;
        if( (temp%10)%2 != 0 ){
            temp++;
        }
    }
    return (float)temp/c;
}

int main(){

    float num;
    printf("Enter the number : ");
    scanf("%f",&num);
    
    long long n;
    printf("Enter the decimals upto which you want round off : ");
    scanf("%d",&n);

    float result = roundoff(num , n+1);
    
    printf("%.4f",result);
    return 0;
}