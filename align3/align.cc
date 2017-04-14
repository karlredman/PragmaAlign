/*
  alignment.cc : 
  An excersize and test in byte packed buffer conversion to 
  and from a native boundry using named types, namespaces, a table and a
  type conversion class.
*/

//posix
#define POSIX_SOURCE 1		// we're posix complient

//standard headers
#include <stdio.h>
#include <assert.h>

//local headers
#include "structMap.h"		// structure macros and maps
#include "CalignCvrt.h"		// struct conversion class
#include "align.h"		// the namespace types for the structures

int doWork(void *Lmystruct, int buffsize, int db, int function);

int pack(char *buffer, int buffsize, int db, int function);
int unpack(char *buffer, int buffsize, int db, int function);

int getDataType(int db, int function);
int convertNto2(char *buffer, int buffSize, int dType);
int convert2toN(char *buffer, int buffSize, int dType);

int main()
{
  //test instantiation

  // dynamic struct with inherited class
  //  CalignCvrt<align2>::mystruct *p = new CalignCvrt<align2>::mystruct;
  CalignCvrt<align2, align2::mystruct>::mystruct *p = new CalignCvrt<align2, align2::mystruct>::mystruct;
  assert(p);
  delete(p);

  //test reference
  alignN::mystruct *aN = new alignN::mystruct; // dynamic Natural struct
  align2::mystruct *a2 = new align2::mystruct; // dynamic 2byte aligned struct

  //assert pounters if not valid
  assert(aN);
  assert(a2);

  //delete pointers
  delete aN;
  delete a2;


  //test casting and functionality

  alignN::mystruct Lmystruct;	// local native struct
  
  //int error = doWork( (void *)&Lmystruct, sizeof(Lmystruct), 0, 0);
  
  return 0;
  }


int doWork(void *buffer, int buffSize, int db, int function)
  {
    int error = 0;
    
    // prepare data
    //.......

    //pack buffer and compress packet
    if( (error = pack( (char *)buffer, buffSize, db, function)) )
      return error;

    //Xmit packet
    //...............

    //recv packet
    //..............

    //decompress packet and unpack buffer 
    error = unpack( (char *)buffer, buffSize, db, function);

    return error;
  }


int pack( char *buffer, int buffSize, int db, int function)
{
  int error = 0;

  //lookup db number and function code - figure out defined type
  int dType = getDataType(db, function);

  //convert buffer from native packing to 2byte backing
  if( (error = convertNto2(buffer, buffSize, dType)) )
    return error;
  
  return error;
}

int unpack( char *buffer, int buffSize, int db, int function)
{
  int error = 0;
  
  //lookup db number and function code - figure out defined type
  int dType = getDataType(db, function);

  //convert buffer from 2byte to native packing
  if( (error = convert2toN(buffer, buffSize, dType)) )
    return error;
  
  return error;
}

#define ALIGN_TYPE_NOT_SUPPORTED 0x0001


int convertNto2(char *buffer, int buffSize, int dType)
{
  //convert a native structure to a 2 byte structure
  switch(dType)
    {
    case s_MYSTRUCT:
      {
	CalignCvrt<align2, align2::mystruct>::mystruct *p = new CalignCvrt<align2, align2::mystruct>::mystruct; 
	delete p;
      }
    break;
    default:
      return ALIGN_TYPE_NOT_SUPPORTED;
    }
  return 0;
}


int convert2toN(char *buffer, int buffSize, int dType)
{
  //convert a 2byte structure to a native structure
    switch(dType)
    {
      case s_MYSTRUCT:
	{
	  CalignCvrt<alignN, alignN::mystruct>::mystruct *p = new CalignCvrt<alignN, alignN::mystruct>::mystruct;
	  delete p;
	}
      break;
          default:
            return ALIGN_TYPE_NOT_SUPPORTED;
    }
  return 0;
}

int getDataType(int db, int function)
{
  //lookup data type in table
  return s_MYSTRUCT;
}

//template<class aType>
//convert(aType *)
//{}
