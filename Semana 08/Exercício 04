#include <stdio.h>

int main(void) {
    int a = 17, b = 5;
    printf("%d / %d = %d\n",  a, b, a / b);   /* 3 — truncamento */
    printf("%d %% %d = %d\n", a, b, a % b);   /* 2 — resto */

    int x = 3;
    int pre = ++x;   /* x=4, pre=4 */
    int pos = x++;   /* pos=4, x=5 */
    printf("pre=%d  pos=%d  x=%d\n", pre, pos, x);

    int max = (a > b) ? a : b;
    printf("max = %d\n", max);

    /* Bit a bit */
    unsigned char flags = 0;
    flags |= (1 << 2);   /* liga bit 2: 0b00000100 = 4 */
    flags |= (1 << 5);   /* liga bit 5: 0b00100100 = 36 */
    printf("flags = %u  (0x%02X)\n", flags, flags);

    flags &= ~(1 << 2);  /* desliga bit 2: 0b00100000 = 32 */
    printf("flags sem bit2 = %u\n", flags);
    return 0;
}
