//Affine cipher
#include <stdio.h>
char* mul_cipher(char str[], int key, int N){
  for(int i = 0; i < N; i++){
      char c = str[i] - 'A';
      c *= key;
      c = c % 26;
      str[i] = c + 'A';
  }
  
  return str;    
}


char* shift_cipher(char str[], int shift, int N) {

  for(int i = 0; i < N; i++){
    char c = str[i] - 'A';
    c += shift;
    c = c % 26;
    str[i] = c + 'A';
  }
  return str;
}

int additive_inv(int n, int a){
   return (n-a);
   //printf("\nThe additive inverse is: %d", n-a);
}

char* shift_decrypt(char str[], int key, int N){
    
    int key_inv = additive_inv(26, key);
    for(int i = 0; i < N; i++){
        char c = str[i] - 'A';
        c += key_inv;
        c = c % 26;
        str[i] = c + 'A';
    }
    return str;
}

int multi_inv(int n, int a){
    for(int i = 1; i < n; i++){
        if((i*a)%n == 1){
            return i;
        }
    }
    printf("\nError! No multiplicative inverse.");
    return -1;
}

char* mul_decrypt(char str[], int key, int N){
    
    int key_inv = multi_inv(26, key);
    char decrypted[100];
    for(int i = 0; i < N; i++){
        char c = str[i] - 'A';
        str[i] = ((key_inv*c)%26) + 'A';
    }
    return str;
}

char* affine_cipher(char str[], int key1, int key2, int N){
    char* T = mul_cipher(str, key1, N);
    char* C = shift_cipher(T, key2, N);
    printf("The encrypted text using affine cipher is: %s\n", C);
    return C;
}

void affine_decrypt(char str[], int key1, int key2, int N){
    char* shift_decrypted = shift_decrypt(str, key2, N);
    char* mul_decrypted = mul_decrypt(shift_decrypted, key1, N);
    printf("\nThe decrypted text using affine cipher is: %s", mul_decrypted);
}

int main()
{
    char str[] = "HELLO";
    int n = sizeof(str)/sizeof(str[0]);
    char *encrypted = affine_cipher(str, 7, 2, n-1);
    affine_decrypt(encrypted, 7, 2, n-1);
    return 0;
}
