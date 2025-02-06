# include <stdio.h>
# include <stdlib.h>

void printVec(int v[], int v_size)
{
    for (int i = 0; i < v_size; i++)
        printf("v[%d] = %d\n", i, v[i]);
}

void insertionsort (int n, int v[])
{
   for (int j = 1; j < n; ++j) {
      int x = v[j];
      int i;
      for (i = j-1; i >= 0 && v[i] > x; --i) 
         v[i+1] = v[i];
      v[i+1] = x;
   }
}

int main()
{
    int v[] = { 4, 7, 124, 8, 12 };
    int v_size = sizeof(v)/sizeof(v[0]);

    printVec(v, v_size);

    return 0;
}