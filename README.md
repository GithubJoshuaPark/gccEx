# ConsoleApplication1

이 프로젝트는 C/C++(C++14) 기반의 콘솔 애플리케이션 예제입니다.
- 배열
- 포인터 
- 구조체 
- 동적 메모리 할당
- 시간 출력 등 
 
C 언어의 핵심 개념을 실습할 수 있습니다.

--- 

주요 기능

•	시간 출력: 현재 시간을 포함한 메시지 출력 (printLine)

•	배열 및 포인터 실습: 1차원/2차원 배열, 포인터 연산, 배열의 크기와 주소 출력 (showArry, getArray, swap)

•	구조체 활용: 도서(Book) 정보를 입력받아 구조체 배열로 저장 및 출력 (showStructEx, printAll)

•	동적 메모리 할당: 입력받은 개수만큼 구조체 배열을 동적으로 할당

•	기본 함수 구현: swap 등

---

파일 구성

•	main.c : 프로그램 진입점, 주요 함수 호출

•	userHeader.c : 주요 기능 함수 구현

•	userHeader.h : 함수 및 구조체 선언

---

빌드 및 실행 방법

1.	Visual Studio에서 솔루션을 엽니다.
2.	__Ctrl+Shift+B__로 빌드합니다.
3.	__Ctrl+F5__로 실행합니다.

---

실행 예시

```bash

Input how many times input: 2

Enter book detail info
[1]: Book book_id:1
[1]: Book title:Programming in C
[1]: Book author:Dennis Ritchie
[1]: Book subject:Programming

Enter book detail info
[2]: Book book_id:2
[2]: Book title:Data Structures
[2]: Book author:Mark Allen Weiss
[2]: Book subject:CS

======================================
Book Id     : [1]
Book title  : [Programming in C]
Book author : [Dennis Ritchie]
Book subject: [Programming]
======================================
Book Id     : [2]
Book title  : [Data Structures]
Book author : [Mark Allen Weiss]
Book subject: [CS]
======================================

```