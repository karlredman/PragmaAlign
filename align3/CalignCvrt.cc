/* CalignCvrt.cc - class deffinition to convert a structure type from one alignment
   to another.
   */

#include "CalignCvrt.h"

// constructor
//     none

//an overloaded function
template<class ParentType, class Type>
int CalignCvrt<ParentType, Type>::convert(Type *pIn, Type *pOut)
{
  cvrtNto2(pIn, pOut);
  
  return 0;
};

//template<class ParentType>
int cvrtNto2(alignN::mystruct *pIn, align2::mystruct *pOut)
{
  // there is an embedded structure - copy addresses for another call
  alignN::mystruct *In = pIn;
  align2::mystruct *Out = pOut;

  pOut->c1 = pIn->c1; Out += sizeof(pOut->c1); In += sizeof(pIn->c1);
  pOut->li = pIn->li; Out += sizeof(pOut->li); In += sizeof(pIn->li);
  pOut->si = pIn->si; Out += sizeof(pOut->si); In += sizeof(pIn->si);
  pOut->c2 = pIn->c2; Out += sizeof(pOut->c2); In += sizeof(pIn->c2);
  
  cvrtNto2( (alignN::anotherstruct *)&In->as, (align2::anotherstruct *)&Out->as);
 
  return 0;
}

int cvrtNto2(alignN::anotherstruct *pIn, align2::anotherstruct *pOut)
{
  pOut->si = pIn->si; 
  pOut->li = pOut->li;

  //figure out char aray copies

  //figure out char * copies

}
