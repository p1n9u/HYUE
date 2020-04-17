/ *
  * 2018045341 Kimdowon
  * ICT media Tech / SW computer
  * 2020.04.18
*/

/*
 * getcwd()와 동일한 동작을 실행하는 함수를 구현하라. 
 * getcwd()의 성공/실패 여부와 상관 없이, 탐색을 시작한 것과 동일한 디렉토리에 존재해야 함
 * 인자가 NULL인 경우는 고려할 필요 없음

 * hint
 * 부모 디렉토리(..)의 각 엔트리를 돌면서 opendir()과 readdir()을 사용하면 현재 작업 디렉토리의 이름을 알 수 있음
 * 현재 작업 디렉토리와 동일한 i-노드와 디바이스 번호를 가진 엔트리를 
 * 찾으면 현재 디렉토리가 무엇인지 알 수 있음
 * 한 번에 한 단계씩 살펴보고, 스캔을 통해 디렉토리 경로를 구축해볼 것
 * 부모 디렉토리가 현재와 동일하다면(루트 디렉토리의 경우), 검색 종료 
*/

#include <dirent.h>
#include <string.h>

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

void creatEnv();

/**
 * 파일을 복사하여 사본을 생성한다. 
 * @param buf   경로명을 저장할 버퍼 변수.
 * @param size  버퍼 변수의 크기
 * @return 버퍼 변수의 시작 주소, 즉 buf
 */

char *mygetcwd(char *buf, size_t size) {
    DIR *c_dirp, *p_dirp;
    struct dirent *dp;
    unsigned long ino_num;
    char dirname[size];
    char back[size];
    int chk = 1;

    for (;;) {
        if ( chk == 0 ) {
	    break;
	}
        c_dirp = opendir(".");
        p_dirp = opendir("..");
        
        while ( (dp = readdir(c_dirp)) != NULL ) {
            if ( strcmp(dp->d_name, ".") == 0 ) {
                ino_num = dp->d_ino;
            }
        }

        while ( (dp = readdir(p_dirp)) != NULL ) {
	    if ( strcmp(dp->d_name, ".") == 0 || strcmp(dp->d_name, "..") == 0 ) {
	        continue;
	    }
            if ( (dp->d_ino) == ino_num ) {
                strncpy(back, dirname, size);
                strncpy(dirname, "/", size);
                strcat(dirname, dp->d_name);
                strcat(dirname, back);
		chk = 1;
		break;
            } else {
		chk = 0;
	    }
        }
        closedir(c_dirp);
        closedir(p_dirp);
        chdir("..");
    }

    buf = dirname;
    strcat(buf, "\0");
    return buf;
}

int main(void) {
    pid_t pid;
    int status;
    char buf[255];

    creatEnv();
    chdir("dir/sub");

    printf("original func: %s\n", getcwd(NULL, 0));
    printf("mygetcwd func: %s\n", mygetcwd(buf, 255));

    return 0;
}

void creatEnv() {
    mkdir("dir", 0755);
    mkdir("dir/sub", 0755);
    mkdir("dir/sub2", 0);
  
    creat("dir/a", 0755);
    creat("dir/b", 0755);
    creat("dir/sub/x", 0755);
    symlink("dir/a", "dir/sl");
    symlink("dir/x", "dir/dsl");
}
