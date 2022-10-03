#include <stdio.h>
#include <string.h>

int gcd(int a, int mod){
    int mn = a;
    if (mod < a) mn = mod;
    for (int i = mn; i >= 1; i--){
        if (a % i == 0 && mod % i == 0) return i;
    }
}

int multiplicative_inverse(int a, int mod){
    while (a < 0) a += mod;
    int g = gcd(a, mod);
    if (g != 1) return -1;
    for (int i = 1; i < mod; i++){
        if ((i * a) % mod == 1) return i;
    }
    return -1;
}

char* multiplicative_cipher_encrypt(char* str, int key){
    for(int i = 0 ; i < strlen(str) ; i++){
        str[i] = (((str[i] - 'a') * key) % 26) + 'a';
    }
    return str;
}

char* multiplicative_cipher_decrypt(char* cipher, int key){
    key = multiplicative_inverse(key, 26);
    if(key == -1){
        printf("Multiplicative inverse does not exist!");
        return NULL;
    }
    for(int i = 0 ; i < strlen(cipher) ; i++){
        cipher[i] = (((cipher[i] - 'a') * key) % 26) + 'a';
    }
    return cipher;
}

int main(){
    printf("Enter a String: ");
    char str[100000];
    scanf("%s", str);

    printf("\n-------------------Multiplicative Cipher-------------------\n\n");

    printf("Enter multiplicative key: ");
    int key;
    scanf("%d", &key);
    char* ans;
    if(key > 0){
        ans = multiplicative_cipher_encrypt(str, key);
        printf("\nMultiplicative Cipher: %s\n\n", ans);
    }
    else printf("\nKey value should be greater than 0\n\n");

    ans = multiplicative_cipher_decrypt(ans, key);
    if(ans != NULL){
        printf("\nDecrypt Cipher: %s\n\n", ans);
    }
    else printf(" Cannot Decrypt Cipher!\n\n");

    printf("--------------------------------------------------\n\n");

    return 0;
}
