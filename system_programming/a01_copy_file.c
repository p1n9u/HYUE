#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
#include <fcntl.h> 
#define BUFSIZE 512 /* 한 번에 읽을 문자열의 크기 */
#define PERM 0644 /* 새로 만든 파일의 사용 권한 */ 

/**
 * 파일을 복사하여 사본을 생성한다.
 * @param name1 원본 파일 이름
 * @param name2 사본 파일 이름
 * @return 처리 결과를 숫자 형태로 반환 (자유롭게 정의하여 사용)
 */
int copy_file(const char *name1, const char *name2); 
void create_holed_file(const char *str);
void fatal(const char *str, int errno);

int main(){
  create_holed_file("file.hole");
  return copy_file("file.hole", "file2.hole");
}

/*
 * 고려사항 *
1. 첫 번째 파일을 개방한다. - open();
2. 두 번째 파일을 생성한다. - open() or creat();
3. 첫 번째 파일을 읽어 두 번째 파일에 쓴다. - read();, write();
4. 첫 번째 파일의 끝에 도달할 때까지 3번 동작을 반복한다. - while loop
5. 두 파일을 닫는다. - close();
*/

int copy_file(const char *name1, const char *name2) { 
  /* 함수 내용 작성 */
  int fd1, fd2, n;
  char buf[BUFSIZE];
  
  // 첫 번째 파일을 개방한다.
  if ((fd1=open(name1, O_RDONLY)) < 0) {
      perror("fd1 open err");
      exit(1);
  }

  // 두 번째 파일을 생성한다.
  if ((fd2=open(name2, O_CREAT | O_WRONLY | O_TRUNC, PERM)) < 0) {
      perror("fd2 creat err");
      exit(1);
  }

  // 첫 번째 파일을 읽어 두 번째 파일에 쓴다.
  while ((n = read(fd1, buf, BUFSIZE)) > 0) {
      write(fd2, buf, n);
  }

  // 두 파일을 닫는다.
  close(fd1);
  close(fd2);
  return 0;
} 

void create_holed_file(const char *str){
  char buf1[] = "abcdefghij", buf2[] = "ABCDEFGHIJ";
  int fd; 

  if ((fd = creat(str, 0640)) < 0)
    fatal("creat error", 1);

  if (write(fd, buf1, 10) != 10)
    fatal("buf1 write error", 1);
    
  if (lseek(fd, 40, SEEK_SET) == -1) 
    fatal("lseek error", 1);

  if (write(fd, buf2, 10) != 10) 
    fatal("buf2 write error", 1);
}

void fatal(const char *str, int errcode){
     perror(str);
     exit(errcode);
}