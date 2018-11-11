#include"test.h"

void fun() {
    printf("%d\n", x);
}

int main(int argc, char const *argv[])
{
    float x = 1.1;
    int t = 0x1F;
    register int _help = 16;
    long long int a = 5;
    if(x == 1.1f) {
        printf("%d # %lu\n", t, sizeof(char));
        printf("%lld\n", a);
    }

    printf("INT32 %d", __INT32_MAX__);

    fun();
    return 0;
}
