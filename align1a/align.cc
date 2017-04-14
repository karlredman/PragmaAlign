/*
  alignment.cc : 
	structure alignment testing
*/

//posix
#define POSIX_SOURCE 1

//standard headers
#include <stdio.h>
#include <assert.h>
#include "align.h"


int
main() {

  // instantiate vars
	As a;
	Bs b;
	Cs c;

  //do work
  printf("Sizeof a = %u, b = %u, c = %u\n", sizeof(a), sizeof(b), 
		sizeof(c));

  
  return(0);

}
  




