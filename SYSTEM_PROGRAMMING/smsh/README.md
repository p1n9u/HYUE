ICT융합학부 Media Tech
2018045341 김도원

구현
==============================================
+ foreground and background execution (&)
+ multiple commands separated by semicolons
+ shell redirection (>, >>, >|, <)
+ shell pipe (ls –la | more)
+ Multiple pipe (ls | grep “^d” | more)
+ cd command
 
* nonclobber : >| 와 set 명령어 구현까지 완료, is_nonclobber(INC) 를 통해 판단하는 것을 구현하는 도중에 마감시간이 다됨.

- history command : 시간부족 시작하면 꼬일거 같아서 손을 안됨. 히스토리를 위한 배열을 만들고 토큰을 처리하면서 스페셜 토큰을 포함하여 이 배열에 저장한 후 파일을 입출력하려 했음.
==============================================

1. smsh.h
헤더파일, 최대값, 토큰타입, 토큰상태, ANSI COLOR, 함수프로토타입 정의
bufsize = maxarg * maxvec 1024

2. smsh.c
프롬프트 출력, 표준입출력fd 를 제외한 fd close.
토큰처리함수 process() 실행
return값이 End of Line이면 loop반복 및 프롬프트 출력
return값이 백그라운드상태가 아니며 자식프로세스의 pid가 0이 아니면 자식프로세스 종료를 기다림.

3. process.c, get_tok.c
토큰을 분리하고 처리하는 함수
getchar()로 받기때문에 >> >| 등 char *는 상태 검증을 하고 아닐경우 ungetc로 다시 버프반환
T_ARG : argv배열에 들어갈 벡터상태
T_INR : 입력 재지정, SRCFD를 닫아줌
T_OTA,OTR,INC : 출력 재지정, DSTFD를 닫아줌
T_SEM : T_CLG 즉 명령어그룹상태가 아닐때는 넘어가고 명령어 그룹상태일떄는 벡터를 다 모아옴
T_PIP : 파이프 설정
T_AMP : bg true or false

4. exec(_argv).c
case I : 명령어그룹인경우 - argv를 인자단위로 쪼갬 -> 명령어 갯수 만큼 자식을 fork() -> redirection -> execvp
case II : 일반 - argv에는 한번에 하나의 명령만 처리 -> fork() -> redirection -> execvp 

5. redirection.c
명령어 파일로 처리할지 표준입출력으로 처리할지 결정 / dup(), 파일로 처리할경우 open with flag

6. shellbuilt.c
사용자 작성 명령어 처리 / 조건에 하나라도 걸리면 사용자 명령을 수행한것으로 보고 true 반환, 종료 / 아니면 exec_argv()의 다음으로 넘어감

7. util.c
쉘 출력관련 함수 ( 프롬프트 관련 ), 디버깅 할때 함수작성용으로 사용했음