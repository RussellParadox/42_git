#include <stdio.h>
#define TO_F (1 / 0.3048 * value)
#define TO_P (0.002205 * value)
#define TO_DF (32 + 1.8 * value)

int   main(void)
{
   int   conversion_qt;
   double   value;
   char   unit;
   
   scanf("%d", &conversion_qt);
   
   for (int i = 0; i < conversion_qt; i++)
   {
      scanf("%lf %c\n", &value, &unit);
      printf("value = %lf, unit = %c\n", value, unit);
      switch (unit)
      {
         case 'm':
            printf("%lf %c\n", TO_F, 'p');
         case 'g':
            printf("%lf %c\n", TO_P, 'l');
         case 'c':
            printf("%lf %c\n", TO_DF, 'f');
      }
   }
}
