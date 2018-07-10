#include "stdio.h"

int main()
{
    int a = 1000;
    if (fork()) {
        a /= 2;
        printf("\n Value of a = %d", a);
    }

    else {
        if (fork()) {
            a *= 2;
            printf("\n Value of a= %d", a);
            printf("\n Value of a= %d", a);

            if (execlp("ls", "ls", "-l", 0) == -1) {
                a = a + 2;
                printf("\n Value of a = %d", a);
            }
        }
        else {
            a += 3;
            printf("\n Value of a = %d", a);
        }
    }

    a++;
    printf("\n Value of a = %d", a);
    return 0;
}