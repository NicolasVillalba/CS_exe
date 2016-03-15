> 学生管理系统说明

#环境说明

> 本系统在Ubuntu平台编写并且测试，使用gcc编译器和c99标准，gcc的版本为4.8.4

> 本系统在密码输入时使用了linux平台上面特有的一些函数接口，若要移植其他平台需要做适当的修改



#各个文件解释


-
-main.c

> 主函数所在目录，也是函数入口

-func.h

> 头文件，所有函数声明

-fileFunc.c

> 文件操作，对链表进行增删改查，然后写入文件

-init.c

> 初始化文件，在程序运行时建立链表

-MenuShow.c

> 菜单文件，用来显示菜单

-


#程序展示

###一.菜单文件

> MenuShow.c

```c
#include "func.h"



void ClearScreen()
{
    system("reset");
}






void RootSysShow()
{
    ClearScreen();
    printf("**************************************************************************\n");
    printf("**************Student   Information   Management   System*****************\n");
    printf("**************************************************************************\n");
    printf("                     1.search student information\n");
    printf("                     2.add student information\n");
    printf("                     3.update student information\n");
    printf("                     4.delete student information\n");
    printf("                     5.add user account\n");
    printf("                     6.update user account\n");
    printf("                     7.delete user account\n");
    printf("                     8.search user account\n");
    printf("                     9.exit\n");
    printf("select an order number:\n");
}


void NormalSysShow()
{
    
    ClearScreen();
    printf("**************************************************************************\n");
    printf("**************Student   Information   Management   System*****************\n");
    printf("**************************************************************************\n");
    printf("                     1.search student information\n");
    printf("                     9.exit\n");
    printf("select an order number:\n");
}


void NormalUsrSearchshow()
{
    ClearScreen();
    printf("1.search by name\n");
    printf("2.search by id\n");
    printf("3.return\n");
}

void RootUsrSearchShow()
{
    ClearScreen();
    printf("0.search by all\n");
    printf("1.search by name\n");
    printf("2.search by id\n");
    printf("3.return\n");
}

//函数set_disp_mode用于控制是否开启输入回显功能  
//如果option为0，则关闭回显，为1则打开回显  
int set_disp_mode(int fd,int option)  
{  
   int err;  
   struct termios term;  
   if(tcgetattr(fd,&term)==-1){  
     perror("Cannot get the attribution of the terminal");  
     return 1;  
   }  
   if(option)  
        term.c_lflag|=ECHOFLAGS;  
   else  
        term.c_lflag &=~ECHOFLAGS;  
   err=tcsetattr(fd,TCSAFLUSH,&term);  
   if(err==-1 && err==EINTR){  
        perror("Cannot set the attribution of the terminal");  
        return 1;  
   }  
   return 0;  
}  

//函数getpasswd用于获得用户输入的密码，并将其存储在指定的字符数组中  
int getpasswd(char* passwd, int size)  
{  
   int c;  
   int n = 0;  
    
   printf("Please Input password:");  
    
   do{  
      c=getchar();  
      if (c != '\n'|c!='\r'){  
         passwd[n++] = c;  
      }  
   }while(c != '\n' && c !='\r' && n < (size - 1));  
   passwd[n] = '\0';  
   return n;  
}  





void SelectOrder()
{
    ClearScreen();
    printf("Please input the username:");
    char user[USR_NAME_LEN];
    scanf("%s", user);
    
    //密码输入
    char passwd[USR_PWD_LEN], *p;
    getchar();
    set_disp_mode(STDIN_FILENO,0); 
    getpasswd(passwd, sizeof(passwd));    
    p=passwd;  
    while(*p!='\n') p++;  
    *p='\0'; 
    set_disp_mode(STDIN_FILENO,1);
}
```

##二.初始化文件

> init.c

```c
#include "func.h"



void link_show_account(pUSR_ACCOUNT pheadAcc)//显示管理员
{
     pUSR_ACCOUNT pcur;
     pcur = pheadAcc;
     while(pcur != NULL)
     {
          printf("%2d ", pcur -> usr_role);
          printf("%5s", pcur -> usr_name);
          pcur = pcur -> pNext_Usr_Account;
          printf("\n");
     }
}



void link_show_infor(pUSR_INFOR pheadusr)//显示学生
{
     pUSR_INFOR pcur;
     pcur = pheadusr;
     while(pcur != NULL)
     {
          printf("%4d ", pcur -> usr_id);
          printf("%15s", pcur -> usr_name);
          printf("%10d", pcur -> usr_course_id);
          printf("%5.2lf", pcur -> usr_course_score);
          pcur = pcur -> pNext_Usr_Infor;
          printf("\n");
     }
}







void SystemInit_usr_account_tag(pUSR_ACCOUNT *pheadAcc, pUSR_ACCOUNT *ptailAcc)
{
    FILE *fp;
    if((fp = fopen("usr_account.txt", "r")) == NULL)
    {
        perror("init.c/SystemInit_usr_account_tag/ usr_account.txt cannot open\n");
        return;
    }
    char buff[100];
    buff[0] = '\0';
    while((fgets(buff, sizeof(buff), fp)) != NULL)
    {
        pUSR_ACCOUNT pnew = (pUSR_ACCOUNT)malloc(sizeof(USR_ACCOUNT));
        memset(pnew, 0, sizeof(USR_ACCOUNT));
        pnew->usr_role = buff[0] - '0';
        pnew->usr_name[0] = '\0';
        pnew->usr_pwd[0] = '\0';
        sscanf(buff, "%d %s %s", &pnew->usr_role, pnew->usr_name, pnew->usr_pwd);
/*        int i = 2;*/
/*        int k = 0;*/
/*        while(buff[i] != ' ')*/
/*            pnew->usr_name[k++] = buff[i++];*/
/*        i++;*/
/*        k = 0;*/
/*        while(buff[i] != '\0')*/
/*        {*/
/*            pnew->usr_pwd[k++] = buff[i++];*/
/*        }*/
        buff[0] = '\0';
        
        if(*ptailAcc == NULL)
        {
            *pheadAcc = pnew;
            *ptailAcc = pnew;
        }else{
            (*ptailAcc)->pNext_Usr_Account = pnew;
            *ptailAcc = pnew;
        }
        
    }
    fclose(fp);
}


void SystemInit_usr_infor_tag(pUSR_INFOR *pheadusr, pUSR_INFOR *ptailusr)
{
    FILE *fp;
    if((fp = fopen("usr_infor.txt", "r")) == NULL)
    {
        perror("init.c/SystemInit_usr_infor_tag/ usr_infor.txt cannot open\n");
        return;
    }
    char buff[100];
    buff[0] = '\0';
    while((fgets(buff, sizeof(buff), fp)) != NULL)
    {
        pUSR_INFOR pnew = (pUSR_INFOR)malloc(sizeof(USR_INFOR));
        memset(pnew, 0, sizeof(USR_INFOR));
        pnew->usr_id = -1;
        pnew->usr_name[0] = '\0';
        pnew->usr_course_id = -1;
        pnew->usr_course_score = -1.0;
        sscanf(buff, "%d %s %d %lf", &pnew->usr_id, pnew->usr_name, &pnew->usr_course_id, &pnew->usr_course_score);

/*        int i = 0, k =0, n = 0;*/
/*        while(buff[i] != ' ') */
/*            n = n*10 + buff[i++] - '0';*/
/*        pnew->usr_id = n;*/
/*        printf("succ %d\n", i);*/
/*        */
/*        */
/*        i++;*/
/*        k = 0;*/
/*        while(buff[i] != ' ')*/
/*              pnew->usr_name[k++] = buff[i++];*/
/*        printf("succ %d\n", i);*/
/*        */
/*        i++;*/
/*        n = 0;*/
/*        while(buff[i] != ' ')*/
/*        {*/
/*              n = n*10 + buff[i++] - '0';*/
/*              printf("succ %d\n", i);*/
/*         }*/
/*        */
/*        pnew->usr_course_id = n;*/
/*        i++;*/
/*        n = 0;*/
/*        printf("buff[%d] = %c\n", i, buff[i]);*/
/*        while(buff[i] != '\0' || buff[i] != '\n' || buff[i] != ' ')*/
/*        {*/
/*           printf("buff[%d] = %c\n", i, buff[i]);*/
/*           if(i > 30) break;*/
/*            n = n*10 + buff[i++] - '0';*/
/*            //printf("succ %d\n", i);*/
/*        }*/
/*        pnew->usr_course_score = n;*/
        
        
        
        
        
        pUSR_INFOR ppre, pcur;
	    if(*pheadusr == NULL)//判断为空
	    {
		    *pheadusr = pnew;
		    *ptailusr = pnew;
	    }else if((*pheadusr)->usr_id > pnew->usr_id){//插入到头部
		    pnew -> pNext_Usr_Infor = *pheadusr;
		    *pheadusr = pnew;
	    }else if((*ptailusr)->usr_id < pnew->usr_id){//插入到尾部
		    (*ptailusr) -> pNext_Usr_Infor = pnew;
		    (*ptailusr) = pnew;
	    }else{//插入中间
		    pcur = *pheadusr;
		    while(pcur != NULL)
		    {
			
			if(pcur -> usr_id >pnew->usr_id)
			{
				ppre -> pNext_Usr_Infor = pnew;
				pnew -> pNext_Usr_Infor = pcur;
				break;
			}
			ppre = pcur;
			pcur = pcur -> pNext_Usr_Infor;
		}
	   }        
        
        
        
    }
}

```

###三.功能及其文件操作

> fileFunc.c

```c
#include "func.h"



void SaveInStudentFile(pUSR_INFOR pheadusr)
{
    FILE *fp;
    if((fp = fopen("usr_infor.txt", "w+")) == NULL)
    {
        perror("init.c/SystemInit_usr_account_tag/ usr_infor.txt cannot open\n");
        return;
    }
    char buff[100];
    buff[0] = '\0';
    pUSR_INFOR pcur = pheadusr;
    while(pcur != NULL)
    {
        sprintf(buff, "%d %s %d %.2lf\n", pcur->usr_id, pcur->usr_name, pcur->usr_course_id, pcur->usr_course_score);
        fputs(buff, fp);
        memset(buff, 0,sizeof(buff));
        pcur = pcur->pNext_Usr_Infor;
    }
    fclose(fp);
}


void SaveInAccountFile(pUSR_ACCOUNT pheadAcc)
{
    FILE *fp;
    if((fp = fopen("usr_account.txt", "w+")) == NULL)
    {
        perror("init.c/SystemInit_usr_account_tag/ usr_account.txt cannot open\n");
        return;
    }
    char buff[100];
    buff[0] = '\0';
    pUSR_ACCOUNT pcur = pheadAcc;
    while(pcur != NULL)
    {
        sprintf(buff, "%d %s %s\n", pcur->usr_role, pcur->usr_name, pcur->usr_pwd);
        fputs(buff, fp);
        memset(buff, 0, sizeof(buff));
        pcur = pcur->pNext_Usr_Account;
    }
    fclose(fp);
}


int AccountCompare(char name[USR_NAME_LEN], char passwd[USR_PWD_LEN], pUSR_ACCOUNT pheadAcc)
{
    pUSR_ACCOUNT pcur = pheadAcc;
    while(pcur != NULL)
    {
        if(strcmp(pcur->usr_name,name)==0 && strcmp(pcur->usr_pwd, passwd) == 0) 
            return pcur->usr_role;
        else
        {
            pcur = pcur->pNext_Usr_Account;
        }
    }
    return -1;
}



//search
void SearchByAll(pUSR_INFOR pheadusr)
{
    pUSR_INFOR pcur = pheadusr;
    while(pcur != NULL)
    {
        printf("%5d %15s %5d %5.2lf\n", pcur->usr_id, pcur->usr_name, pcur->usr_course_id, pcur->usr_course_score);
        pcur = pcur->pNext_Usr_Infor;
    }
}


void SearchByName(pUSR_INFOR pheadusr)
{
    printf("Please input a name:");
    char name[USR_NAME_LEN];
    scanf("%s", name);
    pUSR_INFOR pcur = pheadusr;
    int cnt = 0;
    while(pcur != NULL)
    {
        if(strcmp(name, pcur->usr_name) == 0)
        {
            printf("%5d %15s %5d %5.2lf\n", pcur->usr_id, pcur->usr_name, pcur->usr_course_id, pcur->usr_course_score);
            cnt++;
         }
        pcur = pcur->pNext_Usr_Infor;
    }
    if(cnt == 0) printf("No Such a Student!\n");
}


void SearchById(pUSR_INFOR pheadusr)
{
    printf("Please input a id:");
    int id;
    scanf("%d", &id);
    pUSR_INFOR pcur = pheadusr;
    while(pcur != NULL)
    {
        if(id == pcur->usr_id)
        {
            printf("%5d %15s %5d %5.2lf\n", pcur->usr_id, pcur->usr_name, pcur->usr_course_id, pcur->usr_course_score);
            return;
         }
        pcur = pcur->pNext_Usr_Infor;
    }
    printf("No Such a Student!\n");
}



void AddStudentAccount(pUSR_INFOR *pheadusr, pUSR_INFOR *ptailusr)
{
    pUSR_INFOR pcur = *pheadusr;
    pUSR_INFOR pnew = (pUSR_INFOR)malloc(sizeof(USR_INFOR));
    memset(pnew, 0, sizeof(USR_INFOR));
    printf("Please input the usr_id:");
    scanf("%d", &pnew->usr_id);
    while(pcur != NULL)
    {
        if(pcur->usr_id == pnew->usr_id)
        {
            printf("The id is the same, failed to add!\n");
            return;
        }
        pcur = pcur->pNext_Usr_Infor;
    }
    printf("Please input the usr_name:");
    scanf("%s", pnew->usr_name);
    
    printf("Please input the usr_course_id:");
    scanf("%d", &pnew->usr_course_id);
    
    printf("Please input the usr_course_score:");
    scanf("%lf", &pnew->usr_course_score);
    
    pUSR_INFOR ppre;
	if(*pheadusr == NULL)//判断为空
	{
	    *pheadusr = pnew;
	    *ptailusr = pnew;
	    printf("%5d %15s %5d %5.2lf\n", pnew->usr_id, pnew->usr_name, pnew->usr_course_id, pnew->usr_course_score);
		printf("Add success!\n");
		return;
    }else if((*pheadusr)->usr_id > pnew->usr_id){//插入到头部
	    pnew -> pNext_Usr_Infor = *pheadusr;
	    *pheadusr = pnew;
        printf("%5d %15s %5d %5.2lf\n", pnew->usr_id, pnew->usr_name, pnew->usr_course_id, pnew->usr_course_score);
		printf("Add success!\n");
		return;
	}else if((*ptailusr)->usr_id < pnew->usr_id){//插入到尾部
		(*ptailusr) -> pNext_Usr_Infor = pnew;
		(*ptailusr) = pnew;
		printf("%5d %15s %5d %5.2lf\n", pnew->usr_id, pnew->usr_name, pnew->usr_course_id, pnew->usr_course_score);
		
		printf("Add success!\n");
		return;
	}else{//插入中间
		pcur = *pheadusr;
		while(pcur != NULL)
		{
			
	        if(pcur -> usr_id > pnew->usr_id)
			{
				ppre -> pNext_Usr_Infor = pnew;
				pnew -> pNext_Usr_Infor = pcur;
				printf("%5d %15s %5d %5.2lf\n", pnew->usr_id, pnew->usr_name, pnew->usr_course_id, pnew->usr_course_score);
				printf("Add success!\n");
				return;
			}
			ppre = pcur;
			pcur = pcur -> pNext_Usr_Infor;
		}
	   }
	
	
}

void DeleteStudentInfor(pUSR_INFOR *pheadusr, pUSR_INFOR *ptailusr)
{
    printf("please input usr_id you want delete:");
    int id;
    scanf("%d", &id);
    pUSR_INFOR ppre = NULL;
	pUSR_INFOR pcur;
	if(*pheadusr == NULL) {
		printf("the link is empty,failed to delete!\n");	
	}else{
		pcur = *pheadusr;
		while(pcur != NULL)
		{
			if(pcur -> usr_id==id)
			{
				if(ppre ==NULL)
				{
					*pheadusr = pcur -> pNext_Usr_Infor;
				}else{
					ppre -> pNext_Usr_Infor = pcur -> pNext_Usr_Infor;
				}
				free(pcur);
				pcur = NULL;
				printf("Delete Success!\n");
				return;
			}
				ppre = pcur;
				pcur = pcur -> pNext_Usr_Infor;
		}
		printf("This Node doesn't exist, failed to delete!\n'");
	}
}





void UpdateInfor(pUSR_INFOR *pheadusr)
{
    printf("Please input the student's id what you want change:");
    int id;
    scanf("%d", &id);
    pUSR_INFOR pcur = *pheadusr;
    while(pcur != NULL)
    {
        if(id == pcur->usr_id)
        {
            printf("%5d %15s %5d %5.2lf\n", pcur->usr_id, pcur->usr_name, pcur->usr_course_id, pcur->usr_course_score);
            
            printf("enter the usr_name:");
            scanf("%s", pcur->usr_name);
  
            //printf("222222222222%5d %15s %5d %5.2lf\n", pcur->usr_id, pcur->usr_name, pcur->usr_course_id, pcur->usr_course_score);
            printf("enter the usr_course_id:");
            scanf("%d", &pcur->usr_course_id);
  
            //printf("33333%5d %15s %5d %5.2lf\n", pcur->usr_id, pcur->usr_name, pcur->usr_course_id, pcur->usr_course_score);
            printf("enter the usr_course_score:");
            scanf("%lf", &pcur->usr_course_score);
  
            printf("%5d %15s %5d %5.2lf\n", pcur->usr_id, pcur->usr_name, pcur->usr_course_id, pcur->usr_course_score);
            printf("Update Success!\n");
            //getchar();
            return;
        }
        pcur = pcur->pNext_Usr_Infor;
    }
    printf("No Such a Student and failed to update!\n");
}


void DeleteUserAccount(pUSR_ACCOUNT *pheadAcc, pUSR_ACCOUNT *ptailAcc)
{
    printf("please input name you want delete:");
    char name[USR_NAME_LEN];
    scanf("%s", name);
    pUSR_ACCOUNT ppre = NULL;
	pUSR_ACCOUNT pcur;
	if(*pheadAcc == NULL) {
		printf("the link is empty");	
	}else{
		pcur = *pheadAcc;
		while(pcur != NULL)
		{
			if((strcmp(pcur -> usr_name, name)) == 0)
			{
				if(ppre ==NULL)
				{
					*pheadAcc = pcur -> pNext_Usr_Account;
				}else{
					ppre -> pNext_Usr_Account = pcur -> pNext_Usr_Account;
				}
				free(pcur);
				pcur = NULL;
				return;
			}
				ppre = pcur;
				pcur = pcur -> pNext_Usr_Account;
		}
		printf("THis Node doesn't exist!\n'");
	}
}


void UpdateUserAccount(pUSR_ACCOUNT *pheadAcc)
{
    pUSR_ACCOUNT pcur = *pheadAcc;
    printf("please input the name of the account you want update:");
    char name[USR_NAME_LEN];
    scanf("%s", name);
    while(pcur != NULL)
    {
        if((strcmp(pcur -> usr_name, name)) == 0)
        {
            printf("enter the usr_role:");
            scanf("%d", &pcur->usr_role);
            
            printf("enter the usr_name:");
            scanf("%s", pcur->usr_name);
            
            printf("enter the usr_pwd:");
            scanf("%s", pcur->usr_pwd);
            
            printf("update success!\n");
            return;
        }
        
        pcur = pcur->pNext_Usr_Account;
    }
    printf("update failed!\n");
}



void AddUserAccount(pUSR_ACCOUNT *pheadAcc, pUSR_ACCOUNT *ptailAcc)
{
    //pUSR_ACCOUNT pcur = *pheadAcc;
    pUSR_ACCOUNT pnew = (pUSR_ACCOUNT)malloc(sizeof(USR_ACCOUNT));
    memset(pnew, 0, sizeof(USR_ACCOUNT));
    
    printf("Please input the usr_role(0/1):");
    scanf("%d", &pnew->usr_role);
    
    printf("Please input the usr_name:");
    scanf("%s", pnew->usr_name);
    
    printf("Please input the password:");
    scanf("%s", pnew->usr_pwd);
    
    if(*ptailAcc == NULL)
    {
         *pheadAcc = pnew;
         *ptailAcc = pnew;
         printf("%3d %5s %5s\n", pnew->usr_role, pnew->usr_name, pnew->usr_pwd);
         printf("add success!\n");
         return;
     }else{
         (*ptailAcc)->pNext_Usr_Account = pnew;
         *ptailAcc = pnew;
         printf("%3d %5s %5s\n", pnew->usr_role, pnew->usr_name, pnew->usr_pwd);
         printf("add success!\n");
         return;
     }
     
     printf("Failed to add!\n");
}
```

###四.头文件

> func.h

```c
#include<stdio.h>
#include<stdlib.h>
#include<string.h>



#include <termios.h>  
#include <unistd.h>  
#include <errno.h>  
#define ECHOFLAGS (ECHO | ECHOE | ECHOK | ECHONL)  

#define USR_NAME_LEN 20
#define USR_PWD_LEN 15



typedef struct usr_account_tag{
    int usr_role;//0和1,1表示管理员，0表示普通用户
    char usr_name[USR_NAME_LEN];
    char usr_pwd[USR_PWD_LEN];
    struct usr_account_tag *pNext_Usr_Account;
}USR_ACCOUNT, *pUSR_ACCOUNT;




typedef struct usr_infor_tag{
    int usr_id;
    char usr_name[USR_NAME_LEN];
    int usr_course_id;
    double usr_course_score;
    struct usr_infor_tag *pNext_Usr_Infor;
}USR_INFOR, *pUSR_INFOR;




//MenuShow.c
void ClearScreen();

void RootSysShow();

void NormalSysShow();

void SelectOrder();

void NormalUsrSearchshow();

void RootUsrSearchShow();

int set_disp_mode(int fd,int option);

int getpasswd(char* passwd, int size);



//init.c
void link_show_account(pUSR_ACCOUNT pheadAcc);

void link_show_infor(pUSR_INFOR pheadusr);

void SystemInit_usr_account_tag(pUSR_ACCOUNT *pheadAcc, pUSR_ACCOUNT *ptailAcc);

void SystemInit_usr_infor_tag(pUSR_INFOR *pheadusr, pUSR_INFOR *ptailusr);



//fileFunc.c
void SaveInStudentFile(pUSR_INFOR pheadusr);

void SaveInAccountFile(pUSR_ACCOUNT pheadAcc);

int AccountCompare(char name[USR_NAME_LEN], char passwd[USR_PWD_LEN], pUSR_ACCOUNT pheadAcc);

void SearchByAll(pUSR_INFOR pheadusr);

void SearchByName(pUSR_INFOR pheadusr);

void SearchById(pUSR_INFOR pheadusr);

void UpdateInfor(pUSR_INFOR *pheadusr);

void AddStudentAccount(pUSR_INFOR *pheadusr, pUSR_INFOR *ptailusr);

void DeleteStudentInfor(pUSR_INFOR *pheadusr, pUSR_INFOR *ptailusr);

void DeleteUserAccount(pUSR_ACCOUNT *pheadAcc, pUSR_ACCOUNT *ptailAcc);

void UpdateUserAccount(pUSR_ACCOUNT *pheadAcc);

void AddUserAccount(pUSR_ACCOUNT *pheadAcc, pUSR_ACCOUNT *ptailAcc);

```

###五.主文件夹

> main.c

```c
#include "func.h"


int main()
{
//初始化
    pUSR_ACCOUNT pheadAcc = NULL;
    pUSR_ACCOUNT ptailAcc = NULL;
    SystemInit_usr_account_tag(&pheadAcc, &ptailAcc);
    //link_show_account(pheadAcc);
    
    pUSR_INFOR pheadusr = NULL;
    pUSR_INFOR ptailusr = NULL;
    SystemInit_usr_infor_tag(&pheadusr, &ptailusr);
    //link_show_infor(pheadusr);
    //RootSysShow();
    
    
    ClearScreen();
    
    //RootUsrSearchShow();
    
    
    printf("Please input the username:");
    char user[USR_NAME_LEN];
    scanf("%s", user);
    
    //密码输入
    char passwd[USR_PWD_LEN], *p;
    getchar();
    set_disp_mode(STDIN_FILENO,0); 
    getpasswd(passwd, sizeof(passwd));    
    p=passwd;  
    while(*p!='\n') p++;  
    *p='\0'; 
    set_disp_mode(STDIN_FILENO,1);
    printf("\n");
    int ret = AccountCompare(user, passwd, pheadAcc);
    
    if(ret == 1) {
        printf("root\n");
        
        int s;
GotoLoop1:
        
        RootSysShow();
        while((scanf("%d", &s)) != EOF){
            switch(s){
                case 1:RootUsrSearchShow();
                      int case1;
                     while((scanf("%d", &case1)) != EOF)
                    {
                        switch(case1)
                        {
                            case 0:SearchByAll(pheadusr);break;
                            case 1:SearchByName(pheadusr);break;
                            case 2:SearchById(pheadusr);break;
                            case 3:goto GotoLoop1;
                            default:printf("please input a correct order!\n");
                        }
                    }
                    break;
                case 2:AddStudentAccount(&pheadusr, &ptailusr);
                       SaveInStudentFile(pheadusr);
                       //RootSysShow();
                       break;
                case 3:UpdateInfor(&pheadusr);
                       SaveInStudentFile(pheadusr);
                       break;
                case 4:DeleteStudentInfor(&pheadusr, &ptailusr);
                       SaveInStudentFile(pheadusr);
                       break;
                case 5:AddUserAccount(&pheadAcc, &ptailAcc);
                       SaveInAccountFile(pheadAcc);
                       break;
                case 6:UpdateUserAccount(&pheadAcc);
                       SaveInAccountFile(pheadAcc);
                       break;
                case 7:DeleteUserAccount(&pheadAcc, &ptailAcc);
                       SaveInAccountFile(pheadAcc);
                       printf("Delete Success!\n");
                       break;
                case 8:link_show_account(pheadAcc);
                       break;
                case 9:return 0;
                default:printf("please input a correct order!\n");
            }
        }
    }
    else if(ret == 0) {
        printf("user\n");
        int k;
        
GotoLoop2:
        NormalSysShow();
        while((scanf("%d", &k)) != EOF)
        {
            switch(k)
            {
                case 1:NormalUsrSearchshow();
                      int case2;
                     while((scanf("%d", &case2)) != EOF)
                     {
                        switch(case2)
                        {
                            case 1:SearchByName(pheadusr);break;
                            case 2:SearchById(pheadusr);break;
                            case 3:goto GotoLoop2;
                            default:printf("please input a correct order!\n");
                        }
                     }
                     break;
               case 9:return 0;
               default:printf("please input a correct order!\n");
             }
        }
       }
    else {
        printf("password error!\n");
        return 0;
    }
    
    return 0;
}
```
