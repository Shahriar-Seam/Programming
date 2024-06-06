#include <stdio.h>

int main() 
{
    int t, n1, n2;
    int arr[1001], arr2[1001], arr3[1001];

        printf("1st Set Length : ");
        scanf("%d", &n1);
        printf("Enter The 1st Set With %d Element : ", n1);
        

        for (int i = 0; i < n1; i++) 
        {
            scanf("%d", &arr[i]);
        }
        printf("2nd Set Length : ");
        scanf("%d", &n2);
        printf("Enter The 2nd Set With %d Element : ", n2);

        for (int i = 0; i < n2; i++) 
        {
            scanf("%d", &arr2[i]);
        }
        int i,j,k,x = 0;

        for (i = 0; i < n1; i++) 
        {
            int c = 0;
            for (j = 0; j < n2; j++) 
            {
                if (arr[i] == arr2[j]) 
                {
                    for (k = 0; k < i; k++) 
                    {
                        if (arr[i] == arr[k]) 
                        {
                            c = 1;
                            break;
                        }
                    }
                    if (c == 0) 
                    {
                        arr3[x] = arr2[j];
                        x++;
                        break;        
                    }
                }
            }
        }
        
        printf("The Common Distinct Element From 1st and 2nd Set is : ");

        for (int i = 0; i < x; i++) {
            printf("%d ", arr3[i]);
        }

        printf("\n");

    return 0;
}