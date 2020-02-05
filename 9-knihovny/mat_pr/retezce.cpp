#include "retezce.h"
#include <cstring>
#include <iostream>

void strdel(char *s, int pozice, int pocet) {
  while (s[pozice + pocet] != '\0') {
    s[pozice] = s[pozice + pocet];
    pozice++;
  }
  s[pozice] = '\0';
}

void strins(char *s1, char *s2, int pozice) {
  const int originalniVelikost = strlen(s1);
  const int pocet = strlen(s2);

  // Copy string after original chars were moved
  for (int i = originalniVelikost + pocet - 1; i > pozice + pocet; --i) {
    s1[i] = s1[i - pocet];
    if (i - pocet - pozice >= 0 && i - pocet - pozice <= pocet)
      s1[i - pocet] = s2[i - pocet - pozice - 1];
  }

  //    // Free space for string insertion
  //    for(int i = strlen(s1)+pocet-1; i > pozice; --i){
  //        s1[i] = s1[i-pocet];
  //    }
  //    // Copy insertion string to original from wanted position
  //    for(int i = 0; i < pocet; ++i) {
  //        s1[pozice+i] = s2[i];
  //    }
}
