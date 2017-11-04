#include<stdio.h>
#include<stdlib.h>

int main(int n,char ** args){

  unsigned int a,b,c;
  scanf("%d",&a);
  c=rand()%a;
  printf("%d",c);
  return 0;
}
