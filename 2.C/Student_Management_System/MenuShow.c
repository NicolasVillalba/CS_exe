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
