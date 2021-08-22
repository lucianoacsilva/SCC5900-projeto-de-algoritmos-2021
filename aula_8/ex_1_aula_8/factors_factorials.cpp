#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

bool isprime(int n) {
  if (n == 2){
    return true;
  }

  else {
    if (n%2 == 0) {
      return false;
    }
      // se não é 2
    else {
      for (int i = 3; i*i <=n; i = i + 2) {
        if (n%i == 0) {
          return false;
        }
      }

      return true;
    }
  }
}

int main(){
    int primo[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
    for(;;){
      int n;
      cin >> n;

      if(n==0){
        break;
      }

      int fator[25]={0};
      int indice=0;

      for(int i = n; i >= 2; i--){
        int val = i;
        for(int j = 0;j < 25; j++){
          while((val%primo[j]) == 0){
            fator[j]++;
            val = val/primo[j];
          }

          if(isprime(val)==true){
            break;
          }
        }

        for(int j=0;j<25;j++){
            if(primo[j]==val){
                fator[j]++;
                break;
            }
        }
      }

      for(int j=24;j>=0;j--){
        if(fator[j]!=0){
          indice=j;
          break;
        }
      }

      printf("%d! = ",n);

      for(int i=0;i<=indice;i++){
        printf("%d ",fator[i]);
      }

      cout << endl;
    } 

    return 0;

}