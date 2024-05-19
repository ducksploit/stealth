
# Stealth

Stealth is a XOR based encryption tool written in C which can be used to encrypt data in files with a passphrase. The program uses xor bitwise operator inorder to encrypt files. 

## Idea
Actually there was no topic left with the teacher to offer me for a college project assignment and almost every topic I was thinking of was already taken. So at last I thought of this one. Though the one I actually submitted had actually more features. I didn't include those in this repo because that was dependent on some external header file I found on a github repo for md5 hashing.

## Use Cases
The project can be used to not only to encrypt text files but also binary files which makes the transfer of files more secure.
Though the main usecase I can imagine of this project is to encrypt shellcode with it. Cybersecurity researchers can use it to encrypt shellcode which can be decrypted during runtime by their custom loader of their c2 implant during their research purpose. I have personally tried it and works well.

## Build
The build is quite easy. You just need gcc. 

I guess these simple commands will do the job

####  Linux
``` gcc stealth.c -o stealth```
#### Windows
```gcc stealth.c -o stealth.exe```


# :)

