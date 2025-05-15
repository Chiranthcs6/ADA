#include<stdio.h>
#include<time.h>

void swap(int *a,int *b);
  int partition(int arr[],int low,int high){
    int pivot=arr[high];
    int i=low-1;

    for(int j=low;j<=high-1;j++){
      if(arr[j]<pivot){
      i++;
      swap(&arr[i],&arr[j]);
    }
  }
  swap(&arr[i+1],&arr[high]);
  return i+1;
}

void quicksort(int arr[],int low, int high){
  if(low<high){
    int pi=partition(arr,low,high);
    quicksort(arr,low,pi-1);
    quicksort(arr,pi+1,high);
  }
}
void swap(int* a,int* b){
  int t=*a;
  *a=*b;
  *b=t;
}
int main(){
  int arr[]={2,4,9,1,0,10,13,55,23,32,69};
  int n=sizeof(arr)/sizeof(arr[0]);
  clock_t st,et;
  double time;
  
  st=clock();
  quicksort(arr,0,n-1);
  et=clock();
  time=((double)(et-st))/CLOCKS_PER_SEC;
  printf("Sorted array:\n");
  for(int i=0;i<n;i++){
    printf("%d ",arr[i]);
  }
  printf("\nTime taken :%.6f seconds\n",time);
}