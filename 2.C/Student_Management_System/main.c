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
