#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void merge(int arr[],int l,int m,int r){
    int i,j,k;
    int n1=m-l+1;
    int n2=r-m;

    int *L=(int*)malloc(n1*sizeof(int));
    int *R=(int*)malloc(n2*sizeof(int));

    for(i=0;i<n1;i++){
      L[i]=arr[l+i];
    }
    for(j=0;j<n2;j++){
      R[j]=arr[m+1+j];
    }
    i=0;
    j=0;
    k=l;

    while(i<n1 && j<n2){
      if(L[i]<R[i]){
        arr[k]=L[i];
        i++;
      }
      else{
        arr[k]=R[j];
        j++;
      }
      k++;
    }
      while(i<n1){
        arr[k]=L[i];
        i++;
        k++;
      }
      while(j<n2){
        arr[k]=R[j];
        j++;
        k++;
      }
      free(L);
      free(R);
    }
  void mergesort(int arr[],int l,int r){
    if(l<r){
      int m=l+(r-l)/2;
      mergesort(arr,l,m);
      mergesort(arr,m+1,r);
    }
  }
  void generaterandomArray(int arr[],int n){
    for(int i=0;i<n;i++){
      arr[i]=rand()%10000;
    }
  }
  int main(){
    int n,arr[100];
    printf("\nEnter the number of elements:\n");
    scanf("%d",&n);
    if(n>5000){
      printf("\n Please enter a value below 5000!\n");
    }
    printf("\nEnter the array \n");
    for(int i=0;i<n;i++){
      scanf("%d",&arr[i]);
    }
    generaterandomArray(arr,n);
    clock_t start=clock();
    for(int i=0;i<10000;i++){
      mergesort(arr,0,n-1);
    }      
    clock_t end=clock();
    double time_taken=(double)(end-start)/CLOCKS_PER_SEC/1000.0;
    printf("Time taken to sort %d elements %f in seconds \n",n,time_taken);
  
    return 0;
  }
