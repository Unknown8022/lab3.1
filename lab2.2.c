#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>
#define PUT_DELIM(x, h, b) ((x) + (h) >= (b) ? '\n' : '\0')
#define COND1(x) (x) <= -M_PI_2
#define FUN1(x) (sin(x) * cos((x)/2))
#define COND2(x) (x) < M_PI_2 && (x) > M_PI_2
#define FUN2(x) (abs(x-M_PI_2))
#define COND3(x) (x) >= M_PI_2
#define FUN3(x) (x-1)/(2+sqrt(x))
#define FUN(x) (COND1(x)) ? FUN1(x): (COND2(x) ? FUN2(x) : FUN3(x))
#define TABULATE(msg, a, b, h, c) \
printf(msg); \
 for (x = a; x <= b; x +=h){ \
 if (c == 'x') \
 printf("%6.2f%c", x, PUT_DELIM(x, h, b)); \
 else \
 printf("%6.2f%c", FUN(x), PUT_DELIM(x, h, b)); \
 }
int main()
{
	double  a = -5.0, b = 5.0, h = 0.1, x;
	TABULATE("x:\t", a, b, h, 'x');
	TABULATE("y:\t", a, b, h, 'y');
	return 0;
}