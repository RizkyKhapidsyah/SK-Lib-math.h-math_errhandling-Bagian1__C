#pragma fenv_access (on)

#include <stdio.h>      /* printf */
#include <math.h>       /* math_errhandling */
#include <errno.h>      /* errno, EDOM */
#include <fenv.h>       /* feclearexcept, fetestexcept, FE_ALL_EXCEPT, FE_INVALID */
#include <conio.h>

/*
    Source by CPlusPlus
    Modified For Learn by RK
    I.D.E : VS2019
*/

int main() {
    errno = 0;

    if (math_errhandling & MATH_ERREXCEPT) {
        feclearexcept(FE_ALL_EXCEPT);
    }

    printf("Error handling: %d\n", math_errhandling);

    sqrt(-1);

    if (math_errhandling & MATH_ERRNO) {
        if (errno == EDOM) {
            printf("errno set to EDOM\n");
        }
    }

    if (math_errhandling & MATH_ERREXCEPT) {
        if (fetestexcept(FE_INVALID)) {
            printf("FE_INVALID raised\n");
        }
    }

    _getch();
    return 0;
}