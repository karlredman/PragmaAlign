//align.h - structures used to test alignment methodology
//with namespaces

//allow this file to be included more than once
#ifdef  INCL_AGAIN
#undef _ALIGN_H
#endif

#ifndef _ALIGN_H
#define _ALIGN_H 1

/*
  Setup namespaces to represent the same data types using 
  different byte alignment schemes
  */

//Possible compile time option
#ifndef NATURAL_ALIGNMENT
#define NATURAL_ALIGNMENT 4	/* DEFAULT TO FOUR BYTE ALIGNMENT!!! */
#endif

//Global no packing - sets namespace/class stuff to nopacking
#define INCL_NOPACKING 1

class alignN
{
public:
#pragma pack(NATURAL_ALIGNMENT)	//naturally aligned structures are instantiated

#define INCL_AGAIN		// re-include this header
#include "mystructs.h"		//include structures

};

class align2
{
public:
#pragma pack(2)			// 2 byte alignment

#define INCL_AGAIN		// re-include this header
#include "mystructs.h"		// include structures
};


#pragma pack(NATURAL_ALIGNMENT)	/* re-establish natural alignment */

#endif /* end - #ifndef _ALIGN_H */









