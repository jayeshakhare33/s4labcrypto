#include<stdio.h>
#include<string.h>

int position(char c){
    int i = c;
    if(i >= 97 && i <= 122){
        return i - 97;
    }else if(i >= 65 && i <= 90){
        return i - 65;
    }
}

void decrypt(char message[],char key[]){
    int msg_val, key_val, fin_val;
    char c,d;
    int n = strlen(message);
    char space = 32;
    for(int i = 0; i < n; i++){
        if(message[i] == space){
            printf(" ");
            continue;
        }
        msg_val = position(message[i]);
        key_val = position(key[i]);
        if(msg_val < key_val){
            fin_val = msg_val - key_val + 26;
        }else{
            fin_val = msg_val - key_val;
        }
        printf("%c", fin_val + 65);
    }
}

void verman(char msg[],char key[]){
    int i = 0, msg_val, key_val, fin_val;
    char space = 32;
    if(strlen(msg) == strlen(key)){
        while(i < strlen(key)){
            msg_val = position(msg[i]);
            key_val = position(key[i]);
            fin_val = (msg_val + key_val) % 26;
            printf("%c", fin_val + 65);
            if(msg[i+1] == space){
                printf(" ");
                i = i + 2;
            }else{
                i++;
            }
        }
        printf("\n");
    }else{
        printf("Invalid key.");
    }
}

void main(){
    char msg[100],key[100],message[100];
    printf("\nEnter a string to ENCRYPT : ");
    scanf("%s", msg);
    printf("\nEnter the key : ");
    scanf("%s", key);
    scanf("%s", key);
    printf("Encrypted Message :");
    verman(msg, key);
    printf("\n\n\nEnter a string to DECRYPT : ");
    scanf("%s", message);
    printf("\nEnter the key : ");
    scanf("%s", key);
    printf("\nDecrypted Message :");
    decrypt(message, key);
}