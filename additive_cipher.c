#include<stdio.h>
#include<string.h>

int additive_inverse(int a, int mod)
{
   while (a < 0)
      a += mod;
   return (mod - a % mod) % mod;
}

char * shift_cipher_encryption(char * text , int key) {
    for(int i =0 ; i < strlen(text) ; i++) {
        text[i] = (char)((text[i] - 'a' + key) % 26 + 'a');
    }
    return text;
}

char * shift_cipher_decryption(char * text , int key) {
    key = additive_inverse(key, 26);
    for(int i =0 ; i < strlen(text) ; i++) {
        text[i] = (char)((text[i] - 'a' + key) % 26 + 'a');
    }
    return text;
}


int main() {
    char text[10000];
    printf("Enter text: ");
    scanf("%s", text);

    int key;
    printf("Enter key: ");
    scanf("%d", &key);

    char * cipher_text = shift_cipher_encryption(text , key);
    printf("The encrypted text is: %s\n", cipher_text);
    char * plain_text = shift_cipher_decryption(cipher_text , key);
    printf("The decrypted text is: %s\n", plain_text);
    

    return 0;
}
