# include <stdio.h>
# include <stdlib.h>

void printVec(int v[], int v_size)
{
   printf("int v[] = { ");

   for (int i = 0; i < v_size; i++)
   {
      printf("%d", v[i]);

      if (i + 1 != v_size)
         printf(", ");
   }

   printf(" };\n");
}

void insertionsort (int v[], int v_size)
{
   for (int j = 1; j < v_size; ++j)
   {
      printf("J: v[%d] = %d\n", j, v[j]);

      int x = v[j];
      int i;

      for (i = j-1; i >= 0 && v[i] > x; --i)
      {
         printf("I: v[%d] = %d\n", i, v[i]);
         v[i+1] = v[i];
      }
      v[i+1] = x;
   }
}

int main()
{
   int v[] = { 4, 7, 124, 8, 12 };
   int v_size = sizeof(v)/sizeof(v[0]);

   printVec(v, v_size);

   insertionsort(v, v_size);

   printVec(v, v_size);

   return 0;
}