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
typedef struct _MYSTRUCT {
  char		c1;		/* single byte */
  short         si;
  char		c2;
  long		li;		/* assured to crash on 4byte alignment */
} mystruct;

#endif /* end - #ifndef _ALIGN_H */















