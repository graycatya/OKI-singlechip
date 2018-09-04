;; Compile Options : /TM610409 /MS /near /Imain /Iclk /IINTERR~1 /Ikey /Ilcd /Ilcdshow /Imelody /Ircadc /Itemphum /Itimers /IMACROA~1 /Ieternity /ICLKbuzz /SD /Om /W 1 /Fa_output\_obj\ 
;; Version Number  : Ver.3.54.3
;; File Name       : eternity.c

	type (M610409) 
	model small, near
	$$calendar_treat$eternity segment code 2h #0h
	$$date$eternity segment code 2h #0h
	$$time_CLK$eternity segment code 2h #0h
	$$var_mode$eternity segment code 2h #0h
	$$year$eternity segment code 2h #0h
	$$year_judge$eternity segment code 2h #0h
CVERSION 3.54.3
CGLOBAL 01H 03H 0000H "time_CLK" 08H 02H 03H 00H 83H 08H 00H 00H 07H
CGLOBAL 01H 03H 0000H "date" 08H 02H 01H 00H 83H 16H 00H 00H 01H
CGLOBAL 01H 03H 0000H "var_mode" 08H 02H 04H 00H 83H 04H 00H 00H 07H
CGLOBAL 01H 03H 0000H "year_judge" 08H 02H 05H 00H 80H 08H 00H 00H 02H
CGLOBAL 01H 03H 0000H "calendar_treat" 08H 02H 02H 00H 83H 4eH 00H 00H 01H
CGLOBAL 01H 03H 0000H "year" 08H 02H 00H 00H 81H 04H 00H 00H 01H
CTYPEDEF 0000H 0000H 42H "uint8" 02H 00H 00H
CTYPEDEF 0000H 0000H 42H "DWORD" 02H 00H 02H
CTYPEDEF 0000H 0000H 43H "INT8" 02H 00H 00H
CTYPEDEF 0000H 0000H 42H "uint32" 02H 00H 02H
CTYPEDEF 0000H 0000H 42H "uint16" 02H 00H 01H
CTYPEDEF 0000H 0000H 42H "byte" 02H 00H 00H
CTYPEDEF 0000H 0000H 43H "INT32" 02H 00H 02H
CTYPEDEF 0000H 0000H 43H "INT16" 02H 00H 01H
CTYPEDEF 0000H 0000H 42H "dword" 02H 00H 02H
CTYPEDEF 0000H 0000H 43H "int8" 02H 00H 00H
CTYPEDEF 0000H 0000H 42H "UINT" 02H 00H 01H
CTYPEDEF 0000H 0000H 42H "WORD" 02H 00H 01H
CTYPEDEF 0000H 0000H 43H "int16" 02H 00H 01H
CTYPEDEF 0000H 0000H 43H "int32" 02H 00H 02H
CTYPEDEF 0000H 0000H 42H "UINT8" 02H 00H 00H
CTYPEDEF 0000H 0000H 42H "uint" 02H 00H 01H
CTYPEDEF 0000H 0000H 42H "uchar" 02H 00H 00H
CTYPEDEF 0000H 0000H 42H "UINT16" 02H 00H 01H
CTYPEDEF 0000H 0000H 42H "UINT32" 02H 00H 02H
CTYPEDEF 0000H 0000H 42H "word" 02H 00H 01H
CTYPEDEF 0000H 0000H 42H "BOOL" 02H 00H 00H
CTYPEDEF 0000H 0000H 42H "BYTE" 02H 00H 00H
CFILE 0001H 00000018H "eternity\\eternity.h"
CFILE 0002H 00000025H "MACROA~1\\MacroAndConst.h"
CFILE 0000H 0000006EH "eternity\\eternity.c"

	rseg $$year$eternity
CFUNCTION 0

_year	:
CBLOCK 0 1 10

;; {
CLINEA 0000H 0001H 000AH 0002H 0002H
	push	lr
	push	er8
	mov	er8,	er0
CBLOCK 0 2 10
CRET 0002H
CARGUMENT 47H 0002H 0028H "ye" 02H 00H 01H

;; 	if(ye%400==0 || ye%100!=0 && ye%4==0)
CLINEA 0000H 0001H 000BH 0003H 0027H
	mov	r2,	#090h
	mov	r3,	#01h
	bl	__imodu8sw
	mov	er0,	er0
	beq	_$L2
	mov	er0,	er8
	mov	r2,	#064h
	mov	r3,	#00h
	bl	__imodu8sw
	mov	er0,	er0
	beq	_$L1
	mov	er0,	er8
	mov	er2,	#4 
	bl	__imodu8sw
	mov	er0,	er0
	bne	_$L1
_$L2 :

;; 	  return 366;
CLINEA 0000H 0001H 000CH 0005H 000FH
	mov	r0,	#06eh
CBLOCKEND 0 2 15

;; }  
CLINEA 0000H 0001H 000FH 0002H 0004H
_$L0 :
	mov	r1,	#01h
	pop	er8
	pop	pc

;;  else
CLINEA 0000H 0000H 000DH 0003H 0006H
_$L1 :

;;      return 365;
CLINEA 0000H 0001H 000EH 0007H 0011H
	mov	r0,	#06dh
	bal	_$L0
CBLOCKEND 0 1 15
CFUNCTIONEND 0


	rseg $$date$eternity
CFUNCTION 1

_date	:
CBLOCK 1 1 24

;; { 
CLINEA 0000H 0001H 0018H 0002H 0003H
	push	lr
	bl	__regpushu8sw
	mov	er8,	er0
	mov	er10,	er2
CBLOCK 1 2 24
CRET 000CH
CARGUMENT 47H 0002H 0032H "mon" 02H 00H 01H
CARGUMENT 47H 0002H 0033H "day" 02H 00H 01H
CARGUMENT 43H 0004H 000EH "ye" 02H 00H 02H
CARGUMENT 43H 0002H 0012H "kv" 02H 00H 01H
CARGUMENT 43H 0002H 0014H "da" 07H 03H 00H 01H 0CH 00H 00H 01H
CLOCAL 47H 0002H 002AH 0002H "i" 02H 00H 01H
CLOCAL 4BH 0002H 0000H 0002H "begin" 02H 00H 01H
CLOCAL 4BH 0002H 0000H 0002H "week" 02H 00H 01H

;;        if(mon>1)
CLINEA 0000H 0001H 001BH 0009H 0011H
	cmp	r0,	#01h
	cmpc	r1,	#00h
	bles	_$L13

;;         for(i=0;i<mon-1;i++)  
CLINEA 0000H 0001H 001CH 000EH 0011H
	mov	bp,	#0 

;;         for(i=0;i<mon-1;i++)  
CLINEA 0000H 0000H 001CH 0012H 0019H
	bal	_$L20

;;         for(i=0;i<mon-1;i++)  
CLINEA 0000H 0000H 001CH 001AH 001CH
_$L17 :

;;           ye+=da[kv][i];
CLINEA 0000H 0001H 001DH 000CH 0019H
	mov	er4,	bp
	add	er4,	bp
	l	er0,	18[fp]
	mov	er2,	#24
	bl	__imulu8sw
	l	er2,	20[fp]
	add	er0,	er2
	add	er0,	er4
	l	er0,	[er0]
	mov	r2,	r1
	extbw	er2
	mov	r2,	r3
	mov	er4,	er0
	mov	er6,	er2
	l	er0,	14[fp]
	l	er2,	16[fp]
	add	er0,	er4
	addc	r2,	r6
	addc	r3,	r7
	st	er0,	14[fp]
	st	er2,	16[fp]

;;         for(i=0;i<mon-1;i++)  
CLINEA 0000H 0000H 001CH 001AH 001CH
	add	bp,	#1 

;;         for(i=0;i<mon-1;i++)  
CLINEA 0000H 0000H 001CH 0012H 0019H
_$L20 :
	mov	er0,	er8
	add	er0,	#-1
	cmp	bp,	er0
	blts	_$L17

;;           ye+=da[kv][i];
CLINEA 0000H 0000H 001DH 000CH 0019H
_$L13 :

;;     return week;
CLINEA 0000H 0001H 001FH 0006H 0011H
	mov	er0,	er10
	mov	r2,	r11
	extbw	er2
	mov	r2,	r3
	l	er4,	14[fp]
	l	er6,	16[fp]
	add	er0,	er4
	addc	r2,	r6
	addc	r3,	r7
	push	xr0
	mov	er0,	#7 
	mov	er2,	#0 
	push	xr0
	bl	__lmodu8sw
	add	sp,	#4 
	pop	xr0
CBLOCKEND 1 2 32

;;  } 
CLINEA 0000H 0000H 0020H 0003H 0004H
	b	__regpopu8sw
CBLOCKEND 1 1 32
CFUNCTIONEND 1


	rseg $$time_CLK$eternity
CFUNCTION 3

_time_CLK	:
CBLOCK 3 1 40

;; {
CLINEA 0000H 0001H 0028H 0002H 0002H
	push	lr
	bl	__regpushu8sw
	mov	er10,	er2
	mov	er8,	er0
CBLOCK 3 2 40
CRET 000CH
CARGUMENT 47H 0002H 0034H "day" 04H 03H 00H 00H 01H
CARGUMENT 47H 0002H 0035H "shi" 04H 03H 00H 00H 01H
CARGUMENT 43H 0002H 000EH "fen" 04H 03H 00H 00H 01H
CARGUMENT 43H 0002H 0010H "miao" 04H 03H 00H 00H 01H

;;      if(*miao > 59){ *miao=0; *fen=*fen+1;}
CLINEA 0000H 0001H 0029H 0007H 002CH
	l	bp,	16[fp]
	l	bp,	[bp]
	cmp	r12,	#03bh
	cmpc	r13,	#00h
	bles	_$L22
CBLOCK 3 3 41
	l	bp,	16[fp]
	mov	er0,	#0 
	st	er0,	[bp]
	l	bp,	14[fp]
	l	er0,	[bp]
	add	er0,	#1 
	st	er0,	[bp]
CBLOCKEND 3 3 41
_$L22 :

;;	  if(*fen > 59) { *fen=0; *shi=*shi+1; }
CLINEA 0000H 0001H 002AH 0004H 0029H
	l	bp,	14[fp]
	l	er0,	[bp]
	cmp	r0,	#03bh
	cmpc	r1,	#00h
	bles	_$L24
CBLOCK 3 4 42
	mov	er0,	#0 
	st	er0,	[bp]
	l	er0,	[er10]
	add	er0,	#1 
	st	er0,	[er10]
CBLOCKEND 3 4 42
_$L24 :

;;	  if(*shi > 23) { *shi=0; *day=*day+1; }	
CLINEA 0000H 0001H 002BH 0004H 002AH
	l	er0,	[er10]
	cmp	r0,	#017h
	cmpc	r1,	#00h
	bles	_$L26
CBLOCK 3 5 43
	mov	bp,	#0 
	st	bp,	[er10]
	l	er0,	[er8]
	add	er0,	#1 
	st	er0,	[er8]
CBLOCKEND 3 5 43
_$L26 :
CBLOCKEND 3 2 44

;; }
CLINEA 0000H 0001H 002CH 0002H 0002H
	b	__regpopu8sw
CBLOCKEND 3 1 44
CFUNCTIONEND 3


	rseg $$var_mode$eternity
CFUNCTION 4

_var_mode	:
CBLOCK 4 1 53

;; {
CLINEA 0000H 0001H 0035H 0002H 0002H
	push	lr
	bl	__regpushu8sw
	mov	er8,	er0
CBLOCK 4 2 53
CRET 000CH
CARGUMENT 47H 0002H 0034H "variate" 04H 03H 00H 00H 01H
CARGUMENT 47H 0002H 0031H "often_MAX" 02H 00H 01H
CARGUMENT 43H 0002H 000EH "often_MIN" 02H 00H 01H

;; 	*variate=*variate+1;
CLINEA 0000H 0001H 0036H 0003H 0016H
	l	er0,	[er0]
	add	er0,	#1 
	st	er0,	[er8]

;;	 if(*variate>often_MAX) 
CLINEA 0000H 0001H 0037H 0003H 0019H
	cmp	er0,	er2
	bles	_$L29

;;	  *variate = often_MIN;
CLINEA 0000H 0001H 0038H 0004H 0018H
	l	er2,	14[fp]
	st	er2,	[er8]
_$L29 :
CBLOCKEND 4 2 57

;; } 
CLINEA 0000H 0001H 0039H 0002H 0003H
	b	__regpopu8sw
CBLOCKEND 4 1 57
CFUNCTIONEND 4


	rseg $$year_judge$eternity
CFUNCTION 5

_year_judge	:
CBLOCK 5 1 65

;;   {
CLINEA 0000H 0001H 0041H 0004H 0004H
	push	xr8
	push	xr4
	mov	er8,	er0
	mov	er10,	er2
CBLOCK 5 2 65
CARGUMENT 47H 0002H 0028H "yea" 02H 00H 01H
CARGUMENT 47H 0002H 0029H "ye_z" 04H 03H 00H 00H 01H
CLOCAL 47H 0004H 2726H 0002H "zhi" 02H 00H 02H

;; 	 long int zhi=0;
CLINEA 0000H 0001H 0042H 0004H 0012H
	mov	er4,	#0 
	mov	er6,	#0 

;; 	  if(yea >= 2000 && yea < 2010) {zhi = 730119; *ye_z=2000;}
CLINEA 0000H 0001H 0043H 0005H 003DH
	cmp	r0,	#0d0h
	cmpc	r1,	#07h
	blts	_$L32
	cmp	r0,	#0dah
	cmpc	r1,	#07h
	bges	_$L32
CBLOCK 5 3 67
	mov	r0,	#07h
	mov	r1,	#024h
	mov	er4,	er0
	mov	er6,	#11
	mov	r2,	#0d0h
	mov	r3,	#07h
	st	er2,	[er10]
CBLOCKEND 5 3 67
_$L32 :

;; 	  if(yea >= 2010 && yea < 2020) {zhi = 733772; *ye_z=2010;}
CLINEA 0000H 0001H 0044H 0005H 003DH
	cmp	r8,	#0dah
	cmpc	r9,	#07h
	blts	_$L39
	cmp	r8,	#0e4h
	cmpc	r9,	#07h
	bges	_$L39
CBLOCK 5 4 68
	mov	r0,	#04ch
	mov	r1,	#032h
	mov	er4,	er0
	mov	er6,	#11
	mov	r2,	#0dah
	mov	r3,	#07h
	st	er2,	[er10]
CBLOCKEND 5 4 68
_$L39 :

;; 	  if(yea >= 2020 && yea < 2030) {zhi = 737424; *ye_z=2020;}
CLINEA 0000H 0001H 0045H 0005H 003DH
	cmp	r8,	#0e4h
	cmpc	r9,	#07h
	blts	_$L46
	cmp	r8,	#0eeh
	cmpc	r9,	#07h
	bges	_$L46
CBLOCK 5 5 69
	mov	r0,	#090h
	mov	r1,	#040h
	mov	er4,	er0
	mov	er6,	#11
	mov	r2,	#0e4h
	mov	r3,	#07h
	st	er2,	[er10]
CBLOCKEND 5 5 69
_$L46 :

;; 	  if(yea >= 2030 && yea < 2040) {zhi = 741077; *ye_z=2030;}
CLINEA 0000H 0001H 0046H 0005H 003DH
	cmp	r8,	#0eeh
	cmpc	r9,	#07h
	blts	_$L53
	cmp	r8,	#0f8h
	cmpc	r9,	#07h
	bges	_$L53
CBLOCK 5 6 70
	mov	r0,	#0d5h
	mov	r1,	#04eh
	mov	er4,	er0
	mov	er6,	#11
	mov	r2,	#0eeh
	mov	r3,	#07h
	st	er2,	[er10]
CBLOCKEND 5 6 70
_$L53 :

;; 	  if(yea >= 2040 && yea < 2050) {zhi = 744729; *ye_z=2040;}
CLINEA 0000H 0001H 0047H 0005H 003DH
	cmp	r8,	#0f8h
	cmpc	r9,	#07h
	blts	_$L60
	cmp	r8,	#02h
	cmpc	r9,	#08h
	bges	_$L60
CBLOCK 5 7 71
	mov	r0,	#019h
	mov	r1,	#05dh
	mov	er4,	er0
	mov	er6,	#11
	mov	r2,	#0f8h
	mov	r3,	#07h
	st	er2,	[er10]
CBLOCKEND 5 7 71
_$L60 :

;; 	  if(yea >= 2050 && yea < 2060) {zhi = 748382; *ye_z=2050;}
CLINEA 0000H 0001H 0048H 0005H 003DH
	cmp	r8,	#02h
	cmpc	r9,	#08h
	blts	_$L67
	cmp	r8,	#0ch
	cmpc	r9,	#08h
	bges	_$L67
CBLOCK 5 8 72
	mov	r0,	#05eh
	mov	r1,	#06bh
	mov	er4,	er0
	mov	er6,	#11
	mov	r2,	#02h
	mov	r3,	#08h
	st	er2,	[er10]
CBLOCKEND 5 8 72
_$L67 :

;; 	  if(yea >= 2060 && yea < 2070) {zhi = 752034; *ye_z=2060;}
CLINEA 0000H 0001H 0049H 0005H 003DH
	cmp	r8,	#0ch
	cmpc	r9,	#08h
	blts	_$L74
	cmp	r8,	#016h
	cmpc	r9,	#08h
	bges	_$L74
CBLOCK 5 9 73
	mov	r0,	#0a2h
	mov	r1,	#079h
	mov	er4,	er0
	mov	er6,	#11
	mov	r2,	#0ch
	mov	r3,	#08h
	st	er2,	[er10]
CBLOCKEND 5 9 73
_$L74 :

;; 	  if(yea >= 2070 && yea < 2080) {zhi = 755687; *ye_z=2070;}
CLINEA 0000H 0001H 004AH 0005H 003DH
	cmp	r8,	#016h
	cmpc	r9,	#08h
	blts	_$L81
	cmp	r8,	#020h
	cmpc	r9,	#08h
	bges	_$L81
CBLOCK 5 10 74
	mov	r0,	#0e7h
	mov	r1,	#087h
	mov	er4,	er0
	mov	er6,	#11
	mov	r2,	#016h
	mov	r3,	#08h
	st	er2,	[er10]
CBLOCKEND 5 10 74
_$L81 :

;; 	  if(yea >= 2080 && yea < 2090) {zhi = 759339; *ye_z=2080;}
CLINEA 0000H 0001H 004BH 0005H 003DH
	cmp	r8,	#020h
	cmpc	r9,	#08h
	blts	_$L88
	cmp	r8,	#02ah
	cmpc	r9,	#08h
	bges	_$L88
CBLOCK 5 11 75
	mov	r0,	#02bh
	mov	r1,	#096h
	mov	er4,	er0
	mov	er6,	#11
	mov	r2,	#020h
	mov	r3,	#08h
	st	er2,	[er10]
CBLOCKEND 5 11 75
_$L88 :

;; 	  if(yea >= 2090 && yea <= 2099){zhi = 762992; *ye_z=2090;}
CLINEA 0000H 0001H 004CH 0005H 003DH
	cmp	r8,	#02ah
	cmpc	r9,	#08h
	blts	_$L95
	cmp	r8,	#033h
	cmpc	r9,	#08h
	bgts	_$L95
CBLOCK 5 12 76
	mov	r0,	#070h
	mov	r1,	#0a4h
	mov	er4,	er0
	mov	er6,	#11
	mov	r2,	#02ah
	mov	r3,	#08h
	st	er2,	[er10]
CBLOCKEND 5 12 76
_$L95 :

;; 	  return zhi;
CLINEA 0000H 0001H 004DH 0005H 000FH
	mov	er0,	er4
	mov	er2,	er6
CBLOCKEND 5 2 78

;;   } 
CLINEA 0000H 0000H 004EH 0004H 0005H
	pop	xr4
	pop	xr8
	rt
CBLOCKEND 5 1 78
CFUNCTIONEND 5


	rseg $$calendar_treat$eternity
CFUNCTION 2

_calendar_treat	:
CBLOCK 2 1 86

;;  {
CLINEA 0000H 0001H 0056H 0003H 0003H
	push	lr
	bl	__regpushu8sw
	add	sp,	#-056
	mov	er8,	er0
	mov	er10,	er2
CBLOCK 2 2 86
CRET 0044H
CARGUMENT 47H 0002H 0032H "yea" 04H 03H 00H 00H 01H
CARGUMENT 47H 0002H 0033H "moon" 04H 03H 00H 00H 01H
CARGUMENT 43H 0002H 000EH "dayet" 04H 03H 00H 00H 01H
CARGUMENT 43H 0002H 0010H "mode" 02H 00H 01H
CLOCAL 47H 0002H 002AH 0002H "i" 02H 00H 01H
CLOCAL 4BH 0002H 0000H 0002H "j" 02H 00H 01H
CLOCAL 43H 0002H 0038H 0002H "r_p" 02H 00H 01H
CLOCAL 47H 0002H 0024H 0002H "week" 02H 00H 01H
CLOCAL 43H 0002H 0032H 0002H "ye_x" 02H 00H 01H
CLOCAL 43H 0004H 0036H 0002H "sum" 02H 00H 02H
CLOCAL 43H 0030H 0030H 0002H "days" 08H 01H 02H 00H 01H 0CH 00H 00H 01H

;;    int days[2][12]={{31,28,31,30,31,30,31,31,30,31,30,31},
CLINEA 0000H 0001H 0059H 0005H 003BH
	mov	er0,	#31
	st	er0,	-48[fp]
	mov	er0,	#28
	st	er0,	-46[fp]
	mov	er0,	#31
	st	er0,	-44[fp]
	mov	er0,	#30
	st	er0,	-42[fp]
	mov	er0,	#31
	st	er0,	-40[fp]
	mov	er0,	#30
	st	er0,	-38[fp]
	mov	er0,	#31
	st	er0,	-36[fp]
	st	er0,	-34[fp]
	mov	er0,	#30
	st	er0,	-32[fp]
	mov	er0,	#31
	st	er0,	-30[fp]
	mov	er0,	#30
	st	er0,	-28[fp]
	mov	er0,	#31
	st	er0,	-26[fp]

;;   	 {31,29,31,30,31,30,31,31,30,31,30,31}};
CLINEA 0000H 0001H 005AH 0006H 002CH
	st	er0,	-24[fp]
	mov	er0,	#29
	st	er0,	-22[fp]
	mov	er0,	#31
	st	er0,	-20[fp]
	mov	er0,	#30
	st	er0,	-18[fp]
	mov	er0,	#31
	st	er0,	-16[fp]
	mov	er0,	#30
	st	er0,	-14[fp]
	mov	er0,	#31
	st	er0,	-12[fp]
	st	er0,	-10[fp]
	mov	er0,	#30
	st	er0,	-8[fp]
	mov	er0,	#31
	st	er0,	-6[fp]
	mov	er0,	#30
	st	er0,	-4[fp]
	mov	er0,	#31
	st	er0,	-2[fp]

;;     sum= year_judge(*yea, &ye_x);
CLINEA 0000H 0000H 005BH 0006H 0022H
	mov	er2,	fp
	add	er2,	#-50
	l	er0,	[er8]
	bl	_year_judge
	st	er0,	-54[fp]
	st	er2,	-52[fp]

;;    if(year(*yea)==366) r_p=1;
CLINEA 0000H 0001H 005CH 0005H 001EH
	l	er0,	[er8]
	bl	_year
	cmp	r0,	#06eh
	cmpc	r1,	#01h
	bne	_$L103
	mov	er0,	#1 

;;	 else  r_p=0; 
CLINEA 0000H 0001H 005DH 0003H 000FH
	bal	_$L105
_$L103 :
	mov	er0,	#0 
_$L105 :
	st	er0,	-56[fp]

;;   if(mode == 0)
CLINEA 0000H 0001H 005EH 0004H 0010H
	l	er0,	16[fp]
	bne	_$L106
CBLOCK 2 3 95

;;     if(*dayet>days[r_p][*moon-1]){ *dayet=1; *moon=*moon+1;} 
CLINEA 0000H 0001H 0060H 0006H 003EH
	l	er0,	-56[fp]
	mov	er2,	#24
	bl	__imulu8sw
	mov	bp,	er0
	add	bp,	fp
	l	er0,	[er10]
	add	er0,	er0
	add	bp,	er0
	l	er0,	14[fp]
	l	er0,	[er0]
	l	er2,	-50[bp]
	cmp	er0,	er2
	bles	_$L108
CBLOCK 2 4 96
	l	bp,	14[fp]
	mov	er0,	#1 
	st	er0,	[bp]
	l	er0,	[er10]
	add	er0,	#1 
	st	er0,	[er10]
CBLOCKEND 2 4 96
_$L108 :

;;     if(*moon>12){ *moon=1; *yea=*yea+1; }
CLINEA 0000H 0001H 0061H 0006H 002AH
	l	er0,	[er10]
	cmp	r0,	#0ch
	cmpc	r1,	#00h
	bles	_$L110
CBLOCK 2 5 97
	mov	er2,	#1 
	st	er2,	[er10]
	l	er0,	[er8]
	add	er0,	#1 
	st	er0,	[er8]
CBLOCKEND 2 5 97
_$L110 :

;;     if(*yea>2099)*yea=2000;	  	
CLINEA 0000H 0001H 0062H 0006H 0020H
	l	er0,	[er8]
	cmp	r0,	#033h
	cmpc	r1,	#08h
	bles	_$L121
	mov	r2,	#0d0h
	mov	r3,	#07h
	st	er2,	[er8]

;;    else if(mode == 1)
CLINEA 0000H 0001H 0064H 0005H 0016H
	bal	_$L121
_$L106 :
	cmp	r0,	#01h
	cmpc	r1,	#00h
	bne	_$L121
CBLOCK 2 6 101

;;     if(*yea>2099){*yea=2000; ye_x=2000; }	
CLINEA 0000H 0001H 0066H 0006H 002BH
	l	er0,	[er8]
	cmp	r0,	#033h
	cmpc	r1,	#08h
	bles	_$L117
CBLOCK 2 7 102
	mov	r2,	#0d0h
	mov	r3,	#07h
	st	er2,	[er8]
	mov	r0,	#0d0h
	mov	r1,	#07h
	st	er0,	-50[fp]
CBLOCKEND 2 7 102
_$L117 :

;;     if(*moon>12)*moon=1;
CLINEA 0000H 0001H 0067H 0006H 0019H
	l	er0,	[er10]
	cmp	r0,	#0ch
	cmpc	r1,	#00h
	bles	_$L119
	mov	er2,	#1 
	st	er2,	[er10]
_$L119 :

;;	 if(*dayet>days[r_p][*moon-1])*dayet=1;    	
CLINEA 0000H 0001H 0068H 0003H 002DH
	l	er0,	-56[fp]
	mov	er2,	#24
	bl	__imulu8sw
	mov	bp,	er0
	add	bp,	fp
	l	er0,	[er10]
	add	er0,	er0
	add	bp,	er0
	l	er0,	14[fp]
	l	er0,	[er0]
	l	er2,	-50[bp]
	cmp	er0,	er2
	bles	_$L121
	l	bp,	14[fp]
	mov	er0,	#1 
	st	er0,	[bp]
_$L121 :
CBLOCKEND 2 6 105

;;	for(i=ye_x;i<*yea;i++)  //*从2000年开始 
CLINEA 0000H 0001H 006AH 0006H 000CH
	l	bp,	-50[fp]
CBLOCKEND 2 3 110

;;	for(i=ye_x;i<*yea;i++)  //*从2000年开始 
CLINEA 0000H 0000H 006AH 000DH 0013H
	bal	_$L128

;;	for(i=ye_x;i<*yea;i++)  //*从2000年开始 
CLINEA 0000H 0000H 006AH 0014H 0016H
_$L125 :

;;      sum+=year(i);		
CLINEA 0000H 0001H 006BH 0007H 0015H
	mov	er0,	bp
	bl	_year
	mov	r2,	r1
	extbw	er2
	mov	r2,	r3
	mov	er4,	er0
	mov	er6,	er2
	l	er0,	-54[fp]
	l	er2,	-52[fp]
	add	er0,	er4
	addc	r2,	r6
	addc	r3,	r7
	st	er0,	-54[fp]
	st	er2,	-52[fp]

;;	for(i=ye_x;i<*yea;i++)  //*从2000年开始 
CLINEA 0000H 0000H 006AH 0014H 0016H
	add	bp,	#1 

;;	for(i=ye_x;i<*yea;i++)  //*从2000年开始 
CLINEA 0000H 0000H 006AH 000DH 0013H
_$L128 :
	l	er0,	[er8]
	cmp	bp,	er0
	blts	_$L125

;;    week=date(*moon, *dayet, sum, r_p, days);
CLINEA 0000H 0000H 006CH 0005H 002DH
	mov	er0,	fp
	add	er0,	#-48
	push	er0
	l	er0,	-56[fp]
	push	er0
	l	er0,	-54[fp]
	l	er2,	-52[fp]
	push	xr0
	l	bp,	14[fp]
	l	er2,	[bp]
	l	er0,	[er10]
	bl	_date
	add	sp,	#8 

;;    return week;
CLINEA 0000H 0001H 006DH 0005H 0010H
CBLOCKEND 2 2 110

;;   } 
CLINEA 0000H 0000H 006EH 0004H 0005H
	b	__regpopu8sw
CBLOCKEND 2 1 110
CFUNCTIONEND 2

	public _time_CLK
	public _date
	public _var_mode
	public _year_judge
	public _calendar_treat
	public _year
	extrn code near : _main
	extrn code : __imulu8sw
	extrn code : __imodu8sw
	extrn code : __lmodu8sw
	extrn code : __regpushu8sw
	extrn code : __regpopu8sw

	end
