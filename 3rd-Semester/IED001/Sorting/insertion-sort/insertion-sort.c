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

void insertionSort (int v[], int v_size)
{
   for (int j = 1; j < v_size; ++j)
   {
      int x = v[j];
      int i;
      printf("J: %d\n", j);

      for (i = j-1; i >= 0 && v[i] > x; --i)
      {
         printf("I: %d\n", i);
         v[i+1] = v[i];
      }

      v[i+1] = x;

      printf("Iteration: %d, j: %d, x: %d, i: %d, v[i]: %d, v[i+1]: %d\n", j, j, x, i, v[i], v[i+1]);
   }
}

int main()
{
   // int v[] = { 1, 3, 7, 15 }; // Best case input
   // int v[] = { 7, 15, 3, 1 }; // Normal case input
   int v[] = { 15, 7, 3, 1 }; // Worst case input

   int v_size = sizeof(v)/sizeof(v[0]);

   printVec(v, v_size);

   insertionSort(v, v_size);

   printVec(v, v_size);

   return 0;
}