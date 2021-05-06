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


