#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void selectionsort(int arr[],int n){
  int i,j,min_idx;
  for(i=0;i<n-1;i++){
    min_idx=i;
    for(j=i+1;j<n;j++){
      if(arr[j]<arr[min_idx]){
        min_idx=j;
      
    }
  }
    int temp=arr[min_idx];
    arr[min_idx]=arr[i];
    arr[i]=temp;
  }
}
  void genrannum(int arr[],int n){
    for(int i=0;i<n;i++){
      arr[i]=rand()%10000;
    }
  }
  int main(){
    int n;
    printf("Enter number of elements ");
    scanf("%d",&n);
    if(n>=5000){
      printf("Please enter a value lesser than 5000\n");
      return 1;}
      int*arr=(int*)malloc(n*sizeof(int));
      if(arr==NULL){
        printf("Memory allocation failed \n");
        return 1;
      }
      genrannum(arr,n);

      clock_t start=clock();
      selectionsort(arr,n);
      clock_t end = clock();

      double time=((double)(end-start))/CLOCKS_PER_SEC;
      printf("Time takes to sort %d elements %f seconds \n",n,time);

      printf("Sorted array elements \n");
      for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
        if((i+1)%20==0)printf("\n");
        
      }
      printf("\n");
      free(arr);
      return 0;

    }
  
