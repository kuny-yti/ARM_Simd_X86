#include <stdio.h>
#include "test.h"

int main()
{
    unsigned int i;
	
	init_data();
    for (i = UT_MM_BASE; i < UT_MM_MAX_COUNT; i++) {
        RunTest(i);
    }
    printf("Run Test Complete %d\n", i);

    return 0;
}
