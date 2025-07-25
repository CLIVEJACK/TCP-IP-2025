# TCP-IP-2025
TCP-IP 공부

## 1일차 

### 가상환경 설치 및 환경변수 설정 

1. [VMWARE](https://www.vmware.com/products/desktop-hypervisor/workstation-and-fusion)
2. [ubntu](https://ubuntu.com/)
3. [Putty](https://www.chiark.greenend.org.uk/~sgtatham/putty/latest.html)

#### 소켓통신 
- 인터넷(이더넷)통신이 일반적인 소켓통신이다
- 일반적으로는 TCP방식이 메시지를 주고받는 방식이다

#### 클라이언트(client)
- 일방적으로 정보를 달라고하는 쪽
- 클라이언트는 서버에게 요청을 보내고, 서버는 요청을 처리한 후 응답을 클라이언트에 반환

#### 서버(server)
- 정보를 주는쪽
- 클라이언트에게 네트워크를 통해 정보나 서비스를 제공하는 컴퓨터 시스템 또는 프로그램을 의미

#### VMWARE
- 클라우드 컴퓨팅 및 가상화 소프트웨어 이다 
- 윈도우에서 가상환경을 구축해서 다른 OS를 사용하게하는 것

#### ip
- 컴퓨터의 주소 
- 인터넷 프로토콜(Internet Protocol)의 약자로, 인터넷이 통하는 네트워크에서 어떤 정보를 수신하고 송신하는 통신에 대한 규약을 의미함

#### 포트(Port) 
- 실행되는 프로그램의 최종목적지의 주소, 프로그램을 구분하는 용도 
- 컴퓨터가 각종 신호를 받아들이고 내보낼 수 있도록 연결할 수 있는 연결단자를 말한다. 컴퓨터 케이스에 달려 있어 손쉽게 연결이 가능한 외부 포트와, 컴퓨터 내부에 설치되어 있어 케이스를 열지 않으면 접근할 수 없는 내부 포트가 있다

#### TCP-IP 소켓통신 과정       클라이언트통신 과정
1. 소켓생성 : socket()              socket
2. 소켓주소 할당 : bind()
3. 연결요청 대기 : listen()         connetc
4. 연결허용 : accept()
5. 데이터 송신 : read/write()       read/write
6. 종료 : close()                   close

#### VMware Workstation
- 실행 > Create a New Virual Machine > 우분투설치 폴터 지정설치 > 코어와 메모리는 기본으로 넘기기 > 싱글 파일로 설정 >

    <img src="./image/tcp0001.png" width="600">


#### Ubuntu 명령어
- uname -a : 정보확인
- cd : 폴더 이동
- ls : 현재폴더를 보여준다 
- pwd : 현재위치
- cd .. : 전단계로 이동 
- mkdir : 폴더 생성
- clear : 화면지움 
- rm -fr : 파일 폴더 삭제
- sudo nano /etc/nanorc : nano설정
- touth : 빈파일 생성
- cat : 안에 들어있는 내용 확인
- cp : 복사 
- mv : 파일옮기기
- ./ : 현재 폴더
- ../ : 현재 폴더의 상위폴더로 
- sudo apt install gcc : gcc컴파일러 설치
- ./xxx : 실행명령

#### c언어 함수? 명령어? 부분

- 에러 메시지 : perror("message")

-  fd = open ("hello.txt", O_CREAT | O_WRONLY : ); 
    - fd 파일을 열어라 hello.txt가 없다면 만들고 읽어라 

- write : 오픈한 파일에 데이터를 쓸 때 사용하는 시스템 호출 

- size_t == unsigned int 정수 자료형 
- ssize_t == signed int  장수 자료형
- off_t == long형 정수
- htonl : 호스트 형태의 바이트(데이터) 순서를 네트워크로 형태로 바꿔라 
    - htonl 함수는 호스트 바이트 순서(보통 리틀 엔디안)의 32비트 정수를 네트워크 바이트 순서(빅 엔디안)의 32비트 정수로 변환하는 역할을 합니다. 이는 네트워크 프로그래밍에서 시스템 간의 데이터 호환성을 유지하기 위해 필수적인 작업
    - long intger(일반적으로 4byte) 데이터를 네트워크 byte order로 변경
- htons : 호스트 형태의 바이트 순서를 네트워크로 형태로 바꿔라 
    - short intger(일반적으로 2byte) 데이터를 네트워크 byte order로 변경

1. 빅 엔디안(big endian)
    - 빅 엔디안 방식은 낮은 주소에 데이터의 높은 바이트(MSB, Most Significant Bit)부터 저장하는 방식입니다.
2. 리틀 엔디안(little endian)
    - 리틀 엔디안 방식은 낮은 주소에 데이터의 낮은 바이트(LSB, Least Significant Bit)부터 저장하는 방식입니다.
     unsigned short htons(unsigned short);	h → n (short)
     unsigned short ntohs(unsigned short);	n → h (ushort)
     unsigned long htonl(unsingned long);	n → n (ulong) 
     unsigned long ntohl(unsigned long);	n → h (ulong)


#### IPv4 인터넷 주소의 체계
클래스 A        네트워크ID(1바이트) + 호스트ID(3바이트)         0 ~ 127 이하(0)
클래스 B        네트워크ID(2바이트) + 호스트ID(2바이트)         129 ~ 191(10)
클래스 C        네트워크ID(3바이트) + 호스트ID(1바이트)         192 ~ 223(110)
클래스 D        

#### 프로토콜 체계
PF_INET         IPv4 인터넷 프로토콜 체계
PF_INET6        IPv6 인터넷 프로토콜 체계

#### 소켓의 타입 (전송방식)
TCP(연결지향형 소켓) - SOCK_STREAM
UDP(비연결지향형 소켓) - SOCK_DGRAM

## 2일차 

#### c언어 함수 
- inet_addr() : 문자열로 되어있는 주소값을 정수값으로 바꿀수있다 

- 서버 함수
    socket( )				    소켓생성						전화기 구입
    
    bind( )					    소켓 주소할당				    전화번호 할당
    
    listen( )					연결요청 대기				    개통
    
    accept( )				    연결허용			    	    전화 받기	

    read( )/write( )		    데이터 송수신			        통화

    close( )					연결종료						통화 종료

- 클라이언트 함수 
   socket( )				    소켓생성						전화기 구입

   connect( )					연결요청				         전화 걸기

   read( )/write( )		    데이터 송수신				            통화

   close( )					    연결종료						  통화 종료
    

#### 리눅스 Tip (커멘드)
- 복사 : ctrl + insert or ctrl + shift + C 
- 붙여넣기: shift + insert 


## 3일차 
- 구조체 함수 
    sin_family     	주소체계(Address Family) 	: IPv4, IPv6
    sin_addr	   	32bit IP주소 정보 저장		: xxx.xxx.xxx.xxx
    sin_port 	   	16bit PORT번호 저장			: 0 ~ 65525

    htonl            	host 주소 -> network주소 변환(unsigned long)
    ntohl			network 주소 -> host 주소 (unsigned long)
    INADDR_ANY	현재 실행중인 컴퓨터의 IP를 소켓에 부여.

- fork를 사용하여 멀티프로세스를 사용 
- 제대로 처리해주지 않으면 프로세스를 잡아먹는 좀비 프로세스가 됨

- 좀비프로세스 배움 

## 4일차 
- ppt 35 ~ 

- 멀티프로세서 
    - 시그널이란 운영체제가 어떤 특정한 상황을 프로세서에게 알리는 것으로 자식프로세서의 종료를 운영체제로 부터 전달받는다 
    - fork를 사용해서 멀티프로세스를 사용 (어제한거) 

- 함수 포인터 ppt-36
    - 함수 호출이 되면 함수를 찾아가야하는데 이를 찾을때는 함수의 이름(함수포인터)을 찾는다
    - 함수를 저장할때도 (함수)포인터를 사용한다 
    
- 시그널 and 시그널 액션  ppt-37
    - wait를 사용하거나 시그널 또는 시그액션을 사용 
    - 시그액션을 많이사용하는 편이다 


- 멀티 프로세
    - 모든 프로세서는 자신만의 메모리 공간을 확보하여 사용한다.
    - 따라서 프로세서간 데이터 전달은 불가능하다.
        → 운영체제가 별도의 메모리공간(pipe)을 마련하여 프로세서간 통신을 지원한다.
    
    - 멀티프로세서의 단점
    - 프로세서의 빈번한 생성으로 성능저하가 발생하고
    - 멀티 프로세서의 흐름 구현이 쉽지 않다.
    - 또한 프로세서간 통신이 필요한 경우는 구현이 더 복잡 해진다

- 멀티 플레싱 ppt-39 (selet.c)
    - 멀티 프로세서의 단점을 보안
    
    하나의 프로세서로 다수의 클라이언트에게 서비스를 제공한다. 
    그러면 하나의 프로세서가 여러 개의 소켓을 핸들링해야 한다.
    이것이 IO 멀티 플렉싱이다.
    (하나의 프로세서가 서버 소켓 + 여러 클라이언트 소켓을 관리)
    
    - select : select함수는 다웃의 파일 디스크립트 등록하여 읽기/쓰기/오류에 대한 이벤트 발생 여부를 관찰한다.
        - 간단한 멀티 플레싱으로 
        - 다양한 운영체제에서 사용가능
        - FD수가 많으면 느림 FD개수 제한 매번 fd_set초기화 필요

## 5일차 
- IO 멀티플레싱  ppt-41

    - poll : select보다 유연하고 구조체 배열로 처리(FD수 제한 없음)
        - 구조체 배열로 처리 하기떄문에 FD(파일디스크립트)의 제한이 없음
        1. fds[]에 server socket를 등록하고 읽기 이벤트가 발생하면 client socket을 생성한다.
        2. cliet socket을 등록하고 읽기이벤트가 발생한다면 데이터를 read한다 
        - poll의 상수 
            POLLIN  읽기 가능			POLLOUT  쓰기 가능,  
            POLLET  엣지 트리거 모드		POLLERR  에러 발생,  
            POLLUP  연결 끊김			POLLRDHUP  peer가 FIN 전송

        ```C
        struct pollfd{
            int fd;     // file descriptor
            short events;   // requested events(관찰할 이벤트) 이벤트 설정같은 느낌이고 
            short revents;  // returned events(실제발생한 이벤트) 이벤트 실행같은거라고 생각하면 됨
        }
        ```
    
    - epoll 
        - 리눅스에 고성능 네트워크 서버 구현에 사용되는 이벤트 기반 멀티 플렉싱 서버로 성능과 확장성 우수(대규모접합)
        - 상태변환 확인에서 반복문이 필요없다

        - epoll의 상수 
            EPOLLIN  읽기 가능			EPOLLOUT  쓰기 가능,  
            EPOLLET  엣지 트리거 모드		EPOLLERR  에러 발생,  
            EPOLLUP  연결 끊김			EPOLLRDHUP  peer가 FIN 전송
            
        - Epoll_wait()함수는 관심있는 fd 들에 무슨 일이 일어났는지를 조사한다. 그리고 사건이 일어나면 
        (epoll_event).events[ ] 리스트에 일어난 사건들을 저장한다. 또 동시 접속자수에 상관없이 maxevents
        파라미터로 최대 몇 개까지의 event를 처리할 것인지를 지정해 주고 있다.
        
        - Level-Triggered
            - 읽을게 있으면 계속 이벤트를 발생 
            - 데이터 들어올 때마나 epoll_wait()발생하고 읽을 때 까지 알림을 한다.
            - 디폴트로 생성됨
            
        - Edge-Triggered
            - 상태 변화가 있을 때만 한번 발생
            - 새데이터가 처음 들어올 때 한번만 알림 Read()로 버퍼를 완전히 비우거나 안읽으면 데이터 유실이 일어난다 
            그래서 반듸 루프 + noo-blocking 소켓 + 전체 버퍼 읽기
            - EPOLLET 명시 필요

    - UDP 기반 멀티캐스트 & 브로드 캐스트 
        - 멀티 캐스트 
            - 특정 멀티캐스트 그룹을 대상으로 데이터를 딱 한번 전송한다 
            - 그룹에 속하는 클라이언트는 모두 데이터를 수신한다.
            ex) 같은 네트워크에 있는 모든 장치에게 알림 DHC요청등

        - 브로드캐스트 
            - 동일한 네트워크 내(서브넷)에 존재하는 호느스에게 데이터를 전송하는 방법
            - 데이터 전송의 대상이 호스트가 아닌 네트워크이다.
            ex) 같은 서비스를 구독중인 장치들에게 만 전달한다 IPTV,실시간 스트리밍 서비스, 게임, 모니터링등

## 6일차 

- 코딩테스트 
    평가 : 다음과 같은 webpage 배열을 전송하는 웹서버를 구현하시오.
        클라이언트 인터넷 브라우저로 서버 접속 => http request 형식의 메시지로 서버에 전달 
        => get/post 요청 방식에 따른 서버 동작

    ```c
        char webpale[] = "HTTP/1.1 200 OK\r\n"
                    "Server: Linux Web Server\r\n"
                    "Content-Type: text/html; charset=UTF-8\r\n\r\n"
                    "<!DOCTYPE html>\r\n"
                    "<html><head><title>My Web Page</title>\r\n"
                    "<style>body { background-color: #FFFF00; }</style></head>\r\n"
                    "<body><center><h1>Hello world!!</h1><br>\r\n"
                    "<img src=\"game.jpg\"></center></body></html>\r\n";
    ```        


