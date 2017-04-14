//align.h - structures used to test alignment methodology
//with namespaces

//allow this file to be included more than once
#ifdef  INCL_AGAIN
	#undef _ALIGN_H
#endif

#ifndef _ALIGN_H
#define _ALIGN_H 1

//demonstrate turning pack 2 off
#ifndef INCL_NOPACKING
#pragma pack(2);
#endif

//structures

typedef struct _ANOTHERSTRUCT {
  long		li;
  short		si;
  char *	psz;
} anotherstruct;

typedef struct _MYSTRUCT {
  char		c1;		/* single byte */
  long		li;	        /*likely to crash on 4byte alignment */
  short         si;
  char		c2;
  anotherstruct as;
} mystruct;


#endif /* end - #ifndef _ALIGN_H */















