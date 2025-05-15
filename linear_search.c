#include<stdio.h>
int linear_search(int arr[],int size,int target){
  for(int i=0;i<size;i++){
      if(arr[i]==target){
        return i+1;
      }
  }
  return -1;
}
int main(){
  int target;
  int arr[]={3,5,8,2,5,1,4};
  int size= sizeof(arr)/sizeof(arr[0]);
  printf("Enter the element to be searched \n");
  scanf("%d",&target);

  int res=linear_search(arr,size,target);

  if(res!=-1){
    printf("The element %d is found \n",target);
  }
  else{
    printf("The element is not found \n");
  }
  return 1;
}
