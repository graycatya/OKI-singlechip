;; Compile Options : /TM610409 /MS /near /Imain /Iclk /IINTERR~1 /Ikey /Ilcd /Ilcdshow /Imelody /Iport /Ircadc /Itemphum /Itimers /IMACROA~1 /Ieternity /ICLKbuzz /SD /Ol /Og /Oa /W 1 /Fa_output\_obj\ /Zs 
;; Version Number  : Ver.3.54.3
;; File Name       : port.c

	type (M610409) 
	model small, near
	$$EXICON_0init$port segment code 2h #0h
	$$EXICON_1init$port segment code 2h #0h
	$$EXICON_2init$port segment code 2h #0h
	$$P0D_init$port segment code 2h #0h
	$$P2CON_0init$port segment code 2h #0h
	$$P2CON_1init$port segment code 2h #0h
	$$P2D_init$port segment code 2h #0h
	$$P2MOD_init$port segment code 2h #0h
	$$P3CON_0init$port segment code 2h #0h
	$$P3CON_1init$port segment code 2h #0h
	$$P3DIR_init$port segment code 2h #0h
	$$P3D_init$port segment code 2h #0h
	$$P3MOD_0init$port segment code 2h #0h
	$$P4CON_0init$port segment code 2h #0h
	$$P4CON_1init$port segment code 2h #0h
	$$P4DIR_init$port segment code 2h #0h
	$$P4D_init$port segment code 2h #0h
	$$P4MOD_0init$port segment code 2h #0h
	$$P4MOD_1init$port segment code 2h #0h
	$$P5CON_0init$port segment code 2h #0h
	$$P5CON_1init$port segment code 2h #0h
	$$P5DIR_init$port segment code 2h #0h
	$$P5D_init$port segment code 2h #0h
	$$P5MOD_0init$port segment code 2h #0h
	$$P5MOD_1init$port segment code 2h #0h
	$$P5SISEL_init$port segment code 2h #0h
	$$PCON_0init$port segment code 2h #0h
	$$PCON_1init$port segment code 2h #0h
CVERSION 3.54.3
CGLOBAL 01H 03H 0000H "PCON_1init" 08H 02H 02H 00H 82H 06H 00H 00H 01H
CGLOBAL 01H 03H 0000H "P5SISEL_init" 08H 02H 1BH 00H 82H 06H 00H 00H 01H
CGLOBAL 01H 03H 0000H "PCON_0init" 08H 02H 01H 00H 82H 06H 00H 00H 01H
CGLOBAL 01H 03H 0000H "P0D_init" 08H 02H 00H 00H 82H 06H 00H 00H 01H
CGLOBAL 01H 03H 0000H "P2D_init" 08H 02H 06H 00H 82H 06H 00H 00H 01H
CGLOBAL 01H 03H 0000H "P3D_init" 08H 02H 0AH 00H 82H 06H 00H 00H 01H
CGLOBAL 01H 03H 0000H "P4D_init" 08H 02H 0FH 00H 82H 06H 00H 00H 01H
CGLOBAL 01H 03H 0000H "P5D_init" 08H 02H 15H 00H 82H 06H 00H 00H 01H
CGLOBAL 01H 03H 0000H "P3DIR_init" 08H 02H 0BH 00H 82H 06H 00H 00H 01H
CGLOBAL 01H 03H 0000H "P2MOD_init" 08H 02H 09H 00H 82H 06H 00H 00H 01H
CGLOBAL 01H 03H 0000H "P4DIR_init" 08H 02H 10H 00H 82H 06H 00H 00H 01H
CGLOBAL 01H 03H 0000H "P5DIR_init" 08H 02H 16H 00H 82H 06H 00H 00H 01H
CGLOBAL 01H 03H 0000H "EXICON_0init" 08H 02H 03H 00H 82H 06H 00H 00H 01H
CGLOBAL 01H 03H 0000H "EXICON_1init" 08H 02H 04H 00H 82H 06H 00H 00H 01H
CGLOBAL 01H 03H 0000H "EXICON_2init" 08H 02H 05H 00H 82H 06H 00H 00H 01H
CGLOBAL 01H 03H 0000H "P5CON_1init" 08H 02H 18H 00H 80H 00H 00H 00H 01H
CGLOBAL 01H 03H 0000H "P2CON_0init" 08H 02H 07H 00H 82H 06H 00H 00H 01H
CGLOBAL 01H 03H 0000H "P4MOD_1init" 08H 02H 14H 00H 82H 06H 00H 00H 01H
CGLOBAL 01H 03H 0000H "P3CON_0init" 08H 02H 0CH 00H 82H 06H 00H 00H 01H
CGLOBAL 01H 03H 0000H "P5MOD_1init" 08H 02H 1AH 00H 82H 06H 00H 00H 01H
CGLOBAL 01H 03H 0000H "P4CON_0init" 08H 02H 11H 00H 82H 06H 00H 00H 01H
CGLOBAL 01H 03H 0000H "P5CON_0init" 08H 02H 17H 00H 82H 06H 00H 00H 01H
CGLOBAL 01H 03H 0000H "P3MOD_0init" 08H 02H 0EH 00H 82H 06H 00H 00H 01H
CGLOBAL 01H 03H 0000H "P2CON_1init" 08H 02H 08H 00H 82H 06H 00H 00H 01H
CGLOBAL 01H 03H 0000H "P4MOD_0init" 08H 02H 13H 00H 82H 06H 00H 00H 01H
CGLOBAL 01H 03H 0000H "P3CON_1init" 08H 02H 0DH 00H 82H 06H 00H 00H 01H
CGLOBAL 01H 03H 0000H "P5MOD_0init" 08H 02H 19H 00H 82H 06H 00H 00H 01H
CGLOBAL 01H 03H 0000H "P4CON_1init" 08H 02H 12H 00H 82H 06H 00H 00H 01H
CSTRUCTTAG 0000H 0000H 0000H 0008H 00000001H "_Notag"
CSTRUCTMEM 52H 00000001H 00000000H "b0" 02H 00H 00H
CSTRUCTMEM 52H 00000001H 00000001H "b1" 02H 00H 00H
CSTRUCTMEM 52H 00000001H 00000002H "b2" 02H 00H 00H
CSTRUCTMEM 52H 00000001H 00000003H "b3" 02H 00H 00H
CSTRUCTMEM 52H 00000001H 00000004H "b4" 02H 00H 00H
CSTRUCTMEM 52H 00000001H 00000005H "b5" 02H 00H 00H
CSTRUCTMEM 52H 00000001H 00000006H "b6" 02H 00H 00H
CSTRUCTMEM 52H 00000001H 00000007H "b7" 02H 00H 00H
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
CTYPEDEF 0000H 0000H 43H "_BYTE_FIELD" 04H 00H 05H 00H 00H
CFILE 0001H 00000822H "E:\\IDEU8\\Inc\\m610409.h"
CFILE 0002H 00000063H "port\\port.h"
CFILE 0003H 00000022H "MACROA~1\\MacroAndConst.h"
CFILE 0000H 00000434H "port\\port.c"

	rseg $$P0D_init$port
CFUNCTION 0

_P0D_init	:
CBLOCK 0 1 29

;; {
CLINEA 0000H 0001H 001DH 0002H 0002H
	push	fp
	mov	fp,	sp
	push	xr8
	mov	er8,	er0
	mov	er10,	er2
CBLOCK 0 2 29
CARGUMENT 46H 0002H 0028H "bit0" 02H 00H 01H
CARGUMENT 46H 0002H 0029H "bit1" 02H 00H 01H
CARGUMENT 42H 0002H 0002H "bit2" 02H 00H 01H
CARGUMENT 42H 0002H 0004H "bit3" 02H 00H 01H
CARGUMENT 42H 0002H 0006H "bit4" 02H 00H 01H

;;        bit4 > PORT_HIGH) {
CLINEA 0000H 0001H 0020H 0009H 001BH
	cmp	r0,	#01h
	cmpc	r1,	#00h
	bgt	_$L2
	cmp	r2,	#01h
	cmpc	r3,	#00h
	bgt	_$L2
	l	er0,	2[fp]
	cmp	r0,	#01h
	cmpc	r1,	#00h
	bgt	_$L2
	l	er0,	4[fp]
	cmp	r0,	#01h
	cmpc	r1,	#00h
	bgt	_$L2
	l	er0,	6[fp]
	cmp	r0,	#01h
	cmpc	r1,	#00h
	ble	_$L1
_$L2 :
CBLOCK 0 3 32

;;       	 return (PORT_DEPLOY_FAIL);
CLINEA 0000H 0001H 0021H 000AH 0023H
	mov	er0,	#-1
CBLOCKEND 0 3 34
CBLOCKEND 0 2 39

;;  }
CLINEA 0000H 0001H 0027H 0003H 0003H
_$L0 :
	pop	xr8
	mov	sp,	fp
	pop	fp
	rt

;;        }
CLINEA 0000H 0000H 0022H 0009H 0009H
_$L1 :

;;	P00D = bit0; P01D = bit1;
CLINEA 0000H 0001H 0023H 0002H 001AH
	mov	r0,	r8
	and	r0,	#01h
	beq	_$M1
	sb	0f204h.0
	bal	_$M2
_$M1 :
	rb	0f204h.0
_$M2 :
	mov	r0,	r10
	and	r0,	#01h
	beq	_$M3
	sb	0f204h.1
	bal	_$M4
_$M3 :
	rb	0f204h.1
_$M4 :

;;	P02D = bit2; P03D = bit3;
CLINEA 0000H 0001H 0024H 0002H 001AH
	l	r0,	2[fp]
	and	r0,	#01h
	beq	_$M5
	sb	0f204h.2
	bal	_$M6
_$M5 :
	rb	0f204h.2
_$M6 :
	l	r0,	4[fp]
	and	r0,	#01h
	beq	_$M7
	sb	0f204h.3
	bal	_$M8
_$M7 :
	rb	0f204h.3
_$M8 :

;;	P04D = bit4;
CLINEA 0000H 0001H 0025H 0002H 000DH
	l	r0,	6[fp]
	and	r0,	#01h
	beq	_$M9
	sb	0f204h.4
	bal	_$M10
_$M9 :
	rb	0f204h.4
_$M10 :

;;   return (PORT_DEPLOY_OK);
CLINEA 0000H 0001H 0026H 0004H 001BH
	mov	er0,	#0 
	bal	_$L0
CBLOCKEND 0 1 39
CFUNCTIONEND 0


	rseg $$PCON_0init$port
CFUNCTION 1

_PCON_0init	:
CBLOCK 1 1 63

;; {
CLINEA 0000H 0001H 003FH 0002H 0002H
	push	fp
	mov	fp,	sp
	push	xr8
	mov	er8,	er0
	mov	er10,	er2
CBLOCK 1 2 63
CARGUMENT 46H 0002H 0028H "bit0" 02H 00H 01H
CARGUMENT 46H 0002H 0029H "bit1" 02H 00H 01H
CARGUMENT 42H 0002H 0002H "bit2" 02H 00H 01H
CARGUMENT 42H 0002H 0004H "bit3" 02H 00H 01H
CARGUMENT 42H 0002H 0006H "bit4" 02H 00H 01H

;;        bit4 > PORT_HIGH) {
CLINEA 0000H 0001H 0042H 0009H 001BH
	cmp	r0,	#01h
	cmpc	r1,	#00h
	bgt	_$L19
	cmp	r2,	#01h
	cmpc	r3,	#00h
	bgt	_$L19
	l	er0,	2[fp]
	cmp	r0,	#01h
	cmpc	r1,	#00h
	bgt	_$L19
	l	er0,	4[fp]
	cmp	r0,	#01h
	cmpc	r1,	#00h
	bgt	_$L19
	l	er0,	6[fp]
	cmp	r0,	#01h
	cmpc	r1,	#00h
	ble	_$L18
_$L19 :
CBLOCK 1 3 66

;;       	 return (PORT_DEPLOY_FAIL);
CLINEA 0000H 0001H 0043H 000AH 0023H
	mov	er0,	#-1
CBLOCKEND 1 3 68
CBLOCKEND 1 2 73

;;  }
CLINEA 0000H 0001H 0049H 0003H 0003H
_$L17 :
	pop	xr8
	mov	sp,	fp
	pop	fp
	rt

;;        }  
CLINEA 0000H 0000H 0044H 0009H 000BH
_$L18 :

;;	P00C0 = bit0; P01C0 = bit1;
CLINEA 0000H 0001H 0045H 0002H 001CH
	mov	r0,	r8
	and	r0,	#01h
	beq	_$M12
	sb	0f206h.0
	bal	_$M13
_$M12 :
	rb	0f206h.0
_$M13 :
	mov	r0,	r10
	and	r0,	#01h
	beq	_$M14
	sb	0f206h.1
	bal	_$M15
_$M14 :
	rb	0f206h.1
_$M15 :

;;	P02C0 = bit2; P03C0 = bit3;
CLINEA 0000H 0001H 0046H 0002H 001CH
	l	r0,	2[fp]
	and	r0,	#01h
	beq	_$M16
	sb	0f206h.2
	bal	_$M17
_$M16 :
	rb	0f206h.2
_$M17 :
	l	r0,	4[fp]
	and	r0,	#01h
	beq	_$M18
	sb	0f206h.3
	bal	_$M19
_$M18 :
	rb	0f206h.3
_$M19 :

;;	P04C0 = bit4;
CLINEA 0000H 0001H 0047H 0002H 000EH
	l	r0,	6[fp]
	and	r0,	#01h
	beq	_$M20
	sb	0f206h.4
	bal	_$M21
_$M20 :
	rb	0f206h.4
_$M21 :

;;   return (PORT_DEPLOY_OK);		 	
CLINEA 0000H 0001H 0048H 0004H 001FH
	mov	er0,	#0 
	bal	_$L17
CBLOCKEND 1 1 73
CFUNCTIONEND 1


	rseg $$PCON_1init$port
CFUNCTION 2

_PCON_1init	:
CBLOCK 2 1 97

;; {
CLINEA 0000H 0001H 0061H 0002H 0002H
	push	fp
	mov	fp,	sp
	push	xr8
	mov	er8,	er0
	mov	er10,	er2
CBLOCK 2 2 97
CARGUMENT 46H 0002H 0028H "bit0" 02H 00H 01H
CARGUMENT 46H 0002H 0029H "bit1" 02H 00H 01H
CARGUMENT 42H 0002H 0002H "bit2" 02H 00H 01H
CARGUMENT 42H 0002H 0004H "bit3" 02H 00H 01H
CARGUMENT 42H 0002H 0006H "bit4" 02H 00H 01H

;;        bit4 > PORT_HIGH) {
CLINEA 0000H 0001H 0064H 0009H 001BH
	cmp	r0,	#01h
	cmpc	r1,	#00h
	bgt	_$L36
	cmp	r2,	#01h
	cmpc	r3,	#00h
	bgt	_$L36
	l	er0,	2[fp]
	cmp	r0,	#01h
	cmpc	r1,	#00h
	bgt	_$L36
	l	er0,	4[fp]
	cmp	r0,	#01h
	cmpc	r1,	#00h
	bgt	_$L36
	l	er0,	6[fp]
	cmp	r0,	#01h
	cmpc	r1,	#00h
	ble	_$L35
_$L36 :
CBLOCK 2 3 100

;;       	 return (PORT_DEPLOY_FAIL);
CLINEA 0000H 0001H 0065H 000AH 0023H
	mov	er0,	#-1
CBLOCKEND 2 3 102
CBLOCKEND 2 2 107

;;  }
CLINEA 0000H 0001H 006BH 0003H 0003H
_$L34 :
	pop	xr8
	mov	sp,	fp
	pop	fp
	rt

;;        }  
CLINEA 0000H 0000H 0066H 0009H 000BH
_$L35 :

;;	P00C1 = bit0; P01C1 = bit1;
CLINEA 0000H 0001H 0067H 0002H 001CH
	mov	r0,	r8
	and	r0,	#01h
	beq	_$M23
	sb	0f207h.0
	bal	_$M24
_$M23 :
	rb	0f207h.0
_$M24 :
	mov	r0,	r10
	and	r0,	#01h
	beq	_$M25
	sb	0f207h.1
	bal	_$M26
_$M25 :
	rb	0f207h.1
_$M26 :

;;	P02C1 = bit2; P03C1 = bit3;
CLINEA 0000H 0001H 0068H 0002H 001CH
	l	r0,	2[fp]
	and	r0,	#01h
	beq	_$M27
	sb	0f207h.2
	bal	_$M28
_$M27 :
	rb	0f207h.2
_$M28 :
	l	r0,	4[fp]
	and	r0,	#01h
	beq	_$M29
	sb	0f207h.3
	bal	_$M30
_$M29 :
	rb	0f207h.3
_$M30 :

;;	P04C1 = bit4;
CLINEA 0000H 0001H 0069H 0002H 000EH
	l	r0,	6[fp]
	and	r0,	#01h
	beq	_$M31
	sb	0f207h.4
	bal	_$M32
_$M31 :
	rb	0f207h.4
_$M32 :

;;   return (PORT_DEPLOY_OK);		 	
CLINEA 0000H 0001H 006AH 0004H 001FH
	mov	er0,	#0 
	bal	_$L34
CBLOCKEND 2 1 107
CFUNCTIONEND 2


	rseg $$EXICON_0init$port
CFUNCTION 3

_EXICON_0init	:
CBLOCK 3 1 130

;; {
CLINEA 0000H 0001H 0082H 0002H 0002H
	push	fp
	mov	fp,	sp
	push	xr8
	mov	er8,	er0
	mov	er10,	er2
CBLOCK 3 2 130
CARGUMENT 46H 0002H 0028H "bit0" 02H 00H 01H
CARGUMENT 46H 0002H 0029H "bit1" 02H 00H 01H
CARGUMENT 42H 0002H 0002H "bit2" 02H 00H 01H
CARGUMENT 42H 0002H 0004H "bit3" 02H 00H 01H
CARGUMENT 42H 0002H 0006H "bit4" 02H 00H 01H

;;        bit4 > PORT_HIGH) {
CLINEA 0000H 0001H 0085H 0009H 001BH
	cmp	r0,	#01h
	cmpc	r1,	#00h
	bgt	_$L53
	cmp	r2,	#01h
	cmpc	r3,	#00h
	bgt	_$L53
	l	er0,	2[fp]
	cmp	r0,	#01h
	cmpc	r1,	#00h
	bgt	_$L53
	l	er0,	4[fp]
	cmp	r0,	#01h
	cmpc	r1,	#00h
	bgt	_$L53
	l	er0,	6[fp]
	cmp	r0,	#01h
	cmpc	r1,	#00h
	ble	_$L52
_$L53 :
CBLOCK 3 3 133

;;       	 return (PORT_DEPLOY_FAIL);
CLINEA 0000H 0001H 0086H 000AH 0023H
	mov	er0,	#-1
CBLOCKEND 3 3 135
CBLOCKEND 3 2 140

;;  }
CLINEA 0000H 0001H 008CH 0003H 0003H
_$L51 :
	pop	xr8
	mov	sp,	fp
	pop	fp
	rt

;;        }  
CLINEA 0000H 0000H 0087H 0009H 000BH
_$L52 :

;;	P00E0 = bit0; P01E0 = bit1;
CLINEA 0000H 0001H 0088H 0002H 001CH
	mov	r0,	r8
	and	r0,	#01h
	beq	_$M34
	sb	0f020h.0
	bal	_$M35
_$M34 :
	rb	0f020h.0
_$M35 :
	mov	r0,	r10
	and	r0,	#01h
	beq	_$M36
	sb	0f020h.1
	bal	_$M37
_$M36 :
	rb	0f020h.1
_$M37 :

;;	P02E0 = bit2; P03E0 = bit3;
CLINEA 0000H 0001H 0089H 0002H 001CH
	l	r0,	2[fp]
	and	r0,	#01h
	beq	_$M38
	sb	0f020h.2
	bal	_$M39
_$M38 :
	rb	0f020h.2
_$M39 :
	l	r0,	4[fp]
	and	r0,	#01h
	beq	_$M40
	sb	0f020h.3
	bal	_$M41
_$M40 :
	rb	0f020h.3
_$M41 :

;;	P04E0 = bit4;
CLINEA 0000H 0001H 008AH 0002H 000EH
	l	r0,	6[fp]
	and	r0,	#01h
	beq	_$M42
	sb	0f020h.4
	bal	_$M43
_$M42 :
	rb	0f020h.4
_$M43 :

;;   return (PORT_DEPLOY_OK);		 	
CLINEA 0000H 0001H 008BH 0004H 001FH
	mov	er0,	#0 
	bal	_$L51
CBLOCKEND 3 1 140
CFUNCTIONEND 3


	rseg $$EXICON_1init$port
CFUNCTION 4

_EXICON_1init	:
CBLOCK 4 1 164

;; {
CLINEA 0000H 0001H 00A4H 0002H 0002H
	push	fp
	mov	fp,	sp
	push	xr8
	mov	er8,	er0
	mov	er10,	er2
CBLOCK 4 2 164
CARGUMENT 46H 0002H 0028H "bit0" 02H 00H 01H
CARGUMENT 46H 0002H 0029H "bit1" 02H 00H 01H
CARGUMENT 42H 0002H 0002H "bit2" 02H 00H 01H
CARGUMENT 42H 0002H 0004H "bit3" 02H 00H 01H
CARGUMENT 42H 0002H 0006H "bit4" 02H 00H 01H

;;        bit4 > PORT_HIGH) {
CLINEA 0000H 0001H 00A7H 0009H 001BH
	cmp	r0,	#01h
	cmpc	r1,	#00h
	bgt	_$L70
	cmp	r2,	#01h
	cmpc	r3,	#00h
	bgt	_$L70
	l	er0,	2[fp]
	cmp	r0,	#01h
	cmpc	r1,	#00h
	bgt	_$L70
	l	er0,	4[fp]
	cmp	r0,	#01h
	cmpc	r1,	#00h
	bgt	_$L70
	l	er0,	6[fp]
	cmp	r0,	#01h
	cmpc	r1,	#00h
	ble	_$L69
_$L70 :
CBLOCK 4 3 167

;;       	 return (PORT_DEPLOY_FAIL);
CLINEA 0000H 0001H 00A8H 000AH 0023H
	mov	er0,	#-1
CBLOCKEND 4 3 169
CBLOCKEND 4 2 174

;;  }
CLINEA 0000H 0001H 00AEH 0003H 0003H
_$L68 :
	pop	xr8
	mov	sp,	fp
	pop	fp
	rt

;;        }  
CLINEA 0000H 0000H 00A9H 0009H 000BH
_$L69 :

;;	P00E1 = bit0; P01E1 = bit1;
CLINEA 0000H 0001H 00AAH 0002H 001CH
	mov	r0,	r8
	and	r0,	#01h
	beq	_$M45
	sb	0f021h.0
	bal	_$M46
_$M45 :
	rb	0f021h.0
_$M46 :
	mov	r0,	r10
	and	r0,	#01h
	beq	_$M47
	sb	0f021h.1
	bal	_$M48
_$M47 :
	rb	0f021h.1
_$M48 :

;;	P02E1 = bit2; P03E1 = bit3;
CLINEA 0000H 0001H 00ABH 0002H 001CH
	l	r0,	2[fp]
	and	r0,	#01h
	beq	_$M49
	sb	0f021h.2
	bal	_$M50
_$M49 :
	rb	0f021h.2
_$M50 :
	l	r0,	4[fp]
	and	r0,	#01h
	beq	_$M51
	sb	0f021h.3
	bal	_$M52
_$M51 :
	rb	0f021h.3
_$M52 :

;;	P04E1 = bit4;
CLINEA 0000H 0001H 00ACH 0002H 000EH
	l	r0,	6[fp]
	and	r0,	#01h
	beq	_$M53
	sb	0f021h.4
	bal	_$M54
_$M53 :
	rb	0f021h.4
_$M54 :

;;   return (PORT_DEPLOY_OK);		 	
CLINEA 0000H 0001H 00ADH 0004H 001FH
	mov	er0,	#0 
	bal	_$L68
CBLOCKEND 4 1 174
CFUNCTIONEND 4


	rseg $$EXICON_2init$port
CFUNCTION 5

_EXICON_2init	:
CBLOCK 5 1 197

;; {
CLINEA 0000H 0001H 00C5H 0002H 0002H
	push	fp
	mov	fp,	sp
	push	xr8
	mov	er8,	er0
	mov	er10,	er2
CBLOCK 5 2 197
CARGUMENT 46H 0002H 0028H "bit0" 02H 00H 01H
CARGUMENT 46H 0002H 0029H "bit1" 02H 00H 01H
CARGUMENT 42H 0002H 0002H "bit2" 02H 00H 01H
CARGUMENT 42H 0002H 0004H "bit3" 02H 00H 01H
CARGUMENT 42H 0002H 0006H "bit4" 02H 00H 01H

;;        bit4 > PORT_HIGH) {
CLINEA 0000H 0001H 00C8H 0009H 001BH
	cmp	r0,	#01h
	cmpc	r1,	#00h
	bgt	_$L87
	cmp	r2,	#01h
	cmpc	r3,	#00h
	bgt	_$L87
	l	er0,	2[fp]
	cmp	r0,	#01h
	cmpc	r1,	#00h
	bgt	_$L87
	l	er0,	4[fp]
	cmp	r0,	#01h
	cmpc	r1,	#00h
	bgt	_$L87
	l	er0,	6[fp]
	cmp	r0,	#01h
	cmpc	r1,	#00h
	ble	_$L86
_$L87 :
CBLOCK 5 3 200

;;       	 return (PORT_DEPLOY_FAIL);
CLINEA 0000H 0001H 00C9H 000AH 0023H
	mov	er0,	#-1
CBLOCKEND 5 3 202
CBLOCKEND 5 2 207

;;  }
CLINEA 0000H 0001H 00CFH 0003H 0003H
_$L85 :
	pop	xr8
	mov	sp,	fp
	pop	fp
	rt

;;        }  
CLINEA 0000H 0000H 00CAH 0009H 000BH
_$L86 :

;;	P00SM = bit0; P01SM = bit1;
CLINEA 0000H 0001H 00CBH 0002H 001CH
	mov	r0,	r8
	and	r0,	#01h
	beq	_$M56
	sb	0f022h.0
	bal	_$M57
_$M56 :
	rb	0f022h.0
_$M57 :
	mov	r0,	r10
	and	r0,	#01h
	beq	_$M58
	sb	0f022h.1
	bal	_$M59
_$M58 :
	rb	0f022h.1
_$M59 :

;;	P02SM = bit2; P03SM = bit3;
CLINEA 0000H 0001H 00CCH 0002H 001CH
	l	r0,	2[fp]
	and	r0,	#01h
	beq	_$M60
	sb	0f022h.2
	bal	_$M61
_$M60 :
	rb	0f022h.2
_$M61 :
	l	r0,	4[fp]
	and	r0,	#01h
	beq	_$M62
	sb	0f022h.3
	bal	_$M63
_$M62 :
	rb	0f022h.3
_$M63 :

;;	P04SM = bit4;
CLINEA 0000H 0001H 00CDH 0002H 000EH
	l	r0,	6[fp]
	and	r0,	#01h
	beq	_$M64
	sb	0f022h.4
	bal	_$M65
_$M64 :
	rb	0f022h.4
_$M65 :

;;   return (PORT_DEPLOY_OK);		 	
CLINEA 0000H 0001H 00CEH 0004H 001FH
	mov	er0,	#0 
	bal	_$L85
CBLOCKEND 5 1 207
CFUNCTIONEND 5


	rseg $$P2D_init$port
CFUNCTION 6

_P2D_init	:
CBLOCK 6 1 231

;; {
CLINEA 0000H 0001H 00E7H 0002H 0002H
	push	fp
	mov	fp,	sp
	push	xr8
	mov	er8,	er0
	mov	er10,	er2
CBLOCK 6 2 231
CARGUMENT 46H 0002H 0028H "bit0" 02H 00H 01H
CARGUMENT 46H 0002H 0029H "bit1" 02H 00H 01H
CARGUMENT 42H 0002H 0002H "bit2" 02H 00H 01H
CARGUMENT 42H 0002H 0004H "bit4" 02H 00H 01H

;;       bit2 > PORT_HIGH || bit4 > PORT_HIGH) {
CLINEA 0000H 0001H 00E9H 0008H 002EH
	cmp	r0,	#01h
	cmpc	r1,	#00h
	bgt	_$L104
	cmp	r2,	#01h
	cmpc	r3,	#00h
	bgt	_$L104
	l	er0,	2[fp]
	cmp	r0,	#01h
	cmpc	r1,	#00h
	bgt	_$L104
	l	er0,	4[fp]
	cmp	r0,	#01h
	cmpc	r1,	#00h
	ble	_$L103
_$L104 :
CBLOCK 6 3 233

;;       	 return (PORT_DEPLOY_FAIL);
CLINEA 0000H 0001H 00EAH 000AH 0023H
	mov	er0,	#-1
CBLOCKEND 6 3 235
CBLOCKEND 6 2 239

;;  }
CLINEA 0000H 0001H 00EFH 0003H 0003H
_$L102 :
	pop	xr8
	mov	sp,	fp
	pop	fp
	rt

;;        }   	
CLINEA 0000H 0000H 00EBH 0009H 000DH
_$L103 :

;;	P20D = bit0; P21D = bit1;
CLINEA 0000H 0001H 00ECH 0002H 001AH
	mov	r0,	r8
	and	r0,	#01h
	beq	_$M67
	sb	0f210h.0
	bal	_$M68
_$M67 :
	rb	0f210h.0
_$M68 :
	mov	r0,	r10
	and	r0,	#01h
	beq	_$M69
	sb	0f210h.1
	bal	_$M70
_$M69 :
	rb	0f210h.1
_$M70 :

;;	P22D = bit2; P24D = bit4;
CLINEA 0000H 0001H 00EDH 0002H 001AH
	l	r0,	2[fp]
	and	r0,	#01h
	beq	_$M71
	sb	0f210h.2
	bal	_$M72
_$M71 :
	rb	0f210h.2
_$M72 :
	l	r0,	4[fp]
	and	r0,	#01h
	beq	_$M73
	sb	0f210h.4
	bal	_$M74
_$M73 :
	rb	0f210h.4
_$M74 :

;;   return (PORT_DEPLOY_OK);    
CLINEA 0000H 0001H 00EEH 0004H 001FH
	mov	er0,	#0 
	bal	_$L102
CBLOCKEND 6 1 239
CFUNCTIONEND 6


	rseg $$P2CON_0init$port
CFUNCTION 7

_P2CON_0init	:
CBLOCK 7 1 259

;; {
CLINEA 0000H 0001H 0103H 0002H 0002H
	push	fp
	mov	fp,	sp
	push	xr8
	mov	er8,	er0
	mov	er10,	er2
CBLOCK 7 2 259
CARGUMENT 46H 0002H 0028H "bit0" 02H 00H 01H
CARGUMENT 46H 0002H 0029H "bit1" 02H 00H 01H
CARGUMENT 42H 0002H 0002H "bit2" 02H 00H 01H
CARGUMENT 42H 0002H 0004H "bit3" 02H 00H 01H
CARGUMENT 42H 0002H 0006H "bit4" 02H 00H 01H

;;       bit2 > PORT_HIGH || bit4 > PORT_HIGH) {
CLINEA 0000H 0001H 0105H 0008H 002EH
	cmp	r0,	#01h
	cmpc	r1,	#00h
	bgt	_$L118
	cmp	r2,	#01h
	cmpc	r3,	#00h
	bgt	_$L118
	l	er0,	2[fp]
	cmp	r0,	#01h
	cmpc	r1,	#00h
	bgt	_$L118
	l	er0,	6[fp]
	cmp	r0,	#01h
	cmpc	r1,	#00h
	ble	_$L117
_$L118 :
CBLOCK 7 3 261

;;       	 return (PORT_DEPLOY_FAIL);
CLINEA 0000H 0001H 0106H 000AH 0023H
	mov	er0,	#-1
CBLOCKEND 7 3 263
CBLOCKEND 7 2 267

;;  }
CLINEA 0000H 0001H 010BH 0003H 0003H
_$L116 :
	pop	xr8
	mov	sp,	fp
	pop	fp
	rt

;;        }  
CLINEA 0000H 0000H 0107H 0009H 000BH
_$L117 :

;;	P20C0 = bit0; P21C0 = bit1;
CLINEA 0000H 0001H 0108H 0002H 001CH
	mov	r0,	r8
	and	r0,	#01h
	beq	_$M76
	sb	0f212h.0
	bal	_$M77
_$M76 :
	rb	0f212h.0
_$M77 :
	mov	r0,	r10
	and	r0,	#01h
	beq	_$M78
	sb	0f212h.1
	bal	_$M79
_$M78 :
	rb	0f212h.1
_$M79 :

;;	P22C0 = bit2; P24C0 = bit4;
CLINEA 0000H 0001H 0109H 0002H 001CH
	l	r0,	2[fp]
	and	r0,	#01h
	beq	_$M80
	sb	0f212h.2
	bal	_$M81
_$M80 :
	rb	0f212h.2
_$M81 :
	l	r0,	6[fp]
	and	r0,	#01h
	beq	_$M82
	sb	0f212h.4
	bal	_$M83
_$M82 :
	rb	0f212h.4
_$M83 :

;;   return (PORT_DEPLOY_OK);		 	
CLINEA 0000H 0001H 010AH 0004H 001FH
	mov	er0,	#0 
	bal	_$L116
CBLOCKEND 7 1 267
CFUNCTIONEND 7


	rseg $$P2CON_1init$port
CFUNCTION 8

_P2CON_1init	:
CBLOCK 8 1 287

;; {
CLINEA 0000H 0001H 011FH 0002H 0002H
	push	fp
	mov	fp,	sp
	push	xr8
	mov	er8,	er0
	mov	er10,	er2
CBLOCK 8 2 287
CARGUMENT 46H 0002H 0028H "bit0" 02H 00H 01H
CARGUMENT 46H 0002H 0029H "bit1" 02H 00H 01H
CARGUMENT 42H 0002H 0002H "bit2" 02H 00H 01H
CARGUMENT 42H 0002H 0004H "bit3" 02H 00H 01H
CARGUMENT 42H 0002H 0006H "bit4" 02H 00H 01H

;;       bit2 > PORT_HIGH || bit4 > PORT_HIGH) {
CLINEA 0000H 0001H 0121H 0008H 002EH
	cmp	r0,	#01h
	cmpc	r1,	#00h
	bgt	_$L132
	cmp	r2,	#01h
	cmpc	r3,	#00h
	bgt	_$L132
	l	er0,	2[fp]
	cmp	r0,	#01h
	cmpc	r1,	#00h
	bgt	_$L132
	l	er0,	6[fp]
	cmp	r0,	#01h
	cmpc	r1,	#00h
	ble	_$L131
_$L132 :
CBLOCK 8 3 289

;;       	 return (PORT_DEPLOY_FAIL);
CLINEA 0000H 0001H 0122H 000AH 0023H
	mov	er0,	#-1
CBLOCKEND 8 3 291
CBLOCKEND 8 2 295

;;  }
CLINEA 0000H 0001H 0127H 0003H 0003H
_$L130 :
	pop	xr8
	mov	sp,	fp
	pop	fp
	rt

;;        }  
CLINEA 0000H 0000H 0123H 0009H 000BH
_$L131 :

;;	P20C1 = bit0; P21C1 = bit1;
CLINEA 0000H 0001H 0124H 0002H 001CH
	mov	r0,	r8
	and	r0,	#01h
	beq	_$M85
	sb	0f213h.0
	bal	_$M86
_$M85 :
	rb	0f213h.0
_$M86 :
	mov	r0,	r10
	and	r0,	#01h
	beq	_$M87
	sb	0f213h.1
	bal	_$M88
_$M87 :
	rb	0f213h.1
_$M88 :

;;	P22C1 = bit2; P24C1 = bit4;
CLINEA 0000H 0001H 0125H 0002H 001CH
	l	r0,	2[fp]
	and	r0,	#01h
	beq	_$M89
	sb	0f213h.2
	bal	_$M90
_$M89 :
	rb	0f213h.2
_$M90 :
	l	r0,	6[fp]
	and	r0,	#01h
	beq	_$M91
	sb	0f213h.4
	bal	_$M92
_$M91 :
	rb	0f213h.4
_$M92 :

;;   return (PORT_DEPLOY_OK);		 	
CLINEA 0000H 0001H 0126H 0004H 001FH
	mov	er0,	#0 
	bal	_$L130
CBLOCKEND 8 1 295
CFUNCTIONEND 8


	rseg $$P2MOD_init$port
CFUNCTION 9

_P2MOD_init	:
CBLOCK 9 1 315

;; {
CLINEA 0000H 0001H 013BH 0002H 0002H
	push	fp
	mov	fp,	sp
	push	xr8
	mov	er8,	er0
	mov	er10,	er2
CBLOCK 9 2 315
CARGUMENT 46H 0002H 0028H "bit0" 02H 00H 01H
CARGUMENT 46H 0002H 0029H "bit1" 02H 00H 01H
CARGUMENT 42H 0002H 0002H "bit2" 02H 00H 01H
CARGUMENT 42H 0002H 0004H "bit4" 02H 00H 01H

;;       bit2 > PORT_HIGH || bit4 > PORT_HIGH) {
CLINEA 0000H 0001H 013DH 0008H 002EH
	cmp	r0,	#01h
	cmpc	r1,	#00h
	bgt	_$L146
	cmp	r2,	#01h
	cmpc	r3,	#00h
	bgt	_$L146
	l	er0,	2[fp]
	cmp	r0,	#01h
	cmpc	r1,	#00h
	bgt	_$L146
	l	er0,	4[fp]
	cmp	r0,	#01h
	cmpc	r1,	#00h
	ble	_$L145
_$L146 :
CBLOCK 9 3 317

;;       	 return (PORT_DEPLOY_FAIL);
CLINEA 0000H 0001H 013EH 000AH 0023H
	mov	er0,	#-1
CBLOCKEND 9 3 319
CBLOCKEND 9 2 323

;;  }
CLINEA 0000H 0001H 0143H 0003H 0003H
_$L144 :
	pop	xr8
	mov	sp,	fp
	pop	fp
	rt

;;        }  
CLINEA 0000H 0000H 013FH 0009H 000BH
_$L145 :

;;	P20MD = bit0; P21MD = bit1;
CLINEA 0000H 0001H 0140H 0002H 001CH
	mov	r0,	r8
	and	r0,	#01h
	beq	_$M94
	sb	0f214h.0
	bal	_$M95
_$M94 :
	rb	0f214h.0
_$M95 :
	mov	r0,	r10
	and	r0,	#01h
	beq	_$M96
	sb	0f214h.1
	bal	_$M97
_$M96 :
	rb	0f214h.1
_$M97 :

;;	P22MD = bit2; P24MD = bit4;
CLINEA 0000H 0001H 0141H 0002H 001CH
	l	r0,	2[fp]
	and	r0,	#01h
	beq	_$M98
	sb	0f214h.2
	bal	_$M99
_$M98 :
	rb	0f214h.2
_$M99 :
	l	r0,	4[fp]
	and	r0,	#01h
	beq	_$M100
	sb	0f214h.4
	bal	_$M101
_$M100 :
	rb	0f214h.4
_$M101 :

;;   return (PORT_DEPLOY_OK);	   	
CLINEA 0000H 0001H 0142H 0004H 0020H
	mov	er0,	#0 
	bal	_$L144
CBLOCKEND 9 1 323
CFUNCTIONEND 9


	rseg $$P3D_init$port
CFUNCTION 10

_P3D_init	:
CBLOCK 10 1 356

;;{
CLINEA 0000H 0001H 0164H 0001H 0001H
	push	fp
	mov	fp,	sp
	push	xr8
	mov	er8,	er0
	mov	er10,	er2
CBLOCK 10 2 356
CARGUMENT 46H 0002H 0028H "bit0" 02H 00H 01H
CARGUMENT 46H 0002H 0029H "bit1" 02H 00H 01H
CARGUMENT 42H 0002H 0002H "bit2" 02H 00H 01H
CARGUMENT 42H 0002H 0004H "bit3" 02H 00H 01H
CARGUMENT 42H 0002H 0006H "bit4" 02H 00H 01H
CARGUMENT 42H 0002H 0008H "bit5" 02H 00H 01H

;;	   	bit4 > PORT_HIGH || bit5 > PORT_HIGH) {
CLINEA 0000H 0001H 0167H 0006H 002CH
	cmp	r0,	#01h
	cmpc	r1,	#00h
	bgt	_$L160
	cmp	r2,	#01h
	cmpc	r3,	#00h
	bgt	_$L160
	l	er0,	2[fp]
	cmp	r0,	#01h
	cmpc	r1,	#00h
	bgt	_$L160
	l	er0,	4[fp]
	cmp	r0,	#01h
	cmpc	r1,	#00h
	bgt	_$L160
	l	er0,	6[fp]
	cmp	r0,	#01h
	cmpc	r1,	#00h
	bgt	_$L160
	l	er0,	8[fp]
	cmp	r0,	#01h
	cmpc	r1,	#00h
	ble	_$L159
_$L160 :
CBLOCK 10 3 359

;;       	 return (PORT_DEPLOY_FAIL); 
CLINEA 0000H 0001H 0168H 000AH 0024H
	mov	er0,	#-1
CBLOCKEND 10 3 361
CBLOCKEND 10 2 366

;;  }
CLINEA 0000H 0001H 016EH 0003H 0003H
_$L158 :
	pop	xr8
	mov	sp,	fp
	pop	fp
	rt

;;	   	}
CLINEA 0000H 0000H 0169H 0006H 0006H
_$L159 :

;;	P30D = bit0; P31D = bit1;
CLINEA 0000H 0001H 016AH 0002H 001AH
	mov	r0,	r8
	and	r0,	#01h
	beq	_$M103
	sb	0f218h.0
	bal	_$M104
_$M103 :
	rb	0f218h.0
_$M104 :
	mov	r0,	r10
	and	r0,	#01h
	beq	_$M105
	sb	0f218h.1
	bal	_$M106
_$M105 :
	rb	0f218h.1
_$M106 :

;;	P32D = bit2; P33D = bit3;
CLINEA 0000H 0001H 016BH 0002H 001AH
	l	r0,	2[fp]
	and	r0,	#01h
	beq	_$M107
	sb	0f218h.2
	bal	_$M108
_$M107 :
	rb	0f218h.2
_$M108 :
	l	r0,	4[fp]
	and	r0,	#01h
	beq	_$M109
	sb	0f218h.3
	bal	_$M110
_$M109 :
	rb	0f218h.3
_$M110 :

;;	P34D = bit4; P35D = bit5;
CLINEA 0000H 0001H 016CH 0002H 001AH
	l	r0,	6[fp]
	and	r0,	#01h
	beq	_$M111
	sb	0f218h.4
	bal	_$M112
_$M111 :
	rb	0f218h.4
_$M112 :
	l	r0,	8[fp]
	and	r0,	#01h
	beq	_$M113
	sb	0f218h.5
	bal	_$M114
_$M113 :
	rb	0f218h.5
_$M114 :

;;   return (PORT_DEPLOY_OK);		
CLINEA 0000H 0001H 016DH 0004H 001DH
	mov	er0,	#0 
	bal	_$L158
CBLOCKEND 10 1 366
CFUNCTIONEND 10


	rseg $$P3DIR_init$port
CFUNCTION 11

_P3DIR_init	:
CBLOCK 11 1 393

;; {
CLINEA 0000H 0001H 0189H 0002H 0002H
	push	fp
	mov	fp,	sp
	push	xr8
	mov	er8,	er0
	mov	er10,	er2
CBLOCK 11 2 393
CARGUMENT 46H 0002H 0028H "bit0" 02H 00H 01H
CARGUMENT 46H 0002H 0029H "bit1" 02H 00H 01H
CARGUMENT 42H 0002H 0002H "bit2" 02H 00H 01H
CARGUMENT 42H 0002H 0004H "bit3" 02H 00H 01H
CARGUMENT 42H 0002H 0006H "bit4" 02H 00H 01H
CARGUMENT 42H 0002H 0008H "bit5" 02H 00H 01H

;;	   	bit4 > PORT_HIGH || bit5 > PORT_HIGH) {
CLINEA 0000H 0001H 018CH 0006H 002CH
	cmp	r0,	#01h
	cmpc	r1,	#00h
	bgt	_$L180
	cmp	r2,	#01h
	cmpc	r3,	#00h
	bgt	_$L180
	l	er0,	2[fp]
	cmp	r0,	#01h
	cmpc	r1,	#00h
	bgt	_$L180
	l	er0,	4[fp]
	cmp	r0,	#01h
	cmpc	r1,	#00h
	bgt	_$L180
	l	er0,	6[fp]
	cmp	r0,	#01h
	cmpc	r1,	#00h
	bgt	_$L180
	l	er0,	8[fp]
	cmp	r0,	#01h
	cmpc	r1,	#00h
	ble	_$L179
_$L180 :
CBLOCK 11 3 396

;;       	 return (PORT_DEPLOY_FAIL); 
CLINEA 0000H 0001H 018DH 000AH 0024H
	mov	er0,	#-1
CBLOCKEND 11 3 398
CBLOCKEND 11 2 403

;;  }
CLINEA 0000H 0001H 0193H 0003H 0003H
_$L178 :
	pop	xr8
	mov	sp,	fp
	pop	fp
	rt

;;	   	}
CLINEA 0000H 0000H 018EH 0006H 0006H
_$L179 :

;;	P30DIR = bit0; P31DIR = bit1;
CLINEA 0000H 0001H 018FH 0002H 001EH
	mov	r0,	r8
	and	r0,	#01h
	beq	_$M116
	sb	0f219h.0
	bal	_$M117
_$M116 :
	rb	0f219h.0
_$M117 :
	mov	r0,	r10
	and	r0,	#01h
	beq	_$M118
	sb	0f219h.1
	bal	_$M119
_$M118 :
	rb	0f219h.1
_$M119 :

;;	P32DIR = bit2; P33DIR = bit3;
CLINEA 0000H 0001H 0190H 0002H 001EH
	l	r0,	2[fp]
	and	r0,	#01h
	beq	_$M120
	sb	0f219h.2
	bal	_$M121
_$M120 :
	rb	0f219h.2
_$M121 :
	l	r0,	4[fp]
	and	r0,	#01h
	beq	_$M122
	sb	0f219h.3
	bal	_$M123
_$M122 :
	rb	0f219h.3
_$M123 :

;;	P34DIR = bit4; P35DIR = bit5;
CLINEA 0000H 0001H 0191H 0002H 001EH
	l	r0,	6[fp]
	and	r0,	#01h
	beq	_$M124
	sb	0f219h.4
	bal	_$M125
_$M124 :
	rb	0f219h.4
_$M125 :
	l	r0,	8[fp]
	and	r0,	#01h
	beq	_$M126
	sb	0f219h.5
	bal	_$M127
_$M126 :
	rb	0f219h.5
_$M127 :

;;   return (PORT_DEPLOY_OK);	
CLINEA 0000H 0001H 0192H 0004H 001CH
	mov	er0,	#0 
	bal	_$L178
CBLOCKEND 11 1 403
CFUNCTIONEND 11


	rseg $$P3CON_0init$port
CFUNCTION 12

_P3CON_0init	:
CBLOCK 12 1 430

;; {
CLINEA 0000H 0001H 01AEH 0002H 0002H
	push	fp
	mov	fp,	sp
	push	xr8
	mov	er8,	er0
	mov	er10,	er2
CBLOCK 12 2 430
CARGUMENT 46H 0002H 0028H "bit0" 02H 00H 01H
CARGUMENT 46H 0002H 0029H "bit1" 02H 00H 01H
CARGUMENT 42H 0002H 0002H "bit2" 02H 00H 01H
CARGUMENT 42H 0002H 0004H "bit3" 02H 00H 01H
CARGUMENT 42H 0002H 0006H "bit4" 02H 00H 01H
CARGUMENT 42H 0002H 0008H "bit5" 02H 00H 01H

;;	   	bit4 > PORT_HIGH || bit5 > PORT_HIGH) {
CLINEA 0000H 0001H 01B1H 0006H 002CH
	cmp	r0,	#01h
	cmpc	r1,	#00h
	bgt	_$L200
	cmp	r2,	#01h
	cmpc	r3,	#00h
	bgt	_$L200
	l	er0,	2[fp]
	cmp	r0,	#01h
	cmpc	r1,	#00h
	bgt	_$L200
	l	er0,	4[fp]
	cmp	r0,	#01h
	cmpc	r1,	#00h
	bgt	_$L200
	l	er0,	6[fp]
	cmp	r0,	#01h
	cmpc	r1,	#00h
	bgt	_$L200
	l	er0,	8[fp]
	cmp	r0,	#01h
	cmpc	r1,	#00h
	ble	_$L199
_$L200 :
CBLOCK 12 3 433

;;       	 return (PORT_DEPLOY_FAIL); 
CLINEA 0000H 0001H 01B2H 000AH 0024H
	mov	er0,	#-1
CBLOCKEND 12 3 435
CBLOCKEND 12 2 440

;;  }
CLINEA 0000H 0001H 01B8H 0003H 0003H
_$L198 :
	pop	xr8
	mov	sp,	fp
	pop	fp
	rt

;;	   	} 
CLINEA 0000H 0000H 01B3H 0006H 0007H
_$L199 :

;;	P30C0 = bit0; P31C0 = bit1;
CLINEA 0000H 0001H 01B4H 0002H 001CH
	mov	r0,	r8
	and	r0,	#01h
	beq	_$M129
	sb	0f21ah.0
	bal	_$M130
_$M129 :
	rb	0f21ah.0
_$M130 :
	mov	r0,	r10
	and	r0,	#01h
	beq	_$M131
	sb	0f21ah.1
	bal	_$M132
_$M131 :
	rb	0f21ah.1
_$M132 :

;;	P32C0 = bit2; P33C0 = bit3;
CLINEA 0000H 0001H 01B5H 0002H 001CH
	l	r0,	2[fp]
	and	r0,	#01h
	beq	_$M133
	sb	0f21ah.2
	bal	_$M134
_$M133 :
	rb	0f21ah.2
_$M134 :
	l	r0,	4[fp]
	and	r0,	#01h
	beq	_$M135
	sb	0f21ah.3
	bal	_$M136
_$M135 :
	rb	0f21ah.3
_$M136 :

;;	P34C0 = bit4; P35C0 = bit5;
CLINEA 0000H 0001H 01B6H 0002H 001CH
	l	r0,	6[fp]
	and	r0,	#01h
	beq	_$M137
	sb	0f21ah.4
	bal	_$M138
_$M137 :
	rb	0f21ah.4
_$M138 :
	l	r0,	8[fp]
	and	r0,	#01h
	beq	_$M139
	sb	0f21ah.5
	bal	_$M140
_$M139 :
	rb	0f21ah.5
_$M140 :

;;   return (PORT_DEPLOY_OK);		
CLINEA 0000H 0001H 01B7H 0004H 001DH
	mov	er0,	#0 
	bal	_$L198
CBLOCKEND 12 1 440
CFUNCTIONEND 12


	rseg $$P3CON_1init$port
CFUNCTION 13

_P3CON_1init	:
CBLOCK 13 1 467

;; {
CLINEA 0000H 0001H 01D3H 0002H 0002H
	push	fp
	mov	fp,	sp
	push	xr8
	mov	er8,	er0
	mov	er10,	er2
CBLOCK 13 2 467
CARGUMENT 46H 0002H 0028H "bit0" 02H 00H 01H
CARGUMENT 46H 0002H 0029H "bit1" 02H 00H 01H
CARGUMENT 42H 0002H 0002H "bit2" 02H 00H 01H
CARGUMENT 42H 0002H 0004H "bit3" 02H 00H 01H
CARGUMENT 42H 0002H 0006H "bit4" 02H 00H 01H
CARGUMENT 42H 0002H 0008H "bit5" 02H 00H 01H

;;	   	bit4 > PORT_HIGH || bit5 > PORT_HIGH) {
CLINEA 0000H 0001H 01D6H 0006H 002CH
	cmp	r0,	#01h
	cmpc	r1,	#00h
	bgt	_$L220
	cmp	r2,	#01h
	cmpc	r3,	#00h
	bgt	_$L220
	l	er0,	2[fp]
	cmp	r0,	#01h
	cmpc	r1,	#00h
	bgt	_$L220
	l	er0,	4[fp]
	cmp	r0,	#01h
	cmpc	r1,	#00h
	bgt	_$L220
	l	er0,	6[fp]
	cmp	r0,	#01h
	cmpc	r1,	#00h
	bgt	_$L220
	l	er0,	8[fp]
	cmp	r0,	#01h
	cmpc	r1,	#00h
	ble	_$L219
_$L220 :
CBLOCK 13 3 470

;;       	 return (PORT_DEPLOY_FAIL); 
CLINEA 0000H 0001H 01D7H 000AH 0024H
	mov	er0,	#-1
CBLOCKEND 13 3 472
CBLOCKEND 13 2 477

;;  }
CLINEA 0000H 0001H 01DDH 0003H 0003H
_$L218 :
	pop	xr8
	mov	sp,	fp
	pop	fp
	rt

;;	   	}
CLINEA 0000H 0000H 01D8H 0006H 0006H
_$L219 :

;;	P30C1 = bit0; P31C1 = bit1;
CLINEA 0000H 0001H 01D9H 0002H 001CH
	mov	r0,	r8
	and	r0,	#01h
	beq	_$M142
	sb	0f21bh.0
	bal	_$M143
_$M142 :
	rb	0f21bh.0
_$M143 :
	mov	r0,	r10
	and	r0,	#01h
	beq	_$M144
	sb	0f21bh.1
	bal	_$M145
_$M144 :
	rb	0f21bh.1
_$M145 :

;;	P32C1 = bit2; P33C1 = bit3;
CLINEA 0000H 0001H 01DAH 0002H 001CH
	l	r0,	2[fp]
	and	r0,	#01h
	beq	_$M146
	sb	0f21bh.2
	bal	_$M147
_$M146 :
	rb	0f21bh.2
_$M147 :
	l	r0,	4[fp]
	and	r0,	#01h
	beq	_$M148
	sb	0f21bh.3
	bal	_$M149
_$M148 :
	rb	0f21bh.3
_$M149 :

;;	P34C1 = bit4; P35C1 = bit5;
CLINEA 0000H 0001H 01DBH 0002H 001CH
	l	r0,	6[fp]
	and	r0,	#01h
	beq	_$M150
	sb	0f21bh.4
	bal	_$M151
_$M150 :
	rb	0f21bh.4
_$M151 :
	l	r0,	8[fp]
	and	r0,	#01h
	beq	_$M152
	sb	0f21bh.5
	bal	_$M153
_$M152 :
	rb	0f21bh.5
_$M153 :

;;   return (PORT_DEPLOY_OK);	   	
CLINEA 0000H 0001H 01DCH 0004H 0020H
	mov	er0,	#0 
	bal	_$L218
CBLOCKEND 13 1 477
CFUNCTIONEND 13


	rseg $$P3MOD_0init$port
CFUNCTION 14

_P3MOD_0init	:
CBLOCK 14 1 504

;; {
CLINEA 0000H 0001H 01F8H 0002H 0002H
	push	fp
	mov	fp,	sp
	push	xr8
	mov	er8,	er0
	mov	er10,	er2
CBLOCK 14 2 504
CARGUMENT 46H 0002H 0028H "bit0" 02H 00H 01H
CARGUMENT 46H 0002H 0029H "bit1" 02H 00H 01H
CARGUMENT 42H 0002H 0002H "bit2" 02H 00H 01H
CARGUMENT 42H 0002H 0004H "bit3" 02H 00H 01H
CARGUMENT 42H 0002H 0006H "bit4" 02H 00H 01H
CARGUMENT 42H 0002H 0008H "bit5" 02H 00H 01H

;;	   	bit4 > PORT_HIGH || bit5 > PORT_HIGH) {
CLINEA 0000H 0001H 01FBH 0006H 002CH
	cmp	r0,	#01h
	cmpc	r1,	#00h
	bgt	_$L240
	cmp	r2,	#01h
	cmpc	r3,	#00h
	bgt	_$L240
	l	er0,	2[fp]
	cmp	r0,	#01h
	cmpc	r1,	#00h
	bgt	_$L240
	l	er0,	4[fp]
	cmp	r0,	#01h
	cmpc	r1,	#00h
	bgt	_$L240
	l	er0,	6[fp]
	cmp	r0,	#01h
	cmpc	r1,	#00h
	bgt	_$L240
	l	er0,	8[fp]
	cmp	r0,	#01h
	cmpc	r1,	#00h
	ble	_$L239
_$L240 :
CBLOCK 14 3 507

;;       	 return (PORT_DEPLOY_FAIL); 
CLINEA 0000H 0001H 01FCH 000AH 0024H
	mov	er0,	#-1
CBLOCKEND 14 3 509
CBLOCKEND 14 2 514

;;  }
CLINEA 0000H 0001H 0202H 0003H 0003H
_$L238 :
	pop	xr8
	mov	sp,	fp
	pop	fp
	rt

;;	   	}
CLINEA 0000H 0000H 01FDH 0006H 0006H
_$L239 :

;;	P30MD0 = bit0; P31MD0 = bit1;
CLINEA 0000H 0001H 01FEH 0002H 001EH
	mov	r0,	r8
	and	r0,	#01h
	beq	_$M155
	sb	0f21ch.0
	bal	_$M156
_$M155 :
	rb	0f21ch.0
_$M156 :
	mov	r0,	r10
	and	r0,	#01h
	beq	_$M157
	sb	0f21ch.1
	bal	_$M158
_$M157 :
	rb	0f21ch.1
_$M158 :

;;	P32MD0 = bit2; P33MD0 = bit3;
CLINEA 0000H 0001H 01FFH 0002H 001EH
	l	r0,	2[fp]
	and	r0,	#01h
	beq	_$M159
	sb	0f21ch.2
	bal	_$M160
_$M159 :
	rb	0f21ch.2
_$M160 :
	l	r0,	4[fp]
	and	r0,	#01h
	beq	_$M161
	sb	0f21ch.3
	bal	_$M162
_$M161 :
	rb	0f21ch.3
_$M162 :

;;	P34MD0 = bit4; P35MD0 = bit5;
CLINEA 0000H 0001H 0200H 0002H 001EH
	l	r0,	6[fp]
	and	r0,	#01h
	beq	_$M163
	sb	0f21ch.4
	bal	_$M164
_$M163 :
	rb	0f21ch.4
_$M164 :
	l	r0,	8[fp]
	and	r0,	#01h
	beq	_$M165
	sb	0f21ch.5
	bal	_$M166
_$M165 :
	rb	0f21ch.5
_$M166 :

;;   return (PORT_DEPLOY_OK);	   	
CLINEA 0000H 0001H 0201H 0004H 0020H
	mov	er0,	#0 
	bal	_$L238
CBLOCKEND 14 1 514
CFUNCTIONEND 14


	rseg $$P4D_init$port
CFUNCTION 15

_P4D_init	:
CBLOCK 15 1 553

;; {
CLINEA 0000H 0001H 0229H 0002H 0002H
	push	fp
	mov	fp,	sp
	push	xr8
	mov	er8,	er0
	mov	er10,	er2
CBLOCK 15 2 553
CARGUMENT 46H 0002H 0028H "bit0" 02H 00H 01H
CARGUMENT 46H 0002H 0029H "bit1" 02H 00H 01H
CARGUMENT 42H 0002H 0002H "bit2" 02H 00H 01H
CARGUMENT 42H 0002H 0004H "bit3" 02H 00H 01H
CARGUMENT 42H 0002H 0006H "bit4" 02H 00H 01H
CARGUMENT 42H 0002H 0008H "bit5" 02H 00H 01H
CARGUMENT 42H 0002H 000AH "bit6" 02H 00H 01H
CARGUMENT 42H 0002H 000CH "bit7" 02H 00H 01H

;;	     bit6 > PORT_HIGH || bit7 > PORT_HIGH) {
CLINEA 0000H 0001H 022DH 0007H 002DH
	cmp	r0,	#01h
	cmpc	r1,	#00h
	bgt	_$L260
	cmp	r2,	#01h
	cmpc	r3,	#00h
	bgt	_$L260
	l	er0,	2[fp]
	cmp	r0,	#01h
	cmpc	r1,	#00h
	bgt	_$L260
	l	er0,	4[fp]
	cmp	r0,	#01h
	cmpc	r1,	#00h
	bgt	_$L260
	l	er0,	6[fp]
	cmp	r0,	#01h
	cmpc	r1,	#00h
	bgt	_$L260
	l	er0,	8[fp]
	cmp	r0,	#01h
	cmpc	r1,	#00h
	bgt	_$L260
	l	er0,	10[fp]
	cmp	r0,	#01h
	cmpc	r1,	#00h
	bgt	_$L260
	l	er0,	12[fp]
	cmp	r0,	#01h
	cmpc	r1,	#00h
	ble	_$L259
_$L260 :
CBLOCK 15 3 557

;;       	 return (PORT_DEPLOY_FAIL);
CLINEA 0000H 0001H 022EH 000AH 0023H
	mov	er0,	#-1
CBLOCKEND 15 3 559
CBLOCKEND 15 2 565

;;  }
CLINEA 0000H 0001H 0235H 0003H 0003H
_$L258 :
	pop	xr8
	mov	sp,	fp
	pop	fp
	rt

;;        }
CLINEA 0000H 0000H 022FH 0009H 0009H
_$L259 :

;;	P40D = bit0; P41D = bit1;
CLINEA 0000H 0001H 0230H 0002H 001AH
	mov	r0,	r8
	and	r0,	#01h
	beq	_$M168
	sb	0f220h.0
	bal	_$M169
_$M168 :
	rb	0f220h.0
_$M169 :
	mov	r0,	r10
	and	r0,	#01h
	beq	_$M170
	sb	0f220h.1
	bal	_$M171
_$M170 :
	rb	0f220h.1
_$M171 :

;;	P42D = bit2; P43D = bit3;
CLINEA 0000H 0001H 0231H 0002H 001AH
	l	r0,	2[fp]
	and	r0,	#01h
	beq	_$M172
	sb	0f220h.2
	bal	_$M173
_$M172 :
	rb	0f220h.2
_$M173 :
	l	r0,	4[fp]
	and	r0,	#01h
	beq	_$M174
	sb	0f220h.3
	bal	_$M175
_$M174 :
	rb	0f220h.3
_$M175 :

;;	P44D = bit4; P45D = bit5;
CLINEA 0000H 0001H 0232H 0002H 001AH
	l	r0,	6[fp]
	and	r0,	#01h
	beq	_$M176
	sb	0f220h.4
	bal	_$M177
_$M176 :
	rb	0f220h.4
_$M177 :
	l	r0,	8[fp]
	and	r0,	#01h
	beq	_$M178
	sb	0f220h.5
	bal	_$M179
_$M178 :
	rb	0f220h.5
_$M179 :

;;	P46D = bit6; P47D = bit7;
CLINEA 0000H 0001H 0233H 0002H 001AH
	l	r0,	10[fp]
	and	r0,	#01h
	beq	_$M180
	sb	0f220h.6
	bal	_$M181
_$M180 :
	rb	0f220h.6
_$M181 :
	l	r0,	12[fp]
	and	r0,	#01h
	beq	_$M182
	sb	0f220h.7
	bal	_$M183
_$M182 :
	rb	0f220h.7
_$M183 :

;;   return (PORT_DEPLOY_OK);   	
CLINEA 0000H 0001H 0234H 0004H 001FH
	mov	er0,	#0 
	b	_$L258
CBLOCKEND 15 1 565
CFUNCTIONEND 15


	rseg $$P4DIR_init$port
CFUNCTION 16

_P4DIR_init	:
CBLOCK 16 1 598

;; {
CLINEA 0000H 0001H 0256H 0002H 0002H
	push	fp
	mov	fp,	sp
	push	xr8
	mov	er8,	er0
	mov	er10,	er2
CBLOCK 16 2 598
CARGUMENT 46H 0002H 0028H "bit0" 02H 00H 01H
CARGUMENT 46H 0002H 0029H "bit1" 02H 00H 01H
CARGUMENT 42H 0002H 0002H "bit2" 02H 00H 01H
CARGUMENT 42H 0002H 0004H "bit3" 02H 00H 01H
CARGUMENT 42H 0002H 0006H "bit4" 02H 00H 01H
CARGUMENT 42H 0002H 0008H "bit5" 02H 00H 01H
CARGUMENT 42H 0002H 000AH "bit6" 02H 00H 01H
CARGUMENT 42H 0002H 000CH "bit7" 02H 00H 01H

;;	     bit6 > PORT_HIGH || bit7 > PORT_HIGH) {
CLINEA 0000H 0001H 025AH 0007H 002DH
	cmp	r0,	#01h
	cmpc	r1,	#00h
	bgt	_$L286
	cmp	r2,	#01h
	cmpc	r3,	#00h
	bgt	_$L286
	l	er0,	2[fp]
	cmp	r0,	#01h
	cmpc	r1,	#00h
	bgt	_$L286
	l	er0,	4[fp]
	cmp	r0,	#01h
	cmpc	r1,	#00h
	bgt	_$L286
	l	er0,	6[fp]
	cmp	r0,	#01h
	cmpc	r1,	#00h
	bgt	_$L286
	l	er0,	8[fp]
	cmp	r0,	#01h
	cmpc	r1,	#00h
	bgt	_$L286
	l	er0,	10[fp]
	cmp	r0,	#01h
	cmpc	r1,	#00h
	bgt	_$L286
	l	er0,	12[fp]
	cmp	r0,	#01h
	cmpc	r1,	#00h
	ble	_$L285
_$L286 :
CBLOCK 16 3 602

;;       	 return (PORT_DEPLOY_FAIL);
CLINEA 0000H 0001H 025BH 000AH 0023H
	mov	er0,	#-1
CBLOCKEND 16 3 604
CBLOCKEND 16 2 610

;;  }
CLINEA 0000H 0001H 0262H 0003H 0003H
_$L284 :
	pop	xr8
	mov	sp,	fp
	pop	fp
	rt

;;        }
CLINEA 0000H 0000H 025CH 0009H 0009H
_$L285 :

;;	P40DIR = bit0; P41DIR = bit1;
CLINEA 0000H 0001H 025DH 0002H 001EH
	mov	r0,	r8
	and	r0,	#01h
	beq	_$M185
	sb	0f221h.0
	bal	_$M186
_$M185 :
	rb	0f221h.0
_$M186 :
	mov	r0,	r10
	and	r0,	#01h
	beq	_$M187
	sb	0f221h.1
	bal	_$M188
_$M187 :
	rb	0f221h.1
_$M188 :

;;	P42DIR = bit2; P43DIR = bit3;
CLINEA 0000H 0001H 025EH 0002H 001EH
	l	r0,	2[fp]
	and	r0,	#01h
	beq	_$M189
	sb	0f221h.2
	bal	_$M190
_$M189 :
	rb	0f221h.2
_$M190 :
	l	r0,	4[fp]
	and	r0,	#01h
	beq	_$M191
	sb	0f221h.3
	bal	_$M192
_$M191 :
	rb	0f221h.3
_$M192 :

;;	P44DIR = bit4; P45DIR = bit5;
CLINEA 0000H 0001H 025FH 0002H 001EH
	l	r0,	6[fp]
	and	r0,	#01h
	beq	_$M193
	sb	0f221h.4
	bal	_$M194
_$M193 :
	rb	0f221h.4
_$M194 :
	l	r0,	8[fp]
	and	r0,	#01h
	beq	_$M195
	sb	0f221h.5
	bal	_$M196
_$M195 :
	rb	0f221h.5
_$M196 :

;;	P46DIR = bit6; P47DIR = bit7;
CLINEA 0000H 0001H 0260H 0002H 001EH
	l	r0,	10[fp]
	and	r0,	#01h
	beq	_$M197
	sb	0f221h.6
	bal	_$M198
_$M197 :
	rb	0f221h.6
_$M198 :
	l	r0,	12[fp]
	and	r0,	#01h
	beq	_$M199
	sb	0f221h.7
	bal	_$M200
_$M199 :
	rb	0f221h.7
_$M200 :

;;   return (PORT_DEPLOY_OK);   	
CLINEA 0000H 0001H 0261H 0004H 001FH
	mov	er0,	#0 
	b	_$L284
CBLOCKEND 16 1 610
CFUNCTIONEND 16


	rseg $$P4CON_0init$port
CFUNCTION 17

_P4CON_0init	:
CBLOCK 17 1 643

;; {
CLINEA 0000H 0001H 0283H 0002H 0002H
	push	fp
	mov	fp,	sp
	push	xr8
	mov	er8,	er0
	mov	er10,	er2
CBLOCK 17 2 643
CARGUMENT 46H 0002H 0028H "bit0" 02H 00H 01H
CARGUMENT 46H 0002H 0029H "bit1" 02H 00H 01H
CARGUMENT 42H 0002H 0002H "bit2" 02H 00H 01H
CARGUMENT 42H 0002H 0004H "bit3" 02H 00H 01H
CARGUMENT 42H 0002H 0006H "bit4" 02H 00H 01H
CARGUMENT 42H 0002H 0008H "bit5" 02H 00H 01H
CARGUMENT 42H 0002H 000AH "bit6" 02H 00H 01H
CARGUMENT 42H 0002H 000CH "bit7" 02H 00H 01H

;;	     bit6 > PORT_HIGH || bit7 > PORT_HIGH) {
CLINEA 0000H 0001H 0287H 0007H 002DH
	cmp	r0,	#01h
	cmpc	r1,	#00h
	bgt	_$L312
	cmp	r2,	#01h
	cmpc	r3,	#00h
	bgt	_$L312
	l	er0,	2[fp]
	cmp	r0,	#01h
	cmpc	r1,	#00h
	bgt	_$L312
	l	er0,	4[fp]
	cmp	r0,	#01h
	cmpc	r1,	#00h
	bgt	_$L312
	l	er0,	6[fp]
	cmp	r0,	#01h
	cmpc	r1,	#00h
	bgt	_$L312
	l	er0,	8[fp]
	cmp	r0,	#01h
	cmpc	r1,	#00h
	bgt	_$L312
	l	er0,	10[fp]
	cmp	r0,	#01h
	cmpc	r1,	#00h
	bgt	_$L312
	l	er0,	12[fp]
	cmp	r0,	#01h
	cmpc	r1,	#00h
	ble	_$L311
_$L312 :
CBLOCK 17 3 647

;;       	 return (PORT_DEPLOY_FAIL);
CLINEA 0000H 0001H 0288H 000AH 0023H
	mov	er0,	#-1
CBLOCKEND 17 3 649
CBLOCKEND 17 2 655

;;  }
CLINEA 0000H 0001H 028FH 0003H 0003H
_$L310 :
	pop	xr8
	mov	sp,	fp
	pop	fp
	rt

;;        }
CLINEA 0000H 0000H 0289H 0009H 0009H
_$L311 :

;;	P40C0 = bit0; P41C0 = bit1;
CLINEA 0000H 0001H 028AH 0002H 001CH
	mov	r0,	r8
	and	r0,	#01h
	beq	_$M202
	sb	0f222h.0
	bal	_$M203
_$M202 :
	rb	0f222h.0
_$M203 :
	mov	r0,	r10
	and	r0,	#01h
	beq	_$M204
	sb	0f222h.1
	bal	_$M205
_$M204 :
	rb	0f222h.1
_$M205 :

;;	P42C0 = bit2; P43C0 = bit3;
CLINEA 0000H 0001H 028BH 0002H 001CH
	l	r0,	2[fp]
	and	r0,	#01h
	beq	_$M206
	sb	0f222h.2
	bal	_$M207
_$M206 :
	rb	0f222h.2
_$M207 :
	l	r0,	4[fp]
	and	r0,	#01h
	beq	_$M208
	sb	0f222h.3
	bal	_$M209
_$M208 :
	rb	0f222h.3
_$M209 :

;;	P44C0 = bit4; P45C0 = bit5;
CLINEA 0000H 0001H 028CH 0002H 001CH
	l	r0,	6[fp]
	and	r0,	#01h
	beq	_$M210
	sb	0f222h.4
	bal	_$M211
_$M210 :
	rb	0f222h.4
_$M211 :
	l	r0,	8[fp]
	and	r0,	#01h
	beq	_$M212
	sb	0f222h.5
	bal	_$M213
_$M212 :
	rb	0f222h.5
_$M213 :

;;	P46C0 = bit6; P47C0 = bit7;
CLINEA 0000H 0001H 028DH 0002H 001CH
	l	r0,	10[fp]
	and	r0,	#01h
	beq	_$M214
	sb	0f222h.6
	bal	_$M215
_$M214 :
	rb	0f222h.6
_$M215 :
	l	r0,	12[fp]
	and	r0,	#01h
	beq	_$M216
	sb	0f222h.7
	bal	_$M217
_$M216 :
	rb	0f222h.7
_$M217 :

;;   return (PORT_DEPLOY_OK);   	
CLINEA 0000H 0001H 028EH 0004H 001FH
	mov	er0,	#0 
	b	_$L310
CBLOCKEND 17 1 655
CFUNCTIONEND 17


	rseg $$P4CON_1init$port
CFUNCTION 18

_P4CON_1init	:
CBLOCK 18 1 688

;; {
CLINEA 0000H 0001H 02B0H 0002H 0002H
	push	fp
	mov	fp,	sp
	push	xr8
	mov	er8,	er0
	mov	er10,	er2
CBLOCK 18 2 688
CARGUMENT 46H 0002H 0028H "bit0" 02H 00H 01H
CARGUMENT 46H 0002H 0029H "bit1" 02H 00H 01H
CARGUMENT 42H 0002H 0002H "bit2" 02H 00H 01H
CARGUMENT 42H 0002H 0004H "bit3" 02H 00H 01H
CARGUMENT 42H 0002H 0006H "bit4" 02H 00H 01H
CARGUMENT 42H 0002H 0008H "bit5" 02H 00H 01H
CARGUMENT 42H 0002H 000AH "bit6" 02H 00H 01H
CARGUMENT 42H 0002H 000CH "bit7" 02H 00H 01H

;;	     bit6 > PORT_HIGH || bit7 > PORT_HIGH) {
CLINEA 0000H 0001H 02B4H 0007H 002DH
	cmp	r0,	#01h
	cmpc	r1,	#00h
	bgt	_$L338
	cmp	r2,	#01h
	cmpc	r3,	#00h
	bgt	_$L338
	l	er0,	2[fp]
	cmp	r0,	#01h
	cmpc	r1,	#00h
	bgt	_$L338
	l	er0,	4[fp]
	cmp	r0,	#01h
	cmpc	r1,	#00h
	bgt	_$L338
	l	er0,	6[fp]
	cmp	r0,	#01h
	cmpc	r1,	#00h
	bgt	_$L338
	l	er0,	8[fp]
	cmp	r0,	#01h
	cmpc	r1,	#00h
	bgt	_$L338
	l	er0,	10[fp]
	cmp	r0,	#01h
	cmpc	r1,	#00h
	bgt	_$L338
	l	er0,	12[fp]
	cmp	r0,	#01h
	cmpc	r1,	#00h
	ble	_$L337
_$L338 :
CBLOCK 18 3 692

;;       	 return (PORT_DEPLOY_FAIL);
CLINEA 0000H 0001H 02B5H 000AH 0023H
	mov	er0,	#-1
CBLOCKEND 18 3 694
CBLOCKEND 18 2 700

;;  }
CLINEA 0000H 0001H 02BCH 0003H 0003H
_$L336 :
	pop	xr8
	mov	sp,	fp
	pop	fp
	rt

;;        }
CLINEA 0000H 0000H 02B6H 0009H 0009H
_$L337 :

;;	P40C1 = bit0; P41C1 = bit1;
CLINEA 0000H 0001H 02B7H 0002H 001CH
	mov	r0,	r8
	and	r0,	#01h
	beq	_$M219
	sb	0f223h.0
	bal	_$M220
_$M219 :
	rb	0f223h.0
_$M220 :
	mov	r0,	r10
	and	r0,	#01h
	beq	_$M221
	sb	0f223h.1
	bal	_$M222
_$M221 :
	rb	0f223h.1
_$M222 :

;;	P42C1 = bit2; P43C1 = bit3;
CLINEA 0000H 0001H 02B8H 0002H 001CH
	l	r0,	2[fp]
	and	r0,	#01h
	beq	_$M223
	sb	0f223h.2
	bal	_$M224
_$M223 :
	rb	0f223h.2
_$M224 :
	l	r0,	4[fp]
	and	r0,	#01h
	beq	_$M225
	sb	0f223h.3
	bal	_$M226
_$M225 :
	rb	0f223h.3
_$M226 :

;;	P44C1 = bit4; P45C1 = bit5;
CLINEA 0000H 0001H 02B9H 0002H 001CH
	l	r0,	6[fp]
	and	r0,	#01h
	beq	_$M227
	sb	0f223h.4
	bal	_$M228
_$M227 :
	rb	0f223h.4
_$M228 :
	l	r0,	8[fp]
	and	r0,	#01h
	beq	_$M229
	sb	0f223h.5
	bal	_$M230
_$M229 :
	rb	0f223h.5
_$M230 :

;;	P46C1 = bit6; P47C1 = bit7;
CLINEA 0000H 0001H 02BAH 0002H 001CH
	l	r0,	10[fp]
	and	r0,	#01h
	beq	_$M231
	sb	0f223h.6
	bal	_$M232
_$M231 :
	rb	0f223h.6
_$M232 :
	l	r0,	12[fp]
	and	r0,	#01h
	beq	_$M233
	sb	0f223h.7
	bal	_$M234
_$M233 :
	rb	0f223h.7
_$M234 :

;;   return (PORT_DEPLOY_OK);   	
CLINEA 0000H 0001H 02BBH 0004H 001FH
	mov	er0,	#0 
	b	_$L336
CBLOCKEND 18 1 700
CFUNCTIONEND 18


	rseg $$P4MOD_0init$port
CFUNCTION 19

_P4MOD_0init	:
CBLOCK 19 1 733

;; {
CLINEA 0000H 0001H 02DDH 0002H 0002H
	push	fp
	mov	fp,	sp
	push	xr8
	mov	er8,	er0
	mov	er10,	er2
CBLOCK 19 2 733
CARGUMENT 46H 0002H 0028H "bit0" 02H 00H 01H
CARGUMENT 46H 0002H 0029H "bit1" 02H 00H 01H
CARGUMENT 42H 0002H 0002H "bit2" 02H 00H 01H
CARGUMENT 42H 0002H 0004H "bit3" 02H 00H 01H
CARGUMENT 42H 0002H 0006H "bit4" 02H 00H 01H
CARGUMENT 42H 0002H 0008H "bit5" 02H 00H 01H
CARGUMENT 42H 0002H 000AH "bit6" 02H 00H 01H
CARGUMENT 42H 0002H 000CH "bit7" 02H 00H 01H

;;	     bit6 > PORT_HIGH || bit7 > PORT_HIGH) {
CLINEA 0000H 0001H 02E1H 0007H 002DH
	cmp	r0,	#01h
	cmpc	r1,	#00h
	bgt	_$L364
	cmp	r2,	#01h
	cmpc	r3,	#00h
	bgt	_$L364
	l	er0,	2[fp]
	cmp	r0,	#01h
	cmpc	r1,	#00h
	bgt	_$L364
	l	er0,	4[fp]
	cmp	r0,	#01h
	cmpc	r1,	#00h
	bgt	_$L364
	l	er0,	6[fp]
	cmp	r0,	#01h
	cmpc	r1,	#00h
	bgt	_$L364
	l	er0,	8[fp]
	cmp	r0,	#01h
	cmpc	r1,	#00h
	bgt	_$L364
	l	er0,	10[fp]
	cmp	r0,	#01h
	cmpc	r1,	#00h
	bgt	_$L364
	l	er0,	12[fp]
	cmp	r0,	#01h
	cmpc	r1,	#00h
	ble	_$L363
_$L364 :
CBLOCK 19 3 737

;;       	 return (PORT_DEPLOY_FAIL);
CLINEA 0000H 0001H 02E2H 000AH 0023H
	mov	er0,	#-1
CBLOCKEND 19 3 739
CBLOCKEND 19 2 745

;;  }
CLINEA 0000H 0001H 02E9H 0003H 0003H
_$L362 :
	pop	xr8
	mov	sp,	fp
	pop	fp
	rt

;;        }
CLINEA 0000H 0000H 02E3H 0009H 0009H
_$L363 :

;;	P40MD0 = bit0; P41MD0 = bit1;
CLINEA 0000H 0001H 02E4H 0002H 001EH
	mov	r0,	r8
	and	r0,	#01h
	beq	_$M236
	sb	0f224h.0
	bal	_$M237
_$M236 :
	rb	0f224h.0
_$M237 :
	mov	r0,	r10
	and	r0,	#01h
	beq	_$M238
	sb	0f224h.1
	bal	_$M239
_$M238 :
	rb	0f224h.1
_$M239 :

;;	P42MD0 = bit2; P43MD0 = bit3;
CLINEA 0000H 0001H 02E5H 0002H 001EH
	l	r0,	2[fp]
	and	r0,	#01h
	beq	_$M240
	sb	0f224h.2
	bal	_$M241
_$M240 :
	rb	0f224h.2
_$M241 :
	l	r0,	4[fp]
	and	r0,	#01h
	beq	_$M242
	sb	0f224h.3
	bal	_$M243
_$M242 :
	rb	0f224h.3
_$M243 :

;;	P44MD0 = bit4; P45MD0 = bit5;
CLINEA 0000H 0001H 02E6H 0002H 001EH
	l	r0,	6[fp]
	and	r0,	#01h
	beq	_$M244
	sb	0f224h.4
	bal	_$M245
_$M244 :
	rb	0f224h.4
_$M245 :
	l	r0,	8[fp]
	and	r0,	#01h
	beq	_$M246
	sb	0f224h.5
	bal	_$M247
_$M246 :
	rb	0f224h.5
_$M247 :

;;	P46MD0 = bit6; P47MD0 = bit7;
CLINEA 0000H 0001H 02E7H 0002H 001EH
	l	r0,	10[fp]
	and	r0,	#01h
	beq	_$M248
	sb	0f224h.6
	bal	_$M249
_$M248 :
	rb	0f224h.6
_$M249 :
	l	r0,	12[fp]
	and	r0,	#01h
	beq	_$M250
	sb	0f224h.7
	bal	_$M251
_$M250 :
	rb	0f224h.7
_$M251 :

;;   return (PORT_DEPLOY_OK);   	
CLINEA 0000H 0001H 02E8H 0004H 001FH
	mov	er0,	#0 
	b	_$L362
CBLOCKEND 19 1 745
CFUNCTIONEND 19


	rseg $$P4MOD_1init$port
CFUNCTION 20

_P4MOD_1init	:
CBLOCK 20 1 778

;; {
CLINEA 0000H 0001H 030AH 0002H 0002H
	push	fp
	mov	fp,	sp
	push	xr8
	mov	er8,	er0
	mov	er10,	er2
CBLOCK 20 2 778
CARGUMENT 46H 0002H 0028H "bit0" 02H 00H 01H
CARGUMENT 46H 0002H 0029H "bit1" 02H 00H 01H
CARGUMENT 42H 0002H 0002H "bit2" 02H 00H 01H
CARGUMENT 42H 0002H 0004H "bit3" 02H 00H 01H
CARGUMENT 42H 0002H 0006H "bit4" 02H 00H 01H
CARGUMENT 42H 0002H 0008H "bit5" 02H 00H 01H
CARGUMENT 42H 0002H 000AH "bit6" 02H 00H 01H
CARGUMENT 42H 0002H 000CH "bit7" 02H 00H 01H

;;	     bit6 > PORT_HIGH || bit7 > PORT_HIGH) {
CLINEA 0000H 0001H 030EH 0007H 002DH
	cmp	r0,	#01h
	cmpc	r1,	#00h
	bgt	_$L390
	cmp	r2,	#01h
	cmpc	r3,	#00h
	bgt	_$L390
	l	er0,	2[fp]
	cmp	r0,	#01h
	cmpc	r1,	#00h
	bgt	_$L390
	l	er0,	4[fp]
	cmp	r0,	#01h
	cmpc	r1,	#00h
	bgt	_$L390
	l	er0,	6[fp]
	cmp	r0,	#01h
	cmpc	r1,	#00h
	bgt	_$L390
	l	er0,	8[fp]
	cmp	r0,	#01h
	cmpc	r1,	#00h
	bgt	_$L390
	l	er0,	10[fp]
	cmp	r0,	#01h
	cmpc	r1,	#00h
	bgt	_$L390
	l	er0,	12[fp]
	cmp	r0,	#01h
	cmpc	r1,	#00h
	ble	_$L389
_$L390 :
CBLOCK 20 3 782

;;       	 return (PORT_DEPLOY_FAIL);
CLINEA 0000H 0001H 030FH 000AH 0023H
	mov	er0,	#-1
CBLOCKEND 20 3 784
CBLOCKEND 20 2 790

;;  }
CLINEA 0000H 0001H 0316H 0003H 0003H
_$L388 :
	pop	xr8
	mov	sp,	fp
	pop	fp
	rt

;;        }
CLINEA 0000H 0000H 0310H 0009H 0009H
_$L389 :

;;	P40MD1 = bit0; P41MD1 = bit1;
CLINEA 0000H 0001H 0311H 0002H 001EH
	mov	r0,	r8
	and	r0,	#01h
	beq	_$M253
	sb	0f225h.0
	bal	_$M254
_$M253 :
	rb	0f225h.0
_$M254 :
	mov	r0,	r10
	and	r0,	#01h
	beq	_$M255
	sb	0f225h.1
	bal	_$M256
_$M255 :
	rb	0f225h.1
_$M256 :

;;	P42MD1 = bit2; P43MD1 = bit3;
CLINEA 0000H 0001H 0312H 0002H 001EH
	l	r0,	2[fp]
	and	r0,	#01h
	beq	_$M257
	sb	0f225h.2
	bal	_$M258
_$M257 :
	rb	0f225h.2
_$M258 :
	l	r0,	4[fp]
	and	r0,	#01h
	beq	_$M259
	sb	0f225h.3
	bal	_$M260
_$M259 :
	rb	0f225h.3
_$M260 :

;;	P44MD1 = bit4; P45MD1 = bit5;
CLINEA 0000H 0001H 0313H 0002H 001EH
	l	r0,	6[fp]
	and	r0,	#01h
	beq	_$M261
	sb	0f225h.4
	bal	_$M262
_$M261 :
	rb	0f225h.4
_$M262 :
	l	r0,	8[fp]
	and	r0,	#01h
	beq	_$M263
	sb	0f225h.5
	bal	_$M264
_$M263 :
	rb	0f225h.5
_$M264 :

;;	P46MD1 = bit6; P47MD1 = bit7;
CLINEA 0000H 0001H 0314H 0002H 001EH
	l	r0,	10[fp]
	and	r0,	#01h
	beq	_$M265
	sb	0f225h.6
	bal	_$M266
_$M265 :
	rb	0f225h.6
_$M266 :
	l	r0,	12[fp]
	and	r0,	#01h
	beq	_$M267
	sb	0f225h.7
	bal	_$M268
_$M267 :
	rb	0f225h.7
_$M268 :

;;   return (PORT_DEPLOY_OK);   	
CLINEA 0000H 0001H 0315H 0004H 001FH
	mov	er0,	#0 
	b	_$L388
CBLOCKEND 20 1 790
CFUNCTIONEND 20


	rseg $$P5D_init$port
CFUNCTION 21

_P5D_init	:
CBLOCK 21 1 829

;; {
CLINEA 0000H 0001H 033DH 0002H 0002H
	push	fp
	mov	fp,	sp
	push	xr8
	mov	er8,	er0
	mov	er10,	er2
CBLOCK 21 2 829
CARGUMENT 46H 0002H 0028H "bit0" 02H 00H 01H
CARGUMENT 46H 0002H 0029H "bit1" 02H 00H 01H
CARGUMENT 42H 0002H 0002H "bit2" 02H 00H 01H
CARGUMENT 42H 0002H 0004H "bit3" 02H 00H 01H
CARGUMENT 42H 0002H 0006H "bit4" 02H 00H 01H
CARGUMENT 42H 0002H 0008H "bit5" 02H 00H 01H
CARGUMENT 42H 0002H 000AH "bit6" 02H 00H 01H
CARGUMENT 42H 0002H 000CH "bit7" 02H 00H 01H

;;	     bit6 > PORT_HIGH || bit7 > PORT_HIGH) {
CLINEA 0000H 0001H 0341H 0007H 002DH
	cmp	r0,	#01h
	cmpc	r1,	#00h
	bgt	_$L416
	cmp	r2,	#01h
	cmpc	r3,	#00h
	bgt	_$L416
	l	er0,	2[fp]
	cmp	r0,	#01h
	cmpc	r1,	#00h
	bgt	_$L416
	l	er0,	4[fp]
	cmp	r0,	#01h
	cmpc	r1,	#00h
	bgt	_$L416
	l	er0,	6[fp]
	cmp	r0,	#01h
	cmpc	r1,	#00h
	bgt	_$L416
	l	er0,	8[fp]
	cmp	r0,	#01h
	cmpc	r1,	#00h
	bgt	_$L416
	l	er0,	10[fp]
	cmp	r0,	#01h
	cmpc	r1,	#00h
	bgt	_$L416
	l	er0,	12[fp]
	cmp	r0,	#01h
	cmpc	r1,	#00h
	ble	_$L415
_$L416 :
CBLOCK 21 3 833

;;       	 return (PORT_DEPLOY_FAIL);
CLINEA 0000H 0001H 0342H 000AH 0023H
	mov	er0,	#-1
CBLOCKEND 21 3 835
CBLOCKEND 21 2 841

;;  }
CLINEA 0000H 0001H 0349H 0003H 0003H
_$L414 :
	pop	xr8
	mov	sp,	fp
	pop	fp
	rt

;;        }
CLINEA 0000H 0000H 0343H 0009H 0009H
_$L415 :

;;	P50D = bit0; P51D = bit1;
CLINEA 0000H 0001H 0344H 0002H 001AH
	mov	r0,	r8
	and	r0,	#01h
	beq	_$M270
	sb	0f228h.0
	bal	_$M271
_$M270 :
	rb	0f228h.0
_$M271 :
	mov	r0,	r10
	and	r0,	#01h
	beq	_$M272
	sb	0f228h.1
	bal	_$M273
_$M272 :
	rb	0f228h.1
_$M273 :

;;	P52D = bit2; P53D = bit3;
CLINEA 0000H 0001H 0345H 0002H 001AH
	l	r0,	2[fp]
	and	r0,	#01h
	beq	_$M274
	sb	0f228h.2
	bal	_$M275
_$M274 :
	rb	0f228h.2
_$M275 :
	l	r0,	4[fp]
	and	r0,	#01h
	beq	_$M276
	sb	0f228h.3
	bal	_$M277
_$M276 :
	rb	0f228h.3
_$M277 :

;;	P54D = bit4; P55D = bit5;
CLINEA 0000H 0001H 0346H 0002H 001AH
	l	r0,	6[fp]
	and	r0,	#01h
	beq	_$M278
	sb	0f228h.4
	bal	_$M279
_$M278 :
	rb	0f228h.4
_$M279 :
	l	r0,	8[fp]
	and	r0,	#01h
	beq	_$M280
	sb	0f228h.5
	bal	_$M281
_$M280 :
	rb	0f228h.5
_$M281 :

;;	P56D = bit6; P57D = bit7;
CLINEA 0000H 0001H 0347H 0002H 001AH
	l	r0,	10[fp]
	and	r0,	#01h
	beq	_$M282
	sb	0f228h.6
	bal	_$M283
_$M282 :
	rb	0f228h.6
_$M283 :
	l	r0,	12[fp]
	and	r0,	#01h
	beq	_$M284
	sb	0f228h.7
	bal	_$M285
_$M284 :
	rb	0f228h.7
_$M285 :

;;   return (PORT_DEPLOY_OK);   	
CLINEA 0000H 0001H 0348H 0004H 001FH
	mov	er0,	#0 
	b	_$L414
CBLOCKEND 21 1 841
CFUNCTIONEND 21


	rseg $$P5DIR_init$port
CFUNCTION 22

_P5DIR_init	:
CBLOCK 22 1 874

;; {
CLINEA 0000H 0001H 036AH 0002H 0002H
	push	fp
	mov	fp,	sp
	push	xr8
	mov	er8,	er0
	mov	er10,	er2
CBLOCK 22 2 874
CARGUMENT 46H 0002H 0028H "bit0" 02H 00H 01H
CARGUMENT 46H 0002H 0029H "bit1" 02H 00H 01H
CARGUMENT 42H 0002H 0002H "bit2" 02H 00H 01H
CARGUMENT 42H 0002H 0004H "bit3" 02H 00H 01H
CARGUMENT 42H 0002H 0006H "bit4" 02H 00H 01H
CARGUMENT 42H 0002H 0008H "bit5" 02H 00H 01H
CARGUMENT 42H 0002H 000AH "bit6" 02H 00H 01H
CARGUMENT 42H 0002H 000CH "bit7" 02H 00H 01H

;;	     bit6 > PORT_HIGH || bit7 > PORT_HIGH) {
CLINEA 0000H 0001H 036EH 0007H 002DH
	cmp	r0,	#01h
	cmpc	r1,	#00h
	bgt	_$L442
	cmp	r2,	#01h
	cmpc	r3,	#00h
	bgt	_$L442
	l	er0,	2[fp]
	cmp	r0,	#01h
	cmpc	r1,	#00h
	bgt	_$L442
	l	er0,	4[fp]
	cmp	r0,	#01h
	cmpc	r1,	#00h
	bgt	_$L442
	l	er0,	6[fp]
	cmp	r0,	#01h
	cmpc	r1,	#00h
	bgt	_$L442
	l	er0,	8[fp]
	cmp	r0,	#01h
	cmpc	r1,	#00h
	bgt	_$L442
	l	er0,	10[fp]
	cmp	r0,	#01h
	cmpc	r1,	#00h
	bgt	_$L442
	l	er0,	12[fp]
	cmp	r0,	#01h
	cmpc	r1,	#00h
	ble	_$L441
_$L442 :
CBLOCK 22 3 878

;;       	 return (PORT_DEPLOY_FAIL);
CLINEA 0000H 0001H 036FH 000AH 0023H
	mov	er0,	#-1
CBLOCKEND 22 3 880
CBLOCKEND 22 2 886

;;  }
CLINEA 0000H 0001H 0376H 0003H 0003H
_$L440 :
	pop	xr8
	mov	sp,	fp
	pop	fp
	rt

;;        }
CLINEA 0000H 0000H 0370H 0009H 0009H
_$L441 :

;;	P50DIR = bit0; P51DIR = bit1;
CLINEA 0000H 0001H 0371H 0002H 001EH
	mov	r0,	r8
	and	r0,	#01h
	beq	_$M287
	sb	0f229h.0
	bal	_$M288
_$M287 :
	rb	0f229h.0
_$M288 :
	mov	r0,	r10
	and	r0,	#01h
	beq	_$M289
	sb	0f229h.1
	bal	_$M290
_$M289 :
	rb	0f229h.1
_$M290 :

;;	P52DIR = bit2; P53DIR = bit3;
CLINEA 0000H 0001H 0372H 0002H 001EH
	l	r0,	2[fp]
	and	r0,	#01h
	beq	_$M291
	sb	0f229h.2
	bal	_$M292
_$M291 :
	rb	0f229h.2
_$M292 :
	l	r0,	4[fp]
	and	r0,	#01h
	beq	_$M293
	sb	0f229h.3
	bal	_$M294
_$M293 :
	rb	0f229h.3
_$M294 :

;;	P54DIR = bit4; P55DIR = bit5;
CLINEA 0000H 0001H 0373H 0002H 001EH
	l	r0,	6[fp]
	and	r0,	#01h
	beq	_$M295
	sb	0f229h.4
	bal	_$M296
_$M295 :
	rb	0f229h.4
_$M296 :
	l	r0,	8[fp]
	and	r0,	#01h
	beq	_$M297
	sb	0f229h.5
	bal	_$M298
_$M297 :
	rb	0f229h.5
_$M298 :

;;	P56DIR = bit6; P57DIR = bit7;
CLINEA 0000H 0001H 0374H 0002H 001EH
	l	r0,	10[fp]
	and	r0,	#01h
	beq	_$M299
	sb	0f229h.6
	bal	_$M300
_$M299 :
	rb	0f229h.6
_$M300 :
	l	r0,	12[fp]
	and	r0,	#01h
	beq	_$M301
	sb	0f229h.7
	bal	_$M302
_$M301 :
	rb	0f229h.7
_$M302 :

;;   return (PORT_DEPLOY_OK);   	
CLINEA 0000H 0001H 0375H 0004H 001FH
	mov	er0,	#0 
	b	_$L440
CBLOCKEND 22 1 886
CFUNCTIONEND 22


	rseg $$P5CON_0init$port
CFUNCTION 23

_P5CON_0init	:
CBLOCK 23 1 920

;; {
CLINEA 0000H 0001H 0398H 0002H 0002H
	push	fp
	mov	fp,	sp
	push	xr8
	mov	er8,	er0
	mov	er10,	er2
CBLOCK 23 2 920
CARGUMENT 46H 0002H 0028H "bit0" 02H 00H 01H
CARGUMENT 46H 0002H 0029H "bit1" 02H 00H 01H
CARGUMENT 42H 0002H 0002H "bit2" 02H 00H 01H
CARGUMENT 42H 0002H 0004H "bit3" 02H 00H 01H
CARGUMENT 42H 0002H 0006H "bit4" 02H 00H 01H
CARGUMENT 42H 0002H 0008H "bit5" 02H 00H 01H
CARGUMENT 42H 0002H 000AH "bit6" 02H 00H 01H
CARGUMENT 42H 0002H 000CH "bit7" 02H 00H 01H

;;	     bit6 > PORT_HIGH || bit7 > PORT_HIGH) {
CLINEA 0000H 0001H 039CH 0007H 002DH
	cmp	r0,	#01h
	cmpc	r1,	#00h
	bgt	_$L468
	cmp	r2,	#01h
	cmpc	r3,	#00h
	bgt	_$L468
	l	er0,	2[fp]
	cmp	r0,	#01h
	cmpc	r1,	#00h
	bgt	_$L468
	l	er0,	4[fp]
	cmp	r0,	#01h
	cmpc	r1,	#00h
	bgt	_$L468
	l	er0,	6[fp]
	cmp	r0,	#01h
	cmpc	r1,	#00h
	bgt	_$L468
	l	er0,	8[fp]
	cmp	r0,	#01h
	cmpc	r1,	#00h
	bgt	_$L468
	l	er0,	10[fp]
	cmp	r0,	#01h
	cmpc	r1,	#00h
	bgt	_$L468
	l	er0,	12[fp]
	cmp	r0,	#01h
	cmpc	r1,	#00h
	ble	_$L467
_$L468 :
CBLOCK 23 3 924

;;       	 return (PORT_DEPLOY_FAIL);
CLINEA 0000H 0001H 039DH 000AH 0023H
	mov	er0,	#-1
CBLOCKEND 23 3 926
CBLOCKEND 23 2 932

;;  }
CLINEA 0000H 0001H 03A4H 0003H 0003H
_$L466 :
	pop	xr8
	mov	sp,	fp
	pop	fp
	rt

;;        }
CLINEA 0000H 0000H 039EH 0009H 0009H
_$L467 :

;;	P50C0 = bit0; P51C0 = bit1;
CLINEA 0000H 0001H 039FH 0002H 001CH
	mov	r0,	r8
	and	r0,	#01h
	beq	_$M304
	sb	0f22ah.0
	bal	_$M305
_$M304 :
	rb	0f22ah.0
_$M305 :
	mov	r0,	r10
	and	r0,	#01h
	beq	_$M306
	sb	0f22ah.1
	bal	_$M307
_$M306 :
	rb	0f22ah.1
_$M307 :

;;	P52C0 = bit2; P53C0 = bit3;
CLINEA 0000H 0001H 03A0H 0002H 001CH
	l	r0,	2[fp]
	and	r0,	#01h
	beq	_$M308
	sb	0f22ah.2
	bal	_$M309
_$M308 :
	rb	0f22ah.2
_$M309 :
	l	r0,	4[fp]
	and	r0,	#01h
	beq	_$M310
	sb	0f22ah.3
	bal	_$M311
_$M310 :
	rb	0f22ah.3
_$M311 :

;;	P54C0 = bit4; P55C0 = bit5;
CLINEA 0000H 0001H 03A1H 0002H 001CH
	l	r0,	6[fp]
	and	r0,	#01h
	beq	_$M312
	sb	0f22ah.4
	bal	_$M313
_$M312 :
	rb	0f22ah.4
_$M313 :
	l	r0,	8[fp]
	and	r0,	#01h
	beq	_$M314
	sb	0f22ah.5
	bal	_$M315
_$M314 :
	rb	0f22ah.5
_$M315 :

;;	P56C0 = bit6; P57C0 = bit7;
CLINEA 0000H 0001H 03A2H 0002H 001CH
	l	r0,	10[fp]
	and	r0,	#01h
	beq	_$M316
	sb	0f22ah.6
	bal	_$M317
_$M316 :
	rb	0f22ah.6
_$M317 :
	l	r0,	12[fp]
	and	r0,	#01h
	beq	_$M318
	sb	0f22ah.7
	bal	_$M319
_$M318 :
	rb	0f22ah.7
_$M319 :

;;   return (PORT_DEPLOY_OK);   	
CLINEA 0000H 0001H 03A3H 0004H 001FH
	mov	er0,	#0 
	b	_$L466
CBLOCKEND 23 1 932
CFUNCTIONEND 23


	rseg $$P5CON_1init$port
CFUNCTION 24

_P5CON_1init	:
CBLOCK 24 1 944

;; {
CLINEA 0000H 0001H 03B0H 0002H 0002H
	mov	er2,	er0
CBLOCK 24 2 944
CARGUMENT 46H 0002H 0025H "bit0" 02H 00H 01H

;;   if(bit0 > PORT_HIGH) {
CLINEA 0000H 0001H 03B1H 0004H 0019H
	cmp	r0,	#01h
	cmpc	r1,	#00h
	ble	_$L493
CBLOCK 24 3 945

;;       	 return (PORT_DEPLOY_FAIL);
CLINEA 0000H 0001H 03B2H 000AH 0023H
	mov	er0,	#-1
CBLOCKEND 24 3 947
CBLOCKEND 24 2 950

;;  }
CLINEA 0000H 0001H 03B6H 0003H 0003H
	rt

;;        }
CLINEA 0000H 0000H 03B3H 0009H 0009H
_$L493 :

;;	P5UD = bit0; 
CLINEA 0000H 0001H 03B4H 0002H 000EH
	mov	r0,	r2
	and	r0,	#01h
	beq	_$M321
	sb	0f22bh.0
	bal	_$M322
_$M321 :
	rb	0f22bh.0
_$M322 :

;;   return (PORT_DEPLOY_OK);   	
CLINEA 0000H 0001H 03B5H 0004H 001FH
	mov	er0,	#0 
	rt
CBLOCKEND 24 1 950
CFUNCTIONEND 24


	rseg $$P5MOD_0init$port
CFUNCTION 25

_P5MOD_0init	:
CBLOCK 25 1 977

;; {
CLINEA 0000H 0001H 03D1H 0002H 0002H
	push	fp
	mov	fp,	sp
	push	xr8
	mov	er8,	er0
	mov	er10,	er2
CBLOCK 25 2 977
CARGUMENT 46H 0002H 0028H "bit0" 02H 00H 01H
CARGUMENT 46H 0002H 0029H "bit1" 02H 00H 01H
CARGUMENT 42H 0002H 0002H "bit2" 02H 00H 01H
CARGUMENT 42H 0002H 0004H "bit4" 02H 00H 01H
CARGUMENT 42H 0002H 0006H "bit5" 02H 00H 01H
CARGUMENT 42H 0002H 0008H "bit6" 02H 00H 01H

;;          bit6 > PORT_HIGH) {
CLINEA 0000H 0001H 03D5H 000BH 001DH
	cmp	r0,	#01h
	cmpc	r1,	#00h
	bgt	_$L497
	cmp	r2,	#01h
	cmpc	r3,	#00h
	bgt	_$L497
	l	er0,	2[fp]
	cmp	r0,	#01h
	cmpc	r1,	#00h
	bgt	_$L497
	l	er0,	4[fp]
	cmp	r0,	#01h
	cmpc	r1,	#00h
	bgt	_$L497
	l	er0,	6[fp]
	cmp	r0,	#01h
	cmpc	r1,	#00h
	bgt	_$L497
	l	er0,	8[fp]
	cmp	r0,	#01h
	cmpc	r1,	#00h
	ble	_$L496
_$L497 :
CBLOCK 25 3 981

;;       	 return (PORT_DEPLOY_FAIL);
CLINEA 0000H 0001H 03D6H 000AH 0023H
	mov	er0,	#-1
CBLOCKEND 25 3 983
CBLOCKEND 25 2 989

;;  }
CLINEA 0000H 0001H 03DDH 0003H 0003H
_$L495 :
	pop	xr8
	mov	sp,	fp
	pop	fp
	rt

;;        }
CLINEA 0000H 0000H 03D7H 0009H 0009H
_$L496 :

;;	P50MD0 = bit0; P51MD0 = bit1;
CLINEA 0000H 0001H 03D8H 0002H 001EH
	mov	r0,	r8
	and	r0,	#01h
	beq	_$M324
	sb	0f22ch.0
	bal	_$M325
_$M324 :
	rb	0f22ch.0
_$M325 :
	mov	r0,	r10
	and	r0,	#01h
	beq	_$M326
	sb	0f22ch.1
	bal	_$M327
_$M326 :
	rb	0f22ch.1
_$M327 :

;;	P52MD0 = bit2; 
CLINEA 0000H 0001H 03D9H 0002H 0010H
	l	r0,	2[fp]
	and	r0,	#01h
	beq	_$M328
	sb	0f22ch.2
	bal	_$M329
_$M328 :
	rb	0f22ch.2
_$M329 :

;;	P54MD0 = bit4; P55MD0 = bit5;
CLINEA 0000H 0001H 03DAH 0002H 001EH
	l	r0,	4[fp]
	and	r0,	#01h
	beq	_$M330
	sb	0f22ch.4
	bal	_$M331
_$M330 :
	rb	0f22ch.4
_$M331 :
	l	r0,	6[fp]
	and	r0,	#01h
	beq	_$M332
	sb	0f22ch.5
	bal	_$M333
_$M332 :
	rb	0f22ch.5
_$M333 :

;;	P56MD0 = bit6; 
CLINEA 0000H 0001H 03DBH 0002H 0010H
	l	r0,	8[fp]
	and	r0,	#01h
	beq	_$M334
	sb	0f22ch.6
	bal	_$M335
_$M334 :
	rb	0f22ch.6
_$M335 :

;;   return (PORT_DEPLOY_OK);   	
CLINEA 0000H 0001H 03DCH 0004H 001FH
	mov	er0,	#0 
	bal	_$L495
CBLOCKEND 25 1 989
CFUNCTIONEND 25


	rseg $$P5MOD_1init$port
CFUNCTION 26

_P5MOD_1init	:
CBLOCK 26 1 1018

;; {
CLINEA 0000H 0001H 03FAH 0002H 0002H
	push	fp
	mov	fp,	sp
	push	xr8
	mov	er8,	er0
	mov	er10,	er2
CBLOCK 26 2 1018
CARGUMENT 46H 0002H 0028H "bit0" 02H 00H 01H
CARGUMENT 46H 0002H 0029H "bit1" 02H 00H 01H
CARGUMENT 42H 0002H 0002H "bit2" 02H 00H 01H
CARGUMENT 42H 0002H 0004H "bit4" 02H 00H 01H
CARGUMENT 42H 0002H 0006H "bit5" 02H 00H 01H
CARGUMENT 42H 0002H 0008H "bit6" 02H 00H 01H

;;         bit6 > PORT_HIGH) {
CLINEA 0000H 0001H 03FEH 000AH 001CH
	cmp	r0,	#01h
	cmpc	r1,	#00h
	bgt	_$L517
	cmp	r2,	#01h
	cmpc	r3,	#00h
	bgt	_$L517
	l	er0,	2[fp]
	cmp	r0,	#01h
	cmpc	r1,	#00h
	bgt	_$L517
	l	er0,	4[fp]
	cmp	r0,	#01h
	cmpc	r1,	#00h
	bgt	_$L517
	l	er0,	6[fp]
	cmp	r0,	#01h
	cmpc	r1,	#00h
	bgt	_$L517
	l	er0,	8[fp]
	cmp	r0,	#01h
	cmpc	r1,	#00h
	ble	_$L516
_$L517 :
CBLOCK 26 3 1022

;;       	 return (PORT_DEPLOY_FAIL);
CLINEA 0000H 0001H 03FFH 000AH 0023H
	mov	er0,	#-1
CBLOCKEND 26 3 1024
CBLOCKEND 26 2 1030

;;  }
CLINEA 0000H 0001H 0406H 0003H 0003H
_$L515 :
	pop	xr8
	mov	sp,	fp
	pop	fp
	rt

;;        }
CLINEA 0000H 0000H 0400H 0009H 0009H
_$L516 :

;;	P50MD1 = bit0; P51MD1 = bit1;
CLINEA 0000H 0001H 0401H 0002H 001EH
	mov	r0,	r8
	and	r0,	#01h
	beq	_$M337
	sb	0f22dh.0
	bal	_$M338
_$M337 :
	rb	0f22dh.0
_$M338 :
	mov	r0,	r10
	and	r0,	#01h
	beq	_$M339
	sb	0f22dh.1
	bal	_$M340
_$M339 :
	rb	0f22dh.1
_$M340 :

;;	P52MD1 = bit2; 
CLINEA 0000H 0001H 0402H 0002H 0010H
	l	r0,	2[fp]
	and	r0,	#01h
	beq	_$M341
	sb	0f22dh.2
	bal	_$M342
_$M341 :
	rb	0f22dh.2
_$M342 :

;;	P54MD1 = bit4; P55MD1 = bit5;
CLINEA 0000H 0001H 0403H 0002H 001EH
	l	r0,	4[fp]
	and	r0,	#01h
	beq	_$M343
	sb	0f22dh.4
	bal	_$M344
_$M343 :
	rb	0f22dh.4
_$M344 :
	l	r0,	6[fp]
	and	r0,	#01h
	beq	_$M345
	sb	0f22dh.5
	bal	_$M346
_$M345 :
	rb	0f22dh.5
_$M346 :

;;	P56MD1 = bit6; 
CLINEA 0000H 0001H 0404H 0002H 0010H
	l	r0,	8[fp]
	and	r0,	#01h
	beq	_$M347
	sb	0f22dh.6
	bal	_$M348
_$M347 :
	rb	0f22dh.6
_$M348 :

;;   return (PORT_DEPLOY_OK);   	
CLINEA 0000H 0001H 0405H 0004H 001FH
	mov	er0,	#0 
	bal	_$L515
CBLOCKEND 26 1 1030
CFUNCTIONEND 26


	rseg $$P5SISEL_init$port
CFUNCTION 27

_P5SISEL_init	:
CBLOCK 27 1 1064

;; {
CLINEA 0000H 0001H 0428H 0002H 0002H
	push	fp
	mov	fp,	sp
	push	xr8
	mov	er8,	er0
	mov	er10,	er2
CBLOCK 27 2 1064
CARGUMENT 46H 0002H 0028H "bit0" 02H 00H 01H
CARGUMENT 46H 0002H 0029H "bit1" 02H 00H 01H
CARGUMENT 42H 0002H 0002H "bit2" 02H 00H 01H
CARGUMENT 42H 0002H 0004H "bit3" 02H 00H 01H
CARGUMENT 42H 0002H 0006H "bit4" 02H 00H 01H
CARGUMENT 42H 0002H 0008H "bit5" 02H 00H 01H
CARGUMENT 42H 0002H 000AH "bit6" 02H 00H 01H
CARGUMENT 42H 0002H 000CH "bit7" 02H 00H 01H

;;	     bit6 > PORT_HIGH || bit7 > PORT_HIGH) {
CLINEA 0000H 0001H 042CH 0007H 002DH
	cmp	r0,	#01h
	cmpc	r1,	#00h
	bgt	_$L537
	cmp	r2,	#01h
	cmpc	r3,	#00h
	bgt	_$L537
	l	er0,	2[fp]
	cmp	r0,	#01h
	cmpc	r1,	#00h
	bgt	_$L537
	l	er0,	4[fp]
	cmp	r0,	#01h
	cmpc	r1,	#00h
	bgt	_$L537
	l	er0,	6[fp]
	cmp	r0,	#01h
	cmpc	r1,	#00h
	bgt	_$L537
	l	er0,	8[fp]
	cmp	r0,	#01h
	cmpc	r1,	#00h
	bgt	_$L537
	l	er0,	10[fp]
	cmp	r0,	#01h
	cmpc	r1,	#00h
	bgt	_$L537
	l	er0,	12[fp]
	cmp	r0,	#01h
	cmpc	r1,	#00h
	ble	_$L536
_$L537 :
CBLOCK 27 3 1068

;;       	 return (PORT_DEPLOY_FAIL);
CLINEA 0000H 0001H 042DH 000AH 0023H
	mov	er0,	#-1
CBLOCKEND 27 3 1070
CBLOCKEND 27 2 1076

;;  }
CLINEA 0000H 0001H 0434H 0003H 0003H
_$L535 :
	pop	xr8
	mov	sp,	fp
	pop	fp
	rt

;;        }
CLINEA 0000H 0000H 042EH 0009H 0009H
_$L536 :

;;	P50IS = bit0; P51IS = bit1;
CLINEA 0000H 0001H 042FH 0002H 001CH
	mov	r0,	r8
	and	r0,	#01h
	beq	_$M350
	sb	0f22eh.0
	bal	_$M351
_$M350 :
	rb	0f22eh.0
_$M351 :
	mov	r0,	r10
	and	r0,	#01h
	beq	_$M352
	sb	0f22eh.1
	bal	_$M353
_$M352 :
	rb	0f22eh.1
_$M353 :

;;	P52IS = bit2; P53IS = bit3;
CLINEA 0000H 0001H 0430H 0002H 001CH
	l	r0,	2[fp]
	and	r0,	#01h
	beq	_$M354
	sb	0f22eh.2
	bal	_$M355
_$M354 :
	rb	0f22eh.2
_$M355 :
	l	r0,	4[fp]
	and	r0,	#01h
	beq	_$M356
	sb	0f22eh.3
	bal	_$M357
_$M356 :
	rb	0f22eh.3
_$M357 :

;;	P54IS = bit4; P55IS = bit5;
CLINEA 0000H 0001H 0431H 0002H 001CH
	l	r0,	6[fp]
	and	r0,	#01h
	beq	_$M358
	sb	0f22eh.4
	bal	_$M359
_$M358 :
	rb	0f22eh.4
_$M359 :
	l	r0,	8[fp]
	and	r0,	#01h
	beq	_$M360
	sb	0f22eh.5
	bal	_$M361
_$M360 :
	rb	0f22eh.5
_$M361 :

;;	P56IS = bit6; P57IS = bit7;
CLINEA 0000H 0001H 0432H 0002H 001CH
	l	r0,	10[fp]
	and	r0,	#01h
	beq	_$M362
	sb	0f22eh.6
	bal	_$M363
_$M362 :
	rb	0f22eh.6
_$M363 :
	l	r0,	12[fp]
	and	r0,	#01h
	beq	_$M364
	sb	0f22eh.7
	bal	_$M365
_$M364 :
	rb	0f22eh.7
_$M365 :

;;   return (PORT_DEPLOY_OK);   	
CLINEA 0000H 0001H 0433H 0004H 001FH
	mov	er0,	#0 
	b	_$L535
CBLOCKEND 27 1 1076
CFUNCTIONEND 27

	public _PCON_1init
	public _P5SISEL_init
	public _PCON_0init
	public _P0D_init
	public _P2D_init
	public _P3D_init
	public _P4D_init
	public _P5D_init
	public _P3DIR_init
	public _P2MOD_init
	public _P4DIR_init
	public _P5DIR_init
	public _EXICON_0init
	public _EXICON_1init
	public _EXICON_2init
	public _P5CON_1init
	public _P2CON_0init
	public _P4MOD_1init
	public _P3CON_0init
	public _P5MOD_1init
	public _P4CON_0init
	public _P5CON_0init
	public _P3MOD_0init
	public _P2CON_1init
	public _P4MOD_0init
	public _P3CON_1init
	public _P5MOD_0init
	public _P4CON_1init
	extrn code near : _main

	end
