/*
Caesar cipher - basic shift cipher
*/

#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main(int argc, char *argv[])
{
	if(!argv[2])
	{
		printf("Usage: CaesarCipher -e|-d 'Message'\n");
		return 1;
	}

	char *msg = argv[2];
	unsigned int shift = 23;
	char special[] = ",./<>?\\|;'#:@~[]{}-=_+!£$%^&*()";

	if(strcmp(argv[1], "-e") == 0) {
		printf("Plaintext: \t%s\n", msg);

		//encrypt
		for(int i = 0; i<strlen(msg); i++) {
			if(isupper(msg[i])) {
				if(msg[i]+shift <= 90) {
					msg[i] += shift;
				} else {
					msg[i] += shift-26;
				}
			} else if(isspace(msg[i])) {
				//do nothing
			} else if(strchr(special, msg[i])!=NULL) {
				//do nothing
			} else {
				printf("\nMust be all capitals.\n");
				return 1;
			}
		}
		printf("Ciphertext: \t%s\n", msg);

	} else if(strcmp(argv[1], "-d") == 0) {
		printf("Ciphertext: \t%s\n", msg);

		//decrypt
		for(int i = 0; i<strlen(msg); i++) {
			if(isupper(msg[i])) {
				if(msg[i]-shift >= 65) {
					msg[i] -= shift;
				} else {
					msg[i] += 26-shift;
				}
			} else if(isspace(msg[i])) {
				//do nothing
			} else if(strchr(special, msg[i])!=NULL) {
				//do nothing
			} else {
				printf("\nMust be all capitals.\n");
				return 1;
			}
		}
		printf("Plaintext: \t%s\n", msg);

	} else if(strcmp(argv[1], "-b") == 0) {
		printf("Ciphertext: \t%s\n", msg);

		shift = 1;
		char text[strlen(msg)];

		//bruteforce
		while(shift < 26) {
			for(int i = 0; i<strlen(msg); i++) {
				if(isupper(msg[i])) {
					if(msg[i]-shift >= 65) {
						text[i] = msg[i] - shift;
					} else {
						text[i] = msg[i]+26-shift;
					}
				} else if(isspace(msg[i])) {
					text[i] = msg[i];
				} else if(strchr(special, msg[i])!=NULL) {
					text[i] = msg[i];
				} else {
					printf("\nMust be all capitals.\n");
					return 1;
				}
			}
			printf("Plaintext: \t%s | Key: %d\n", text, shift++);
		}
	} else {
		printf("Usage: CaesarCipher -e|-d 'Message'\n");
		return 1;
	}
}
