#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        int p;
        scanf("%d",&p);
        int ar[p];
        for(int i=0;i<p;i++)
        {
            scanf("%d",&ar[i]);
        }
        int f=1;
        for(int i=1;i<p;i++)
        {
            if(abs(ar[i]-ar[i-1])!=5 && abs(ar[i]-ar[i-1]!=7))
            {
                f=0;
                break;
            }
        }
        if(f==1)
        {
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
    }
    return 0;
}

// #include <stdio.h>
// #include <stdlib.h>
// int main()
// {
//     int n;
//     scanf("%d", &n);
//     while (n--)
//     {
//         int p;
//         scanf("%d", &p);
//         int ar[p];
//         for (int i = 0; i < p; i++)
//         {
//             scanf("%d", &ar[i]);
//         }
//         int f = 1;
//         for (int i = 1; i < p; i++)
//         {
//             if (abs(ar[i] - ar[i - 1]) != 5 && abs(ar[i] - ar[i - 1] )!= 7)
//             {
//                 f = 0;
//                 break;
//             }
//         }
//         if (f == 1)
//         {
//             printf("YES\n");
//         }
//         else
//         {
//             printf("NO\n");
//         }
//     }
//     return 0;
// }