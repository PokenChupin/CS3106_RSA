#include <stdio.h>
#include <math.h>
#include <string.h>

typedef struct{
	int n;
	int de;
}Key;

void initKeys(Key *, Key *);
void encrypt(char msg[], Key pub);
void decrypt(char msg[], Key pri);

//Helper Functions
double exponent(int base, int exp);


int main(){
	
	int z;	
	
	Key pub, pri;
	initKeys(&pub, &pri);
	char msg[] = "RASTAMAN";
	printf("\n\nOriginal Message: %s",msg);
	encrypt(msg,pub);
	printf("\nEncrypted Message: %s",msg);
	decrypt(msg,pri);
	printf("\nDecrypted Message: %s",msg);
	
	strcpy(msg,"ENCRYPTION");
	
	printf("\n\nOriginal Message: %s",msg);
	encrypt(msg,pub);
	printf("\nEncrypted Message: %s",msg);
	decrypt(msg,pri);
	printf("\nDecrypted Message: %s",msg);
	return 0;
}

void initKeys(Key *pub, Key *pri){
	int p,q,z,d,n;
	p = 11;
	q = 13;
	pub->de = 7;
	n = p * q;
	z = (p-1) * (q-1);
	for(d=z;((pub->de*d)-1) % z != 0;d++){}
	pub->n = pri->n = n;
	pri->de = d;
	printf("\nRSA Settings:");
	printf("\n p = %d\t; q = %d",p,q);
	printf("\n e = %d\t; d = %d",pub->de,d);
	printf("\n n = %d; z = %d",n,z);
}

void encrypt(char msg[], Key pub){
	int i,size = strlen(msg);
	int num,exp;
	
	for(i=0;i<size;i++){
		num = 1;
		for(exp = 0; exp < pub.de;exp++){
			num = num * msg[i];
			num = num % pub.n;
		}
		msg[i] = num;
	}
}

void decrypt(char msg[], Key pri){
	int i,size = strlen(msg);
	
	int exp;
	int num=1;

	for(i=0;i<size;i++){
		num = 1;		
		for(exp=0;exp<pri.de;exp++){
			num = num * msg[i];
			num = num % pri.n;
		}
		msg[i] = num;	
	}	
}
