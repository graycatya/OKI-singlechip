;; Compile Options : /TM610409 /MS /near /Imain /Iclk /IINTERR~1 /Ikey /Ilcd /Ilcdshow /Imelody /Ircadc /Itemphum /Itimers /IMACROA~1 /Ieternity /ICLKbuzz /SD /Om /W 1 /Fa_output\_obj\ 
;; Version Number  : Ver.3.54.3
;; File Name       : lcdshow.c

	type (M610409) 
	model small, near
	$$NINITVAR segment data 2h #0h
	$$NINITTAB segment table 2h any
	$$CIK_glint$lcdshow segment code 2h #0h
	$$DATA_INT$lcdshow segment code 2h #0h
	$$DATA_compare$lcdshow segment code 2h #0h
	$$MAX_MIN_realtime$lcdshow segment code 2h #0h
	$$PICK_dataCOR$lcdshow segment code 2h #0h
	$$TEM_HUM_realtime$lcdshow segment code 2h #0h
	$$TIM_FEN$lcdshow segment code 2h #0h
	$$TIM_SHI$lcdshow segment code 2h #0h
	$$UI_AIS_APM$lcdshow segment code 2h #0h
	$$UI_BUZZ$lcdshow segment code 2h #0h
	$$UI_MODA$lcdshow segment code 2h #0h
	$$UI_P$lcdshow segment code 2h #0h
	$$UI_TEMP_HUM$lcdshow segment code 2h #0h
	$$UI_TIME$lcdshow segment code 2h #0h
	$$UI_YE$lcdshow segment code 2h #0h
	$$UI_YEAR_TIME$lcdshow segment code 2h #0h
	$$UI_all_CLMON$lcdshow segment code 2h #0h
CVERSION 3.54.3
CGLOBAL 01H 03H 0000H "DATA_compare" 08H 02H 10H 00H 83H 08H 00H 00H 07H
CGLOBAL 01H 03H 0000H "UI_BUZZ" 08H 02H 00H 00H 80H 02H 00H 00H 07H
CGLOBAL 01H 03H 0000H "UI_AIS_APM" 08H 02H 08H 00H 83H 04H 00H 00H 07H
CGLOBAL 01H 03H 0000H "CIK_glint" 08H 02H 0AH 00H 80H 04H 00H 00H 07H
CGLOBAL 01H 03H 0000H "UI_P" 08H 02H 01H 00H 80H 02H 00H 00H 07H
CGLOBAL 01H 03H 0000H "UI_TEMP_HUM" 08H 02H 0BH 00H 83H 0aH 00H 00H 07H
CGLOBAL 01H 03H 0000H "MAX_MIN_realtime" 08H 02H 0DH 00H 80H 02H 00H 00H 07H
CGLOBAL 01H 03H 0000H "UI_YEAR_TIME" 08H 02H 06H 00H 83H 08H 00H 00H 07H
CGLOBAL 01H 03H 0000H "UI_MODA" 08H 02H 07H 00H 80H 00H 00H 00H 07H
CGLOBAL 01H 03H 0000H "UI_all_CLMON" 08H 02H 09H 00H 83H 08H 00H 00H 07H
CGLOBAL 01H 03H 0000H "UI_TIME" 08H 02H 05H 00H 83H 10H 00H 00H 07H
CGLOBAL 01H 03H 0000H "PICK_dataCOR" 08H 02H 0EH 00H 80H 00H 00H 00H 07H
CGLOBAL 01H 03H 0000H "TEM_HUM_realtime" 08H 02H 0CH 00H 81H 06H 00H 00H 07H
CGLOBAL 01H 03H 0000H "TIM_FEN" 08H 02H 04H 00H 80H 02H 00H 00H 07H
CGLOBAL 01H 03H 0000H "UI_YE" 08H 02H 02H 00H 83H 06H 00H 00H 07H
CGLOBAL 01H 03H 0000H "TIM_SHI" 08H 02H 03H 00H 83H 0eH 00H 00H 07H
CGLOBAL 01H 03H 0000H "DATA_INT" 08H 02H 0FH 00H 83H 04H 00H 00H 07H
CSTRUCTTAG 0000H 0000H 0001H 0004H 00000008H "Ma_Mi"
CSTRUCTMEM 43H 00000002H 00000000H "max_temp" 02H 00H 01H
CSTRUCTMEM 43H 00000002H 00000002H "min_temp" 02H 00H 01H
CSTRUCTMEM 43H 00000002H 00000004H "max_hum" 02H 00H 01H
CSTRUCTMEM 43H 00000002H 00000006H "min_hum" 02H 00H 01H
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
CGLOBAL 01H 42H 0012H "NOISY1_bell" 0BH 01H 03H 00H 01H 03H 00H 01H 02H 00H 00H 00H
CGLOBAL 01H 42H 000CH "table" 05H 01H 0CH 00H 00H 00H
CGLOBAL 01H 42H 002AH "week" 0BH 01H 07H 00H 01H 03H 00H 01H 02H 00H 00H 00H
CGLOBAL 01H 42H 0060H "TIME_system" 0BH 01H 02H 00H 01H 18H 00H 01H 02H 00H 00H 00H
CGLOBAL 01H 42H 0006H "NOISY0_bell" 08H 01H 03H 00H 01H 02H 00H 00H 00H
CFILE 0001H 00000057H "lcdshow\\lcdshow.h"
CFILE 0002H 00000822H "E:\\IDEU8\\Inc\\m610409.h"
CFILE 0003H 00000025H "MACROA~1\\MacroAndConst.h"
CFILE 0004H 0000001FH "temphum\\temphum.h"
CFILE 0000H 000001CFH "lcdshow\\lcdshow.c"

	rseg $$UI_BUZZ$lcdshow
CFUNCTION 0

_UI_BUZZ	:
CBLOCK 0 1 56

;; {
CLINEA 0000H 0001H 0038H 0002H 0002H
	push	er8
	mov	er8,	er0
CBLOCK 0 2 56
CARGUMENT 46H 0002H 0028H "P" 02H 00H 01H
CARGUMENT 46H 0002H 0025H "BU_bit" 02H 00H 01H

;;         if(BU_bit==1)
CLINEA 0000H 0001H 0039H 000AH 0016H
	cmp	r2,	#01h
	cmpc	r3,	#00h
	bne	_$L1
CBLOCK 0 3 58

;;     	  	if(P==0)Buzz=LOW;  //此时为BUZZ闪烁 
CLINEA 0000H 0001H 003BH 000AH 002DH
	mov	er8,	er8
	bne	_$L3
	mov	r0,	#00h
	st	r0,	0f11ch
_$L3 :

;;     	  	if(P==1)Buzz=HIGH;
CLINEA 0000H 0001H 003CH 000AH 001BH
	cmp	r8,	#01h
	cmpc	r9,	#00h
	bne	_$L7
	mov	r0,	#01h
	st	r0,	0f11ch
CBLOCKEND 0 3 61

;;          else Buzz=LOW;
CLINEA 0000H 0001H 003EH 000BH 0018H
	bal	_$L7
_$L1 :
	mov	r0,	#00h
	st	r0,	0f11ch
_$L7 :
CBLOCKEND 0 2 63

;;  }
CLINEA 0000H 0001H 003FH 0003H 0003H
	pop	er8
	rt
CBLOCKEND 0 1 63
CFUNCTIONEND 0


	rseg $$UI_P$lcdshow
CFUNCTION 1

_UI_P	:
CBLOCK 1 1 71

;; {
CLINEA 0000H 0001H 0047H 0002H 0002H
	push	er8
	mov	er8,	er0
CBLOCK 1 2 71
CARGUMENT 46H 0002H 0028H "P" 02H 00H 01H
CARGUMENT 46H 0002H 0025H "P_bit" 02H 00H 01H

;;  if(P_bit==1)Clk=HIGH;
CLINEA 0000H 0001H 0048H 0003H 0017H
	mov	er0,	er2
	cmp	r2,	#01h
	cmpc	r3,	#00h
	bne	_$L9
	mov	r0,	#01h
	st	r0,	0f100h

;;   else if(P_bit==2)Clk=LOW;	
CLINEA 0000H 0001H 0049H 0004H 001DH
	bal	_$L20
_$L9 :
	cmp	r0,	#02h
	cmpc	r1,	#00h
	bne	_$L12
	mov	r0,	#00h
	st	r0,	0f100h

;;    else if(P_bit==3)
CLINEA 0000H 0001H 004AH 0005H 0015H
	bal	_$L20
_$L12 :
	cmp	r0,	#03h
	cmpc	r1,	#00h
	bne	_$L20
CBLOCK 1 3 75

;;	  if(P==0)Clk=LOW;      //此时为时钟计数闪烁 
CLINEA 0000H 0001H 004CH 0004H 002EH
	mov	er8,	er8
	bne	_$L17
	mov	r0,	#00h
	st	r0,	0f100h

;;  	   else if(P==1)Clk=HIGH; 
CLINEA 0000H 0001H 004DH 0007H 001DH
	bal	_$L20
_$L17 :
	cmp	r8,	#01h
	cmpc	r9,	#00h
	bne	_$L20
	mov	r0,	#01h
	st	r0,	0f100h
_$L20 :
CBLOCKEND 1 3 78
CBLOCKEND 1 2 79

;;  }
CLINEA 0000H 0001H 004FH 0003H 0003H
	pop	er8
	rt
CBLOCKEND 1 1 79
CFUNCTIONEND 1


	rseg $$UI_YE$lcdshow
CFUNCTION 2

_UI_YE	:
CBLOCK 2 1 88

;; {
CLINEA 0000H 0001H 0058H 0002H 0002H
	push	lr
	bl	__regpushu8sw
	mov	er8,	er0
CBLOCK 2 2 88
CRET 000CH
CARGUMENT 46H 0002H 0032H "YETI_VALUE" 02H 00H 01H
CARGUMENT 46H 0002H 002FH "BU_YT" 02H 00H 01H
CARGUMENT 42H 0002H 000EH "P" 02H 00H 01H

;;  	if(BU_YT==0)Year_Out=0x00; //年英文显示（year）
CLINEA 0000H 0001H 0059H 0004H 0032H
	mov	er2,	er2
	bne	_$L23
	mov	r0,	#00h
	st	r0,	0f104h
_$L23 :

;;	if(BU_YT==1) //常亮模式 
CLINEA 0000H 0001H 005AH 0002H 0019H
	mov	er0,	er2
	cmp	r2,	#01h
	cmpc	r3,	#00h
	bne	_$L25
CBLOCK 2 3 91

;;	 	Year_Out=0x01; //年英文显示（year）
CLINEA 0000H 0001H 005CH 0004H 0026H
	mov	r0,	#01h
	st	r0,	0f104h

;;    	year_time0=table[YETI_VALUE/1000]; //年千位 
CLINEA 0000H 0001H 005DH 0006H 0031H
	mov	er0,	er8
	mov	r2,	#0e8h
	mov	r3,	#03h
	bl	__uidivu8sw
	l	r0,	NEAR _table[er0]
	st	r0,	0f105h

;;  	    year_time1=table[YETI_VALUE/100%10]; //年百位
CLINEA 0000H 0001H 005EH 0008H 0034H
	mov	er0,	er8
	mov	r2,	#064h
	div	er0,	r2
	mov	er2,	er0
	mov	r0,	#0ah
	div	er2,	r0
	mov	r1,	#00h
	l	r0,	NEAR _table[er0]
	st	r0,	0f106h

;;    	year_time2=table[YETI_VALUE/10%10]; //年十位
CLINEA 0000H 0001H 005FH 0006H 0031H
	mov	er0,	er8
	mov	r2,	#0ah
	div	er0,	r2
	mov	er2,	er0
	mov	r0,	#0ah
	div	er2,	r0
	mov	r1,	#00h
	l	r0,	NEAR _table[er0]
	st	r0,	0f107h

;;    	year_time3=table[YETI_VALUE%10]; //年个位 		
CLINEA 0000H 0001H 0060H 0006H 0031H
	mov	er2,	er8
	mov	r0,	#0ah
	div	er2,	r0
	l	r0,	NEAR _table[er0]
	st	r0,	0f108h

;;    else if(BU_YT==2) //闪烁模式 
CLINEA 0000H 0001H 0062H 0005H 0021H
	bal	_$L33
_$L25 :
	cmp	r0,	#02h
	cmpc	r1,	#00h
	bne	_$L33
CBLOCK 2 4 99

;;   	  Year_Out=0x01; //年英文显示（year）
CLINEA 0000H 0001H 0064H 0007H 0029H
	mov	r0,	#01h
	st	r0,	0f104h

;;      if(P==0) //灭 
CLINEA 0000H 0001H 0065H 0007H 0014H
	l	er0,	14[fp]
	bne	_$L30
CBLOCK 2 5 102

;;    	year_time0=0; //年千位 
CLINEA 0000H 0001H 0067H 0006H 001CH
	mov	r0,	#00h
	st	r0,	0f105h

;;  	    year_time1=0; //年百位
CLINEA 0000H 0001H 0068H 0008H 001DH
	st	r0,	0f106h

;;    	year_time2=0; //年十位
CLINEA 0000H 0001H 0069H 0006H 001BH
	st	r0,	0f107h

;;    	year_time3=0; //年个位    		
CLINEA 0000H 0001H 006AH 0006H 0021H
	st	r0,	0f108h

;;	  else if(P==1) //亮 
CLINEA 0000H 0001H 006CH 0004H 0016H
	bal	_$L33
_$L30 :
	cmp	r0,	#01h
	cmpc	r1,	#00h
	bne	_$L33
CBLOCK 2 6 109

;;    	year_time0=table[YETI_VALUE/1000]; //年千位 
CLINEA 0000H 0001H 006EH 0006H 0031H
	mov	er0,	er8
	mov	r2,	#0e8h
	mov	r3,	#03h
	bl	__uidivu8sw
	l	r0,	NEAR _table[er0]
	st	r0,	0f105h

;;  	    year_time1=table[YETI_VALUE/100%10]; //年百位
CLINEA 0000H 0001H 006FH 0008H 0034H
	mov	er0,	er8
	mov	r2,	#064h
	div	er0,	r2
	mov	er2,	er0
	mov	r0,	#0ah
	div	er2,	r0
	mov	r1,	#00h
	l	r0,	NEAR _table[er0]
	st	r0,	0f106h

;;    	year_time2=table[YETI_VALUE/10%10]; //年十位
CLINEA 0000H 0001H 0070H 0006H 0031H
	mov	er0,	er8
	mov	r2,	#0ah
	div	er0,	r2
	mov	er2,	er0
	mov	r0,	#0ah
	div	er2,	r0
	mov	r1,	#00h
	l	r0,	NEAR _table[er0]
	st	r0,	0f107h

;;    	year_time3=table[YETI_VALUE%10]; //年个位	   	 
CLINEA 0000H 0001H 0071H 0006H 0034H
	mov	er2,	er8
	mov	r0,	#0ah
	div	er2,	r0
	l	r0,	NEAR _table[er0]
	st	r0,	0f108h
CBLOCKEND 2 6 114

;;       }	
CLINEA 0000H 0000H 0072H 0008H 0009H
_$L33 :
CBLOCKEND 2 4 115
CBLOCKEND 2 5 116
CBLOCKEND 2 3 116
CBLOCKEND 2 2 116

;; } 
CLINEA 0000H 0001H 0074H 0002H 0003H
	b	__regpopu8sw
CBLOCKEND 2 1 116
CFUNCTIONEND 2


	rseg $$TIM_SHI$lcdshow
CFUNCTION 3

_TIM_SHI	:
CBLOCK 3 1 126

;;  {
CLINEA 0000H 0001H 007EH 0003H 0003H
	push	lr
	bl	__regpushu8sw
	mov	er10,	er2
	mov	er8,	er0
CBLOCK 3 2 126
CRET 000CH
CARGUMENT 46H 0002H 0032H "TIM_VALUE" 02H 00H 01H
CARGUMENT 46H 0002H 0033H "TIM_ZHI" 02H 00H 01H
CARGUMENT 42H 0002H 000EH "P" 02H 00H 01H

;;      if(P==0) //灭 
CLINEA 0000H 0001H 007FH 0007H 0014H
	l	er0,	14[fp]
	bne	_$L36
CBLOCK 3 3 128

;;       	year_time0=0; //时十位 
CLINEA 0000H 0001H 0081H 0009H 001FH
	mov	r0,	#00h
	st	r0,	0f105h

;;  	    year_time1=0; //时个位   		
CLINEA 0000H 0001H 0082H 0008H 0022H
	st	r0,	0f106h

;;	  else if(P==1) //亮 
CLINEA 0000H 0001H 0084H 0004H 0016H
	bal	_$L39
_$L36 :
	cmp	r0,	#01h
	cmpc	r1,	#00h
	bne	_$L39
CBLOCK 3 4 133

;;	 	if(TIME_system[TIM_ZHI][TIM_VALUE][0]==0x3f) year_time0=LOW; //时十位 
CLINEA 0000H 0000H 0086H 0000H 0000H
	mov	er0,	er10
	mov	er2,	#48
	bl	__imulu8sw
	mov	er2,	er0
	mov	er4,	er0
	mov	er0,	er8
	add	er0,	er8
	mov	er6,	er0

;;	 	if(TIME_system[TIM_ZHI][TIM_VALUE][0]==0x3f) year_time0=LOW; //时十位 
CLINEA 0000H 0001H 0086H 0004H 0049H
	mov	bp,	er2
	add	bp,	er0
	l	r0,	NEAR _TIME_system[bp]
	cmp	r0,	#03fh
	bne	_$L41
	mov	r0,	#00h

;;		 else year_time0=TIME_system[TIM_ZHI][TIM_VALUE][0];
CLINEA 0000H 0001H 0087H 0004H 0036H
	bal	_$L43
_$L41 :
	mov	bp,	er4
	add	bp,	er6
	l	r0,	NEAR _TIME_system[bp]
_$L43 :
	st	r0,	0f105h

;;  	      year_time1=TIME_system[TIM_ZHI][TIM_VALUE][1]; //时个位	   	 
CLINEA 0000H 0001H 0088H 000AH 0046H
	mov	bp,	er4
	add	bp,	er6
	l	r0,	NEAR _TIME_system+01h[bp]
	st	r0,	0f106h
CBLOCKEND 3 4 137

;;       }    	
CLINEA 0000H 0000H 0089H 0008H 000DH
_$L39 :
CBLOCKEND 3 3 138
CBLOCKEND 3 2 138

;;   }
CLINEA 0000H 0001H 008AH 0004H 0004H
	b	__regpopu8sw
CBLOCKEND 3 1 138
CFUNCTIONEND 3


	rseg $$TIM_FEN$lcdshow
CFUNCTION 4

_TIM_FEN	:
CBLOCK 4 1 147

;;  {
CLINEA 0000H 0001H 0093H 0003H 0003H
	push	er8
	mov	er8,	er0
CBLOCK 4 2 147
CARGUMENT 46H 0002H 0028H "MAR_VALUE" 02H 00H 01H
CARGUMENT 46H 0002H 0025H "P" 02H 00H 01H

;;      if(P==0) //灭 
CLINEA 0000H 0001H 0094H 0007H 0014H
	mov	er2,	er2
	bne	_$L45
CBLOCK 4 3 149

;;    	year_time2=0; //分十位
CLINEA 0000H 0001H 0096H 0006H 001BH
	mov	r0,	#00h
	st	r0,	0f107h

;;    	year_time3=0; //分个位    		
CLINEA 0000H 0001H 0097H 0006H 0021H
	st	r0,	0f108h

;;	  else if(P==1) //亮 
CLINEA 0000H 0001H 0099H 0004H 0016H
	bal	_$L48
_$L45 :
	cmp	r2,	#01h
	cmpc	r3,	#00h
	bne	_$L48
CBLOCK 4 4 154

;;    	  year_time2=table[MAR_VALUE/10]; //分十位
CLINEA 0000H 0001H 009BH 0008H 002FH
	mov	er0,	er8
	mov	r2,	#0ah
	div	er0,	r2
	l	r0,	NEAR _table[er0]
	st	r0,	0f107h

;;    	  year_time3=table[MAR_VALUE%10]; //分个位 	   	 
CLINEA 0000H 0001H 009CH 0008H 0036H
	mov	er2,	er8
	mov	r0,	#0ah
	div	er2,	r0
	mov	r1,	#00h
	l	r0,	NEAR _table[er0]
	st	r0,	0f108h
CBLOCKEND 4 4 157

;;       }    	
CLINEA 0000H 0000H 009DH 0008H 000DH
_$L48 :
CBLOCKEND 4 3 158
CBLOCKEND 4 2 158

;;   }
CLINEA 0000H 0001H 009EH 0004H 0004H
	pop	er8
	rt
CBLOCKEND 4 1 158
CFUNCTIONEND 4


	rseg $$UI_TIME$lcdshow
CFUNCTION 5

_UI_TIME	:
CBLOCK 5 1 167

;; {
CLINEA 0000H 0001H 00A7H 0002H 0002H
	push	lr
	bl	__regpushu8sw
	mov	er8,	er0
	mov	er10,	er2
CBLOCK 5 2 167
CRET 000CH
CARGUMENT 46H 0002H 0032H "TIM_VALUE" 02H 00H 01H
CARGUMENT 46H 0002H 0033H "MAR_VALUE" 02H 00H 01H
CARGUMENT 42H 0002H 000EH "TIM_ZHI" 02H 00H 01H
CARGUMENT 42H 0002H 0010H "BU_YT" 02H 00H 01H
CARGUMENT 42H 0002H 0012H "P" 02H 00H 01H

;;	if(BU_YT==1) //常亮模式 
CLINEA 0000H 0001H 00A8H 0002H 0019H
	l	er0,	16[fp]
	cmp	r0,	#01h
	cmpc	r1,	#00h
	bne	_$L51
CBLOCK 5 3 169

;;	 	if(TIME_system[TIM_ZHI][TIM_VALUE][0]==0x3f) year_time0=LOW; //时十位 
CLINEA 0000H 0000H 00AAH 0000H 0000H
	l	er0,	14[fp]
	mov	er2,	#48
	bl	__imulu8sw
	mov	er2,	er0
	mov	er4,	er0
	mov	er0,	er8
	add	er0,	er8
	mov	er6,	er0

;;	 	if(TIME_system[TIM_ZHI][TIM_VALUE][0]==0x3f) year_time0=LOW; //时十位 
CLINEA 0000H 0001H 00AAH 0004H 0049H
	mov	bp,	er2
	add	bp,	er0
	l	r0,	NEAR _TIME_system[bp]
	cmp	r0,	#03fh
	bne	_$L53
	mov	r0,	#00h

;;		 else year_time0=TIME_system[TIM_ZHI][TIM_VALUE][0];
CLINEA 0000H 0001H 00ABH 0004H 0036H
	bal	_$L55
_$L53 :
	mov	bp,	er4
	add	bp,	er6
	l	r0,	NEAR _TIME_system[bp]
_$L55 :
	st	r0,	0f105h

;;  	      year_time1=TIME_system[TIM_ZHI][TIM_VALUE][1]; //时个位
CLINEA 0000H 0001H 00ACH 000AH 0040H
	mov	bp,	er4
	add	bp,	er6
	l	r0,	NEAR _TIME_system+01h[bp]
	st	r0,	0f106h

;;    	  year_time2=table[MAR_VALUE/10]; //分十位
CLINEA 0000H 0001H 00ADH 0008H 002FH
	mov	er0,	er10
	mov	r2,	#0ah
	div	er0,	r2
	l	r0,	NEAR _table[er0]
	st	r0,	0f107h

;;    	  year_time3=table[MAR_VALUE%10]; //分个位 		
CLINEA 0000H 0001H 00AEH 0008H 0032H
	mov	er2,	er10
	mov	r0,	#0ah
	div	er2,	r0
	mov	r1,	#00h
	l	r0,	NEAR _table[er0]
	st	r0,	0f108h

;;    else if(BU_YT==2)    //时闪烁模式	
CLINEA 0000H 0001H 00B0H 0005H 0026H
	bal	_$L60
_$L51 :
	cmp	r0,	#02h
	cmpc	r1,	#00h
	bne	_$L57
CBLOCK 5 4 177

;;       year_time2=table[MAR_VALUE/10]; //分十位
CLINEA 0000H 0001H 00B2H 0008H 002FH
	mov	er0,	er10
	mov	r2,	#0ah
	div	er0,	r2
	l	r0,	NEAR _table[er0]
	st	r0,	0f107h

;;       year_time3=table[MAR_VALUE%10]; //分个位
CLINEA 0000H 0001H 00B3H 0008H 002FH
	mov	er2,	er10
	mov	r0,	#0ah
	div	er2,	r0
	mov	r1,	#00h
	l	r0,	NEAR _table[er0]
	st	r0,	0f108h

;;	    TIM_SHI(TIM_VALUE, TIM_ZHI, P);
CLINEA 0000H 0001H 00B4H 0006H 0024H
	l	er0,	18[fp]
	push	er0
	l	er2,	14[fp]
	mov	er0,	er8
	bl	_TIM_SHI
	add	sp,	#2 

;;    else if(BU_YT==3)    //分闪烁模式 
CLINEA 0000H 0001H 00B6H 0005H 0026H
	bal	_$L60
_$L57 :
	cmp	r0,	#03h
	cmpc	r1,	#00h
	bne	_$L60
CBLOCK 5 5 183

;;	 	if(TIME_system[TIM_ZHI][TIM_VALUE][0]==0x3f) year_time0=LOW; //时十位 
CLINEA 0000H 0000H 00B8H 0000H 0000H
	l	er0,	14[fp]
	mov	er2,	#48
	bl	__imulu8sw
	mov	er2,	er0
	mov	er4,	er0
	mov	er0,	er8
	add	er0,	er8
	mov	er6,	er0

;;	 	if(TIME_system[TIM_ZHI][TIM_VALUE][0]==0x3f) year_time0=LOW; //时十位 
CLINEA 0000H 0001H 00B8H 0004H 0049H
	mov	bp,	er2
	add	bp,	er0
	l	r0,	NEAR _TIME_system[bp]
	cmp	r0,	#03fh
	bne	_$L62
	mov	r0,	#00h

;;		 else year_time0=TIME_system[TIM_ZHI][TIM_VALUE][0];
CLINEA 0000H 0001H 00B9H 0004H 0036H
	bal	_$L64
_$L62 :
	mov	bp,	er4
	add	bp,	er6
	l	r0,	NEAR _TIME_system[bp]
_$L64 :
	st	r0,	0f105h

;;  	      year_time1=TIME_system[TIM_ZHI][TIM_VALUE][1]; //时个位
CLINEA 0000H 0001H 00BAH 000AH 0040H
	mov	bp,	er4
	add	bp,	er6
	l	r0,	NEAR _TIME_system+01h[bp]
	st	r0,	0f106h

;;          TIM_FEN(MAR_VALUE, P);	
CLINEA 0000H 0001H 00BBH 000BH 0021H
	l	er2,	18[fp]
	mov	er0,	er10
	bl	_TIM_FEN
CBLOCKEND 5 5 188

;;     } 
CLINEA 0000H 0000H 00BCH 0006H 0007H
_$L60 :
CBLOCKEND 5 4 189
CBLOCKEND 5 3 189
CBLOCKEND 5 2 189

;; } 
CLINEA 0000H 0001H 00BDH 0002H 0003H
	b	__regpopu8sw
CBLOCKEND 5 1 189
CFUNCTIONEND 5


	rseg $$UI_YEAR_TIME$lcdshow
CFUNCTION 6

_UI_YEAR_TIME	:
CBLOCK 6 1 199

;; {
CLINEA 0000H 0001H 00C7H 0002H 0002H
	push	lr
	bl	__regpushu8sw
	mov	er10,	er2
	mov	er8,	er0
CBLOCK 6 2 199
CRET 000CH
CARGUMENT 46H 0002H 0032H "P" 02H 00H 01H
CARGUMENT 46H 0002H 0033H "DISP_MON" 02H 00H 01H
CARGUMENT 42H 0002H 000EH "CLK_mode" 02H 00H 01H
CARGUMENT 42H 0002H 0010H "Mon" 02H 00H 01H
CARGUMENT 42H 0002H 0012H "dat_AIM" 02H 00H 01H

;;   if(DISP_MON==0) //月/日常亮 
CLINEA 0000H 0001H 00C8H 0004H 001FH
	mov	er2,	er2
	bne	_$L66
CBLOCK 6 3 201

;;      if(Mon/10==0) Mon_Da0=LOW;
CLINEA 0000H 0000H 00CAH 0000H 0000H
	l	er0,	16[fp]
	mov	r2,	#0ah
	div	er0,	r2

;;      if(Mon/10==0) Mon_Da0=LOW;
CLINEA 0000H 0001H 00CAH 0007H 0020H
	mov	er0,	er0
	bne	_$L68
	mov	r0,	#00h

;;     else Mon_Da0=table[Mon/10];
CLINEA 0000H 0001H 00CBH 0006H 0020H
	bal	_$L70
_$L68 :
	l	r0,	NEAR _table[er0]
_$L70 :
	st	r0,	0f110h

;;      Mon_Da1=table[Mon%10]; 
CLINEA 0000H 0001H 00CCH 0007H 001DH
	l	er2,	16[fp]
	mov	r0,	#0ah
	div	er2,	r0
	mov	r1,	#00h
	l	r0,	NEAR _table[er0]
	st	r0,	0f111h

;;      if(dat_AIM/10==0) Mon_Da2=LOW;
CLINEA 0000H 0000H 00CDH 0000H 0000H
	l	er0,	18[fp]
	mov	r2,	#0ah
	div	er0,	r2

;;      if(dat_AIM/10==0) Mon_Da2=LOW;
CLINEA 0000H 0001H 00CDH 0007H 0024H
	mov	er0,	er0
	bne	_$L71
	mov	r0,	#00h

;;     else Mon_Da2=table[dat_AIM/10]; 
CLINEA 0000H 0001H 00CEH 0006H 0025H
	bal	_$L73
_$L71 :
	l	r0,	NEAR _table[er0]
_$L73 :
	st	r0,	0f112h

;;      Mon_Da3=table[dat_AIM%10]; 
CLINEA 0000H 0001H 00CFH 0007H 0021H
	l	er2,	18[fp]
	mov	r0,	#0ah
	div	er2,	r0
	mov	r1,	#00h
	l	r0,	NEAR _table[er0]
	st	r0,	0f113h
CBLOCKEND 6 3 208

;;     }
CLINEA 0000H 0000H 00D0H 0006H 0006H
_$L66 :

;;  if(DISP_MON == 2)
CLINEA 0000H 0001H 00D1H 0003H 0013H
	cmp	r10,	#02h
	cmpc	r11,	#00h
	beq	_$M7
	b	_$L98
_$M7 :
CBLOCK 6 4 210

;;   if(CLK_mode == 2) //月闪烁/日常亮 
CLINEA 0000H 0001H 00D3H 0004H 0025H
	l	er0,	14[fp]
	cmp	r0,	#02h
	cmpc	r1,	#00h
	bne	_$L76
CBLOCK 6 5 212

;;   	  if(dat_AIM/10==0) Mon_Da2=LOW;
CLINEA 0000H 0000H 00D5H 0000H 0000H
	l	er0,	18[fp]
	mov	r2,	#0ah
	div	er0,	r2

;;   	  if(dat_AIM/10==0) Mon_Da2=LOW;
CLINEA 0000H 0001H 00D5H 0007H 0024H
	mov	er0,	er0
	bne	_$L78
	mov	r0,	#00h

;;       else Mon_Da2=table[dat_AIM/10]; 
CLINEA 0000H 0001H 00D6H 0008H 0027H
	bal	_$L80
_$L78 :
	l	r0,	NEAR _table[er0]
_$L80 :
	st	r0,	0f112h

;;       Mon_Da3=table[dat_AIM%10];    	  
CLINEA 0000H 0001H 00D7H 0008H 0028H
	l	er2,	18[fp]
	mov	r0,	#0ah
	div	er2,	r0
	mov	r1,	#00h
	l	r0,	NEAR _table[er0]
	st	r0,	0f113h

;;  	  if(P==0)
CLINEA 0000H 0001H 00D8H 0006H 000DH
	mov	er8,	er8
	bne	_$L81
CBLOCK 6 6 217

;;        Mon_Da0=0;
CLINEA 0000H 0001H 00DAH 0009H 0012H
	mov	r0,	#00h
	st	r0,	0f110h

;;  	   else if(P==1)
CLINEA 0000H 0001H 00DDH 0007H 0013H
	bal	_$L84
_$L81 :
	cmp	r8,	#01h
	cmpc	r9,	#00h
	beq	_$M8
	b	_$L98
_$M8 :
CBLOCK 6 7 222

;;   	    if(Mon/10==0) Mon_Da0=LOW;
CLINEA 0000H 0000H 00DFH 0000H 0000H
	l	er0,	16[fp]
	mov	r2,	#0ah
	div	er0,	r2

;;   	    if(Mon/10==0) Mon_Da0=LOW;
CLINEA 0000H 0001H 00DFH 0009H 0022H
	mov	er0,	er0
	bne	_$L86
	mov	r0,	#00h

;;         else Mon_Da0=table[Mon/10]; 
CLINEA 0000H 0001H 00E0H 000AH 0025H
	bal	_$L88
_$L86 :
	l	r0,	NEAR _table[er0]
_$L88 :
	st	r0,	0f110h

;;          Mon_Da1=table[Mon%10];
CLINEA 0000H 0001H 00E1H 000BH 0020H
	l	er2,	16[fp]
	mov	r0,	#0ah
	div	er2,	r0
	mov	r1,	#00h
	l	r0,	NEAR _table[er0]
CBLOCKEND 6 7 226

;;	    }	
CLINEA 0000H 0000H 00E2H 0006H 0007H
_$L84 :
	st	r0,	0f111h

;;   else if(CLK_mode==3) //日闪烁/月常亮 
CLINEA 0000H 0001H 00E4H 0004H 0028H
	bal	_$L98
_$L76 :
	cmp	r0,	#03h
	cmpc	r1,	#00h
	bne	_$L98
CBLOCK 6 8 229

;;      if(Mon/10==0) Mon_Da0=LOW;
CLINEA 0000H 0000H 00E6H 0000H 0000H
	l	er0,	16[fp]
	mov	r2,	#0ah
	div	er0,	r2

;;      if(Mon/10==0) Mon_Da0=LOW;
CLINEA 0000H 0001H 00E6H 0007H 0020H
	mov	er0,	er0
	bne	_$L92
	mov	r0,	#00h

;;       else Mon_Da0=table[Mon/10]; 
CLINEA 0000H 0001H 00E7H 0008H 0023H
	bal	_$L94
_$L92 :
	l	r0,	NEAR _table[er0]
_$L94 :
	st	r0,	0f110h

;;        Mon_Da1=table[Mon%10]; 
CLINEA 0000H 0001H 00E8H 0009H 001FH
	l	er2,	16[fp]
	mov	r0,	#0ah
	div	er2,	r0
	mov	r1,	#00h
	l	r0,	NEAR _table[er0]
	st	r0,	0f111h

;;  	  if(P==0)
CLINEA 0000H 0001H 00E9H 0006H 000DH
	mov	er8,	er8
	bne	_$L95
CBLOCK 6 9 234

;;        Mon_Da2=0;
CLINEA 0000H 0001H 00EBH 0009H 0012H
	mov	r0,	#00h
	st	r0,	0f112h

;;        Mon_Da3=0;  	   	 
CLINEA 0000H 0001H 00ECH 0009H 001AH
	st	r0,	0f113h

;;  	   else if(P==1)
CLINEA 0000H 0001H 00EEH 0007H 0013H
	bal	_$L98
_$L95 :
	cmp	r8,	#01h
	cmpc	r9,	#00h
	bne	_$L98
CBLOCK 6 10 239

;;   	  if(dat_AIM/10==0) Mon_Da2=LOW;
CLINEA 0000H 0000H 00F0H 0000H 0000H
	l	er0,	18[fp]
	mov	r2,	#0ah
	div	er0,	r2

;;   	  if(dat_AIM/10==0) Mon_Da2=LOW;
CLINEA 0000H 0001H 00F0H 0007H 0024H
	mov	er0,	er0
	bne	_$L100
	mov	r0,	#00h

;;       else Mon_Da2=table[dat_AIM/10]; 
CLINEA 0000H 0001H 00F1H 0008H 0027H
	bal	_$L102
_$L100 :
	l	r0,	NEAR _table[er0]
_$L102 :
	st	r0,	0f112h

;;       Mon_Da3=table[dat_AIM%10];
CLINEA 0000H 0001H 00F2H 0008H 0021H
	l	er2,	18[fp]
	mov	r0,	#0ah
	div	er2,	r0
	mov	r1,	#00h
	l	r0,	NEAR _table[er0]
	st	r0,	0f113h
CBLOCKEND 6 10 243

;;	    }   	
CLINEA 0000H 0000H 00F3H 0006H 000AH
_$L98 :
CBLOCKEND 6 8 244
CBLOCKEND 6 9 250
CBLOCKEND 6 4 245
CBLOCKEND 6 5 250
CBLOCKEND 6 6 250

;;  if(DISP_MON==1) //闹钟模式闪烁 
CLINEA 0000H 0001H 00F6H 0003H 0021H
	cmp	r10,	#01h
	cmpc	r11,	#00h
	bne	_$L105
CBLOCK 6 11 247

;;      if(CLK_mode == 3)CIK_glint(P, dat_AIM);
CLINEA 0000H 0001H 00F8H 0007H 002DH
	l	er0,	14[fp]
	cmp	r0,	#03h
	cmpc	r1,	#00h
	bne	_$L105
	l	er2,	18[fp]
	mov	er0,	er8
	bl	_CIK_glint
_$L105 :
CBLOCKEND 6 11 249
CBLOCKEND 6 2 250

;;  }
CLINEA 0000H 0001H 00FAH 0003H 0003H
	b	__regpopu8sw
CBLOCKEND 6 1 250
CFUNCTIONEND 6


	rseg $$UI_MODA$lcdshow
CFUNCTION 7

_UI_MODA	:
CBLOCK 7 1 258

;; {
CLINEA 0000H 0001H 0102H 0002H 0002H
CBLOCK 7 2 258
CARGUMENT 46H 0002H 0024H "MO_BIT" 02H 00H 01H

;;   if(MO_BIT==1)MonDa_Day=0; 
CLINEA 0000H 0001H 0103H 0004H 001DH
	cmp	r0,	#01h
	cmpc	r1,	#00h
	bne	_$L108
	mov	r0,	#00h
	st	r0,	0f102h

;;    else if(MO_BIT==2)MonDa_Day=0x05;	
CLINEA 0000H 0001H 0104H 0005H 0026H
	rt
_$L108 :
	cmp	r0,	#02h
	cmpc	r1,	#00h
	bne	_$L111
	mov	r0,	#05h
	st	r0,	0f102h
_$L111 :
CBLOCKEND 7 2 261

;;  } 
CLINEA 0000H 0001H 0105H 0003H 0004H
	rt
CBLOCKEND 7 1 261
CFUNCTIONEND 7


	rseg $$UI_AIS_APM$lcdshow
CFUNCTION 8

_UI_AIS_APM	:
CBLOCK 8 1 270

;; {
CLINEA 0000H 0001H 010EH 0002H 0002H
	push	lr
	bl	__regpushu8sw
	mov	er10,	er2
CBLOCK 8 2 270
CRET 000CH
CARGUMENT 46H 0002H 0030H "AS_bit" 02H 00H 01H
CARGUMENT 46H 0002H 0035H "AP_bit" 02H 00H 01H
CARGUMENT 42H 0002H 000EH "mode_ap" 02H 00H 01H

;;   if(AS_bit==1)AiSe=0x03; //AIMset常亮 
CLINEA 0000H 0001H 010FH 0004H 0028H
	cmp	r0,	#01h
	cmpc	r1,	#00h
	bne	_$L114
	mov	r0,	#03h

;;    else if(AS_bit==2)AiSe=0x02;//set常亮 
CLINEA 0000H 0001H 0110H 0005H 002AH
	bal	_$L119
_$L114 :
	cmp	r0,	#02h
	cmpc	r1,	#00h
	bne	_$L117
	mov	r0,	#02h

;;	 else AiSe=LOW;//灭
CLINEA 0000H 0001H 0111H 0003H 0014H
	bal	_$L119
_$L117 :
	mov	r0,	#00h
_$L119 :
	st	r0,	0f103h

;;   if(mode_ap == 1) //12/24允许判断 
CLINEA 0000H 0001H 0113H 0004H 0024H
	l	er0,	14[fp]
	cmp	r0,	#01h
	cmpc	r1,	#00h
	bne	_$L120
CBLOCK 8 3 276

;;   if(AP_bit==1)A_PM=0x01; //AM常亮 
CLINEA 0000H 0001H 0115H 0004H 0024H
	mov	er0,	er10
	cmp	r10,	#01h
	cmpc	r11,	#00h
	bne	_$L122
	mov	r0,	#01h

;;    else if(AP_bit==2)A_PM =0x02;//PM常亮 
CLINEA 0000H 0001H 0116H 0005H 002AH
	bal	_$L125
_$L122 :
	cmp	r0,	#02h
	cmpc	r1,	#00h
	bne	_$L127
	mov	r0,	#02h
_$L125 :
	st	r0,	0f11dh
CBLOCKEND 8 3 279

;;	 else A_PM=LOW;//灭	
CLINEA 0000H 0001H 0118H 0003H 0015H
	bal	_$L127
_$L120 :
	mov	r0,	#00h
	st	r0,	0f11dh
_$L127 :
CBLOCKEND 8 2 281

;;  } 
CLINEA 0000H 0001H 0119H 0003H 0004H
	b	__regpopu8sw
CBLOCKEND 8 1 281
CFUNCTIONEND 8


	rseg $$UI_all_CLMON$lcdshow
CFUNCTION 9

_UI_all_CLMON	:
CBLOCK 9 1 290

;; {
CLINEA 0000H 0001H 0122H 0002H 0002H
	push	lr
	bl	__regpushu8sw
	mov	er10,	er2
	mov	er8,	er0
CBLOCK 9 2 290
CRET 000CH
CARGUMENT 46H 0002H 0032H "all" 02H 00H 01H
CARGUMENT 46H 0002H 0033H "cl" 02H 00H 01H
CARGUMENT 42H 0002H 000EH "alcl_bit" 02H 00H 01H

;;   if(alcl_bit==1)
CLINEA 0000H 0001H 0123H 0004H 0012H
	l	er0,	14[fp]
	cmp	r0,	#01h
	cmpc	r1,	#00h
	bne	_$L129
CBLOCK 9 3 292

;;   	  Day_0=NOISY1_bell[cl-1][0][0]; 
CLINEA 0000H 0001H 0125H 0007H 0025H
	mov	er0,	er2
	mov	er2,	#6 
	bl	__imulu8sw
	l	r0,	NEAR _NOISY1_bell-06h[er0]
	st	r0,	0f10ah

;;	  Day_1=NOISY1_bell[cl-1][0][1];  
CLINEA 0000H 0001H 0126H 0004H 0023H
	mov	er0,	er10
	mov	er2,	#6 
	bl	__imulu8sw
	l	r0,	NEAR _NOISY1_bell-05h[er0]
	st	r0,	0f10bh

;;	  Day_2=NOISY1_bell[cl-1][1][0];  
CLINEA 0000H 0001H 0127H 0004H 0023H
	mov	er0,	er10
	mov	er2,	#6 
	bl	__imulu8sw
	l	r0,	NEAR _NOISY1_bell-04h[er0]
	st	r0,	0f10ch

;;	  Day_3=NOISY1_bell[cl-1][1][1];  
CLINEA 0000H 0001H 0128H 0004H 0023H
	mov	er0,	er10
	mov	er2,	#6 
	bl	__imulu8sw
	l	r0,	NEAR _NOISY1_bell-03h[er0]
	st	r0,	0f10dh

;;	  Day_4=NOISY1_bell[cl-1][2][0];  
CLINEA 0000H 0001H 0129H 0004H 0023H
	mov	er0,	er10
	mov	er2,	#6 
	bl	__imulu8sw
	l	r0,	NEAR _NOISY1_bell-02h[er0]
	st	r0,	0f10eh

;;	  Day_5=NOISY1_bell[cl-1][2][1]; 	
CLINEA 0000H 0001H 012AH 0004H 0023H
	mov	er0,	er10
	mov	er2,	#6 
	bl	__imulu8sw
	l	r0,	NEAR _NOISY1_bell-01h[er0]
	st	r0,	0f10fh

;;   else if(alcl_bit==2)
CLINEA 0000H 0001H 012CH 0004H 0017H
	bal	_$L132
_$L129 :
	cmp	r0,	#02h
	cmpc	r1,	#00h
	bne	_$L132
CBLOCK 9 4 301

;;          Day_0=week[all][0][0]; 
CLINEA 0000H 0001H 012EH 000BH 0021H
	mov	er0,	er8
	mov	er2,	#6 
	bl	__imulu8sw
	l	r0,	NEAR _week[er0]
	st	r0,	0f10ah

;;	  Day_1=week[all][0][1]; 
CLINEA 0000H 0001H 012FH 0004H 001AH
	mov	er0,	er8
	mov	er2,	#6 
	bl	__imulu8sw
	l	r0,	NEAR _week+01h[er0]
	st	r0,	0f10bh

;;	  Day_2=week[all][1][0]; 
CLINEA 0000H 0001H 0130H 0004H 001AH
	mov	er0,	er8
	mov	er2,	#6 
	bl	__imulu8sw
	l	r0,	NEAR _week+02h[er0]
	st	r0,	0f10ch

;;	  Day_3=week[all][1][1]; 
CLINEA 0000H 0001H 0131H 0004H 001AH
	mov	er0,	er8
	mov	er2,	#6 
	bl	__imulu8sw
	l	r0,	NEAR _week+03h[er0]
	st	r0,	0f10dh

;;	  Day_4=week[all][2][0]; 
CLINEA 0000H 0001H 0132H 0004H 001AH
	mov	er0,	er8
	mov	er2,	#6 
	bl	__imulu8sw
	l	r0,	NEAR _week+04h[er0]
	st	r0,	0f10eh

;;	  Day_5=week[all][2][1]; 	
CLINEA 0000H 0001H 0133H 0004H 001BH
	mov	er0,	er8
	mov	er2,	#6 
	bl	__imulu8sw
	l	r0,	NEAR _week+05h[er0]
	st	r0,	0f10fh
CBLOCKEND 9 4 308

;;	 }	
CLINEA 0000H 0000H 0134H 0003H 0004H
_$L132 :
CBLOCKEND 9 3 309
CBLOCKEND 9 2 309

;;  } 
CLINEA 0000H 0001H 0135H 0003H 0004H
	b	__regpopu8sw
CBLOCKEND 9 1 309
CFUNCTIONEND 9


	rseg $$CIK_glint$lcdshow
CFUNCTION 10

_CIK_glint	:
CBLOCK 10 1 317

;; {
CLINEA 0000H 0001H 013DH 0002H 0002H
	push	xr8
	mov	er8,	er0
	mov	er10,	er2
CBLOCK 10 2 317
CARGUMENT 46H 0002H 0028H "P" 02H 00H 01H
CARGUMENT 46H 0002H 0029H "da_AIM" 02H 00H 01H

;;      Mon_Da0=0;
CLINEA 0000H 0001H 013EH 0007H 0010H
	mov	r0,	#00h
	st	r0,	0f110h

;;      Mon_Da1=0; 
CLINEA 0000H 0001H 013FH 0007H 0011H
	st	r0,	0f111h

;;   	  if(P==0)
CLINEA 0000H 0001H 0140H 0007H 000EH
	mov	er8,	er8
	bne	_$L135
CBLOCK 10 3 321

;;        Mon_Da2=0;
CLINEA 0000H 0001H 0142H 0009H 0012H
	st	r0,	0f112h

;;        Mon_Da3=0;  	   	 
CLINEA 0000H 0001H 0143H 0009H 001AH
	st	r0,	0f113h

;;	  else if(P==1)	
CLINEA 0000H 0001H 0145H 0004H 0011H
	bal	_$L138
_$L135 :
	cmp	r8,	#01h
	cmpc	r9,	#00h
	bne	_$L138
CBLOCK 10 4 326

;;         Mon_Da2=NOISY0_bell[da_AIM-1][0];
CLINEA 0000H 0001H 0147H 000AH 002AH
	mov	er0,	er10
	add	er0,	er10
	l	r0,	NEAR _NOISY0_bell-02h[er0]
	st	r0,	0f112h

;;         Mon_Da3=NOISY0_bell[da_AIM-1][1]; 					    		   		   
CLINEA 0000H 0001H 0148H 000AH 003EH
	mov	er0,	er10
	add	er0,	er10
	l	r0,	NEAR _NOISY0_bell-01h[er0]
	st	r0,	0f113h
CBLOCKEND 10 4 329

;;	    }   	
CLINEA 0000H 0000H 0149H 0006H 000AH
_$L138 :
CBLOCKEND 10 3 330
CBLOCKEND 10 2 330

;;  } 
CLINEA 0000H 0001H 014AH 0003H 0004H
	pop	xr8
	rt
CBLOCKEND 10 1 330
CFUNCTIONEND 10


	rseg $$UI_TEMP_HUM$lcdshow
CFUNCTION 11

_UI_TEMP_HUM	:
CBLOCK 11 1 340

;;  {
CLINEA 0000H 0001H 0154H 0003H 0003H
	push	lr
	bl	__regpushu8sw
	mov	er10,	er2
	mov	er8,	er0
CBLOCK 11 2 340
CRET 000CH
CARGUMENT 46H 0002H 0032H "P" 02H 00H 01H
CARGUMENT 47H 0002H 0033H "TEM_data" 02H 00H 01H
CARGUMENT 43H 0002H 000EH "HUM_data" 02H 00H 01H
CARGUMENT 43H 0002H 0010H "T_H" 06H 03H 00H 00H 05H 01H 00H
CARGUMENT 42H 0002H 0012H "MAI_MON" 02H 00H 01H
CARGUMENT 42H 0002H 0014H "MAI_K" 02H 00H 01H
CARGUMENT 43H 0002H 0016H "c_f" 02H 00H 01H

;;  	if(MAI_MON==1 && MAI_K==0) //显示实时温湿度 
CLINEA 0000H 0001H 0155H 0004H 002FH
	l	er0,	18[fp]
	cmp	r0,	#01h
	cmpc	r1,	#00h
	bne	_$L141
	l	er0,	20[fp]
	bne	_$L141
CBLOCK 11 3 342

;;       TEM_HUM_realtime(TEM_data, HUM_data);  
CLINEA 0000H 0001H 0158H 0008H 002EH
	l	er2,	14[fp]
	mov	er0,	er10
	bl	_TEM_HUM_realtime

;;    else if(MAI_MON==2 && MAI_K==0) //显示最小温湿度  
CLINEA 0000H 0001H 015AH 0005H 0036H
	bal	_$L157
_$L141 :
	l	er0,	18[fp]
	cmp	r0,	#02h
	cmpc	r1,	#00h
	bne	_$L149
	l	er0,	20[fp]
	bne	_$L149
CBLOCK 11 4 347

;;       TEM_HUM_realtime(C_FCUTOVER(T_H->min_temp, c_f), T_H->min_hum);	
CLINEA 0000H 0001H 015CH 0008H 0047H
	l	er2,	22[fp]
	l	bp,	16[fp]
	l	er0,	2[bp]
	bl	_C_FCUTOVER
	l	er2,	6[bp]
	bl	_TEM_HUM_realtime

;;    else if(MAI_MON==3 && MAI_K==0) //显示最大温湿度 
CLINEA 0000H 0001H 015FH 0005H 0035H
	bal	_$L157
_$L149 :
	l	er0,	18[fp]
	cmp	r0,	#03h
	cmpc	r1,	#00h
	bne	_$L157
	l	er0,	20[fp]
	bne	_$L157
CBLOCK 11 5 352

;;       TEM_HUM_realtime(C_FCUTOVER(T_H->max_temp, c_f), T_H->max_hum);	
CLINEA 0000H 0001H 0161H 0008H 0047H
	l	er2,	22[fp]
	l	bp,	16[fp]
	l	er0,	[bp]
	bl	_C_FCUTOVER
	l	er2,	4[bp]
	bl	_TEM_HUM_realtime
CBLOCKEND 11 5 355

;;      }
CLINEA 0000H 0000H 0163H 0007H 0007H
_$L157 :
CBLOCKEND 11 4 361

;;    if(MAI_K==1) //重置最大小显示
CLINEA 0000H 0001H 0164H 0005H 0021H
	l	er0,	20[fp]
	cmp	r0,	#01h
	cmpc	r1,	#00h
	bne	_$L164
CBLOCKEND 11 3 361
CBLOCK 11 6 357

;; 	   TEM_HUM_realtime(-600, -600);
CLINEA 0000H 0001H 0166H 0006H 0022H
	mov	r2,	#0a8h
	mov	r3,	#0fdh
	mov	r0,	#0a8h
	mov	r1,	#0fdh
	bl	_TEM_HUM_realtime
CBLOCKEND 11 6 359

;;	  } 
CLINEA 0000H 0000H 0167H 0004H 0005H
_$L164 :

;;	  MAX_MIN_realtime(P, MAI_MON);
CLINEA 0000H 0001H 0168H 0004H 0020H
	l	er2,	18[fp]
	mov	er0,	er8
	bl	_MAX_MIN_realtime
CBLOCKEND 11 2 361

;;  } 
CLINEA 0000H 0001H 0169H 0003H 0004H
	b	__regpopu8sw
CBLOCKEND 11 1 361
CFUNCTIONEND 11


	rseg $$TEM_HUM_realtime$lcdshow
CFUNCTION 12

_TEM_HUM_realtime	:
CBLOCK 12 1 369

;; {
CLINEA 0000H 0001H 0171H 0002H 0002H
	push	lr
	push	xr8
	mov	er8,	er0
	mov	er10,	er2
CBLOCK 12 2 369
CRET 0004H
CARGUMENT 47H 0002H 0028H "TE_data" 02H 00H 01H
CARGUMENT 47H 0002H 0029H "HU_data" 02H 00H 01H

;; 	if(TE_data>-600)
CLINEA 0000H 0001H 0173H 0003H 0012H
	cmp	r0,	#0a8h
	cmpc	r1,	#0fdh
	bles	_$L167
CBLOCK 12 3 372

;;     if(TE_data<0)carry=HIGH; //负号 
CLINEA 0000H 0001H 0175H 0006H 0025H
	mov	er0,	er0
	bps	_$L169
	mov	r0,	#01h
	st	r0,	0f109h

;;      else if(TE_data>=0)carry=LOW;      
CLINEA 0000H 0001H 0176H 0007H 0029H
	bal	_$L172
_$L169 :
	mov	er0,	er8
	bns	_$L172
	mov	r0,	#00h
	st	r0,	0f109h
_$L172 :

;;     if(TE_data>=1000)Temp_0=HIGH; //过了100后 
CLINEA 0000H 0001H 0177H 0006H 002FH
	mov	er0,	er8
	cmp	r8,	#0e8h
	cmpc	r9,	#03h
	blts	_$L174
	mov	r0,	#01h
	st	r0,	0f114h

;;      else if(TE_data<1000)Temp_0=LOW;
CLINEA 0000H 0001H 0178H 0007H 0026H
	bal	_$L177
_$L174 :
	cmp	r0,	#0e8h
	cmpc	r1,	#03h
	bges	_$L177
	mov	r0,	#00h
	st	r0,	0f114h
_$L177 :

;;     if(TE_data<100)Temp_1=LOW;
CLINEA 0000H 0001H 0179H 0006H 001FH
	mov	er0,	er8
	cmp	r8,	#064h
	cmpc	r9,	#00h
	bges	_$L179
	mov	r0,	#00h

;; 	  else Temp_1=table[TE_data/100%10]; 
CLINEA 0000H 0001H 017AH 0005H 0027H
	bal	_$L181
_$L179 :
	mov	r2,	#064h
	mov	r3,	#00h
	bl	__idivu8sw
	mov	er2,	#10
	bl	__imodu8sw
	l	r0,	NEAR _table[er0]
_$L181 :
	st	r0,	0f115h

;;  	       Temp_2=table[TE_data/10%10]; 
CLINEA 0000H 0001H 017BH 000BH 0027H
	mov	er0,	er8
	mov	er2,	#10
	bl	__idivu8sw
	mov	er2,	#10
	bl	__imodu8sw
	l	r0,	NEAR _table[er0]
	st	r0,	0f116h

;;  	       Temp_3=table[TE_data%10]; 
CLINEA 0000H 0001H 017CH 000BH 0024H
	mov	er0,	er8
	mov	er2,	#10
	bl	__imodu8sw
	l	r0,	NEAR _table[er0]
CBLOCKEND 12 3 381

;;     else 
CLINEA 0000H 0001H 017EH 0006H 000AH
	bal	_$L182
_$L167 :
CBLOCK 12 4 383

;;       Temp_1=table[11]; 
CLINEA 0000H 0001H 0180H 0008H 0019H
	l	r0,	NEAR _table+0bh
	st	r0,	0f115h

;;  	   Temp_2=table[11]; 
CLINEA 0000H 0001H 0181H 0007H 0018H
	st	r0,	0f116h

;;  	   Temp_3=table[11];	
CLINEA 0000H 0001H 0182H 0007H 0018H
CBLOCKEND 12 4 387

;;       }
CLINEA 0000H 0000H 0183H 0008H 0008H
_$L182 :
	st	r0,	0f117h

;;  	 if(HU_data>-600)
CLINEA 0000H 0001H 0185H 0005H 0014H
	mov	er0,	er10
	cmp	r10,	#0a8h
	cmpc	r11,	#0fdh
	bles	_$L183
CBLOCK 12 5 390

;;  	  if(HU_data<10)Hum_0=LOW;
CLINEA 0000H 0001H 0187H 0006H 001DH
	cmp	r10,	#0ah
	cmpc	r11,	#00h
	bges	_$L185
	mov	r0,	#00h
	st	r0,	0f118h

;;  	   else if(HU_data>=10)Hum_0=table[HU_data/10];
CLINEA 0000H 0001H 0188H 0007H 0032H
	bal	_$L188
_$L185 :
	cmp	r0,	#0ah
	cmpc	r1,	#00h
	blts	_$L188
	mov	er2,	#10
	bl	__idivu8sw
	l	r0,	NEAR _table[er0]
	st	r0,	0f118h
_$L188 :

;;  	   Hum_1=table[HU_data%10];	
CLINEA 0000H 0001H 0189H 0007H 001FH
	mov	er0,	er10
	mov	er2,	#10
	bl	__imodu8sw
	l	r0,	NEAR _table[er0]
CBLOCKEND 12 5 394

;;     else
CLINEA 0000H 0001H 018BH 0006H 0009H
	bal	_$L190
_$L183 :
CBLOCK 12 6 396

;;   	   Hum_0=table[11];
CLINEA 0000H 0001H 018DH 0008H 0017H
	l	r0,	NEAR _table+0bh
	st	r0,	0f118h

;;  	   Hum_1=table[11];
CLINEA 0000H 0001H 018EH 0007H 0016H
CBLOCKEND 12 6 399

;;      }
CLINEA 0000H 0000H 018FH 0007H 0007H
_$L190 :
	st	r0,	0f119h
CBLOCKEND 12 2 400

;;  } 
CLINEA 0000H 0001H 0190H 0003H 0004H
	pop	xr8
	pop	pc
CBLOCKEND 12 1 400
CFUNCTIONEND 12


	rseg $$MAX_MIN_realtime$lcdshow
CFUNCTION 13

_MAX_MIN_realtime	:
CBLOCK 13 1 408

;; {
CLINEA 0000H 0001H 0198H 0002H 0002H
	push	er8
	mov	er8,	er0
CBLOCK 13 2 408
CARGUMENT 46H 0002H 0028H "P" 02H 00H 01H
CARGUMENT 46H 0002H 0025H "MAI_MON" 02H 00H 01H

;;  	if(MAI_MON==1) Min_Max=LOW;
CLINEA 0000H 0001H 0199H 0004H 001EH
	mov	er0,	er2
	cmp	r2,	#01h
	cmpc	r3,	#00h
	bne	_$L192
	mov	r0,	#00h
	st	r0,	0f101h

;;     else if(MAI_MON==2)
CLINEA 0000H 0001H 019AH 0006H 0018H
	bal	_$L208
_$L192 :
	cmp	r0,	#02h
	cmpc	r1,	#00h
	bne	_$L195
CBLOCK 13 3 411

;;  	    if(P==0)Min_Max=LOW;
CLINEA 0000H 0001H 019CH 0008H 001BH
	mov	er8,	er8
	bne	_$L197
	mov	r0,	#00h

;;	   	 else if(P==1) Min_Max=0x01;
CLINEA 0000H 0001H 019DH 0007H 0021H
	bal	_$L200
_$L197 :
	cmp	r8,	#01h
	cmpc	r9,	#00h
	bne	_$L208
	mov	r0,	#01h
_$L200 :
	st	r0,	0f101h

;;	 else if(MAI_MON==3)
CLINEA 0000H 0001H 019FH 0003H 0015H
	bal	_$L208
_$L195 :
	cmp	r0,	#03h
	cmpc	r1,	#00h
	bne	_$L208
CBLOCK 13 4 416

;;  	    if(P==0)Min_Max=LOW;
CLINEA 0000H 0001H 01A1H 0008H 001BH
	mov	er8,	er8
	bne	_$L205
	mov	r0,	#00h
	st	r0,	0f101h

;;	   	 else if(P==1) Min_Max=0x02;
CLINEA 0000H 0001H 01A2H 0007H 0021H
	bal	_$L208
_$L205 :
	cmp	r8,	#01h
	cmpc	r9,	#00h
	bne	_$L208
	mov	r0,	#02h
	st	r0,	0f101h
_$L208 :
CBLOCKEND 13 4 419
CBLOCKEND 13 3 420
CBLOCKEND 13 2 420

;;  }
CLINEA 0000H 0001H 01A4H 0003H 0003H
	pop	er8
	rt
CBLOCKEND 13 1 420
CFUNCTIONEND 13


	rseg $$PICK_dataCOR$lcdshow
CFUNCTION 14

_PICK_dataCOR	:
CBLOCK 14 1 428

;; {
CLINEA 0000H 0001H 01ACH 0002H 0002H
	mov	er2,	er0
CBLOCK 14 2 428
CARGUMENT 46H 0002H 0025H "DATA_bit" 02H 00H 01H

;;   P_BAT=0x01; 
CLINEA 0000H 0001H 01ADH 0004H 000FH
	mov	r0,	#01h
	st	r0,	0f11ah

;;   if(DATA_bit==1)C_F_H=0x05; //C度显示 
CLINEA 0000H 0001H 01AEH 0004H 0028H
	cmp	r2,	#01h
	cmpc	r3,	#00h
	bne	_$L211
	mov	r0,	#05h
	st	r0,	0f11bh

;;    else if(DATA_bit==0)C_F_H=0x03;	//F度显示 
CLINEA 0000H 0001H 01AFH 0005H 002EH
	rt
_$L211 :
	mov	er2,	er2
	bne	_$L214
	mov	r0,	#03h
	st	r0,	0f11bh
_$L214 :
CBLOCKEND 14 2 432

;;  }
CLINEA 0000H 0001H 01B0H 0003H 0003H
	rt
CBLOCKEND 14 1 432
CFUNCTIONEND 14


	rseg $$DATA_INT$lcdshow
CFUNCTION 15

_DATA_INT	:
CBLOCK 15 1 442

;; {
CLINEA 0000H 0001H 01BAH 0002H 0002H
	push	lr
	bl	__regpushu8sw
CBLOCK 15 2 442
CRET 000CH
CARGUMENT 47H 0002H 0030H "TEMP_DATA" 02H 00H 01H
CARGUMENT 47H 0002H 0031H "HUM_DATA" 02H 00H 01H
CARGUMENT 43H 0002H 000EH "M_m" 06H 03H 00H 00H 05H 01H 00H

;;   	M_m->min_temp=TEMP_DATA;
CLINEA 0000H 0001H 01BBH 0005H 001CH
	l	bp,	14[fp]
	st	er0,	2[bp]

;;   	M_m->max_temp=TEMP_DATA;
CLINEA 0000H 0001H 01BCH 0005H 001CH
	st	er0,	[bp]

;;   	M_m->min_hum=HUM_DATA;
CLINEA 0000H 0001H 01BDH 0005H 001AH
	st	er2,	6[bp]

;;   	M_m->max_hum=HUM_DATA;
CLINEA 0000H 0001H 01BEH 0005H 001AH
	st	er2,	4[bp]
CBLOCKEND 15 2 447

;;  }
CLINEA 0000H 0001H 01BFH 0003H 0003H
	b	__regpopu8sw
CBLOCKEND 15 1 447
CFUNCTIONEND 15


	rseg $$DATA_compare$lcdshow
CFUNCTION 16

_DATA_compare	:
CBLOCK 16 1 456

;; {
CLINEA 0000H 0001H 01C8H 0002H 0002H
	push	lr
	bl	__regpushu8sw
	mov	er8,	er0
	mov	er10,	er2
CBLOCK 16 2 456
CRET 000CH
CARGUMENT 47H 0002H 0034H "TEMP_DATA" 02H 00H 01H
CARGUMENT 47H 0002H 0035H "HUM_DATA" 02H 00H 01H
CARGUMENT 43H 0002H 000EH "M_ai" 06H 03H 00H 00H 05H 01H 00H

;;   	if(TEMP_DATA < M_ai->min_temp)M_ai->min_temp=TEMP_DATA;
CLINEA 0000H 0001H 01C9H 0005H 003BH
	l	bp,	14[fp]
	l	bp,	2[bp]
	cmp	er0,	bp
	bges	_$L218
	l	bp,	14[fp]
	st	er0,	2[bp]
_$L218 :

;;   	if(TEMP_DATA > M_ai->max_temp)M_ai->max_temp=TEMP_DATA;
CLINEA 0000H 0001H 01CAH 0005H 003BH
	l	bp,	14[fp]
	l	bp,	[bp]
	cmp	er0,	bp
	bles	_$L220
	l	bp,	14[fp]
	st	er8,	[bp]
_$L220 :

;;   	if(HUM_DATA < M_ai->min_hum)M_ai->min_hum=HUM_DATA;
CLINEA 0000H 0001H 01CBH 0005H 0037H
	l	bp,	14[fp]
	l	bp,	6[bp]
	cmp	er10,	bp
	bges	_$L222
	l	bp,	14[fp]
	st	er10,	6[bp]
_$L222 :

;;   	if(HUM_DATA > M_ai->max_hum)M_ai->max_hum=HUM_DATA;
CLINEA 0000H 0001H 01CCH 0005H 0037H
	l	bp,	14[fp]
	l	bp,	4[bp]
	cmp	er10,	bp
	bles	_$L224
	l	bp,	14[fp]
	st	er10,	4[bp]
_$L224 :
CBLOCKEND 16 2 461

;;  }
CLINEA 0000H 0001H 01CDH 0003H 0003H
	b	__regpopu8sw
CBLOCKEND 16 1 461
CFUNCTIONEND 16

	public _DATA_compare
	public _UI_BUZZ
	public _UI_AIS_APM
	public _CIK_glint
	public _UI_P
	public _NOISY1_bell
	public _UI_TEMP_HUM
	public _MAX_MIN_realtime
	public _table
	public _UI_YEAR_TIME
	public _UI_MODA
	public _UI_all_CLMON
	public _week
	public _UI_TIME
	public _PICK_dataCOR
	public _TEM_HUM_realtime
	public _TIM_FEN
	public _UI_YE
	public _TIM_SHI
	public _TIME_system
	public _DATA_INT
	public _NOISY0_bell
	extrn code near : _C_FCUTOVER
	extrn code near : _main

	rseg $$NINITTAB
	db	03fh
	db	03fh
	db	03fh
	db	06h
	db	03fh
	db	05bh
	db	03fh
	db	04fh
	db	03fh
	db	066h
	db	03fh
	db	06dh
	db	03fh
	db	07dh
	db	03fh
	db	07h
	db	03fh
	db	07fh
	db	03fh
	db	06fh
	db	06h
	db	03fh
	db	06h
	db	06h
	db	06h
	db	05bh
	db	06h
	db	04fh
	db	06h
	db	066h
	db	06h
	db	06dh
	db	06h
	db	07dh
	db	06h
	db	07h
	db	06h
	db	07fh
	db	06h
	db	06fh
	db	05bh
	db	03fh
	db	05bh
	db	06h
	db	05bh
	db	05bh
	db	05bh
	db	04fh
	db	06h
	db	05bh
	db	03fh
	db	06h
	db	03fh
	db	05bh
	db	03fh
	db	04fh
	db	03fh
	db	066h
	db	03fh
	db	06dh
	db	03fh
	db	07dh
	db	03fh
	db	07h
	db	03fh
	db	07fh
	db	03fh
	db	06fh
	db	06h
	db	03fh
	db	06h
	db	06h
	db	06h
	db	05bh
	db	03fh
	db	06h
	db	03fh
	db	05bh
	db	03fh
	db	04fh
	db	03fh
	db	066h
	db	03fh
	db	06dh
	db	03fh
	db	07dh
	db	03fh
	db	07h
	db	03fh
	db	07fh
	db	03fh
	db	06fh
	db	06h
	db	03fh
	db	06h
	db	06h
	db	06dh
	db	01h
	db	03eh
	db	00h
	db	036h
	db	018h
	db	036h
	db	050h
	db	03fh
	db	00h
	db	036h
	db	018h
	db	01h
	db	024h
	db	03eh
	db	00h
	db	079h
	db	01h
	db	036h
	db	0ah
	db	079h
	db	01h
	db	0fh
	db	024h
	db	01h
	db	024h
	db	076h
	db	01h
	db	03eh
	db	00h
	db	071h
	db	01h
	db	073h
	db	09h
	db	09h
	db	024h
	db	06dh
	db	01h
	db	077h
	db	01h
	db	01h
	db	024h
	db	040h
	db	040h
	db	00h
	db	037h
	db	00h
	db	06h
	db	03fh
	db	00h
	db	071h
	db	01h
	db	071h
	db	01h
	db	073h
	db	09h
	db	079h
	db	01h
	db	073h
	db	01h
	db	00h
	db	00h
	db	03fh
	db	00h
	db	01h
	db	024h
	db	03fh
	db	06h
	db	05bh
	db	04fh
	db	066h
	db	06dh
	db	07dh
	db	07h
	db	07fh
	db	06fh
	db	00h
	db	040h

	rseg $$NINITVAR
_TIME_system :
	ds	060h
_week :
	ds	02ah
_NOISY0_bell :
	ds	06h
_NOISY1_bell :
	ds	012h
_table :
	ds	0ch
	extrn code : __imulu8sw
	extrn code : __imodu8sw
	extrn code : __idivu8sw
	extrn code : __uidivu8sw
	extrn code : __regpushu8sw
	extrn code : __regpopu8sw

	end
