#include <stdio.h>
#include "test.h"

int main()
{
    unsigned int i;
    int passCount = 0;
    int failCount = 0;
    for (i = UT_MM_BASE; i < UT_MM_MAX_COUNT; i++) {
        int flag = 0;
        const char *s = RunTest((InstructionTest)i, &flag);
        printf("Running Test:%d %s\n", i, s);
        if (flag) {
            passCount++;
        } else {
            printf("Run Test FAIL!!! %s\n", s);
            failCount++;
        }
    }
    printf("Run Test Complete: Passed %d tests : Failed %d\n", passCount, failCount);

    return 0;
}
