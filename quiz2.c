#include<stdio.h>
#include<math.h>
void  solveEquation(int a  , int b , int c){
    int x1 = (-b + sqrt((b*b) - (4*a*c))) / (2 * a);
    int x2 = (-b - sqrt((b*b) - (4*a*c))) / (2 * a);
    printf("Age One is %d and second is %d " , x1 , x2);
}
int main(){
    int a = 1;
    int b;
    printf("Enter First Number (Subtracted Number)\n ");
    b = 44;
    //scanf("%d" , &b);
    b = -1 * b;
    int c;
    printf("Enter Second Number (Multiplied Number) \n");
    //scanf("%d" , &c);
    c = 1280;
    c = -1 * c;
    solveEquation(a , b , c);
    return 0;
}