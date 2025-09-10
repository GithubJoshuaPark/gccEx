#pragma once
#ifndef USERHEADER_H
#define USERHEADER_H

#include <stdbool.h>
#include <stdint.h> // Added to define UINT16

typedef uint16_t UINT16; // Define UINT16 as an alias for uint16_t

struct Book {
int book_id;
char title[50];
char author[50];
char subject[100];
};

struct Status1 {
	unsigned int a;  // 4 bytes
	unsigned int b;  // 4 bytes
	unsigned int c;  // 4 bytes
	unsigned int d;  // 4 bytes
	unsigned int e;  // 4 bytes
	unsigned int f;  // 4 bytes
	unsigned int g;  // 4 bytes
	unsigned int h;  // 4 bytes
} status1;

struct Status2 {
	unsigned int a : 1; // 
	unsigned int b : 1;
	unsigned int c : 1;
	unsigned int d : 1;
	unsigned int e : 1;
	unsigned int f : 1;
	unsigned int g : 1;
	unsigned int h : 1;
} status2;

struct Byte {
	UINT16 HiByte : 8;
	UINT16 LoByte : 8;
} byte;

struct Bit {
	UINT16 VAUXLow : 1;
	UINT16 VAUXoverCUR : 1;
	UINT16 CAN5VThShutdown : 1;
	UINT16 CAN5VUV : 1;
	UINT16 CAN5VOC : 1;
	UINT16 VSENSELow : 1;
	UINT16 VSUPUV : 1;
	UINT16 IDDOcNorm : 1;

	UINT16 Rvd1: 3;
	UINT16 VDDThShutdown : 1;
	UINT16 Rvd2: 1;
	UINT16 RSTLow : 1;
	UINT16 VSUPBatFail : 1;
	UINT16 IDDOcLp : 1;
} bit;

typedef union {
	UINT16 all;
	struct Bit bit;
	struct Byte byte;
} USBCREGFlag;

void printLine(char* str, bool isLine);
void swap(int* x, int* y);
int* getArray(void);
double getAvg(int* arr);
void showArry(void);
void printAll(struct Book* book, int howMany);
int showStructEx(void);

#endif