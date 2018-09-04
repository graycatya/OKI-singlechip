;; Compile Options : /TM610409 /MS /near /Imain /Iclk /IINTERR~1 /Ikey /Ilcd /Ilcdshow /Imelody /Ircadc /Itemphum /Itimers /IMACROA~1 /Ieternity /ICLKbuzz /SD /Om /W 1 /Fa_output\_obj\ 
;; Version Number  : Ver.3.54.3
;; File Name       : temphum.c

	type (M610409) 
	model small, near
	$$C_FCUTOVER$temphum segment code 2h #0h
	$$HUM_A$temphum segment code 2h #0h
	$$HUM_HS$temphum segment code 2h #0h
	$$H_H$temphum segment code 2h #0h
	$$H_T$temphum segment code 2h #0h
	$$TEMP_ZH$temphum segment code 2h #0h
	$$TE_A$temphum segment code 2h #0h
	$$TE_B$temphum segment code 2h #0h
	$$Temp_trade$temphum segment code 2h #0h
CVERSION 3.54.3
CGLOBAL 01H 03H 0000H "Temp_trade" 08H 02H 08H 00H 81H 10H 00H 00H 01H
CGLOBAL 01H 03H 0000H "C_FCUTOVER" 08H 02H 00H 00H 81H 0cH 00H 00H 01H
CGLOBAL 01H 03H 0000H "TE_A" 08H 02H 02H 00H 83H 0eH 00H 00H 01H
CGLOBAL 01H 03H 0000H "TE_B" 08H 02H 03H 00H 83H 0eH 00H 00H 01H
CGLOBAL 01H 03H 0000H "HUM_A" 08H 02H 06H 00H 83H 20H 00H 00H 01H
CGLOBAL 01H 03H 0000H "TEMP_ZH" 08H 02H 01H 00H 81H 02H 00H 00H 01H
CGLOBAL 01H 03H 0000H "H_H" 08H 02H 05H 00H 83H 3cH 00H 00H 01H
CGLOBAL 01H 03H 0000H "H_T" 08H 02H 04H 00H 83H 10H 00H 00H 01H
CGLOBAL 01H 03H 0000H "HUM_HS" 08H 02H 07H 00H 83H 0eH 00H 00H 07H
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
CFILE 0001H 0000001FH "temphum\\temphum.h"
CFILE 0002H 00000025H "MACROA~1\\MacroAndConst.h"
CFILE 0000H 000000C6H "temphum\\temphum.c"

	rseg $$Temp_trade$temphum
CFUNCTION 8

_Temp_trade	:
CBLOCK 8 1 9

;; {
CLINEA 0000H 0001H 0009H 0002H 0002H
	push	lr
	bl	__regpushu8sw
	mov	er8,	er0
CBLOCK 8 2 9
CRET 000CH
CARGUMENT 46H 0002H 0032H "CA_Y" 02H 00H 01H
CARGUMENT 46H 0002H 002FH "CB_Y" 02H 00H 01H
CLOCAL 4BH 0004H 0000H 0002H "zhi" 02H 00H 02H
CLOCAL 47H 0002H 0026H 0002H "sum" 02H 00H 01H

;; 	sum=(zhi*1000)/CA_Y;
CLINEA 0000H 0001H 000DH 0003H 0016H
	mov	er0,	er2
	mov	er2,	#0 
	push	xr0
	mov	r0,	#0e8h
	mov	r1,	#03h
	push	xr0
	bl	__lmulu8sw
	add	sp,	#4 
	pop	xr4
	mov	er0,	er8
	push	qr0
	bl	__ldivu8sw
	add	sp,	#4 
	pop	xr0
	mov	er4,	er0

;; 	if(sum%10 >= 5)sum=sum/10+1;
CLINEA 0000H 0001H 000EH 0003H 001EH
	mov	er2,	#10
	bl	__imodu8sw
	cmp	r0,	#05h
	cmpc	r1,	#00h
	blts	_$L1
	mov	er0,	er4
	mov	er2,	#10
	bl	__idivu8sw
	add	er0,	#1 

;; 	 else sum=sum/10;
CLINEA 0000H 0001H 000FH 0004H 0013H
	bal	_$L3
_$L1 :
	mov	er0,	er4
	mov	er2,	#10
	bl	__idivu8sw
_$L3 :

;;    return sum;
CLINEA 0000H 0001H 0010H 0005H 000FH
CBLOCKEND 8 2 17

;; } 
CLINEA 0000H 0000H 0011H 0002H 0003H
	b	__regpopu8sw
CBLOCKEND 8 1 17
CFUNCTIONEND 8


	rseg $$C_FCUTOVER$temphum
CFUNCTION 0

_C_FCUTOVER	:
CBLOCK 0 1 25

;; {
CLINEA 0000H 0001H 0019H 0002H 0002H
	push	lr
	push	er4
CBLOCK 0 2 25
CRET 0002H
CARGUMENT 47H 0002H 0024H "zhi" 02H 00H 01H
CARGUMENT 47H 0002H 0025H "C_F" 02H 00H 01H
CLOCAL 47H 0002H 0026H 0002H "sum" 02H 00H 01H

;; 	if(C_F==0)
CLINEA 0000H 0001H 001CH 0003H 000CH
	mov	er2,	er2
	bne	_$L5
CBLOCK 0 3 29

;;	   sum=((float)(zhi)*9/50+32)*100;
CLINEA 0000H 0001H 001EH 0005H 0023H
	mov	r2,	r1
	extbw	er2
	mov	r2,	r3
	push	xr0
	bl	__fildu8sw
	mov	er0,	#0 
	mov	r2,	#010h
	mov	r3,	#041h
	push	xr0
	bl	__fmulu8sw
	add	sp,	#4 
	mov	r2,	#048h
	mov	r3,	#042h
	push	xr0
	bl	__fdivu8sw
	add	sp,	#4 
	mov	r2,	#00h
	push	xr0
	bl	__faddu8sw
	add	sp,	#4 
	mov	r2,	#0c8h
	push	xr0
	bl	__fmulu8sw
	add	sp,	#4 
	bl	__ftolu8sw
	pop	er0
	add	sp,	#2 
	mov	er4,	er0

;;	    if(sum%10>=5)sum=sum/10+1;
CLINEA 0000H 0001H 001FH 0006H 001FH
	mov	er2,	#10
	bl	__imodu8sw
	cmp	r0,	#05h
	cmpc	r1,	#00h
	blts	_$L7
	mov	er0,	er4
	mov	er2,	#10
	bl	__idivu8sw
	add	er0,	#1 

;;         else sum=sum/10;
CLINEA 0000H 0001H 0020H 000AH 0019H
	bal	_$L9
_$L7 :
	mov	er0,	er4
	mov	er2,	#10
	bl	__idivu8sw
_$L9 :
CBLOCKEND 0 3 33

;;    else 
CLINEA 0000H 0001H 0022H 0005H 0009H
_$L5 :
CBLOCK 0 4 35

;;      {sum=zhi;}
CLINEA 0000H 0000H 0023H 0007H 0010H
CBLOCKEND 0 4 35
_$L10 :

;;    return sum;
CLINEA 0000H 0001H 0024H 0005H 000FH
CBLOCKEND 0 2 37

;; }
CLINEA 0000H 0000H 0025H 0002H 0002H
	pop	er4
	pop	pc
CBLOCKEND 0 1 37
CFUNCTIONEND 0


	rseg $$TEMP_ZH$temphum
CFUNCTION 1

_TEMP_ZH	:
CBLOCK 1 1 45

;;  {
CLINEA 0000H 0001H 002DH 0003H 0003H
	push	lr
CBLOCK 1 2 45
CRET 0000H
CARGUMENT 47H 0002H 0024H "TE" 02H 00H 01H
CLOCAL 47H 0002H 0024H 0002H "sum" 02H 00H 01H

;;       if(TE == -600)return TE; 
CLINEA 0000H 0001H 002FH 0008H 0020H
	cmp	r0,	#0a8h
	cmpc	r1,	#0fdh
	bne	_$L12
CBLOCKEND 1 2 52

;;  }
CLINEA 0000H 0001H 0034H 0003H 0003H
_$L11 :
	pop	pc

;;       if(TE == -600)return TE; 
CLINEA 0000H 0000H 002FH 0008H 0020H
_$L12 :
	mov	er2,	#10
	bl	__idivu8sw

;;      return sum;
CLINEA 0000H 0001H 0033H 0007H 0011H
	pop	pc
CBLOCKEND 1 1 52
CFUNCTIONEND 1


	rseg $$TE_A$temphum
CFUNCTION 2

_TE_A	:
CBLOCK 2 1 61

;;  {
CLINEA 0000H 0001H 003DH 0003H 0003H
	push	lr
	bl	__regpushu8sw
	mov	er10,	er2
	mov	er8,	er0
CBLOCK 2 2 61
CRET 000CH
CARGUMENT 47H 0002H 0032H "CAI" 02H 00H 01H
CARGUMENT 47H 0002H 0033H "TE" 04H 03H 00H 00H 01H
CARGUMENT 43H 0002H 000EH "CA" 04H 03H 00H 00H 01H
CARGUMENT 43H 0002H 0010H "Ai" 02H 00H 01H
CLOCAL 47H 0002H 0026H 0002H "sum" 02H 00H 01H
CLOCAL 4BH 0002H 0000H 0002H "c" 02H 00H 01H
CLOCAL 4BH 0002H 0000H 0002H "d" 02H 00H 01H

;;     int sum=-600,c=0,d=0;
CLINEA 0000H 0001H 003EH 0006H 001AH
	mov	r4,	#0a8h
	mov	r5,	#0fdh

;;	  if(CAI > TE[Ai] && CAI < TE[Ai+1])
CLINEA 0000H 0000H 003FH 0000H 0000H
	l	er0,	16[fp]
	add	er0,	er0
	mov	bp,	er0

;;	  if(CAI > TE[Ai] && CAI < TE[Ai+1])
CLINEA 0000H 0001H 003FH 0004H 0025H
	add	er0,	er2
	l	er0,	[er0]
	cmp	er8,	er0
	bles	_$L18
	mov	er0,	er2
	add	er0,	bp
	l	er0,	02h[er0]
	cmp	er8,	er0
	bges	_$L18
CBLOCK 2 3 64

;; 		  sum=-(CA[Ai]*(-100)-(d*100)/c);  
CLINEA 0000H 0001H 0043H 0006H 0026H
	mov	er0,	er2
	add	er0,	bp
	l	er4,	02h[er0]
	l	er6,	[er0]
	sub	r4,	r6
	subc	r5,	r7
	add	er4,	#1 
	mov	er0,	er8
	sub	r0,	r6
	subc	r1,	r7
	mov	r2,	#064h
	mov	r3,	#00h
	bl	__imulu8sw
	mov	er2,	er4
	bl	__idivu8sw
	mov	er4,	er0
	mov	er0,	bp
	l	er2,	14[fp]
	add	er0,	er2
	l	er0,	[er0]
	mov	r2,	#09ch
	mov	r3,	#0ffh
	bl	__imulu8sw
	sub	r0,	r4
	subc	r1,	r5
	mov	er2,	#0 
	sub	r2,	r0
	subc	r3,	r1
	mov	er4,	er2

;;	    else if(CAI == TE[Ai])
CLINEA 0000H 0001H 0045H 0006H 001BH
	bal	_$L29
_$L18 :
	mov	er0,	er2
	add	er0,	bp
	l	er0,	[er0]
	cmp	er0,	er8
	bne	_$L26
CBLOCK 2 4 70

;;   			 sum=CA[Ai]*100;
CLINEA 0000H 0001H 0047H 0008H 0016H
	mov	er0,	bp
	l	er2,	14[fp]
	add	er0,	er2
	l	er0,	[er0]
	mov	r2,	#064h
	mov	r3,	#00h
	bl	__imulu8sw
	mov	er4,	er0

;;	    else if(CAI == TE[Ai+1])
CLINEA 0000H 0001H 0049H 0006H 001DH
	bal	_$L29
_$L26 :
	mov	er0,	er10
	add	er0,	bp
	l	er0,	02h[er0]
	cmp	er0,	er8
	bne	_$L29
CBLOCK 2 5 74

;;   			 sum=CA[Ai+1]*100;   
CLINEA 0000H 0001H 004BH 0008H 001BH
	mov	er0,	bp
	l	er2,	14[fp]
	add	er0,	er2
	l	er0,	02h[er0]
	mov	r2,	#064h
	mov	r3,	#00h
	bl	__imulu8sw
	mov	er4,	er0
CBLOCKEND 2 5 76

;;		   }
CLINEA 0000H 0000H 004CH 0006H 0006H
_$L29 :
CBLOCKEND 2 4 78

;;     return sum;
CLINEA 0000H 0001H 004DH 0006H 0010H
	mov	er0,	er4
CBLOCKEND 2 3 78
CBLOCKEND 2 2 78

;;   }
CLINEA 0000H 0000H 004EH 0004H 0004H
	b	__regpopu8sw
CBLOCKEND 2 1 78
CFUNCTIONEND 2


	rseg $$TE_B$temphum
CFUNCTION 3

_TE_B	:
CBLOCK 3 1 86

;; {
CLINEA 0000H 0001H 0056H 0002H 0002H
	push	lr
	bl	__regpushu8sw
	mov	er10,	er2
	mov	er8,	er0
CBLOCK 3 2 86
CRET 000CH
CARGUMENT 47H 0002H 0032H "CAI" 02H 00H 01H
CARGUMENT 47H 0002H 0033H "TE" 04H 03H 00H 00H 01H
CARGUMENT 43H 0002H 000EH "CA" 04H 03H 00H 00H 01H
CARGUMENT 43H 0002H 0010H "Bi" 02H 00H 01H
CLOCAL 47H 0002H 0026H 0002H "sum" 02H 00H 01H
CLOCAL 4BH 0002H 0000H 0002H "c" 02H 00H 01H
CLOCAL 4BH 0002H 0000H 0002H "d" 02H 00H 01H

;; 	int sum=-600,c=0,d=0;
CLINEA 0000H 0001H 0057H 0003H 0017H
	mov	r4,	#0a8h
	mov	r5,	#0fdh

;;       if(CAI > TE[Bi] && CAI < TE[Bi+1])
CLINEA 0000H 0000H 0058H 0000H 0000H
	l	er0,	16[fp]
	add	er0,	er0
	mov	bp,	er0

;;       if(CAI > TE[Bi] && CAI < TE[Bi+1])
CLINEA 0000H 0001H 0058H 0008H 0029H
	add	er0,	er2
	l	er0,	[er0]
	cmp	er8,	er0
	bles	_$L32
	mov	er0,	er2
	add	er0,	bp
	l	er0,	02h[er0]
	cmp	er8,	er0
	bges	_$L32
CBLOCK 3 3 89

;;   			 sum=CA[Bi]*100+(d*100)/c; 
CLINEA 0000H 0001H 005CH 0008H 0021H
	mov	er0,	er2
	add	er0,	bp
	l	er4,	02h[er0]
	l	er6,	[er0]
	sub	r4,	r6
	subc	r5,	r7
	add	er4,	#1 
	mov	er0,	er8
	sub	r0,	r6
	subc	r1,	r7
	mov	r2,	#064h
	mov	r3,	#00h
	bl	__imulu8sw
	mov	er2,	er4
	bl	__idivu8sw
	mov	er4,	er0
	mov	er0,	bp
	l	er2,	14[fp]
	add	er0,	er2
	l	er0,	[er0]
	mov	r2,	#064h
	mov	r3,	#00h
	bl	__imulu8sw
	add	er0,	er4
	mov	er4,	er0

;;		  else if(CAI == TE[Bi])
CLINEA 0000H 0001H 005EH 0005H 001AH
	bal	_$L43
_$L32 :
	mov	er0,	er2
	add	er0,	bp
	l	er0,	[er0]
	cmp	er0,	er8
	bne	_$L40
CBLOCK 3 4 95

;;   			 sum=CA[Bi]*100;
CLINEA 0000H 0001H 0060H 0008H 0016H
	mov	er0,	bp
	l	er2,	14[fp]
	add	er0,	er2
	l	er0,	[er0]
	mov	r2,	#064h
	mov	r3,	#00h
	bl	__imulu8sw
	mov	er4,	er0

;;		  else if(CAI == TE[Bi+1])
CLINEA 0000H 0001H 0062H 0005H 001CH
	bal	_$L43
_$L40 :
	mov	er0,	er10
	add	er0,	bp
	l	er0,	02h[er0]
	cmp	er0,	er8
	bne	_$L43
CBLOCK 3 5 99

;;   			 sum=CA[Bi+1]*100;
CLINEA 0000H 0001H 0064H 0008H 0018H
	mov	er0,	bp
	l	er2,	14[fp]
	add	er0,	er2
	l	er0,	02h[er0]
	mov	r2,	#064h
	mov	r3,	#00h
	bl	__imulu8sw
	mov	er4,	er0
CBLOCKEND 3 5 101

;;   		    }	
CLINEA 0000H 0000H 0065H 000AH 000BH
_$L43 :
CBLOCKEND 3 4 103

;;     return sum; 
CLINEA 0000H 0001H 0066H 0006H 0011H
	mov	er0,	er4
CBLOCKEND 3 3 103
CBLOCKEND 3 2 103

;;   }
CLINEA 0000H 0000H 0067H 0004H 0004H
	b	__regpopu8sw
CBLOCKEND 3 1 103
CFUNCTIONEND 3


	rseg $$H_T$temphum
CFUNCTION 4

_H_T	:
CBLOCK 4 1 113

;; {
CLINEA 0000H 0001H 0071H 0002H 0002H
	push	lr
	bl	__regpushu8sw
	mov	er8,	er0
	mov	er10,	er2
CBLOCK 4 2 113
CRET 000CH
CARGUMENT 47H 0002H 0032H "CAI_Y" 02H 00H 01H
CARGUMENT 47H 0002H 0033H "SHU" 02H 00H 01H
CARGUMENT 43H 0002H 000EH "TEM" 04H 03H 00H 00H 01H
CARGUMENT 43H 0002H 0010H "CA_Z" 04H 03H 00H 00H 01H
CLOCAL 47H 0002H 0026H 0002H "i" 02H 00H 01H
CLOCAL 47H 0002H 0027H 0002H "zhi" 02H 00H 01H

;;	int i=0;
CLINEA 0000H 0001H 0072H 0002H 0009H
	mov	er4,	#0 

;;	int zhi=-600;
CLINEA 0000H 0001H 0073H 0002H 000EH
	mov	r6,	#0a8h
	mov	r7,	#0fdh

;;  for(i=0;i<SHU;i++)
CLINEA 0000H 0001H 0075H 0003H 0014H
	bal	_$L51
_$L48 :
CBLOCK 4 3 118

;;	  	if(i<50)
CLINEA 0000H 0001H 0077H 0005H 000CH
	mov	er0,	er4
	cmp	r4,	#032h
	cmpc	r5,	#00h
	bges	_$L52
CBLOCK 4 4 120

;; 	  		zhi=TE_A(CAI_Y, TEM, CA_Z, i); /*-50-0温度算法*/
CLINEA 0000H 0000H 0079H 0007H 0036H
	push	er4
	l	er0,	16[fp]
	push	er0
	l	er2,	14[fp]
	mov	er0,	er8
	bl	_TE_A
	add	sp,	#4 

;;     	    zhi=TEMP_ZH(zhi);
CLINEA 0000H 0000H 007AH 000BH 001BH
	bl	_TEMP_ZH
	mov	er6,	er0

;; 	  		if(zhi!=-600)break;
CLINEA 0000H 0001H 007BH 0007H 0019H
	cmp	r0,	#0a8h
	cmpc	r1,	#0fdh
	bne	_$L47
_$L54 :
CBLOCKEND 4 3 131
CBLOCKEND 4 4 134

;;  for(i=0;i<SHU;i++)
CLINEA 0000H 0000H 0075H 0003H 0014H
	add	er4,	#1 
_$L51 :
	cmp	er4,	er10
	blts	_$L48

;;      }
CLINEA 0000H 0000H 0083H 0007H 0007H
_$L47 :

;;   	return zhi;  
CLINEA 0000H 0001H 0085H 0005H 0011H
	mov	er0,	er6
CBLOCKEND 4 2 134

;;  }
CLINEA 0000H 0000H 0086H 0003H 0003H
	b	__regpopu8sw

;;  	    else if((i>49 && i<172)) 
CLINEA 0000H 0000H 007DH 0008H 0020H
_$L52 :
	cmp	r0,	#031h
	cmpc	r1,	#00h
	bles	_$L54
	cmp	r0,	#0ach
	cmpc	r1,	#00h
	bges	_$L54

;;   		    zhi=TE_B(CAI_Y, TEM, CA_Z, i); /*0-95温度算法*/
CLINEA 0000H 0000H 007FH 000AH 0038H
	push	er4
	l	er0,	16[fp]
	push	er0
	l	er2,	14[fp]
	mov	er0,	er8
	bl	_TE_B
	add	sp,	#4 

;;            zhi=TEMP_ZH(zhi);
CLINEA 0000H 0000H 0080H 000DH 001DH
	bl	_TEMP_ZH
	mov	er6,	er0

;;		    if(zhi!=-600)break;
CLINEA 0000H 0001H 0081H 0007H 0019H
	cmp	r0,	#0a8h
	cmpc	r1,	#0fdh
	beq	_$L54
	bal	_$L47
CBLOCKEND 4 1 134
CFUNCTIONEND 4


	rseg $$H_H$temphum
CFUNCTION 5

_H_H	:
CBLOCK 5 1 142

;; {
CLINEA 0000H 0001H 008EH 0002H 0002H
	push	lr
	bl	__regpushu8sw
	add	sp,	#-042
	mov	er10,	er2
	mov	er8,	er0
CBLOCK 5 2 142
CRET 0036H
CARGUMENT 47H 0002H 0032H "CAI_Y" 02H 00H 01H
CARGUMENT 47H 0002H 0033H "TEMP" 02H 00H 01H
CARGUMENT 43H 0002H 000EH "SHU" 02H 00H 01H
CARGUMENT 43H 0002H 0010H "HU" 04H 03H 00H 00H 01H
CARGUMENT 43H 0002H 0012H "TE" 04H 03H 00H 00H 01H
CARGUMENT 42H 0002H 0014H "H_CAY" 07H 03H 00H 01H 15H 00H 00H 01H
CLOCAL 47H 0002H 002AH 0002H "zhi" 02H 00H 01H
CLOCAL 47H 0002H 0027H 0002H "i" 02H 00H 01H

;;   int zhi=-600,i;
CLINEA 0000H 0001H 008FH 0004H 0012H
	mov	r12,	#0a8h
	mov	r13,	#0fdh

;;   if(TEMP>=0 && TEMP<=60)
CLINEA 0000H 0001H 0090H 0004H 001AH
	mov	er0,	er2
	bps	_$M7
	b	_$L67
_$M7 :

;;   if(TEMP>=0 && TEMP<=60)
CLINEA 0000H 0000H 0090H 000AH 000DH
	cmp	r2,	#03ch
	cmpc	r3,	#00h
	bles	_$M8
	b	_$L75
_$M8 :

;;     for(i=0; i<SHU; i++)
CLINEA 0000H 0001H 0091H 000AH 000DH
	mov	er6,	#0 

;;     for(i=0; i<SHU; i++)
CLINEA 0000H 0000H 0091H 000FH 0014H
	b	_$L79

;;     for(i=0; i<SHU; i++)
CLINEA 0000H 0000H 0091H 0016H 0018H
_$L76 :
CBLOCK 5 3 146

;;       	if(TEMP==TE[i])zhi=HUM_A(CAI_Y, HU, H_CAY, i);
CLINEA 0000H 0000H 0093H 0000H 0000H
	mov	er0,	er6
	add	er0,	er6
	mov	er4,	er0

;;       	if(TEMP==TE[i])zhi=HUM_A(CAI_Y, HU, H_CAY, i);
CLINEA 0000H 0001H 0093H 0009H 0036H
	l	er2,	18[fp]
	add	er0,	er2
	l	er0,	[er0]
	cmp	er0,	er10
	bne	_$L80
	push	er6
	l	er0,	20[fp]
	push	er0
	l	er2,	16[fp]
	mov	er0,	er8
	bl	_HUM_A
	add	sp,	#4 
	mov	bp,	er0

;;       	 else if(TEMP>TE[i] && TEMP<TE[i+1])
CLINEA 0000H 0001H 0094H 000AH 002CH
	bal	_$L83
_$L80 :
	mov	er0,	er4
	add	er0,	er2
	l	er0,	[er0]
	cmp	er10,	er0
	bles	_$L83
	mov	er0,	er4
	add	er0,	er2
	l	er0,	02h[er0]
	cmp	er10,	er0
	bges	_$L83
CBLOCK 5 4 149
CLOCAL 4BH 0002H 0000H 0004H "X" 02H 00H 01H
CLOCAL 4BH 0002H 0000H 0004H "Y" 02H 00H 01H
CLOCAL 42H 002AH 002AH 0004H "NEW_hum" 08H 01H 01H 00H 01H 15H 00H 00H 01H

;;   	              HUM_HS(Y, H_CAY, NEW_hum, i);
CLINEA 0000H 0001H 009AH 0013H 002FH
	push	er6
	mov	er0,	fp
	add	er0,	#-42
	push	er0
	l	er2,	20[fp]
	mov	er0,	er4
	l	er4,	18[fp]
	add	er0,	er4
	mov	er4,	er0
	mov	er0,	er10
	l	er4,	[er4]
	sub	r0,	r4
	subc	r1,	r5
	mov	er4,	er2
	mov	er2,	#10
	bl	__imulu8sw
	mov	er2,	#4 
	bl	__idivu8sw
	mov	er2,	er4
	bl	_HUM_HS
	add	sp,	#4 

;;   	              zhi=HUM_A(CAI_Y, HU, NEW_hum, 0); 
CLINEA 0000H 0000H 009CH 0013H 0034H
	mov	er0,	#0 
	push	er0
	mov	er0,	fp
	add	er0,	#-42
	push	er0
	l	er2,	16[fp]
	mov	er0,	er8
	bl	_HUM_A
	add	sp,	#4 
	mov	bp,	er0
CBLOCKEND 5 4 157

;;      		   }
CLINEA 0000H 0000H 009DH 000CH 000CH
_$L83 :

;;       	if(zhi!=-600)break;
CLINEA 0000H 0001H 009EH 0009H 001BH
	cmp	r12,	#0a8h
	cmpc	r13,	#0fdh
	bne	_$L75
CBLOCKEND 5 3 159

;;     for(i=0; i<SHU; i++)
CLINEA 0000H 0000H 0091H 0016H 0018H
	add	er6,	#1 

;;     for(i=0; i<SHU; i++)
CLINEA 0000H 0000H 0091H 000FH 0014H
_$L79 :
	l	er2,	14[fp]
	cmp	er6,	er2
	bges	_$M9
	b	_$L76
_$M9 :

;;       }
CLINEA 0000H 0000H 009FH 0008H 0008H
_$L75 :
_$L67 :

;;     return zhi;
CLINEA 0000H 0001H 00A0H 0006H 0010H
	mov	er0,	bp
CBLOCKEND 5 2 161

;; }
CLINEA 0000H 0000H 00A1H 0002H 0002H
	b	__regpopu8sw
CBLOCKEND 5 1 161
CFUNCTIONEND 5


	rseg $$HUM_A$temphum
CFUNCTION 6

_HUM_A	:
CBLOCK 6 1 169

;; {
CLINEA 0000H 0001H 00A9H 0002H 0002H
	push	lr
	bl	__regpushu8sw
	add	sp,	#-010
	mov	er8,	er0
	mov	er10,	er2
CBLOCK 6 2 169
CRET 0016H
CARGUMENT 47H 0002H 0032H "CAI" 02H 00H 01H
CARGUMENT 47H 0002H 0033H "H" 04H 03H 00H 00H 01H
CARGUMENT 42H 0002H 000EH "CA" 07H 03H 00H 01H 15H 00H 00H 01H
CARGUMENT 43H 0002H 0010H "Bi" 02H 00H 01H
CLOCAL 43H 0002H 000AH 0002H "sum" 02H 00H 01H
CLOCAL 43H 0002H 0002H 0002H "j" 02H 00H 01H
CLOCAL 43H 0004H 0008H 0002H "c" 02H 00H 02H
CLOCAL 47H 0004H 2726H 0002H "d" 02H 00H 02H

;; 	int sum=-600,j;
CLINEA 0000H 0001H 00AAH 0003H 0011H
	mov	r0,	#0a8h
	mov	r1,	#0fdh
	st	er0,	-10[fp]

;;     for(j=0; j<_HUM_; j++)
CLINEA 0000H 0001H 00ACH 0006H 001BH
	mov	er0,	#0 
	st	er0,	-2[fp]
_$L95 :
CBLOCK 6 3 173

;;      	if(CAI>=CA[Bi][j] && CAI<=CA[Bi][j+1])
CLINEA 0000H 0000H 00AEH 0000H 0000H
	l	er0,	16[fp]
	mov	er2,	#42
	bl	__imulu8sw
	mov	er2,	er0
	mov	er6,	er0
	l	er0,	-2[fp]
	add	er0,	er0
	st	er0,	-4[fp]

;;      	if(CAI>=CA[Bi][j] && CAI<=CA[Bi][j+1])
CLINEA 0000H 0001H 00AEH 0008H 002DH
	l	er4,	14[fp]
	add	er2,	er4
	add	er2,	er0
	l	er2,	[er2]
	cmp	er8,	er2
	bge	_$M11
	b	_$L99
_$M11 :
	mov	er0,	er6
	add	er0,	er4
	l	er2,	-4[fp]
	add	er0,	er2
	l	er0,	02h[er0]
	cmp	er8,	er0
	ble	_$M12
	b	_$L99
_$M12 :
CBLOCK 6 4 175

;; 	      	c=CAI-CA[Bi][j]+1;
CLINEA 0000H 0001H 00B0H 000AH 001BH
	mov	bp,	er6
	add	bp,	er4
	add	bp,	er2
	mov	er0,	er8
	l	er2,	[bp]
	sub	r0,	r2
	subc	r1,	r3
	add	er0,	#1 
	mov	er2,	#0 
	st	er0,	-8[fp]
	st	er2,	-6[fp]

;; 	      	d=(c*100)/(CA[Bi][j+1]-CA[Bi][j]);
CLINEA 0000H 0001H 00B1H 000AH 002BH
	push	xr0
	mov	r0,	#064h
	mov	r1,	#00h
	push	xr0
	bl	__lmulu8sw
	add	sp,	#4 
	pop	xr4
	l	er0,	2[bp]
	l	er2,	[bp]
	sub	r0,	r2
	subc	r1,	r3
	mov	er2,	#0 
	push	qr0
	bl	__ldivu8sw
	add	sp,	#4 
	pop	xr0
	mov	er4,	er0
	mov	er6,	er2

;; 	      	if(d%10>5)d=d+5; //四舍五入处理 
CLINEA 0000H 0001H 00B2H 000AH 0029H
	push	xr0
	mov	er0,	#10
	mov	er2,	#0 
	push	xr0
	bl	__lmodu8sw
	add	sp,	#4 
	pop	xr0
	cmp	r0,	#05h
	cmpc	r1,	#00h
	cmpc	r2,	#00h
	cmpc	r3,	#00h
	bles	_$L106
	mov	er0,	er4
	mov	er2,	er6
	add	er0,	#5 
	addc	r2,	#00h
	addc	r3,	#00h
	mov	er4,	er0
	mov	er6,	er2
_$L106 :

;; 	      	d=(6*d)/100;
CLINEA 0000H 0001H 00B3H 000AH 0015H
	push	xr4
	mov	er0,	#6 
	mov	er2,	#0 
	push	xr0
	bl	__lmulu8sw
	add	sp,	#4 
	mov	r0,	#064h
	push	xr0
	bl	__ldivu8sw
	add	sp,	#4 
	pop	xr0
	mov	er4,	er0

;; 	      	sum=H[j]+d;
CLINEA 0000H 0001H 00B4H 000AH 0014H
	l	er0,	-4[fp]
	add	er0,	er10
	l	er0,	[er0]
	add	er0,	er4
	st	er0,	-10[fp]
CBLOCKEND 6 4 181

;; 	      }
CLINEA 0000H 0000H 00B5H 0009H 0009H
_$L99 :
CBLOCKEND 6 3 182

;;     for(j=0; j<_HUM_; j++)
CLINEA 0000H 0000H 00ACH 0006H 001BH
	l	er0,	-2[fp]
	add	er0,	#1 
	st	er0,	-2[fp]

;;     for(j=0; j<_HUM_; j++)
CLINEA 0000H 0000H 00ACH 000FH 0014H
	cmp	r0,	#015h
	cmpc	r1,	#00h
	bges	_$M13
	b	_$L95
_$M13 :

;;     return sum; 
CLINEA 0000H 0001H 00B7H 0006H 0011H
	l	er0,	-10[fp]
CBLOCKEND 6 2 184

;;   }
CLINEA 0000H 0000H 00B8H 0004H 0004H
	b	__regpopu8sw
CBLOCKEND 6 1 184
CFUNCTIONEND 6


	rseg $$HUM_HS$temphum
CFUNCTION 7

_HUM_HS	:
CBLOCK 7 1 192

;; {
CLINEA 0000H 0001H 00C0H 0002H 0002H
	push	lr
	bl	__regpushu8sw
	add	sp,	#-02
	mov	er10,	er2
	mov	er8,	er0
CBLOCK 7 2 192
CRET 000EH
CARGUMENT 47H 0002H 0032H "T_P" 02H 00H 01H
CARGUMENT 46H 0002H 0033H "H_z" 07H 03H 00H 01H 15H 00H 00H 01H
CARGUMENT 42H 0002H 000EH "NEW_h" 07H 03H 00H 01H 15H 00H 00H 01H
CARGUMENT 43H 0002H 0010H "bi" 02H 00H 01H
CLOCAL 43H 0002H 0002H 0002H "i" 02H 00H 01H

;;  	int i=0;
CLINEA 0000H 0001H 00C1H 0004H 000BH
	mov	er0,	#0 
	st	er0,	-2[fp]

;;	 for(i=0; i<_HUM_; i++)
CLINEA 0000H 0000H 00C2H 0003H 0018H
_$L111 :

;;	   NEW_h[0][i]=(T_P*(H_z[bi+1][i]-H_z[bi][i]))/10+H_z[bi][i];
CLINEA 0000H 0001H 00C3H 0005H 003EH
	mov	er4,	er0
	add	er4,	er0
	l	er0,	16[fp]
	mov	er2,	#42
	bl	__imulu8sw
	mov	er6,	er0
	add	er6,	er10
	add	er6,	er4
	l	er0,	02ah[er6]
	l	er2,	[er6]
	sub	r0,	r2
	subc	r1,	r3
	mov	er2,	er8
	bl	__imulu8sw
	mov	r2,	#0ah
	div	er0,	r2
	l	er2,	[er6]
	add	er0,	er2
	l	er2,	14[fp]
	add	er4,	er2
	st	er0,	[er4]

;;	 for(i=0; i<_HUM_; i++)
CLINEA 0000H 0000H 00C2H 0003H 0018H
	l	er0,	-2[fp]
	add	er0,	#1 
	st	er0,	-2[fp]

;;	 for(i=0; i<_HUM_; i++)
CLINEA 0000H 0000H 00C2H 000FH 0014H
	cmp	r0,	#015h
	cmpc	r1,	#00h
	blts	_$L111
CBLOCKEND 7 2 196

;; }
CLINEA 0000H 0001H 00C4H 0002H 0002H
	b	__regpopu8sw
CBLOCKEND 7 1 196
CFUNCTIONEND 7

	public _Temp_trade
	public _C_FCUTOVER
	public _TE_A
	public _TE_B
	public _HUM_A
	public _TEMP_ZH
	public _H_H
	public _H_T
	public _HUM_HS
	extrn code near : _main
	extrn code : __imulu8sw
	extrn code : __imodu8sw
	extrn code : __idivu8sw
	extrn code : __lmulu8sw
	extrn code : __faddu8sw
	extrn code : __fmulu8sw
	extrn code : __fdivu8sw
	extrn code : __fildu8sw
	extrn code : __ftolu8sw
	extrn code : __ldivu8sw
	extrn code : __lmodu8sw
	extrn code : __regpushu8sw
	extrn code : __regpopu8sw

	end
