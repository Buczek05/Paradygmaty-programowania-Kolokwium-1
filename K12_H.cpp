/* Dane studenta                                                    */

#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <math.h>
#include <stdlib.h>
#include <locale.h>
#pragma warning (disable: 4996)
#define  _CRT_SECURE_NO_WARNINGS
//#pragma GCC diagnostic ignored "-Wwrite-strings"
// https://www.robmiles.com/journal/2020/12/29/strings-and-c-warnings



int cis_pac_min[][16] = { 
/*  ciœn. SBP  0*/{   120, 125, 124, 132,   115, 135, 121, 142,   140, 135, 141, 129,  115, 151, 142, 122 }, 
/*  ciœn. DBP  1*/{    80,  75,  77,  83,   84,  79,  78,  83,    89,  77,  78,  81,   70,  77,  83,  83 }, 
/*  czas       2a*/{    15,  30,  45,  60,   15,  30,  45,  60,  15,  30,  45,  60,    15,  30,  45,  60 }, 
// idx czasu //2b {     0,   1,   2,   3,    1,   2    3,   0,    2,   3,   0,   1,     3,   0    1,   2 },
/* idx pacjent 3*/{     0,   1,   2,   3,    1,   2,   3,   0,    2,   3,   0,   1,     3,  0,  1,   2 }
};
/* https://www.omnicalculator.com/pl/zdrowie/srednie-cisnienie-tetnicze#co-to-jest-srednie-cisnienie-t
etnicze
  MAP = 1/3 • SBP + 2/3 • DBP
  MAP to œrednie ciœnienie têtnicze (ang. mean arterial pressure),
 SBP to skurczowe ciœnienie krwi (ang. systolic blood pressure), a
 DBP to rozkurczowe ciœnienie krwi (ang. diastolic blood pressure).
*/
// tutaj zdefiniuj tablicê nazwisk pacjentów :  Abacki,Babacki, Cabacki, Dadacki

// UWAGA  Uproszczenie na ni¿sz¹ ocenê - niezalecane 
// dana tablica dane_wynik_b w celu wykonania daszej czêsci zadania
int wynik_b[][4] = { //  UWAGA zastosowanie tej tablicy bardzo ogranicza zaliczenie 
// i obni¿a ostateczn¹ ocenê
      {    93,      101,       99,      102},
      {    94,       91,      102,       97},
      {   105,       97,       92,       95},
      {    84,       96,       92,       99}
};
int main(int argc, char* argv[])
{setlocale(LC_CTYPE, "Polish");
	printf("¯yczê pomyœlnoœci-H\n");
	system("pause"); exit(1);
}

