#include<stdio.h>
#include<stdarg.h>

void print_ints(int num, ...)
{
    va_list args;
    va_start(args, num);
    for(int i = 0; i<num;i++)
    {
        int value = va_arg(args, int);
        printf("%d: %d\n", i, value);
    }
    va_end(args); // for gcc this is not needed but we put it in for portability.

}
int main()
{
    print_ints(3, 4, 5, 6);
    print_ints(7, 7 , 9, 80, 78, 90, 98, 0);
}