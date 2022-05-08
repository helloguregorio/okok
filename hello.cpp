#include <iostream>
int saturating_add(int x, int y)
{
    int result = x + y;
    int bias = (sizeof(int) << 3) - 1;
    int condition1 = ~(x >> bias ^ y >> bias);
    int result_signed = result >> bias;
    int condition2 = result_signed ^ (x >> bias);
    int condition3 = condition1 & condition2;
    int result_overflow = result_signed - (0x1 << bias);
    return (result_overflow & condition3) | (result & ~condition3);
}