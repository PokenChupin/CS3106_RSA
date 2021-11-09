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

int main(){
	
	int z;	
	
	Key pub, pri;
	initKeys(&pub, &pri);
	char msg[] = "RASTAMAN";
	printf("Original Message: %s",msg);
	encrypt(msg,pub);
	printf("\nEncrypted Message: %s",msg);
	decrypt(msg,pub);
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
}

void encrypt(char msg[], Key pub){
	int i,size = strlen(msg);
	double power;
	
	for(i=0;i<size;i++){
		power = pow(msg[i], pub.de);
		msg[i] = fmod(power,pub.n);
	}
}

void decrypt(char msg[], Key pri){
	int i,size = strlen(msg);
	double power;
	for(i=0;i<size;i++){
		power = pow(msg[i], pri.de);
		msg[i] = fmod(pow(msg[i], pri.de), pri.n);
	}	
}
