typedef struct _As {
long	l1;
long	l2;
long 	l3;
long	l4;
short	s1;
short	s2;
short	s3;
short	s4;
}As; //24B

typedef struct _Bs {
char	c1;
char 	c2;
char 	c3;
char 	c4;
char 	c5;
}Bs; //5B

typedef struct _Cs {
Bs	b;
As	a;
}Cs; //29-32
