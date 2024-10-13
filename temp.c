#include<stdio.h>
int main(){
    int ara1[2][2],ara2[2][2],ara3[2][2];
    int i,j,k,l,n;
   
    for(i=0;i<2;i++){
         for(j=0;j<2;j++){
             scanf("%d",&ara1[i][j]);
         }
    }
    for(i=0;i<2;i++){
         for(j=0;j<2;j++){
             scanf("%d",&ara2[i][j]);
         }
    }
   for(i=0;i<2;i++){
        for(j=0;j<2;j++){
            ara3[i][j]=ara1[i][j]*ara2[i][j];
            
        }
   }
   for(i=0;i<2;i++){
        for(j=0;j<2;j++){
   printf("%d\n",ara3[i][j]);
        }
        printf("\n");
   }
   
    
    
    return 0;
}//