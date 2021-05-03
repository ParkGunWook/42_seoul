# 소개

C 프로그래밍은 standard functions에 접근할 수 없을때 매우 지루하다. 이 프로젝트는 이러한 함수들을 재작성하고 이해할 기회를 준다. 이 라이브러리는 너의 미래의 C프로젝트에 도움을 줄 것이다.

이 프로젝트를 통해서 우리는 또한 너의 함수의 리스트를 확장할 기회를 준다. 1년동안 쓸 함수 잘 만들기를 바란다.

# 기초 준수사항

- 너의 프로젝트는 Norm에 맞추어서 작성되어야한다. 만약 너가 추가적인 파일/함수를 가지면, 그들은 놈 체크에 포함되고 *norm error*가 포함되면 0점을 받을 것이다.

- 너의 함수는 정의되지 않은 행동으로 인한 의도되지 않게 종료되어서는 안된다.(세그 폴트, 버스 에러, 더블 프리) 만약 이런 것들이 일어나면, 너의 프로젝트는 *non functional*로 0점을 받게 될 것이다.

- 메모리 공간에 할당된 모든 힙들은 필요할때 적절하게 해제되어야한다. 어떠한 리크도 허용되지 않는다.

- 만약 과제가 그것을 필요하면, 너는 반드시 너의 소스파일을 컴파일하는 **Makefile**을 제출해야한다. 그리고 flag들은 -Wall, -Wextra, -Werror로 컴파일될 것이다. 그리고 너의 **Makefile**은 반드시 relink되어서는 안된다.

- 너의 메이크파일은 반드시 $(NAME), all, clean, flcean, re를 포함해야한다.

- 너의 프로젝트에서 보너스를 받고싶으면, 너는 반드시 너의 **Makefile**에 **bounus**를 포함해야하고, 다양한 헤더, 라이브러리, 또는 함수를 위한 것들이 포함되어야한다. 보너스들은 다른 파일인 `_bonus.{c/h}.`에 포함되어야한다. 의무와 보너스 파트는 개별적으로 채점될 것이다.

- 만약 너의 프로젝트가 `libft`를 사용하게 하면, 너는 반드시 그것의 소스를 복사하고 그것의 관련된 `libft` 폴더내의 `Makefile`을 복사해야한다. 너의 프로젝트의 **Makefile**은 반드시 그것의 **Makefile**을 사용해서 만들어져야하고, 그후에 프로젝트는 컴파일 될 것이다.

- 우리는 너가 이 작업이 **제출 되지 않고 채점되지 않는다해도** 반드시 테스트 프로그램을 만들도록 장려한다. 그것은 너에게 너의 작업과 동료의 작업이 쉽게 채점될 찬스를 준다. 너는 너의 디펜스동안에 이것이 특히 유용하다는 것을 알 수 있다. 실제로, 디펜스 동안에, 너는 너의 테스트와 동료의 테스트를 사용하는 것이 자유이다.

- 너의 작업을 너에게 할당된 깃 레포에 제출해라. 깃 레포에 있는 작업만이 채점될 것이다. 만약 **Deepthought**가 너의 작업에 할당되면, 그것은 너의 동료 평가 이후일 것이다. 만약 에러가 너의 작업의 일부분 어딘가에서 일어나면, 채점은 중단될 것이다.

# 의무 과제
|  |  |
| - | - |
| 프로그램명 | libft.a |
| 제출 파일 | *.c, libft.h, Makefile |
| Makefilie | YES |
| External functs. | 곧 나옴 |
| Libft authorized | Non-applicable |
| Description | 너의 전용 라이브러리를 작성하고, 너의 curcus를 위한 중요한 함수의 정수를 포함한다. |

## 기술적 고려사항

- 전역 변수는 금지되어 있다.
- 만약 너가 복잡한 함수를 위해서 서브 함수가 필요하면, 너는 반드시 이런 서브 함수를 너의 라이브러리에 포함되지 않도록 **static**으로 정의해야한다. 그것은 너의 미래의 프로젝트에도 도움이 될 것이다.
- 너의 레포의 루트에 모든 파일을 제출해라.
- 모든 .c파일은 flags로 컴파일되어야한다.
- 너는 반드시 **ar** 커맨드를 이용해서 너의 라이브러리를 만들어야한다. **libtool**을 사용하는 것은 금지되어 있다.

## Libc functions

첫번째 파트에서, 너는 **libc** 함수의 세트를 재 코드 해야하고, 그들의 man에 정의를 따른다. 너의 함수는 같은 프로토타입을 가질 필요가 있고 원작과 같이 작동해야한다. 너의 함수의 이름은 반드시 "ft_"를 접두사로 가져야한다. 예를 들어서 **strlen**은 **ft_strlen**이 될 것이다.

> 너가 re-code해야하는 몇몇 함수의 프로토타입은 "restrict" qualifier를 사용해야한다. 이 키워드는 c99 스탠다드의 일부이다. 그것은 그러므로 너의 프로토타입에 포함되도록 금지되어야하고 그것을 컴파일 하기 위해서는 -str=c99 플래그를 사용해야한다.

너는 다음 함수들을 다시 짜야한다. 이런 함수는 외부 함수가 전혀 필요하지 않다.
|  |  |
| - | - |
| memset | strrchr |
| bzero | strnstr |
| memcpy | strncmp |
| memccpy | atoi |
| memmove | isalpha |
| memchr | isdigit |
| memcpm | isalnum |
| strlen | isascii |
| strlcpy | isprint |
| strlcat | toupper |
| strchr | tolower |
| calloc(malloc allowed) | strdup(malloc allowed) |

## 추가 함수

두번째 파트에서, 너는 반드시 libc에는 포함되지 않고 다른 형태의 함수의 집합을 코드해야한다. 이런 함수의 몇몇은 첫번째 파트의 함수를 사용하는 것이 유용할 것이다.

|  |  |
| - | - |
| 함수 이름 | ft_substr |
| 프로토 타입 | `char *ft_substr(char const *s, unsigned int start, size_t len);` |
| Turn in files | - |
| Parameters | #1. 서브스트링으로 생성될 스트링 |
| | #2. 스트링 's'안의 서브스트링의 시작 인덱스 |
| | #3. 서브 스트링의 최대 길이 |
| 리턴 값 | 서브스트링, 할당이 실패하면 NULL |
| 외부 함수 | malloc |
| 설명 | 스트링 s로 부터 서브스트링을 할당(malloc(3))하고 리턴한다.
| | 서브 스트링은 인덱스 'start'에서 시작하고 최대 길이는 'len'이다. |


| | |
| - | - |
| 함수 이름 | ft_strjoin |
| 프로토 타입 | `char *ft_strjoin(char const *s1, char const *s2);` |
| Turn in files | - |
| Parmeters | #1. The prefix string. |
| | #2. The suffix string. |
| 리턴 값 | 새로운 스트링, 할당이 실패하면 NULL |
| 외부 함수 | malloc |
| 설명 | 's1'과 's2'를 이은 결과인 새로운 스트링을 할당하고 리턴한다. |

| | |
| - | - |
| 함수 이름 | ft_strtrim |
| 프로토 타입 | `char *ft_strtrim(char const *s1, char const *set);` |
| Turn in files | - |
| Parameters | #1. The string to be trimmed. |
| | #2. The reference set of charaters to trim. |
| 리턴 값 | 잘린 스트링. 만약 할당이 실패하면 NULL |
| 외부 함수 | malloc |
| 설명 | 스트링의 시작과 끝으로 부터 'set'에서 정의된 것들을 제거한 's1'의 카피를 할당하고 리턴한다. |

| | |
| - | - |
| 함수 이름 | ft_split |
| 프로토타입 | `char **ft_split(char const *s, char c);` |
| Turn in files | - |
| Parameters | #1. The string to be split. |
| | #2. The delimeter character. |
| 리턴 값 | 스플릿으로부터 결과된 새로운 스트링의 행렬. 할당 실패시 NULL |
| 외부 함수 | malloc, free |
| 설명 | delimter인 캐릭터 'c'를 사용해서 's'로 분할된 스트링의 행렬을 리턴한다. 그 행렬은 반드시 NULL 포인터로 종료되어야 한다. |

| | |
| - | - |
| 함수 이름 | ft_itoa |
| 프로토타입 | `char *ft_itoa(int n);` |
| Turn in files | - |
| Parameters | #1 . 변환될 정수 |
| 리턴 값 | 정수를 표현하는 스트링. 할당 실패시 NULL |
| 외부 함수 | malloc |
| 설명 | argument로 받은 정수를 표현하는 스트링을 리턴한다. 음수는 반드시 처리되어야한다. |

| | |
| - | - |
| 함수 이름 | ft_strmapi |
| 프로토타입 | `char *ft_strmapi(char const *s, char (*f)(unisgned int, char)); |
| Turn in files | - |
| Parameters | #1. The string on which to iterate. |
| | #2. The function to apply to each character. |
| 리턴 값 | 'f'의 연속적인 기능으로부터 생성된 문자열. 할당 실패시 NULL |
| 외부 함수 | malloc |
| 설명 | 연속된 기능 함수 'f'로부터 생성된 새로운 스트링 |

| | |
| - | - |
| 함수 이름 | ft_putchar_fd |
| 프로토타입 | `void ft_putchar_ft(char c, int fd);` |
| Turn in files | - |
| Parameters | #1. The character to output |
| | #2. The file descriptor on which to write |
| 리턴 값 | None |
| 외부 함수 | write |
| 설명 | Outputs the character 'c' to the given file descriptor |

| | |
| - | - |
| 함수 이름 | ft_putstr_fd |
| 프로토타입 | `void ft_putstr_fd(char *s, int fd);` |
| Turn in files | - |
| Parameters | #1. The string to output. |
| | #2. The file descriptor on which to write. |
| 리턴 값 | None  |
| 외부 함수 | write |
| 설명 | Outputs the string 's' to the given file descriptor |

| | |
| - | - |
| 함수 이름 | ft_putendl_fd |
| 프로토타입 | `void ft_putendl_fd(char *s, int fd);` |
| Turn in files | - |
| Parameters | #1. The string to output. |
| | #2. The file descriptor on which to write. |
| 리턴 값 | None |
| 외부 함수 | write |
| 설명 | Outputs the string 's' to the given file descriptor, followed by a newline |

| | |
| - | - |
| 함수 이름 | ft_putnbr_fd |
| 프로토타입 | `void ft_putnbr_fd(int n, int fd);` |
| Turn in files | - |
| Parameters | #1. The integer to output |
| | #2. The file descriptor on which to write. |
| 리턴 값 | None |
| 외부 함수 | write |
| 설명 | Outputs the integer 'n' to the give file descriptor |

## Bounus part

만약 너가 의무 과제를 성공적으로 완료했으면, 너는 추가로 작업을 할 수 있다. 너는 보너스 포인트의 마지막 섹션을 보면 된다.

메모리와 스트링을 조절하는 것은, 그러나 너는 리스트로 관리하는 것이 더욱 쉽다는 것을 알 수 있다.

너는 너의 리스트에 다음과 같이 요소를 만들어야한다. 이 구조는 반드시 너의 `libft.h` 파일에 추가되어야한다.

`make bonus`가 보너스 함수를 `libft.a`라이브러리에 추가할 것이다.

너는 `_bonus`를 `.c` 파일과 헤더에 추가할 필요가 없다. 오직 **_bonus**를 너의 보너스 함수?? 머선말이고

```c
typedef struct  s_list
{
    void            *content;
    struct  s_list  *next;
}               t_list;
```

| | |
| - | - |
| 함수 이름 | ft_lstnew |
| 프로토타입 | `t_list *ft_lstnew(void *content);` |
| Turn in files | - |
| Parameters | #1. The content to create the new element with. |
| 리턴 값 | The new element |
| 외부 함수 | malloc |
| 설명 | 새로운 요소를 할당하고 리턴한다. 변수 'content'는 파라미터 'content'의 값으로 초기화 된다. 변수 'next'는 NULL로 초기화된다. |

| | |
| - | - |
| 함수 이름 | ft_lstadd_front |
| 프로토타입 | `void ft_lstadd_front(t_list **lst, t_list *new);` |
| Turn in files | - |
| Parameters | #1. The address of a pointer to the first link of a list |
| | #2. The address of a pointer to the element to be added to the list. |
| 리턴 값 | None |
| 외부 함수 | malloc |
| 설명 | Adds the element 'new' at the beginning of the list  |

| | |
| - | - |
| 함수 이름 | ft_lstsize |
| 프로토타입 | `int ft_lstsize(t_list *lst);` |
| Turn in files | - |
| Parameters | #1. The beginning of the list |
| |  |
| 리턴 값 | Length of the list |
| 외부 함수 | malloc |
| 설명 | Counts the number of elements in a list. |

| | |
| - | - |
| 함수 이름 | ft_lstadd_back |
| 프로토타입 | `void ft_lstadd_back(t_list **lst, t_list *new);` |
| Turn in files | - |
| Parameters | #1. The address of a pointer to the first link of a list |
| | #2. The address of a pointer to the element to be added to the list |
| 리턴 값 | None |
| 외부 함수 | malloc |
| 설명 | Adds the element 'new' at the end of the list |

| | |
| - | - |
| 함수 이름 | ft_lstdelone |
| 프로토타입 | `void ft_lstdelone(t_list *lst, void (*del)(void*));` |
| Turn in files | - |
| Parameters | #1. The element to free |
| | #2. The address of the function to delete the contents |
| 리턴 값 | None |
| 외부 함수 | free |
| 설명 | 요소로 파라미터를 받고 파라미터로 주어진 함수 'del'을 이용해서 요소의 컨텐츠의 메모리를 해제하고 요소를 해제한다. 'next'의 메모리는 해제될 필요가 없다. |

| | |
| - | - |
| 함수 이름 | ft_lstclear |
| 프로토타입 | `void ft_lstclear(t_list **lst, void (*del)(void *));` |
| Turn in files | - |
| Parameters | #1. The address of a pointer to an element. |
| | #2. The address of the function used to delete the   |
| 리턴 값 |  |
| 외부 함수 | malloc |
| 설명 | 주어진 요소와 그 요소의 연속된 모든 것들을 삭제한다. 마지막으로, 포인터를 향한 리스트는 NULL로 세팅된다. |

| | |
| - | - |
| 함수 이름 | ft_lstiter |
| 프로토타입 | `void ft_lstiter(t_list *lst, void (*f)(void *));` |
| Turn in files | - |
| Parameters | #1. The address of a pointer to an element |
| | #2. The address of the function used to iterate on the list. |
| | #3. The address of the function used to delete the contents of an element if needed |
| 리턴 값 | The new list. NULL if the allocation fails.  |
| 외부 함수 | malloc, free |
| 설명 | 리스트 'lst'를 반복하고 각 요소에 'f'를 적용한다. 함수 'f'의 연속적인 적용의 결과를 만든다. 'del'함수는 만약 필요하다면 사용한다. |
