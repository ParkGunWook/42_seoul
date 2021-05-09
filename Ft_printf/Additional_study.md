## About relink

메이크의 주요한 역할은 메이크 파일에 의존이 명세되어있다는 것이다.
```c
FileX: FileA FileB FileC
	Command to make FileX from FileA FileB FileC
```
이러한 의존이 주어졌을 때, 만약 `FileX`의 수정시간보다 `FileA`, `FileB`, `FileC` 중 하나라도 수정시간이 후이면, `make`는 새로운 버전의 `FileX`를 만들 것이다.

일반적인 의존 규칙은 오브젝트 파일이 C 소스 파일과 몇가지 헤더파일에 의존한다는 것을 말한다.
```c
foo.o: foo.c foo.h project.h
	$(CC) -c foo.c
```

실질적인 프로젝트를 위한 메이크파일에서, 파일의 룰과 리스트들은 더욱 복잡한데, 커맨드, 옵션, 파일의 리스트를 나르기 위해서 다양한 심벌을 사용한다.

다른 룰은 오브젝트 파일을 통해서 실행 파일을 만든다.
```c
MyProgram: foo.o bar.o baz.o
	$(LD) -o $@ $^
```

이러한 컨텍스트에서, "relink"는 단지 링크 오브젝트를 다시 실행파일에 링크하는 커맨드를 실행한다고 의미한다. 그것은 하나의 필요한 파일이 타겟파일보다 새롭기 때문에 일어나거나 메이크 파일의 룰이 디펜던시들을 표현하기에 충분히 쓰이지 않았다는 의미이다.

[참고자료](stackoverflow.com/questions/52502399/what-does-it-mean-for-a-makefile-to-relink)

## About floating point.

double 기준 (64비트)
| 역할 | 크기(bits) |
| - | - |
| sign | 1 |
| exponent | 11 |
| Signified precision | 52 |

사인 비트는 넘버의 부호를 결정한다.

지수 부분은 11비트의 부호가 없는 인티저로 0~2047을 표현한다.(바이어스 폼을 취한다.) 1023은 실제로는 0을 의미한다. 지수의 범위는 -1022부터 1023을 표현하는데 -1023(모두 0)과 +1024(모두 1)들은 특별한 숫자를 저장한다.

지수 부분 - 1023을 가수부에 곱하면 된다.

여기서 바이어스 폼이란, 값은 지수 바이어스 만큼 오프셋을 가진다는 것이다. 크고 작은 수를 표현하기 위해서 사용한다. 2의 보수가 사용하기 힘들어서이다.

이 문제를 해결하기 위해서 지수는 부호가 없는 값에 저장되고 바이어스를 뺌으로서 부호를 가진 범위를 갖는다.


53비트 가수부분은 15~17의 significant decimal digit 정밀도를 준다. 만약 최대 15개의 숫자를 가진 데시멀 스트링이 IEEE 754로 전환되면, 다시 같은 숫자로 돌아온다. 마지막 결과는 오리지널 스트링과 일치한다. 만약 IEEE 754 배정밀도 숫자가 최소 17개의 significant digits로 해석되면, 그리고 다시 돌아오면 그 최종결과는 오리지널 숫자와 일치한다.



[floating point bit 계산기](https://www.binaryconvert.com/result_double.html?decimal=048046053)

https://wonsorang.tistory.com/653
