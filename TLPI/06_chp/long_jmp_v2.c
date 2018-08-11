#include <setjmp.h>
#include <stdio.h>
#include <stdlib.h>

static jmp_buf env;

void foo();
void bar();
void baz();
void foo(int value)
{
    int local_variable = value;
    printf("foo started\n");
    switch (setjmp(env)) {
    case 0:
        printf("foo branch1 %d\n", local_variable);
        break;
    case 1:
        printf("foo branch2 %d\n", local_variable);
        break;
    }
    printf("foo end\n");
    return;
}

void baz()
{
    printf("baz start\n");
    longjmp(env, 1);
    printf("baz end\n");
    return;
}

void bar()
{
    printf("bar started\n");
    baz();
    printf("bar ended");
    return;
}

int main()
{
    foo(1000);
    bar();
    exit(EXIT_SUCCESS);
}
