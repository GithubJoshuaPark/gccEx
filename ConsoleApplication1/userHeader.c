#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include "userheader.h"

void printLine(char* str, bool isLine) {
	// 현재 시간 가져오기
	time_t t;
	struct tm tm_info; // 구조체를 스택에 선언
	char timeStr[20];   // yyyy-mm-dd hh:mm:ss → 19자리 + '\0'

	time(&t); // 현재 epoch time 가져오기
	if (localtime_s(&tm_info, &t) != 0) {
		perror("localtime_s failed");
		return;
	}
	strftime(timeStr, sizeof(timeStr), "%Y-%m-%d %H:%M:%S", &tm_info);

	if (isLine) {
		printf("\n------------------------------------------------");
	}
	// 시간과 함께 문자열 출력
	printf("\n[%s] %s\n", timeStr, str);
	if (isLine) {
		printf("------------------------------------------------\n");
	}
}

void swap(int* x, int* y) {
	int temp = 0;
	temp = *x;
	*x = *y;
	*y = temp;
}

int* getArray(void) {

	// ! static keyword allows the variable keep alive even out of the function   
	static int arr[3];

	int i;
	for (i = 0; i < 3; i++) {
		arr[i] = i + 10;
		printf("[%d]:arr[%d] = %d, sizeof(arr[%d]): %d\n"
			    ,(unsigned int)&arr[i]
			    , i
			    , arr[i]
			    , i
			    , sizeof(arr[i])
				);
	}
	return arr;
}

double getAvg(int* arr) {
	int i, size_ = 0, sum = 0;
	double avg;

	size_ = (unsigned int)sizeof(arr) / sizeof(int);
	for (i = 0; i < size_; i++) {
		sum += arr[i];
		//sum+= *(arr+i);
	}

	printf("size_ : %d\n", size_);
	printf("sum   : %d\n", sum);
	printf("avg   : %f\n", (double)sum / size_);

	return (double)sum / size_;
}

void showArry(void) {
	int i, j, k, size_ = 0, lenOfA_ = 0, a[][3] = { {0,1,2},{3,4,5} };
	int* p = &a[0][0];

	size_ = sizeof(a);
	lenOfA_ = size_ / sizeof(int);

	// &a;
	// &a+1;
	// a+1;
	// *a;
	// *a+1;
	// **a;

	printLine("Test int a[2][3]", true);
	printf("sizeof(int a[2][3]): %02d bytes\n", size_);
	printf("sizeof(int)        : %02d bytes\n", (unsigned int)sizeof(int));
	printf("length(a[2][3])    : %02d bytes\n", (unsigned int)(size_ / sizeof(int)));

	for (i = 0; i < 2; i++) {
		for (j = 0; j < 3; j++) {
			printf("a[%d][%d] = %d\t address: %p\n", i, j, a[i][j], (void*)&a[i][j]);
		}
	}

	printf("---------------\n");
	for (k = 0; k < lenOfA_; k++) {
		printf("*(p + %d) = %d\t address: %p\n", k, *(p + k), (void*)(p + k));
	}

	printf("a     = %p\n", a);      // 62fd80
	printf("&a    = %p\n", &a);     // 62fd80       

	printf("&a+1  = %p\n", &a + 1); // 62fd98     
	printf("a+1   = %p\n", a + 1);  // 62fd8c  

	printf("*a    = %p\n", *a);     //  6487424
	printf("*a+1  = %p\n", *a + 1); //  6487428

	printf("**a   = %d\n", **a); //   0
}

void printAll(struct Book* book, int howMany) {
	int i;
	printf("======================================\n");

	for (i = 0; i < howMany; i++) {
		printf("Book Id     : [%d]\n", book[i].book_id);
		printf("Book title  : [%s]\n", book[i].title);
		printf("Book author : [%s]\n", book[i].author);
		printf("Book subject: [%s]\n", book[i].subject);
		printf("======================================\n");
	}
}

int showStructEx(void) {
	printLine("showStructEx Start", true);

	int i, howMany;
	struct Book* book;

	printf("Input how many times input: ");
	//scanf("%d", &howMany);
	scanf_s("%d", &howMany);

	book = (struct Book*)malloc(howMany * sizeof(struct Book));
	if (book == NULL) {
		perror("Memory allocation failed !");
		return 1;
	}

	for (i = 0; i < howMany; i++) {
		printf("\nEnter book detail info\n");
		printf("[%d]: Book book_id:", i + 1);
		//scanf("%d", &book[i].book_id);
		scanf_s("%d", &book[i].book_id);

		// 입력 버퍼에 남아있는 모든 문자 제거
		while (getchar() != '\n');

		printf("[%d]: Book title  :", i + 1);
		fgets(book[i].title, sizeof(book[i].title), stdin);
		book[i].title[strcspn(book[i].title, "\n")] = '\0';

		printf("[%d]: Book author :", i + 1);
		fgets(book[i].author, sizeof(book[i].author), stdin);
		book[i].author[strcspn(book[i].author, "\n")] = '\0';

		printf("[%d]: Book subject:", i + 1);
		fgets(book[i].subject, sizeof(book[i].subject), stdin);
		book[i].subject[strcspn(book[i].subject, "\n")] = '\0';
	}

	// print all book[]
	printAll(book, howMany);

	// save the data into file
    FILE* file = fopen("people.txt", "a"); // append 모드로 파일 열기
	if (file == NULL) {
		perror("Error opening file");
		return 1;
	}

	fprintf(file, "==========================\n");
	for (i = 0; i < howMany; i++) {
		fprintf(file, "Book Id     : %d\n", book[i].book_id);
		fprintf(file, "Book title  : %s\n", book[i].title);
		fprintf(file, "Book author : %s\n", book[i].author);
		fprintf(file, "Book subject: %s\n", book[i].subject);
		fprintf(file, "--------------------------\n");
	}

	fclose(file); // close the file
	free(book);   // free the memory

	printLine("showStructEx End", true);
	return 1;
}
