#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>   
#define N 100


struct employee
{
	char num[10];
	char name[10];
	char tel[11];
    char sex[2];
	int addr;                                                       /*��ַ*/
	int deptnum;                                              /*����*/
    char deptname[25];                                            /*��������*/
	float basepay;                                                /*��������*/
	signed int bonus;                                           /*����*/
	float meritpay;                                       /*��Ч����*/
	float sumpay;                                          /*�ۺϹ���*/
	float totalpay;                                          /*ʵ�ù���*/
}em[20];

void print();                                                    /*�������˵�*/
void create();                                                   /*��������ϵͳ*/
void display();                                                  /*��ʾ*/
void searchbase();                                               /*���������ѯ*/
/* schbase_num  sch_dept��schbase_name������searchbase���� */
void sch_num(FILE *fp); 
void sch_name(FILE *fp); 
void sch_dept(FILE *fp);
void search();                                                    /*��ѯ*/
void searchpay();                                           /*���ʲ�ѯ*/
void schpay_num(FILE *fp,FILE *f);                                /*���ʲ�ѯ*/
void delete1();                                                    /*ɾ��*/
/* del_num������delete1���� */
void del_num(FILE *fp,FILE *f);
void sort();                                                      /*����*/
/* sort_sumpay��sort_totalpay������sort���� */
void sort_sumpay();
void sort_totalpay();

void main()
{  
	char choose,yes_no;
	do
	{
		print();                                                    /*��ʾ���˵�*/
		printf("         ");
		choose=getch(); 
		switch(choose)
		{
		case '1':	create();		break;		                    /*����*/
		case '2':	display();   	break;		                    /*��ʾ*/
		case '3':	search();		break;	                      	/*��ѯ */
		case '4':	delete1();		break;		                    /*ɾ��*/
		case '5':	sort();		    break;		                    /*����*/
		case '0':	break;		
		default:printf("\n        ��Ϊ�Ƿ�ѡ��   \n");
		}
		if(choose=='0')
			break;
		printf("        Ҫ����ѡ����(Y/N)?   ");
		do 
		{
			yes_no=getch();
		}while(yes_no!='Y'&&yes_no!='y'&&yes_no!='N'&&yes_no!='n');
	}while(yes_no=='Y'||yes_no=='y');
}

void print()                                                      /*��ʾ�˵�����*/
{  
	printf("\n\n");
	printf("                         ��ҵ���ʹ���ϵͳ  ");
	printf("\n");
	printf("       �q�T�T�T�T�T�T�T�T�T�T�T�T���������T�T�T�T�r\n");
	printf("	|	     ������ѡ����(0-5):         |\n"); 
	printf("	|-----------------------------------------|\n");
	printf("	|	1--����Ա����Ϣ     	          |\n"); 
	printf("	|	2--��ʾԱ����Ϣ     	          |\n");
	printf("	|	3--��ѯԱ����Ϣ                   |\n");
	printf("	|	4--ɾ��Ա����Ϣ                   |\n");
	printf("	|	5--����Ա����Ϣ    	          |\n");
	printf("	|	0--�˳�				  |\n");  
	printf("	|-----------------------------------------|\n");
	printf("        �t�T�T�T�T���������T�T�T�T�T�T�T�T�T�T�T�T�s\n");
    printf("\n");
    printf("     ��ӭ������ҵ���ʹ���ϵͳ������ѡ��Ҫ���еĲ���!\n ");

}
void create()
{
	int i,n;
	FILE *fp; 
	fp=fopen("f:\\��06С��_��ҵ���ʹ���ϵͳ\\score.dat","r+");
	if(fp==NULL)
	{
		printf("\n		���ļ�ʧ��!\n");
		return;
	} 
	rewind(fp);
	printf("\n");
	printf("\t\t������Ա������:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("\n������Ա�����š����ű�š��������ơ��������ʡ����𡢼�Ч���ʡ��ۺϹ���\n");
		scanf("%s %s %s %f %f %d %f" ,&em[i].num ,&em[i].deptnum,&em[i].deptname,&em[i].basepay,&em[i].bonus,&em[i].meritpay,&em[i].sumpay);
	}
	for(i=0;i<n;i++)
    { 
	
		if( em[i].bonus==-1)
			em[i].sumpay=em[i].basepay+em[i].meritpay;
		else
			em[i].sumpay= em[i].basepay+ em[i].meritpay+ em[i].bonus;
		if(0<em[i].sumpay&&em[i].sumpay<=1500)
			em[i].totalpay=em[i].sumpay*97/100;
		if(1500<em[i].sumpay&&em[i].sumpay<=4500)
			em[i].totalpay=em[i].sumpay*90/100;
		if(4500<em[i].sumpay&&em[i].sumpay <=9000)
			em[i].totalpay=em[i].sumpay*80/100;
		if(9000<em[i].sumpay&&em[i].sumpay<=35000)
		    em[i].totalpay=em[i].sumpay*75/100;
		if(em[i].sumpay>35000)
			em[i].totalpay=em[i].sumpay*70/100;
		
fprintf(fp,"%-10s%-7s%-15s%-5.0f%-8.2f%-5d%-8.2f%-8.2f%-8.2f\n",em[i].num ,em[i].deptnum,em[i].deptname,em[i].basepay,em[i].bonus,em[i].meritpay,em[i].sumpay,em[i].totalpay);

	}	
	
        fclose(fp);
		printf("�����ɹ�!!\n");

}
void display()
{    
	int i=0;
	int n=0;
	struct employee;
	FILE *fp;  

	fp=fopen("f:\\��06С��_��ҵ���ʹ���ϵͳ\\score.dat","r");
	if(fp==NULL)
	{
		printf("		���ļ�ʧ��!\n");
		return;
	}   
	
	printf("\nԱ������ ���ű��  �������� �������� ���� ��Ч���� �ۺϹ��� ʵ�ù���\n"); 
	while(feof(fp)==0)
	{	
		fscanf(fp,"%s%s%s%f%f%d%f%f%f\n",&em[i].num ,&em[i].deptnum,&em[i].deptname,&em[i].basepay,&em[i].bonus,&em[i].meritpay,&em[i].sumpay,&em[i].totalpay);
		printf("%-4s  %-7s  %-12s%-5.0f  %-8.2f  %-5d    %-8.2f %-8.2f  %-8.2f\n",em[i].num ,em[i].deptnum,em[i].deptname,em[i].basepay,em[i].bonus,em[i].meritpay,em[i].sumpay,em[i].totalpay);
		n++;
	}
	if(n==0)
		printf("		�ļ����޼�¼!\n"); 
	else 
		printf("		�ļ��й���%d����¼!\n",n);  
	fclose(fp);



}
void search()
{
	char c;
	FILE *fp;
	
	fp=fopen("f:\\��06С��_��ҵ���ʹ���ϵͳ\\student.txt","r");
	if(fp==NULL)
	{
		printf("		���ļ�ʧ��!\n");
		return;
	}             
	
	printf("	��ѯ������Ϣ(b),���ǲ�ѯԱ����Ч(r)?     ");
	c=getch();
	if(c=='b'||c=='B')
		searchbase();		                                        /*��ѯ������Ϣ*/
	if(c=='r'||c=='R')
		searchpay();		                                    /*��ѯ����*/
    if(c!='b'&&c!='B'&&c!='r'&&c!='R')
		printf("\n		��Ϊ�Ƿ��ַ�!\n");	 
		fclose(fp);
}	
void searchbase()
{
	char c;
	FILE *fp;
	
	fp=fopen("f:\\��06С��_��ҵ���ʹ���ϵͳ\\student.txt","r");
	if(fp==NULL)
	{
		printf("		���ļ�ʧ��!\n");
		return;
	}             
	
	printf("\n		�����Ų�ѯ(h),��������ѯ(m)�����ǰ����Ų�ѯ(d)?   ");
	c=getch();
	if(c=='h'||c=='H')
		sch_num(fp);		                                        /*�����Ų�ѯ*/
	else if(c=='m'||c=='M')
		sch_name(fp);		                                        /*��������ѯ*/
    else 
	{
		if(c=='d'||c=='D')
		sch_dept(fp);		                                        /*�����Ų�ѯ*/
	else 
		printf("		��Ϊ�Ƿ��ַ�!\n");	 
	}
	fclose(fp);
}
void sch_num(FILE *fp)
{
	int flag=0,n=0;
	char tempnum[6];
	struct employee temp; 
	FILE *fp1;
	
	fp1=fopen("f:\\��06С��_��ҵ���ʹ���ϵͳ\\student.txt","r");
	
	printf("		������Ҫ��ѯ�Ĺ���:");
	gets(tempnum);  
	while(feof(fp)==0)
	{
		fscanf(fp,"%10s%25s%5s%8d%15s\n",&temp.num,&temp.name,&temp.sex,&temp.deptnum,&temp.tel); 
		if(strcmp(tempnum,temp.num)==0)
		{
			if(flag==0)  
				printf("       ����            ����        �Ա�    ���ű��       �绰����\n"); 
			printf("%10s%18s%8s%12d%13s\n",temp.num,temp.name,temp.sex,temp.deptnum,temp.tel);
			flag=1;
			n++;
		} 
	
	}
	if(n==0)
		printf("		�ļ����޼�¼!\n"); 
	else 
	{if(flag==0)
			printf("		�ļ����޴���!\n"); 
	}
	fclose(fp1);
}	  

void sch_name(FILE *fp)
{
	int flag=0,n=0;
	char tempname[10];
	struct employee temp; 
	FILE *fp1;
	
	fp1=fopen("f:\\��06С��_��ҵ���ʹ���ϵͳ\\student.txt","r");
	
	printf("		������Ҫ��ѯ��¼������:");
	gets(tempname);  
	while(feof(fp)==0)
	{
		fscanf(fp,"%10s%25s%5s%8d%15s\n",&temp.num,&temp.name,&temp.sex,&temp.deptnum,&temp.tel); 
		if(strcmp(tempname,temp.name)==0)
		{
			if(flag==0)  
				printf("        ����            ����        �Ա�    ����        �绰����\n"); 
			printf("%10s%18s%8s%12d%13s\n",temp.num,temp.name,temp.sex,temp.deptnum,temp.tel);
			flag=1;
		} 
		n++;
	}
	if(n==0)
		printf("		�ļ����޼�¼!\n"); 
	else 
	{if(flag==0)
			printf("		�ļ����޴���!\n");  
	}
	fclose(fp1);
}

void sch_dept(FILE *fp)
{
	int flag=0,n=0;
	int i;
	int tempdept;
	FILE *fp1;
	
	fp1=fopen("f:\\��06С��_��ҵ���ʹ���ϵͳ\\student.txt","r");
	 
	printf("		������Ҫ��ѯ��¼�Ĳ��ű��:");
	scanf("%d",&tempdept);
	printf("\n");
   for(i=0;i<4;i++)
	{ while(feof(fp)==0)
	   { fscanf(fp,"%10s%25s%5s%8d%15s\n",em[i].num,em[i].name,em[i].sex,&em[i].deptnum,em[i].tel); 
		   
			 if(tempdept==em[i].deptnum)
		   {
			if(flag==0)  
			    		printf("        ѧ��            ����        �Ա�    ���ű��     �绰����\n"); 
			printf("%10s%18s%8s%12d%13s\n",em[i].num,em[i].name,em[i].sex,em[i].deptnum
				,em[i].tel);
			flag=1;
			n++;
		   } 
	    
		}		   	
	 }
		
	
	if(n==0)
		printf("		�ļ����޼�¼!\n"); 
    else 
		printf("		�˲�����%d��!\n",n);  
	fclose(fp1);
	
}
	 
void searchpay()
{
   
	FILE *fp,*f;
	f=fopen("f:\\��06С��_��ҵ���ʹ���ϵͳ\\student.txt","r");
	fp=fopen("f:\\��06С��_��ҵ���ʹ���ϵͳ\\score.dat","r");
	if(fp==NULL)
	{
		printf("		���ļ�ʧ��!\n");
		return;
	}             
	schpay_num(fp,f);
	 	fclose(f);
	fclose(fp);
}

void schpay_num(FILE *fp,FILE *f)
{
	int n=0;
float flag=0;

    char tempnum[6];
	struct employee temp; 
	
	printf("\n		������Ҫ��ѯ�Ĺ���:");
	gets(tempnum); 
 	
	while(feof(f)==0){
		fscanf(f,"%10s%25s%5s%8d%15s\n",&temp.num,&temp.name,&temp.sex,&temp.deptnum,&temp.tel); 
		if(strcmp(tempnum,temp.num)==0)
		{
		printf("	    ѧ��	 	      ����      \n");
			printf("     %10s  %25s\n",temp.num,temp.name);
		}    
		
	}
 
	printf("���ű��		   ��������		�ۺϹ���      ʵ�ù���     \n");
 
	while(feof(fp)==0)
	{
		fscanf(fp,"%5s%s%s%f%d%f%f%f\n",&temp.num,&temp.deptnum,&temp.deptname,&temp.basepay,&temp.bonus,&temp.meritpay,&temp.sumpay,&temp.totalpay); 
	
		
		if(strcmp(tempnum,temp.num)==0)
		{
				
			
			printf("%s%30s%20.2f%17.2f\n",temp.deptnum,temp.deptname,temp.sumpay,temp.totalpay);
			flag+=temp.totalpay;
			n++;
		} 
	
	}
   if(n==0)
		printf("		�ļ����޼�¼!\n"); 
	else 
	{if(flag==0)
			printf("		�ļ����޴���!\n");
		else
		{printf("���ý���");
		 printf("%d",n);
		 printf("\nʵ�ù���Ϊ:");
         printf("%7.2f",flag);
         printf("\n");
		}
	}
}	  
 

void delete1()
{    
   FILE *fp,*f;
   f=fopen("f:\\��06С��_��ҵ���ʹ���ϵͳ\\score.dat","r");
   fp=fopen("f:\\��06С��_��ҵ���ʹ���ϵͳ\\student.txt","r+");
   if(fp==NULL||f==NULL)
   {
	 printf("	���ļ�ʧ��!\n");
	 return;
   }   

  del_num(fp,f);

}	

void del_num(FILE *fp,FILE *f)
{ int t;
  FILE *fp1;
  char tempnum[6];
  struct employee temp;
  printf("		������Ҫɾ����¼�Ĺ���:");
  gets(tempnum);    
  fp1=fopen("f:\\��06С��_��ҵ���ʹ���ϵͳ\\employee1.txt","w+");
  //����employee.TXTɾ���������
  while(feof(fp)==0)
  {
     fscanf(fp,"%s%25s%5s%8d%15s\n",&temp.num,&temp.name,&temp.sex,&temp.deptnum,&temp.tel); 
     if(strcmp(tempnum,temp.num)==0) continue;
     fprintf(fp1,"%5s %20s  %5s %8d%15s\n",&temp.num,&temp.name,&temp.sex,&temp.deptnum,&temp.tel);
  }
 
  //����ɾ���������д��employee.TXT
  remove("f:\\��06С��_��ҵ���ʹ���ϵͳ\\employee.txt.txt");
  fp=fopen("f:\\��06С��_��ҵ���ʹ���ϵͳ\\employee.txt","w+");	
  rewind(fp1);
  t=getc(fp1);
  while(!feof(fp1))
  {
     putc(t,fp);
     t=getc(fp1);
  }

  fclose(fp);
  
  //����pay.datɾ���������
  fp1=fopen("f:\\��06С��_��ҵ���ʹ���ϵͳ\\employee1.txt","w+");
  while(feof(f)==0)
  {
     fscanf(f,"%s%s%s%f%d%f%f%f\n",&temp.num,&temp.deptnum,&temp.deptname,&temp.basepay,&temp.bonus,&temp.meritpay,&temp.sumpay,&temp.totalpay); 
     if(strcmp(tempnum,temp.num)==0) continue;
     fprintf(fp1,"%-10s%-7s%-15s%-8.2f%-5d%-8.2f%-8.2f%-8.2f\n",temp.num ,temp.deptnum,temp.deptname,temp.basepay,temp.bonus,temp.meritpay,temp.sumpay,temp.totalpay);
  }
//����ɾ���������д��pay.dat
   f=fopen("f:\\��06С��_��ҵ���ʹ���ϵͳ\\pay.dat","w+");	
   rewind(fp1);
   t=getc(fp1);
   while(!feof(fp1))
	{
		putc(t,f);
        t=getc(fp1);
	}



	fclose(f);
    fclose(fp1);
    remove("f:\\��06С��_��ҵ���ʹ���ϵͳ\\employee1.txt");
	printf("               ��ɾ��Ա����Ϣ\n");
}	


void sort()
{
	char c;
	FILE *fp;
	
	fp=fopen("f:\\��06С��_��ҵ���ʹ���ϵͳ\\score.dat","a+");
	if(fp==NULL)
	{
		printf("		���ļ�ʧ��!\n");
		return;
	}   
	fclose(fp);
	
	printf("      ��ʵ�ù�������(c),���ǰ��ۺϹ�������(s)?    ");
	c=getch();
	if(c=='s'||c=='S')
		sort_sumpay();		                                       /*���ۺϹ�������*/
	else if(c=='c'||c=='C')
		sort_totalpay();		                                           /*��ʵ�ù�������*/
	else
		printf("\n		��Ϊ�Ƿ��ַ�!\n");	 	
}	 

void sort_sumpay()
{   char c;
    int i=0;
	int n=0;
    int j,k;
	FILE *fp;
	float a[12];
	fp=fopen("f:\\��06С��_��ҵ���ʹ���ϵͳ\\score.dat","r");
	if(fp==NULL)
	{
		printf("\n		���ļ�ʧ��!\n");
		return;
	}  

	while(feof(fp)==0)
	{ fscanf(fp,"%s%s%s%f%d%f%f%f\n",&em[i].num ,&em[i].deptnum,&em[i].deptname,&em[i].basepay,&em[i].bonus,&em[i].meritpay,&em[i].sumpay,&em[i].totalpay);

	a[i]=em[i].sumpay;
	  i++;
	}
//��������
  for( k=1;k<20;k++)
	  for( j=k;(j>0)&&(a[j]<a[j-1]);j--)
	  {float d=a[j];
	   a[j]=a[j-1];
	   a[j-1]=d;
	  }
	printf("\n		������(u)�����ǰ�����(d)?\n\n");
	c=getch();    
if(c=='u'||c=='U')                                                  /*���ۺϹ��ʵ���������*/
    for(j=0;j<12;j++)
	{       
		for(k=0;k<12;k++)
		   if(a[j]==em[k].sumpay)
           {
			   printf("%-10s%-7s%-15s%-8.2f%-5d%-8.2f%-8.2f%-8.2f\n",em[k].num ,em[k].deptnum,em[k].deptname,em[k].basepay,em[k].bonus,em[k].meritpay,em[k].sumpay,em[k].totalpay);
               break;
		   }
	}
	else if(c=='d'||c=='d')
       for( j=19;j>=0;j--)
	   {    
		   for(k=0;k<20;k++)
		   if(a[j]==em[k].sumpay)
		   {
            	printf("%-10s%-7s%-15s%-8.2f%-5d%-8.2f%-8.2f%-8.2f\n",em[k].num ,em[k].deptnum,em[k].deptname,em[k].basepay,em[k].bonus,em[k].meritpay,em[k].sumpay,em[k].totalpay);
               break;
		   }
		
		}	
	   else
	      printf("\n �����ַ�!\n");
	   	
	fclose(fp);
}


void sort_totalpay()
{
	char c;
    int i=0;
	int n=0;
    int j,k;
	FILE *fp;
	float a[20];
	float b[20];
	fp=fopen("f:\\��06С��_��ҵ���ʹ���ϵͳ\\pay.dat","r");
	if(fp==NULL)
	{
		printf("\n		���ļ�ʧ��!\n");
		return;
	}  

	while(feof(fp)==0)
	{ fscanf(fp,"%s%s%s%f%d%f%f%f\n",&em[i].num ,&em[i].deptnum,&em[i].deptname,&em[i].basepay,&em[i].bonus,&em[i].meritpay,&em[i].sumpay,&em[i].totalpay);

	a[i]=em[i].totalpay;
	  i++;
	}
//��������
  for( k=1;k<20;k++)
	  for( j=k;(j>0)&&(a[j]<a[j-1]);j--)
	  {float d=a[j];
	   a[j]=a[j-1];
	   a[j-1]=d;
	  }
for(k=0;k<20;k++)
   b[k]=em[k].totalpay;
	printf("\n		������(u)�����ǰ�����(d)?\n\n");
	c=getch();    
if(c=='u'||c=='U')                                                      /* ���ۺϹ��ʵ��������� */
{  
 for(j=0;j<20;j++)
	{       
		for(k=0;k<20;k++)
		   if(a[j]==em[k].totalpay)
           {    
			   printf("%-10s%-7s%-15s%-8.2f%-5d%-8.2f%-8.2f%-8.2f\n",em[k].num ,em[k].deptnum,em[k].deptname,em[k].basepay,em[k].bonus,em[k].meritpay,em[k].sumpay,em[k].totalpay);
               em[k].totalpay=0;
			   break;
		   }
	}
for(k=0;k<20;k++)em[k].totalpay=b[k];
}
	else if(c=='d'||c=='d')
	{
       for( j=11;j>=0;j--)
	   {    
		   for(k=0;k<20;k++)
		   if(a[j]==em[k].totalpay)
		   {
            	printf("%-10s%-7s%-15s%-8.2f%-5d%-8.2f%-8.2f%-8.2f\n",em[k].num ,em[k].deptnum,em[k].deptname,em[k].basepay,em[k].bonus,em[k].meritpay,em[k].sumpay,em[k].totalpay);
                  em[k].totalpay=0;
				break;
		   }
		
		}
for(k=0;k<20;k++)em[k].totalpay=b[k];
	   }
	   else{
	      printf("\n �����ַ�!\n");
	   }
	
	
	fclose(fp);
}