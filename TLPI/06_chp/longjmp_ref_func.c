#include <stdio.h>
#include <setjmp.h>

static jmp_buf env;

void func(int jmp_switch_case) {
    if (jmp_switch_case) {
        switch (setjmp(env)) {
        case 0:
            printf("caz 1\n");
            break;
        case 1:
            printf("caz 2\n");
            break;
        case 2:
            printf("caz 3\n");
            break;
        }
    }
}

int main(int argc, char** argv) {
    //(void)argc;
    //(void)argv;
    func(0);
    func(1);
    longjmp(env,0);
}
