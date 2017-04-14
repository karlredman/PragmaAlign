/*
  alignment.cc : 
  An excersize and test in byte packed buffer conversion to 
  a native boundry using named types and namespaces.
*/

//posix
#define POSIX_SOURCE 1

//standard headers
#include <stdio.h>
#include <assert.h>

/*
  Setup namespaces to represent the same data types using 
  different byte alignment schemes
  */

//Global no packing - sets namespace/class stuff to nopacking
#define INCL_NOPACKING 1

class align2 {
public:
#pragma pack(2)			// 2 byte alignment
  
#include "align.h"		// include structures

//  int  x;			// arbitrary variable
};

class alignN {
public:
#pragma pack(4)			//naturally aligned (use of pragma above without native reset would have set
				// the rest of the source to 2byte alignment)

#define INCL_AGAIN		// re-include this header
#include "align.h"		//include structures
};

int
main() {

  // instantiate vars
  alignN::mystruct *aN = new alignN::mystruct;
  align2::mystruct *a2 = new align2::mystruct;

  assert(aN);
  assert(a2);

  //do work
  printf("Sizeof aN = %u, a2 = %u\n", sizeof(*aN), sizeof(*a2));

  aN->c1 = 'x';
  aN->si = 2;
  aN->c2 = 'y';
  aN->li = 4;

  a2->c1 = 'x';
  a2->si = 2;
  a2->c2 = 'y';
  a2->li = 4;

	printf("\n");
	printf("aN:\n");
	printf("%u\n", &aN->c1);
	printf("%u\n", &aN->si);
	printf("%u\n", &aN->c2);
	printf("%u\n", &aN->li);

	
	printf("\n");
	printf("a2:\n");
	printf("%u\n", &a2->c1);
	printf("%u\n", &a2->si);
	printf("%u\n", &a2->c2);
	printf("%u\n", &a2->li);

  // free vars 
  delete aN; delete a2;
  
  return(0);

}
  




