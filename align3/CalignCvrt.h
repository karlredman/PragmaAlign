/* CalignCvrt.h - class that converts structures (you add the convert function)
   
   This class assumes that you are passing it the address of 2 EXACT structures that 
   are packed with different boundries.  The easiest way (it seams) to declare the structures
   is through the use of namespaces that use internal packing.

                                                       -ksr
 */

#include "align.h"		/* contains the definitions for
				   alignment class structures */

//specify type for conversion and declare class
template<class ParentType, class Type>
class CalignCvrt:public ParentType {
  
 public:

  //constructor
//      CalignCvrt();
  //constructor overload - gets address and type of structure from user
//      CalignCvrt(){};

//  ~CalignCvrt();
  
 private:
  
  //variables
      

  //overloadable conversion function
      int convert(Type *pIn, Type *pOut);
};

//template<class ParentType>
int cvrtNto2(alignN::mystruct *pIn, align2::mystruct *pOut);
//int cvrtNto2(alignN::anotherstruct *pIn, align::anotherstruct *pOut);





