#include <stdio.h>

void search(int arr[], int n, int x) {
   int i, count = 0, pos[n], j = 0;
   for (i = 0; i < n; i++) {
      if (arr[i] == x) {
         pos[j] = i;
         j++;
         count++;
      }
   }
   if (count == 0) {
      printf("%d not found in the array.\n", x);
   } else {
      printf("%d found in the array at positions: ", x);
      for (i = 0; i < count; i++) {
         printf("%d", pos[i]);
         if (i != count - 1) {
            printf(", ");
         }
      }
      printf(".\n");
      printf("%d occurs %d time(s) in the array.\n", x, count);
   }
}

int main() {
   int n, i, x;
   printf("Enter the size of the array: ");
   scanf("%d", &n);
   int arr[n];
   printf("Enter the elements of the array:\n");
   for (i = 0; i < n; i++) {
      scanf("%d", &arr[i]);
   }
   printf("Enter the number to search: ");
   scanf("%d", &x);
   search(arr, n, x);
   return 0;
}

