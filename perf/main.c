#include <stdio.h>
#include "test.h"

int main()
{
    unsigned int i = 0;
    unsigned long tick = 0;
    double average = 0;

    for (i = UT_MM_BASE; i < UT_MM_MAX_COUNT; i++)
    {
        struct InsCase * ins = TestCase(i);
        if (ins && ins->func && ins->str)
        {
            tick = ins->func();
            average = 1.0 * tick / 100000;
            printf("%s:  tick:%ld, time:%lf ns\n", ins->str, tick, average);
        }

    }
    printf("Run Test Complete %d\n", i);

    return 0;
}
