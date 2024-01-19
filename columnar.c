#include<stdio.h>
#include<string.h>

int position(char c){
    int i = c;
    if(i >= 97 && i <= 122){
        return i - 97;
    }else if(i >= 65 && i <= 90){
        return i - 65;
    }else if( i == 32){
        return 32;
    }
}

void columnar(char message[], char key[]){
    int rows, key_len, msg_len, min;
    char space = 32;
    key_len = strlen(key);
    msg_len = strlen(message);
    if(msg_len % key_len == 0){
        rows = msg_len / key_len;
    }else{
        rows = (msg_len / key_len) + 1;
        for(int k = 0; k < (key_len - (msg_len % key_len)); k++){
            message[msg_len + k] = 120;
        }
        msg_len = strlen(message);
    }
    int matrix[rows][key_len];
    for(int i = 0 ;i < rows; i++){
        for(int j = 0; j < key_len; j++){
            if(message[(i * key_len) + j] == space){
                matrix[i][j] = 36;
                continue;
            }
            matrix[i][j] = message[(i * key_len) + j];
        }
    }
    int arr[key_len], darr[key_len];
    for(int i = 0; i < key_len; i++){
        arr[i] = position(key[i]);
        darr[i] = position(key[i]);
    }
    {
        int i, j, flag, temp;
        for (i = 0; i < key_len - 1; i++) {
            flag = 0;
            for (j = 0; j < key_len - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                    flag = 1;
                }
            } 
            if (flag == 0)
                break;
        }
    }
    {
        int index, drr_flag = 0;
        for(int k = 0; k < key_len; k++){
            for(int i =0; i < key_len; i++){
                if(arr[drr_flag] == darr[i]){
                    index = i;
                    drr_flag++;
                    break;
                }
            }
            for(int l = 0; l < rows; l++){
                printf("%c", matrix[l][index]);
            }
        }
    }
}

void main(){
    char msg[100],key[100],message[100];
    printf("\nEnter a string to ENCRYPT : ");
    scanf("%s", msg);
    printf("\nEnter the key : ");
    scanf("%s", key);
    printf("Encrypted Message :");
    columnar(msg, key);
    //printf("\n\n\nEnter a string to DECRYPT : ");
    //scanf("%s", message);
    //printf("\nEnter the key : ");
    //scanf("%s", key);
    //printf("\nDecrypted Message :");
    //decrypt(message, key);
}