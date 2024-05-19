#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASS_LENGTH 500

void xor_encrypt_decrypt(char* data, char* key, int data_size) {
    int keysize = strlen(key);
    
    for (int i=0; i < data_size; i++) {
        data[i] = data[i] ^ key[i % keysize];
    }
}

void file_encrypt() {
    char filename[150], outputfilename[150], encrypt_pass[MAX_PASS_LENGTH];
    FILE *fileptr;
    
    printf("Enter the path of the file you want to encrypt: ");
    scanf(" %[^\n]s", filename);
    
    fileptr = fopen(filename, "rb");
    
    if (fileptr == NULL) {
        printf("\n[-] The path you entered is invalid!!!\n");
        exit(0);
    }
    
    // filesize
    fseek(fileptr, 0, SEEK_END);
    long filesize = ftell(fileptr);
    rewind(fileptr);
    
    char *filedata = (char*) malloc((filesize+1) * sizeof(char));
    
    size_t bytes = fread(filedata, 1, filesize, fileptr);
    filedata[filesize] = '\0';
    fclose(fileptr);
    
    printf("Enter the encryption key[passphrase]: ");
    scanf(" %[^\n]s", encrypt_pass);
    
    xor_encrypt_decrypt(filedata, encrypt_pass, filesize);
    
    
    printf("Enter the name or path of the encrypted file you want: ");
    scanf(" %[^\n]s", outputfilename);
    
    fileptr = fopen(outputfilename, "wb");
    
    if (fileptr == NULL) {
        printf("[-] Failed to create a file!!!\n");
        exit(0);
    }
    
    for (int i=0; i < filesize; i++) {
        fputc(filedata[i], fileptr);
    }
    printf("\n[+] Your file has been successfully encrypted!!!\n");
}

void file_decrypt() {
    char filename[150], outputfilename[150], decrypt_pass[MAX_PASS_LENGTH];
    FILE *fileptr;
    
    printf("Enter the path of the file you want to decrypt: ");
    scanf(" %[^\n]s", filename);
    
    fileptr = fopen(filename, "rb");
    
    if (fileptr == NULL) {
        printf("\n[-] The path you entered is invalid!!!\n");
        exit(0);
    }
    
    // filesize
    fseek(fileptr, 0, SEEK_END);
    long filesize = ftell(fileptr);
    rewind(fileptr);
    
    char *filedata = (char*) malloc((filesize+1) * sizeof(char));
    
    size_t bytes = fread(filedata, 1, filesize, fileptr);
    filedata[filesize] = '\0';
    fclose(fileptr);
    
    printf("\n[NOTE]: Entering wrong passphrase will decrypt the file with wrong contents\n");
    printf("Enter the passphrase to decrypt the file: ");
    scanf(" %[^\n]s", decrypt_pass);
    
    xor_encrypt_decrypt(filedata, decrypt_pass, filesize);
    
    
    printf("Enter the name or path of the decrypted file you want: ");
    scanf(" %[^\n]s", outputfilename);
    
    fileptr = fopen(outputfilename, "wb");
    
    if (fileptr == NULL) {
        printf("[-] Failed to create a file!!!\n");
        exit(0);
    }
    
    for (int i=0; i < filesize; i++) {
        fputc(filedata[i], fileptr);
    }
    printf("\n[+] Your file has been successfully decrypted!!!\n");
}

int main() {
    
    const char *green = "\033[0;32m";
    const char *reset = "\033[0m";
    
    printf("%s", green);
     printf("  _________ __                .__   __  .__     \n"
           " /   _____//  |_  ____ _____  |  |_/  |_|  |__  \n"
           " \\_____  \\\\   __\\/ __ \\\\__  \\ |  |\\   __\\  |  \\ \n"
           " /        \\|  | \\  ___/ / __ \\|  |_|  | |   Y  \\\n"
           "/_______  /|__|  \\___  >____  /____/__| |___|  /\n"
           "        \\/           \\/     \\/               \\/ \n\n");
    printf("%s", reset);
    

    
    
    char choice;
    printf("1) Encrypt the file\n");
    printf("2) Decrypt the file\n\n");
    
    printf("Enter your choice: ");
    scanf("%c", &choice);
    
    if (choice == '1') {
        file_encrypt();
    } else if (choice == '2') {
        file_decrypt();
    } else {
        printf("[*] Invalid choice\n");
    }
    return 0;
}
