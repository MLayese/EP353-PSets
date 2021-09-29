#include <stdio.h>

int main() {

    for (int i = 0; i < 11; i+=4) 
    {
         printf("---\n");
        for (int j = 0; j < 11; j+=2) 
        {
            if (j >= i) printf("Integer j is %i\n", j);
        }
    }
    return 0;
}