#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

FILE *fp;
int count=0, n=1;

#define MAX 500

struct Karyawan
{
	char nama[26];		
	int usia;			
	char noTelp[13];	
	int date;
	int month;
	int year;
	int jmlhOrg;		
} K[MAX];

void enter()
{
	for(int i=0; i<35; i++)
	{
		printf("\n");
	}
}

void menu()
{
	enter();
	printf("*****************************\n");
	printf("  PT. SEMBILAN KARYA BANGSA  \n");
	printf("*****************************\n");
	printf("\n");
	printf("1. Registration\n");
	printf("2. Update Registrant\n");
	printf("3. Delete Registrant\n");
	printf("4. View Registrant\n");
	printf("5. Exit\n\n");
	printf("Select your choice: ");
}


void reg()
{
	char nama1[26];		
	int usia1;			
	char noTelp1[13];	
	int date1, month1, year1;	
	int jmlhOrg1;
	int counter=0;		
	
	start:
	enter();
	printf(" REGISTRATION \n");
	printf("==============\n\n");
	
	do
	{
		printf("Masukan nama [<26 char]\t\t\t\t\t: ");
		scanf("%[^\n]", nama1); getchar();
	} while(strlen(nama1)>26);
	
	do
	{
		printf("Masukan usia [min. 17 tahun]\t\t\t\t: ");
		scanf("%d", &usia1); getchar();
	} while(usia1<17);

	do
	{
		printf("Masukan nomor telepon\t\t\t\t\t: ");
		scanf("%[^\n]", noTelp1); getchar();
	} while(strlen(noTelp1)<10&&strlen(noTelp1)>13);
	
	do
	{
		printf("Masukan tanggal lahir [dd-mm-yyyy]\t\t\t: ");
		scanf("%d-%d-%d", &date1, &month1, &year1); getchar();
		if((month1>12 || year1>2018) || ((month1==1 || month1==3 || month1==5 || month1==7 || month1==8 || month1==10 || month1==12) && date1>31) ||
			((month1==4 || month1==6 || month1==9 || month1==11) && date1>30))
		{
			printf("Data is Invalid!\n"); getchar();
			goto start;
		} 
		else if(month1==2)
		{
			if((month1%4!=0 && date1>28) || (month1%4==0 && date1>29))
			{
				printf("Data is Invalid!\n"); getchar();
				goto start;
			}
		}
		counter++;
	} while(counter==0);
	
	do
	{
		printf("Masukan jumlah keikutsertaan organisasi [min. 1]\t: ");
		scanf("%d", &jmlhOrg1); getchar();
	} while(jmlhOrg1<1);
	
	//menyimpan di struct
	strcpy(K[count].nama, nama1);
	K[count].usia		= usia1;
	strcpy(K[count].noTelp, noTelp1);
	K[count].date 		= date1;
	K[count].month 		= month1;
	K[count].year 		= year1;
	K[count].jmlhOrg 	= jmlhOrg1;
	count++;
	printf("\nSuccessfully Add Data\n");
	getchar();
}

int searchData(char a[])
{	
	for(int i=0; i<count; i++)
	{
		if(strcmpi(a, K[i].nama)==0) //mencari data yang sama
		{
			return i;
		}
	}
	return -1;
}

void upd()
{
	char nama2[26];		
	int usia2;			
	char noTelp2[13];	
	int date2, month2, year2;	
	int jmlhOrg2;
	int counter=0;
	int check2=0;
	
	start:
	enter();
	printf(" UPDATE REGISTRANT \n");
	printf("===================\n\n");
	
	printf("Masukan nama untuk update data: ");
	scanf("%[^\n]", nama2); getchar();
	
	check2 = searchData(nama2); // proses pencarian data
	
	if(check2==-1) // jika data tidak ditemukan, keluar error message
	{
		printf("\nData is not Found!\n"); 
	} else // jika data ditemukan, minta input data baru
	{
		do
		{
			printf("Masukan nama [<26 char]\t\t\t\t\t: ");
			scanf("%[^\n]", nama2); getchar();
		} while(strlen(nama2)>26);
	
		do
		{
			printf("Masukan usia [min. 17 tahun]\t\t\t\t: ");
			scanf("%d", &usia2); getchar();
		} while(usia2<17);

		do
		{
			printf("Masukan nomor telepon\t\t\t\t\t: ");
			scanf("%[^\n]", noTelp2); getchar();
		} while(strlen(noTelp2)<10&&strlen(noTelp2)>13);
	
		do
		{
			printf("Masukan tanggal lahir [dd-mm-yyyy]\t\t\t: ");
			scanf("%d-%d-%d", &date2, &month2, &year2); getchar();
			if((month2>12 || year2>2018) || ((month2==1 || month2==3 || month2==5 || month2==7 || month2==8 || month2==10 || month2==12) && date2>31) 
			|| ((month2==4 || month2==6 || month2==9 || month2==11) && date2>30))
			{
				printf("Data is Invalid!\n"); getchar();
				goto start;
			} 
			else if(month2==2)
			{
				if((month2%4!=0 && date2>28) || (month2%4==0 && date2>29))
				{
					printf("Data is Invalid!\n"); getchar();
					goto start;
				}
			}
			counter++;
		} while(counter==0);
	
		do
		{
			printf("Masukan jumlah keikutsertaan organisasi [min. 1]\t: ");
			scanf("%d", &jmlhOrg2); getchar();
		} while(jmlhOrg2<1);
	
		//menyimpan di struct
		strcpy(K[check2].nama, nama2);
		K[check2].usia		= usia2;
		strcpy(K[check2].noTelp, noTelp2);
		K[check2].date 		= date2;
		K[check2].month 	= month2;
		K[check2].year 		= year2;
		K[check2].jmlhOrg 	= jmlhOrg2;
		
		printf("\nSuccessfully Update Data\n");
	}
	getchar();
}
	
void del()
{
	char nama3[26], pilih[3];
	int check3, i;
	
	enter();
	printf(" DELETE REGISTRANT \n");
	printf("===================\n\n");
	
	printf("Masukan nama untuk delete data [0 to Cancel]: ");
	scanf("%[^\n]", nama3); getchar();
	
	check3 = searchData(nama3);
	
	if(check3==-1) // jika data tidak ditemukan, maka akan keluar error message
	{
		printf("\nData is not Found!\n");
	} else
	{
		for(i=check3; i<count-1; i++)
		{
			K[i] = K[i+1];
		}
		count--;
		printf("\nSuccessfully Delete Data\n");
	}
		
	if(strcmp(nama3, "0")==0) // jika input 0, maka akan kembali ke menu utama
	{
		return;
	}

	getchar();

}	
	
void viw()
{
	enter();
	printf(" VIEW REGISTRANT \n");
	printf("=================\n\n");
	printf("%-28s %6s %15s %15s %33s\n\n", "Nama", "Usia", "Nomor Telepon", "Tanggal Lahir", "Jumlah Keikutsertaan Organisasi");
	for(int i=0; i<count; i++)
	{
		if(strcmpi(K[i].nama,"")!=0)
		{
			printf("%-28s %6d %15s      %02d-%02d-%d %33d\n", K[i].nama, K[i].usia, K[i].noTelp, K[i].date, K[i].month, K[i].year, K[i].jmlhOrg);
		}
	}
	getchar();
}

void read_file()
{
	fp = fopen("dataRegist4.txt", "r");
	if(fp == NULL)
	{
		perror("File is not Found!"); getchar();
	}
	else
	{
		fseek(fp, 0, SEEK_END);
		if(ftell(fp)!=0)
		{
			rewind(fp);
			while(!feof(fp))
			{
				fscanf(fp, "%[^.].%d.%[^.].%d-%d-%d.%d\n", 
					K[count].nama, &K[count].usia, K[count].noTelp, &K[count].date, &K[count].month, &K[count].year, &K[count].jmlhOrg);
				count++;
			}
		}
		fclose(fp);
	}
}	
	
void write_file()
{
	fp = fopen("dataRegist4.txt", "w");
	int i;
	if(fp == NULL)
	{
		perror("Error."); getchar();
	} else
	{
		for(i=0; i<count; i++)
		{
			fprintf(fp, "%s.%d.%s.%d-%d-%d.%d\n", 
				K[i].nama, K[i].usia, K[i].noTelp, K[i].date, K[i].month, K[i].year, K[i].jmlhOrg);
	 	}
		fclose(fp);
	}
}	

int main()
{
	count=0;
	int choice;
	
	read_file();
	do
	{
		menu();
		scanf("%d", &choice); getchar();
		switch(choice)
		{
			case 1:
				reg(); break;
			case 2:
				upd(); break;
			case 3:
				del(); break;
			case 4:
				viw(); break;
		}
	} while(choice!=5);
	write_file();
	
	return 0;
}
