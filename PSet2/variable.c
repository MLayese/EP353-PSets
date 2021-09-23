# include <stdio.h>

int main (){

    int number = 123;
    double pi = 3.1416;
    float z = 40.5f;
    char c = 20;
    char *str = "Hello, World!";
    
    printf("number: %i, pi: %f, z: %f, c: %i, str: %s\n",
        number, pi, z, c, str);

    number = 234;
    pi = 3.14159265;
    z = .12f;
    c = 'a';
    str = "Hello, Variables!";

    return 0;
}