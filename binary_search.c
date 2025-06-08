#include<stdio.h>

void sort(int arr[],int size){
  int temp;
  for(int i=0;i<size-1;i++){
    for(int j=i+1;j<size;j++){
      if(arr[i]>arr[j]){
        temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
      }
    }
  }
} 
int main(){
  int f,m,l,c,n,search,arr[100];

  printf("Enter number of integers");
  scanf("%d",&n);

  printf("Enter %d integer \n",n);
  for(c=0;c<n;c++){
    scanf("%d",&arr[c]);
  }
  printf("Enter the value searched"); 
  scanf("%d",&search);

  sort(arr,n);
  f=0;
  l=n-1;
  m=(f+l)/2;    
 
  while(f<=l){
    if(arr[m]< search){
      f=m+1;
    }
    else if(arr[m]==search){
      printf("%d is found at location %d\n",search,m+1);
      break;
    }
    else
      l=m-1;
      m=(f+l)/2;
  }
  if(f>l){
    printf("Not found! %d is not present in the list",search);
  }
}