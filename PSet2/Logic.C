#include <stdio.h>
#include <stdbool.h>

int main(){
    int a, b;
    bool result;
    //int a, b, result;

    a = 10;
    b = 11;

    //0 means false, 1 means true
    a = b = true; //set a and b to true
    printf("a = %i, b = %i\n", a, b);
    result = !a;
    printf("!a = %i\n", result);

    b = false;
    result = a && b;
    printf("a && b -> %i\n", result);

    b = false;
    result = a || b;
    printf("a && b -> %i\n", result);

    return 0;

}