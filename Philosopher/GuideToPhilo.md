# Mandatory Part

너는 하나의 프로그램을 위해서 보너스와 필수 파트에 대해서 다음의 기본 룰을 지켜야한다.

- 이 프로젝트는 C이고 놈체크, 릭, 비정상 행동은 0점을 의미한다.
- 하나 또는 그 이상의 필로소퍼가 둥근 책상에서 3가지 행동중 하나를 한다.
	- Thinking, Eating, Sleeping
- 필로소퍼는 커다란 스파게티가 놓인 둥근 책상에 앉아있다.
- 테이블 위에는 몇몇 포크가 있다.
- 스파게티가 단일 포크로 먹기 힘들기에, 필로소퍼들은 반드시 양손에 포크를 2개 쥐고있다고 가정한다.
- 필로소퍼는 굶어서는 안된다.
- 모든 필로소퍼는 먹을 필요가 있다.
- 필로소퍼는 얘기하지 않는다.
- 필로소퍼는 다른 필로소퍼들이 죽을지 모른다.
- 필로소퍼가 다 먹으면, 그는 포크를 놓고 잠에 빠진다.
- 필로소퍼가 잠에서 깨어나면, 그는 생각한다.
- 이 시뮬레이션은 필로소퍼가 죽을때까지 진행된다.
- 각 프로그램은 같은 옵션을 가진다.
	1. number_of_philosophers
		필로소퍼의 수이자 포크의 수이다.
	2. time_to_die
		밀리세컨드로서, 만약 필로소퍼가 시뮬레이션의 시작 또는 그의 마지막 식사 이후로 먹는 것을 시작하지 않은지 'time_to_die'가 지나면, 죽는다.
	3. time_to_eat
		밀리세컨드이고 필로소퍼가 먹는데 걸리는 시간이다. 그 시간동안 그는 두개의 포크를 유지해야한다.
	4. time_to_sleep
		밀리세컨드이고 필로소퍼가 자는데 사용하는 시간이다.
	5. [number_of_times_each_philosopher_must_eat]
		이 옵션은 선택적이고, 필로소퍼가 최소한 이 횟수만큼 먹으면 시뮬레이션은 종료된다. 만약 정의되어있지 않으면, 시뮬레이션은 필로소퍼의 죽음으로만 해결된다.
- 각 필로소퍼는 반드시 1 이상이 주어져야 한다.
- 필로소퍼 1번은 필로소퍼의 수 옆에 있다. 다른 필로소퍼 N은 N-1과 N+1 옆에 있다.
- 필로소퍼의 상태 변화는 반드시 출력되어야 한다.(X는 필로소퍼의 넘버와 timestamp_in_ms는 밀리세컨드로 현재 타임 스탬프가 찍혀야 한다.)
	- timestamp_in_ms X has taken a fork
	- timestamp_in_ms X is eating
	- timestamp_in_ms X is sleeping
	- timestamp_in_ms X is thinking
	- timestamp_in_ms X died
- 상태는 다른 필로소퍼의 상태와 섞여서 출력되어서는 안된다.(atomic하게)
- 너는 필로소퍼의 죽음과 그것의 출력에 10ms 이상의 시간을 가져서는 안된다.
- 필로소퍼는 죽음을 회피해야 한다.

# 프로그램 설명

## 프로그램 이름
philo
## 제출 폴더
philo/
## 메이크 파일
필요
## 어규먼트
number_of_philosophers time_to_die time_to_eat
time_to_sleep [number_of_times_each_philosopher_must_eat]
## 외부 함수
memset, printf, malloc, free, write,
usleep, gettimeofday,
pthread_create, pthread_detach, pthread_join,
pthread_mutex_init, pthread_mutex_destroy, pthread_mutext_lock, pthread_mutext_unlock
## 맆엪
비허용
## 설명
뮤텍스와 스레드를 가진 필로소퍼
## 룰
- 필로소퍼 사이에 하나의 포크가 있고, 그러므로 만약 그들이 다수의 필로소퍼이면, 포크가 필로소퍼의 양쪽에 존재한다.
- 필로소퍼가 포크를 동시에 소유하는 것을 방지하기 위해서, 너는 포크 상태를 뮤텍스로 방어해야한다.
- 각 필로소퍼는 스레드다.

# 보너스 프로그램

## 프로그램 이름
philo_bonus
## 제출 폴더
philo_bonus/
## 메이크 파일
필요
## 어규먼트
number_of_philosophers time_to_die time_to_eat
time_to_sleep [number_of_times_each_philosopher_must_eat]
## 외부 함수
memset, printf, malloc, free, write,
usleep, gettimeofday,
watipid, fork, kill, exit,
pthread_create, pthread_detach, pthread_join,
sem_open, sem_close, sem_post, sem_wait, sem_unlink
## 맆엪
비허용
## 설명
세마포와 프로세스를 가진 필로소퍼
## 룰
- 포크는 식탁의 중앙에 있다.
- 그들은 메모리 상에서는 상태를 가지지 않지만 포크의 가용숫자는 세마포어로 표현된다.
- 각 필로소퍼들은 프로세스이고 메인 프로세스는 필로소퍼가 아니다.

# 외부함수 가이드
## gettimeofday

### 함수 원형
`int gettimeofdy(struct timeval *restrict tv, struct timezone *restrict tz);`
### 설명

함수 **gettimeofday()**와 **settimeofday()**는 타임존과 같이 시간을 설정하고 얻을 수 있다.

*tv* 어규먼트는 *struct timeval*이고 *<sys/time.h>*에 정의되어 있다.

```c
struct timeval {
	time_t		tv_sec; /* seconds */
	suseconds_t	tv_usec; /* microseconds */
}
```

그리고 에포크 이후에 세컨드와 마이크로 세컨드를 제공한다.

*tz* 아규먼트는 *struct timezone*이다.

```c
struct timezone {
	int tz_minuteswest;	/* minutes west of Greewich */
	int tz_dsttime; /* type of DST coreection */
}
```

만약 *tv* 또는 *tz*가 NULL이면, 다음 구조는 셋되거나 리턴되지 않는다.

*timezone* 구조의 사용은 필수적이지 않다. *tz* 아규먼트는 보통 NULL이다.

리눅스에서,