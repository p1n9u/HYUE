#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h> 
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

void fatal(const char* str, int no);
void access_perm(char *perm, mode_t mode);

/*
chmod a+rX와 동일하게 동작하는 프로그램을 stat()과 chmod()를 이용하여 구현하라.

** 나머지는 모두 구현되어 있으며, chmod_arX 함수만 구현할 것. **

chmod a+rX [path] 명령은 다음과 같은 일을 수행한다.
모든 읽기 권한 활성화
디렉토리에는 모든 실행 권한을 활성화 한다.
이미 실행 권한이 있는 파일에 대해 모든 실행 권한을 활성화 한다. 
이때, 이미 실행 권한이 있는 파일이라는 의미는 사용자 종류에 상관 없이 하나라도 실행 권한을 가지고 있는 경우를 의미한다.
*/
void chmod_arX(char *list[]){
  int i;
  char *file_name;
  struct stat file_info;
  mode_t file_mode;
  
  for(i = 0; list[i] != NULL; i++){
    file_name = list[i];
    stat(file_name, &file_info);
    file_mode = file_info.st_mode;
    if (S_ISDIR(file_mode)) { // if dir
      chmod(file_name, 0555);
    } else {
      // 0r 1w 2x 3r 4w 5x 6r 7w 8x , 이 정보는 주어진 access_perm함수의 for loop 에서 얻었습니다. 
      if ( ( (file_mode << 2) & 0x100 ) || ( (file_mode << 5) & 0x100 ) || ( (file_mode << 8) & 0x100 ) ){ // 이미 실행 권한이 있는 파일
        chmod(file_name, 0555);
      } else {
        chmod(file_name, 0444);
      }   
    }
  }
}

int main(void) {
  struct stat statbuf;
  char perm[11];
  char pathname[80];
  char *list[] = {"dir1", "file1", "file2", NULL};
  int fd1, fd2, d, i;

  rmdir(list[0]);
  remove(list[1]);
  remove(list[2]);

  mkdir(list[0], 0400);
  fd1 = creat(list[1], 0400);
  fd2 = creat(list[2], 0500);
  
  printf("===== before =====\n");
  for(i = 0; list[i] != NULL; i++){
    if (stat(list[i], &statbuf) < 0) fatal("stat error", 1);
    access_perm(perm, statbuf.st_mode);
    printf("%s\t%s\n", list[i], perm);
  }
  
  chmod_arX(list);
  
  printf("\n===== after ======\n");
  for(i = 0; list[i] != NULL; i++){
    if (stat(list[i], &statbuf) < 0) fatal("stat error", 1);
    access_perm(perm, statbuf.st_mode);
    printf("%s\t%s\n", list[i], perm);
  }
  close(fd1);
  close(fd2);
  return 0;
}

void fatal(const char* str, int no){
  perror(str);
  exit(no);
}

void access_perm(char *perm, mode_t mode) {
  char permchar[] = "rwx";
  memset(perm, '-', 10);
  perm[10] = '\0';
  int i;
  
  if (S_ISDIR(mode)) perm[0] = 'd';
  else if (S_ISCHR(mode)) perm[0] = 'c';
  else if (S_ISBLK(mode)) perm[0] = 'b';
  else if (S_ISFIFO(mode)) perm[0] = 'p';
  else if (S_ISLNK(mode)) perm[0] = 'l';
  
  for (i = 0; i < 9; i++)
    if ((mode << i) & 0x100)
      perm[i+1] = permchar[i%3];
      
  if (mode & S_ISUID) perm[3] = 's';
  if (mode & S_ISGID) perm[6] = 's';
  if (mode & S_ISVTX) perm[9] = 't';
}