#include<stdio.h>
#include<string.h>
#include<stdlib.h>

FILE *fp;
struct person{
	char id[15];
	char name[50];//namae
	long int phone;
	char address[256];
};


void Regi(){                    //$BEPO?%b!<%I(B
	fp = fopen("data.txt","a");
	char ser[50],dummy;
	int i,top[50],pp;
	long int y[50],e[50];

	printf("How many people??\n");
	scanf(" %d",&pp);
	struct person data[pp];	
	for(i=0;i<pp;i++){
		top[i]=-1;
		printf("No.%d\n",i+1);
	
		printf("ID --> ");
		scanf("%s",data[i].id);
		printf("name --> ");
		scanf(" %50[^\n]",data[i].name);
		printf("phone number --> ");
		scanf(" %1d%ld",&top[i],&data[i].phone);
		printf("address --> ");
		scanf("%s",data[i].address);
	}
	printf("\nRegistered--------------------------------------------\n");
	for(i=0;i<pp;i++){
		if(top[i]!=-1){
			printf("ID: %s//name: %s//phone-number: %d%ld//address: %s\n",data[i].id ,data[i].name ,top[i],data[i].phone,data[i].address);
			fprintf(fp,"ID: %s//name: %s//phone-number: %d%ld//address: %s\n",data[i].id,data[i].name,top[i] ,data[i].phone,data[i].address);
			
		}else{
			printf("ID: %s//name: %s//phone-number: %ld//address: %s\n",data[i].id,data[i].name ,data[i].phone,data[i].address);
			fprintf(fp,"ID: %s//name: %s//phone-number: %ld//address: %s\n",data[i].id,data[i].name ,data[i].phone,data[i].address);
		}
	}
	printf("------------------------------------------------------\n");
	fclose(fp);
}


void Ser(){			//$B8!:w%b!<%I(B
	char ser[50],name[50][50],add[50][50],l[50][15];
	int c=0,t,n,fid=0,top2[50],pp;
	long int e[50];

	fp = fopen("data.txt","r");
	printf("serch\n");
	scanf(" %50[^\n]",ser);
	while((fscanf(fp,"%*s %[^\n/]//%*s %[^\n/]//%*s %1d%ld//%*s %s",l[c],name[c],&top2[c],&e[c],add[c]))!=EOF){
		c++;
	}
	for(t=0;t<=c;t++){
		//printf("%s\n",name[t]);
		if(!strcmp(name[t],ser)){
			printf("found!!\n");
			fid=1;
			break;
		}
	}
	if(fid){
		printf("------------------------------------------------------\n");
		printf("ID: %s\n",l[t]);
		printf("name: %s\n",name[t]);
		printf("phone-number: %d%ld\n",top2[t],e[t]);
		printf("address: %s\n",add[t]); 
		printf("------------------------------------------------------\n");
	}else{
		printf("not found...\n");
	}
	fclose(fp);
}


void IDser(){			//ID$B8!:w%b!<%I(B
	char name[50][50],add[50][50],ids[15],l[50][15];
	int c=0,t,n,fid=0,top2[50],pp;
	long int e[50];

	fp = fopen("data.txt","r");
	printf("serch\n");
	scanf(" %s",ids);
	while((fscanf(fp,"%*s %[^\n/]//%*s %[^\n/]//%*s %1d%ld//%*s %s",l[c],name[c],&top2[c],&e[c],add[c]))!=EOF){
		c++;
	}
	for(t=0;t<=c;t++){
		//printf("%s\n",l[t]);
		if(!strcmp(l[t],ids)){
			printf("found!!\n");
			fid=1;
			break;
		}
	}
	if(fid){
		printf("------------------------------------------------------\n");
		printf("ID: %s\n",l[t]);
		printf("name: %s\n",name[t]);
		printf("phone-number: %d%ld\n",top2[t],e[t]);
		printf("address: %s\n",add[t]);
		printf("------------------------------------------------------\n");
	}else{
		printf("not found...\n");
	}	
	fclose(fp);
}


void cl(){		//$B%U%!%$%k%G!<%?:o=|(B
	fp = fopen("data.txt","w");
	fclose(fp);
}

void iddel(){
	char name[50][50],add[50][50],l[50][15],ids[15];
	int c=0,t,n,fid=0,top2[50],pp,i;
	long int e[50];

	fp = fopen("data.txt","r");
	printf("serch\n");
	scanf(" %s",ids);
	while((fscanf(fp,"%*s %[^\n/]//%*s %[^\n/]//%*s %1d%ld//%*s %s",l[c],name[c],&top2[c],&e[c],add[c]))!=EOF){
		c++;
	}
	for(t=0;t<c;t++){
		if(!strcmp(l[t],ids)){
			printf("found!!\n");
			fid=1;
			break;
		}
	}
	if(fid){
		printf("------------------------------------------------------\n");
		printf("ID: %s\n",l[t]);
		printf("name: %s\n",name[t]);
		printf("phone-number: %d%ld\n",top2[t],e[t]);
		printf("address: %s\n",add[t]);
		printf("------------------------------------------------------\n");	
		printf("delete....\n");
	}else{
		printf("not found...\n");
	}
	fclose(fp);
	if(fid){
		fp =fopen("data.txt","w");	
		for(i=0;i<c;i++){
			if(i==t){
				continue;
			}
			if(top2[i]!=-1){
				fprintf(fp,"ID: %s//name: %s//phone-number: %d%ld//address: %s\n",l[i],name[i],top2[i],e[t],add[t]);
			}else{
				fprintf(fp,"ID: %s//name: %s//phone-number: %ld//address: %s\n",l[i],name[i],e[t],add[t]);
			}	
		}	
		fclose(fp);
	}
}

void namedel(){		//$BL>A0:o=|(B	
	char ser[50],name[50][50],add[50][50],l[50][15];
	int c=0,t,n,fid=0,top2[50],pp,i;
	long int e[50];
	fp = fopen("data.txt","r");
	printf("serch\n");
	scanf(" %50[^\n]",ser);
	while((fscanf(fp,"%*s %[^\n/]//%*s %[^\n/]//%*s %1d%ld//%*s %s",l[c],name[c],&top2[c],&e[c],add[c]))!=EOF){
		c++;
	}
	for(t=0;t<=c;t++){
		//printf("%s\n",name[t]);
		if(!strcmp(name[t],ser)){
			printf("found!!\n");
			fid=1;
			break;
		}
	}
	fclose(fp);
	if(fid){
		printf("------------------------------------------------------\n");
		printf("ID: %s\n",l[t]);
		printf("name: %s\n",name[t]);
		printf("phone-number: %d%ld\n",top2[t],e[t]);
		printf("address: %s\n",add[t]); 
		printf("------------------------------------------------------\n");
	}else{
		printf("not found...\n");
	}
	if(fid){
		fp =fopen("data.txt","w");	
		for(i=0;i<c;i++){
			if(i==t){
				continue;
			}
			if(top2[i]!=-1){
				fprintf(fp,"ID: %s//name: %s//phone-number: %d%ld//address: %s\n",l[i],name[i],top2[i],e[t],add[t]);
			}else{
				fprintf(fp,"ID: %s//name: %s//phone-number: %ld//address: %s\n",l[i],name[i],e[t],add[t]);
			}	
		}	
		fclose(fp);
	}
}

void list(){		//$B%U%!%$%kFb%G!<%?%j%9%H(B	
	char name[50][50],add[50][50],l[50][15];
	int c=0,t,top2[50];
	long int e[50];
	fp = fopen("data.txt","r");
	while((fscanf(fp,"%*s %[^\n/]//%*s %[^\n/]//%*s %1d%ld//%*s %s",l[c],name[c],&top2[c],&e[c],add[c]))!=EOF){
		c++;
	}
	printf("ok\n");
	for(t=0;t<c;t++){
		printf("------------------------------------------------------\n");
		printf("ID: %s\n",l[t]);
		printf("name: %s\n",name[t]);
		printf("phone-number: %d%ld\n",top2[t],e[t]);
		printf("address: %s\n",add[t]);
		printf("------------------------------------------------------\n");
	}
}

void pass(){	//$B%Q%9%o!<%I@_Dj(B
	char pas[50],cp[50];

	fp=fopen("pass.txt","r");
	fscanf(fp,"%*s %s",pas);
	printf("Change password\n");
	printf("(current)Please enter your password: ");
	scanf("%s",cp);
	fclose(fp);

	if(!strcmp(pas,cp)){
		fp=fopen("pass.txt","w");
		printf("Please enter your new password: ");
		scanf("%s",pas);
		fprintf(fp,"password: %s",pas);
		fclose(fp);
	}else{
		printf("not password\n");
	}
}

int main(){
	char spass[50],copass[50],flg=0;
	fp=fopen("pass.txt","a");
	fclose(fp);
	fp=fopen("pass.txt","r");
	/*if(fp==NULL){
		printf("Please make pass.txt\n(This is the file to save the password)\n");
		exit(0);
		return -1;
	}*/
	if(fscanf(fp,"%*s %s",spass)==EOF){
		fclose(fp);
		fp=fopen("pass.txt","w");
		printf("Please enter new password: ");
		scanf("%s",spass);
		fprintf(fp,"password: %s",spass);
		fclose(fp);
		flg=1;
	}else{
		fscanf(fp,"%*s %s",spass);
		printf("Please enter your password: ");
		scanf("%s",copass);
		fclose(fp);
		if(!strcmp(copass,spass)){
			flg=1;
		}
	}

	if(flg){
	while(1){
		char mode;

		printf("mode select (Registration:r Search:s IDserch:i IDdelete:d namedelete:D list:l clear:c passwordchange:p end:q)\n");
		scanf(" %[pDdlrscqi]",&mode);
		switch(mode){
			case 'r':
				Regi();
				break;
			case 's':
				Ser();
				break;
			case 'i':
				IDser();
				break;
			case 'd':
				iddel();
				break;
			case 'D':
				namedel();
				break;
			case 'l':
				list();
				break;
			case 'c':
				cl();
				printf("clear\n");
				break;
			case 'p':
				pass();
				break;
			case 'q':
				printf("finish\n");
				exit(0);
		}
	}
	}else{
		printf("not pass\n");
	}
}	
