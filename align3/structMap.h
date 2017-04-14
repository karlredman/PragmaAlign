//////////////////buffer conversion routines ////////////////////////////////////

//positioning and base macros
#define CVAL(buf, pos) (((unsigned char *) (buf))[pos])
#define PVAL(buf, pos) ((unsigned)CVAL(buf, pos))

//get 2 bytes from buf
#define SVAL(buf, pos) (PVAL(buf,pos) | PVAL(buf, (pos)+1)<<8)

//put 2 bytes into buf
#define SSVAL(buf, pos, val) SSVALX((buf), (pos), ( (uint16)(val) ) )
#define SSVALX(buf, pos, val) (CVAL(buf, pos)=(val)&0xFF, CVAL(buf, pos+1)=(val)>>8)

//little endian routines
#define ISVAL(buf, pos) (*(short *)((char *)(buf) + (pos)))


/////////////// type definitions for table lookups ///////////////////////////////

//structure element type definitions
#define sNone	0x00

				/* common types */
#define sChar	0x01
#define sCharP	0x02
#define sShort	0x03
#define sShortP	0x04
#define sInt	0x05
#define sIntP	0x06
#define sLong	0x07
#define sLongP  0x08

				/* user types */

#define s_MYSTRUCT	0x0100
#define s_ANOTHERSTRUCT 0X0101

