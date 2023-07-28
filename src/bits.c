/*
 ============================================================================
 Name        : bits.c
 Author      : gitPeregrin
 Version     :
 Copyright   : My copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int powi(int num, int deg){
  if (!deg)
	  return (int)1;
  if (deg & 1)
	  return powi(num, deg - 1) * num;
  num = powi(num, deg >> 1);
  return num * num;
}

_Bool getbit(long long num, char b){
  int pwrd = powi(2,b-1);
  return (num & pwrd) >> (b - 1);
}


void setbit(long long * num, char b, _Bool exp){
  int pwrd = (powi(2,b-1));
  if(getbit(*num,b) == exp) return;
  *num += (*num & pwrd) >> (b - 1) ? -1*pwrd : pwrd;
}



int main(void) {

  int number = 10;

  setbit((long long*)&number,1,1);

  printf("%d -> ", number);

  for(char i=sizeof(number)*8;i>0;i--){
      if(i%8 == 0) printf(" ");
      printf("[%d]",getbit(number,i));
  }


  if( getbit(number,2) ) printf("Второй бит числа равен 1");
  else 		printf("Второй бит числа равен 0");

  return EXIT_SUCCESS;
}
