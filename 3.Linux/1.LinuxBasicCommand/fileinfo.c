///$ ./fileinfo 文件名


#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>


void show_stat_info(char * fname,struct stat *buf)
{
    printf("  mode:  %o\n",buf->st_mode);
    printf(" links:  %d\n",buf->st_nlink);
    printf("  user:  %d\n",buf->st_uid);
    printf("  group: %d\n",buf->st_gid);
    printf("   size: %d\n",buf->st_size);
    printf("modtime: %d\n",buf->st_mtime);
    printf("  group: %s\n",fname);
}


int main(int argc, char *argv[])
{
    struct stat info;
    if(argc > 1){
        if(stat(argv[1], &info) != -1)
        {
            show_stat_info(argv[1], &info);
            return 0;
        }
    }else
        perror(argv[1]);
    return 1;
}
