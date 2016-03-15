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

