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

