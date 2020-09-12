#include <stdio.h>
#include "test.h"

int main()
{
    unsigned int i;
    int passCount = 0;
    int failCount = 0;

    for (i = UT_MM_BASE; i < UT_MM_MAX_COUNT; i++)
    {
        struct InsCase * ins = TestCase(i);
        if (ins && ins->func && ins->str)
        {
            printf("Running Test:%d %s\n", i, ins->str);
            if (ins->func())
                passCount++;
            else
            {
                printf("Run Test FAIL!!! %s\n", ins->str);
                failCount++;
            }
        }
    }
    printf("Run Test Complete: Passed %d tests : Failed %d\n", passCount, failCount);

    return 0;
}
