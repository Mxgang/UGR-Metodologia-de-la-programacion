#include "myIO.h"

void mezcla_ordenada(float *v1, int tv1, float *v2, int tv2, float *res){
  int cv1=0, cv2=0;

  while(cv1<tv1 || cv2<tv2){
    if((*v1 <= *v2) && (cv1<tv1)){
      *res=*v1;
      v1++; res++; cv1++;
    }
    else if(cv2<tv2){
      *res=*v2;
      v2++; res++; cv2++;
    }

  }
}


int main(){
  MyIO io;

  const int TOPE = 100;
  float v1[TOPE] = {2,3,8,22,44,88,99,100,101,255,665};
  float v2[TOPE]= {1,3,4,5,6,25,87,89,99,100,500,1000};
  float res[2*TOPE];

  int tam_v1=12, tam_v2=12;
  int tam_res=tam_v1+tam_v2;

  mezcla_ordenada(&v1[0],tam_v1,&v2[0],tam_v2,&res[0]);

  io.imprimeVector(&res[0], tam_res);

  return 0;

}