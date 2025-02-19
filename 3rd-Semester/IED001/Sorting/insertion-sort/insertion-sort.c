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

void rtx_insertionSort(int v[], int v_size)
{
   int aux = 0;

   for (int i = 0; i < v_size; i++)
   {
      int selected_element = v[i];

      for (int j = i; j >= 0; j--)
      {
         // printf("selected_element < v[j] ? => %d < v[%d] => %d < %d\n", selected_element, j, selected_element, v[j]);

         if (selected_element < v[j])
         {
            v[j+1] = v[j];
            v[j] = selected_element;
            // printVec(v, v_size);
         } 
      }
   }
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
   // int v[] = { 15, 7, 3, 1 }; // Worst case input

   int v[] = {9, 78, -2, 435, 10, 11, 88, 56489302, -54893, 10, 9, 234, 74, 74};

   int v_size = sizeof(v)/sizeof(v[0]);

   printVec(v, v_size);

   // insertionSort(v, v_size);
   rtx_insertionSort(v, v_size);

   printVec(v, v_size);

   return 0;
}