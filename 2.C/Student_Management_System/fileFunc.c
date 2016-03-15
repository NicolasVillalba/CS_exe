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
