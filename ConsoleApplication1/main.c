#include <stdio.h>
#include <stdlib.h>
#include "userheader.h"


/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int main(int argc, char* argv[]) {

	printLine("Test Line Start", true);

	int x = 5, y = 10;
	int intArr[] = { 10, 100, 200 };
	int i, * p, ** pp, sizeOfElement, sizeOfArray;
	char isFileCreat = 0;
	char fileName[50] = "people.txt";

	// type      |   1byte     | 2byte     | 4byte            |  8byte 
	// ---------------------------------------------------------------------
	//           |   char     | short     | int   %d, %u      |  double      %f, %lf
	//               %c, %d     %hd, %hu  | long  %ld, %lu    |  long long   %lld, %llu
	//                                    | float %f

	p = &x;
	pp = &p;
	printf("x's' address : %x\n", (unsigned int) & x);
	printf("p's  address : %x\n", (unsigned int)p);
	printf("p's  size    : %d\n", (unsigned int)sizeof(p));
	printf("  *p's value : %d\n", *p);
	printf("**pp's value : %d\n", **pp);

	p = intArr;

	sizeOfElement = sizeof(int);
	sizeOfArray = sizeof(intArr) / sizeof(int);

	if (sizeof(intArr) > 0) {
		printf("\n----------------\n");
		printf("sizeof(int)              : %d\n", sizeOfElement);
		printf("sizeof(intArr)           : %d\n", (unsigned int)sizeof(intArr));
		printf("intArr[]'s element number: %d\n", sizeOfArray);
	}

	for (i = 0; i < sizeOfArray; i++) {
		printf("\n----------------\n");
		printf("intArr[%d]'s address: %x\n", (unsigned int)i, (unsigned int)p);
		printf("intArr[%d]'s value  : %d\n", i, *p);
		p++;
	}

	// ex: getArray()
	printLine("Test getArray()", true);
	printf("\n");
	p = NULL;
	p = getArray();
	printf("sizeof(p) = %d\n", (unsigned int)sizeof(p));

	// ex: getAvg(p);
	printLine("Test getAvg(p)", true);
	printf("avg = getAvg(p)\n");
	printf("avg = %f\n", getAvg(p));

	printf("\n\n----------------\n");
	printf("Before swap: x: %2d, y:%2d\n", x, y);
	swap(&x, &y);
	printf(" After swap: x: %2d, y:%2d\n", x, y);


	printLine("Test showArry", true);
	showArry();

	printf("\n\n----------------\n");
	printf("Do you want to create a file (y/n)? ");
	scanf_s("%c", &isFileCreat, 1);

	if (isFileCreat == 'y' || isFileCreat == 'Y') {
		// get fileName from user
		printf("File name to create (default: people.txt): ");
		scanf_s("%s", fileName, (unsigned int)sizeof(fileName));

		// fileName should not be empty with the default value, "people.txt"
		if (fileName[0] == '\0') {
			strcpy_s(fileName, sizeof(fileName), "people.txt");
		}

		int return_ = showStructEx(fileName);
		if (return_ != 0) {
			printf("Error occured !\n");
			return 1;
		}
	}
	else {
		printf("File creation skipped.\n");
	}


	printLine("Test Bit Field", true);
	printf("===========================\n");
	printf("status1 memory is     = %d\n", (unsigned int)sizeof(status1));  // 8 bytes
	printf("status2 memory is     = %d\n", (unsigned int)sizeof(status2));  // 4 bytes

	printf("===========================\n");
	printf("UINT16 memory is      = %d\n", (unsigned int)sizeof(UINT16));
	printf("byte memory is        = %d\n", (unsigned int)sizeof(byte));
	printf("bit  memory is        = %d\n", (unsigned int)sizeof(bit));
	printf("USBCREGFlag memory is = %d\n", (unsigned int)sizeof(USBCREGFlag));

	printLine("Test Line End", true);

	return 0;
}