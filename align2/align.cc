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

#include "structMap.h"

//Global no packing - sets namespace/class stuff to nopacking
#define INCL_NOPACKING 1

class align2 {
public:
#pragma pack(2)			// 2 byte alignment

#include "align.h"		// include structures
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

  printf("\n");

  // sizes of structures
  printf("Sizeof aN = %u, a2 = %u\n\n", sizeof(*aN), sizeof(*a2));

  // setup native struture elements' contents
  aN->c1 = 'x';
  aN->si = 0xff;
  aN->c2 = 'y';
  aN->li = 0xffff;

  short sAr[] = {0x1234};

  short s = 0;

  s = SVAL(sAr, 0);
  printf("s = %x, SVAL returned : %x\n", sAr[0], s);
  
  s = ISVAL(sAr, 0);
  printf("s = %x, ISVAL returned : %x\n", sAr[0], s);

  // free vars 
  delete aN; delete a2;
  printf("\n");
  return(0);
}
  



///////// function that looks up types, for conversion
int lookupfunc(char *buffer, int buffSize, int func, int db)
{
  //array for type lookup
  int *Ttable[][] = new _TYPETABLE;
  int *Tarray = null;

  //lookup structure type in table (table of db# and function code)
  Tarray = Ttable[func][db];

  int *tmpBuffer = Nbuffer;

  convertType(Nbuffer, sizeof(Nbuffer),Obuffer, buffsize, Tarray, sizeof(Tarray));

  if(!error)
    buffer = Nbuffer;

  delete Ttable;

} //end lookupfunc


int _TYPETABLE[][]  {
  {0, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, f12, f13, f14, f15, f16, f17, f18, f19, f20, f21, f22},
  {db1,s_MYSTRUCT,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {db2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {db3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {db4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {db5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {db6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {db7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {db8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {db9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,s_ANOTHERSTRUCT},
  {db10,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {db11,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {db12,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {db13,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {db14,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {db15,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {db16,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {db17,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {db18,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {db19,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {db20,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {db21,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {db22,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {db23,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {db24,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {db25,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {db26,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {db27,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {db28,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {db29,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {db30,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
  } //end Ttable[][]


INT X[][]={
  {i, us, l, c, q},
  {1, 1,  1, 32, 1}
};

INT Q[][]={
  {i, s, c, l, c},
  {1, 1, 1, 1,24}
};





int convertType(char *Nbuffer, int NbufferSize, char *Obuffer, int buffsize, int *Tarray, TarraySize, 
		int oAlign, int Nalign);
{
  int error = 0;
  int *tArray = NULL;
  char *p = Nbuffer;

  for( int i = 0;(error == 0) && (i < TarraySize); i++)
    {
      Nbuffer = align_offset(char *Np, char Nbuffer, Nalign);

      switch (T.type)
	{
	case sNone:
	  //do nothing
	  break;
	case sChar:
	  memcpy(Np, Op, T.size);
	  Np += ( sizeof(char) * T.size );
	  break;
	case sCharP:
	  memcpy(Np, Op, sizeof(char *));
	  Np += sizeof(char *);
	  Op = align_offset(char *Op, char Obuffer, Oalign);
	  break;
	case sShort:
	  memcpy(Np, Op, sizeof(short));
	  Np += sizeof(short);
	  Op = align_offset(char *Op, char Obuffer, Oalign);
	  break;
	case sShortP:
	  memcpy(Np, Op, sizeof(short *));
	  Np += sizeof(short *);
	  Op = align_offset(char *Op, char Obuffer, Oalign);
	  break;
	case sInt:
	  memcpy(Np, Op, sizeof(int));
	  Np += sizeof(int);
	  Op = align_offset(char *Op, char Obuffer, Oalign);
	  break;
	case sIntP:
	  memcpy(Np, Op, sizeof(int *));
	  Np += sizeof(int *);
	  Op = align_offset(char *Op, char Obuffer, Oalign);
	  break;
	case sLong:
	  memcpy(Np, Op, sizeof(long));
	  Np += sizeof(long);
	  Op = align_offset(char *Op, char Obuffer, Oalign);
	  break;
	case sLongP:
	  memcpy(Np, Op, sizeof(long *));
	  Np += sizeof(long *);
	  Op = align_offset(char *Op, char Obuffer, Oalign);
	  break;
	case s_MYSTRUCT:
	  tArray = new int[] = m_MYSTRUCT;
	  convertType(Np, sizeof(Nbuffer-offset),Op, buffsize-offset, tarray, sizeof(Tarray));
	  delete tarray;
	  break;
	case s_ANOTHERSTRUCT:
	  tArray = new int[] = m_ANOTHERSTRUCT;
	  convertType(Np, sizeof(Nbuffer-offset),Op, buffsize-offset, tarray, sizeof(Tarray));
	  delete tarray;
	  break;
	default:
	  error = -1;
	  break;
	} //end switch type
    }
      
  if(tArray)
    delete tArray;
  
  return(error);
} //end convertType

