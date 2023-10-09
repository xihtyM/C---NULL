#include <stdio.h>
#include "null.h"

typedef struct T
{
	int a;
	int b;
} T;

int main(void)
{
	printf("%p, %p\n", (T*)null, null);
    return 0;
}
