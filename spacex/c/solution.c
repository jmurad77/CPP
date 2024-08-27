#include "stdio.h"
#include "stdlib.h"
#include "util.h"
#include "test_util.h"

/**
 * Write the sorted prime factorization of x to a file named solution.txt.
 *
 * Example: factor(420) writes the following to solution.txt:
 * "2 2 3 5 7"
 */
void factor(int x)
{
    FILE* fp = fopen("solution.txt", "wb");

    for(;;)
    {
        for (int c = 2; c * c <= x; ++c)
        {
            if (x % c == 0)
            {
                char str[100];
                snprintf(str, 100, "%d", c);
                fprintf(fp, "%s ", str);
                x /= c;
                goto repeat;
            }
        }
        char str[100];
        snprintf(str, 100, "%d", x);
        fprintf(fp, "%s ", str);

        break;

    repeat:
        continue;
    }

    fprintf(fp, "\n");
    fclose(fp);
}
