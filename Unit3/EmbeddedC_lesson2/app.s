
app.o:     file format elf32-littlearm


Disassembly of section .text:

00000000 <main>:
   0:	e92d4800 	push	{fp, lr}
   4:	e28db004 	add	fp, sp, #4
   8:	e59f0004 	ldr	r0, [pc, #4]	; 14 <main+0x14>
   c:	ebfffffe 	bl	0 <Uart_Send_String>
  10:	e8bd8800 	pop	{fp, pc}
  14:	00000000 	andeq	r0, r0, r0

Disassembly of section .data:

00000000 <string_buffer>:
   0:	7261656c 	rsbvc	r6, r1, #108, 10	; 0x1b000000
   4:	6e692d6e 	cdpvs	13, 6, cr2, cr9, cr14, {3}
   8:	7065642d 	rsbvc	r6, r5, sp, lsr #8
   c:	4d3a6874 	ldcmi	8, cr6, [sl, #-464]!	; 0xfffffe30
  10:	6f6d6861 	svcvs	0x006d6861
  14:	00006475 	andeq	r6, r0, r5, ror r4
	...

Disassembly of section .debug_info:

00000000 <.debug_info>:
   0:	000000cb 	andeq	r0, r0, fp, asr #1
   4:	00000002 	andeq	r0, r0, r2
   8:	01040000 	mrseq	r0, (UNDEF: 4)
   c:	000000f8 	strdeq	r0, [r0], -r8
  10:	00000001 	andeq	r0, r0, r1
  14:	00000600 	andeq	r0, r0, r0, lsl #12
  18:	00000000 	andeq	r0, r0, r0
  1c:	00001800 	andeq	r1, r0, r0, lsl #16
  20:	00000000 	andeq	r0, r0, r0
  24:	06010200 	streq	r0, [r1], -r0, lsl #4
  28:	0000011d 	andeq	r0, r0, sp, lsl r1
  2c:	0000d903 	andeq	sp, r0, r3, lsl #18
  30:	372a0200 	strcc	r0, [sl, -r0, lsl #4]!
  34:	02000000 	andeq	r0, r0, #0
  38:	00680801 	rsbeq	r0, r8, r1, lsl #16
  3c:	02020000 	andeq	r0, r2, #0
  40:	00010405 	andeq	r0, r1, r5, lsl #8
  44:	07020200 	streq	r0, [r2, -r0, lsl #4]
  48:	00000088 	andeq	r0, r0, r8, lsl #1
  4c:	14050402 	strne	r0, [r5], #-1026	; 0x402
  50:	02000001 	andeq	r0, r0, #1
  54:	00760704 	rsbseq	r0, r6, r4, lsl #14
  58:	08020000 	stmdaeq	r2, {}	; <UNPREDICTABLE>
  5c:	0000ea05 	andeq	lr, r0, r5, lsl #20
  60:	07080200 	streq	r0, [r8, -r0, lsl #4]
  64:	000000c2 	andeq	r0, r0, r2, asr #1
  68:	69050404 	stmdbvs	r5, {r2, sl}
  6c:	0200746e 	andeq	r7, r0, #1845493760	; 0x6e000000
  70:	00b50704 	adcseq	r0, r5, r4, lsl #14
  74:	0e030000 	cdpeq	0, 0, cr0, cr3, cr0, {0}
  78:	03000001 	movweq	r0, #1
  7c:	00002c21 	andeq	r2, r0, r1, lsr #24
  80:	04040200 	streq	r0, [r4], #-512	; 0x200
  84:	00000062 	andeq	r0, r0, r2, rrx
  88:	a9040802 	stmdbge	r4, {r1, fp}
  8c:	05000000 	streq	r0, [r0, #-0]
  90:	0000b001 	andeq	fp, r0, r1
  94:	01040100 	mrseq	r0, (UNDEF: 20)
  98:	00000000 	andeq	r0, r0, r0
  9c:	00000018 	andeq	r0, r0, r8, lsl r0
  a0:	00000000 	andeq	r0, r0, r0
  a4:	00760601 	rsbseq	r0, r6, r1, lsl #12
  a8:	00b50000 	adcseq	r0, r5, r0
  ac:	b5070000 	strlt	r0, [r7, #-0]
  b0:	63000000 	movwvs	r0, #0
  b4:	07040200 	streq	r0, [r4, -r0, lsl #4]
  b8:	000000e1 	andeq	r0, r0, r1, ror #1
  bc:	00009b08 	andeq	r9, r0, r8, lsl #22
  c0:	a5030100 	strge	r0, [r3, #-256]	; 0x100
  c4:	01000000 	mrseq	r0, (UNDEF: 0)
  c8:	00000305 	andeq	r0, r0, r5, lsl #6
  cc:	Address 0x000000cc is out of bounds.


Disassembly of section .debug_abbrev:

00000000 <.debug_abbrev>:
   0:	25011101 	strcs	r1, [r1, #-257]	; 0x101
   4:	030b130e 	movweq	r1, #45838	; 0xb30e
   8:	110e1b0e 	tstne	lr, lr, lsl #22
   c:	10011201 	andne	r1, r1, r1, lsl #4
  10:	02000006 	andeq	r0, r0, #6
  14:	0b0b0024 	bleq	2c00ac <main+0x2c00ac>
  18:	0e030b3e 	vmoveq.16	d3[0], r0
  1c:	16030000 	strne	r0, [r3], -r0
  20:	3a0e0300 	bcc	380c28 <main+0x380c28>
  24:	490b3b0b 	stmdbmi	fp, {r0, r1, r3, r8, r9, fp, ip, sp}
  28:	04000013 	streq	r0, [r0], #-19
  2c:	0b0b0024 	bleq	2c00c4 <main+0x2c00c4>
  30:	08030b3e 	stmdaeq	r3, {r1, r2, r3, r4, r5, r8, r9, fp}
  34:	2e050000 	cdpcs	0, 0, cr0, cr5, cr0, {0}
  38:	030c3f00 	movweq	r3, #52992	; 0xcf00
  3c:	3b0b3a0e 	blcc	2ce87c <main+0x2ce87c>
  40:	110c270b 	tstne	ip, fp, lsl #14
  44:	40011201 	andmi	r1, r1, r1, lsl #4
  48:	0c429606 	mcrreq	6, 0, r9, r2, cr6
  4c:	01060000 	mrseq	r0, (UNDEF: 6)
  50:	01134901 	tsteq	r3, r1, lsl #18
  54:	07000013 	smladeq	r0, r3, r0, r0
  58:	13490021 	movtne	r0, #36897	; 0x9021
  5c:	00000b2f 	andeq	r0, r0, pc, lsr #22
  60:	03003408 	movweq	r3, #1032	; 0x408
  64:	3b0b3a0e 	blcc	2ce8a4 <main+0x2ce8a4>
  68:	3f13490b 	svccc	0x0013490b
  6c:	000a020c 	andeq	r0, sl, ip, lsl #4
	...

Disassembly of section .debug_loc:

00000000 <.debug_loc>:
   0:	00000000 	andeq	r0, r0, r0
   4:	00000004 	andeq	r0, r0, r4
   8:	007d0002 	rsbseq	r0, sp, r2
   c:	00000004 	andeq	r0, r0, r4
  10:	00000008 	andeq	r0, r0, r8
  14:	087d0002 	ldmdaeq	sp!, {r1}^
  18:	00000008 	andeq	r0, r0, r8
  1c:	00000018 	andeq	r0, r0, r8, lsl r0
  20:	047b0002 	ldrbteq	r0, [fp], #-2
	...

Disassembly of section .debug_aranges:

00000000 <.debug_aranges>:
   0:	0000001c 	andeq	r0, r0, ip, lsl r0
   4:	00000002 	andeq	r0, r0, r2
   8:	00040000 	andeq	r0, r4, r0
	...
  14:	00000018 	andeq	r0, r0, r8, lsl r0
	...

Disassembly of section .debug_line:

00000000 <.debug_line>:
   0:	0000008a 	andeq	r0, r0, sl, lsl #1
   4:	00750002 	rsbseq	r0, r5, r2
   8:	01020000 	mrseq	r0, (UNDEF: 2)
   c:	000d0efb 	strdeq	r0, [sp], -fp
  10:	01010101 	tsteq	r1, r1, lsl #2
  14:	01000000 	mrseq	r0, (UNDEF: 0)
  18:	63010000 	movwvs	r0, #4096	; 0x1000
  1c:	72612f3a 	rsbvc	r2, r1, #58, 30	; 0xe8
  20:	6f745f6d 	svcvs	0x00745f6d
  24:	68636c6f 	stmdavs	r3!, {r0, r1, r2, r3, r5, r6, sl, fp, sp, lr}^
  28:	2f6e6961 	svccs	0x006e6961
  2c:	2f62696c 	svccs	0x0062696c
  30:	2f636367 	svccs	0x00636367
  34:	2e2f2e2e 	cdpcs	14, 2, cr2, cr15, cr14, {1}
  38:	72612f2e 	rsbvc	r2, r1, #46, 30	; 0xb8
  3c:	6f6e2d6d 	svcvs	0x006e2d6d
  40:	652d656e 	strvs	r6, [sp, #-1390]!	; 0x56e
  44:	2f696261 	svccs	0x00696261
  48:	2d737973 	ldclcs	9, cr7, [r3, #-460]!	; 0xfffffe34
  4c:	6c636e69 	stclvs	14, cr6, [r3], #-420	; 0xfffffe5c
  50:	00656475 	rsbeq	r6, r5, r5, ror r4
  54:	70706100 	rsbsvc	r6, r0, r0, lsl #2
  58:	0000632e 	andeq	r6, r0, lr, lsr #6
  5c:	74730000 	ldrbtvc	r0, [r3], #-0
  60:	746e6964 	strbtvc	r6, [lr], #-2404	; 0x964
  64:	0100682e 	tsteq	r0, lr, lsr #16
  68:	6c700000 	ldclvs	0, cr0, [r0], #-0
  6c:	6f667461 	svcvs	0x00667461
  70:	545f6d72 	ldrbpl	r6, [pc], #-3442	; 78 <.debug_line+0x78>
  74:	73657079 	cmnvc	r5, #121	; 0x79
  78:	0000682e 	andeq	r6, r0, lr, lsr #16
  7c:	00000000 	andeq	r0, r0, r0
  80:	00000205 	andeq	r0, r0, r5, lsl #4
  84:	4b160000 	blmi	58008c <main+0x58008c>
  88:	0004024b 	andeq	r0, r4, fp, asr #4
  8c:	Address 0x0000008c is out of bounds.


Disassembly of section .debug_str:

00000000 <.debug_str>:
   0:	2e707061 	cdpcs	0, 7, cr7, cr0, cr1, {3}
   4:	3a440063 	bcc	1100198 <main+0x1100198>
   8:	20594d5c 	subscs	r4, r9, ip, asr sp
   c:	72756f43 	rsbsvc	r6, r5, #268	; 0x10c
  10:	5c736573 	cfldr64pl	mvdx6, [r3], #-460	; 0xfffffe34
  14:	65626d45 	strbvs	r6, [r2, #-3397]!	; 0xd45
  18:	64656464 	strbtvs	r6, [r5], #-1124	; 0x464
  1c:	72654b20 	rsbvc	r4, r5, #32, 22	; 0x8000
  20:	69465c6f 	stmdbvs	r6, {r0, r1, r2, r3, r5, r6, sl, fp, ip, lr}^
  24:	20747372 	rsbscs	r7, r4, r2, ror r3
  28:	6d726554 	cfldr64vs	mvdx6, [r2, #-336]!	; 0xfffffeb0
  2c:	646f435c 	strbtvs	r4, [pc], #-860	; 34 <.debug_str+0x34>
  30:	614d5c65 	cmpvs	sp, r5, ror #24
  34:	72657473 	rsbvc	r7, r5, #1929379840	; 0x73000000
  38:	626d452d 	rsbvs	r4, sp, #188743680	; 0xb400000
  3c:	65646465 	strbvs	r6, [r4, #-1125]!	; 0x465
  40:	79532d64 	ldmdbvc	r3, {r2, r5, r6, r8, sl, fp, sp}^
  44:	6d657473 	cfstrdvs	mvd7, [r5, #-460]!	; 0xfffffe34
  48:	6e555c73 	mrcvs	12, 2, r5, cr5, cr3, {3}
  4c:	5c337469 	cfldrspl	mvf7, [r3], #-420	; 0xfffffe5c
  50:	65626d45 	strbvs	r6, [r2, #-3397]!	; 0xd45
  54:	64656464 	strbtvs	r6, [r5], #-1124	; 0x464
  58:	656c5f43 	strbvs	r5, [ip, #-3907]!	; 0xf43
  5c:	6e6f7373 	mcrvs	3, 3, r7, cr15, cr3, {3}
  60:	6c660032 	stclvs	0, cr0, [r6], #-200	; 0xffffff38
  64:	0074616f 	rsbseq	r6, r4, pc, ror #2
  68:	69736e75 	ldmdbvs	r3!, {r0, r2, r4, r5, r6, r9, sl, fp, sp, lr}^
  6c:	64656e67 	strbtvs	r6, [r5], #-3687	; 0xe67
  70:	61686320 	cmnvs	r8, r0, lsr #6
  74:	6f6c0072 	svcvs	0x006c0072
  78:	7520676e 	strvc	r6, [r0, #-1902]!	; 0x76e
  7c:	6769736e 	strbvs	r7, [r9, -lr, ror #6]!
  80:	2064656e 	rsbcs	r6, r4, lr, ror #10
  84:	00746e69 	rsbseq	r6, r4, r9, ror #28
  88:	726f6873 	rsbvc	r6, pc, #7536640	; 0x730000
  8c:	6e752074 	mrcvs	0, 3, r2, cr5, cr4, {3}
  90:	6e676973 	mcrvs	9, 3, r6, cr7, cr3, {3}
  94:	69206465 	stmdbvs	r0!, {r0, r2, r5, r6, sl, sp, lr}
  98:	7300746e 	movwvc	r7, #1134	; 0x46e
  9c:	6e697274 	mcrvs	2, 3, r7, cr9, cr4, {3}
  a0:	75625f67 	strbvc	r5, [r2, #-3943]!	; 0xf67
  a4:	72656666 	rsbvc	r6, r5, #106954752	; 0x6600000
  a8:	756f6400 	strbvc	r6, [pc, #-1024]!	; fffffcb0 <main+0xfffffcb0>
  ac:	00656c62 	rsbeq	r6, r5, r2, ror #24
  b0:	6e69616d 	powvsez	f6, f1, #5.0
  b4:	736e7500 	cmnvc	lr, #0, 10
  b8:	656e6769 	strbvs	r6, [lr, #-1897]!	; 0x769
  bc:	6e692064 	cdpvs	0, 6, cr2, cr9, cr4, {3}
  c0:	6f6c0074 	svcvs	0x006c0074
  c4:	6c20676e 	stcvs	7, cr6, [r0], #-440	; 0xfffffe48
  c8:	20676e6f 	rsbcs	r6, r7, pc, ror #28
  cc:	69736e75 	ldmdbvs	r3!, {r0, r2, r4, r5, r6, r9, sl, fp, sp, lr}^
  d0:	64656e67 	strbtvs	r6, [r5], #-3687	; 0xe67
  d4:	746e6920 	strbtvc	r6, [lr], #-2336	; 0x920
  d8:	6e697500 	cdpvs	5, 6, cr7, cr9, cr0, {0}
  dc:	745f3874 	ldrbvc	r3, [pc], #-2164	; e4 <.debug_str+0xe4>
  e0:	7a697300 	bvc	1a5cce8 <main+0x1a5cce8>
  e4:	70797465 	rsbsvc	r7, r9, r5, ror #8
  e8:	6f6c0065 	svcvs	0x006c0065
  ec:	6c20676e 	stcvs	7, cr6, [r0], #-440	; 0xfffffe48
  f0:	20676e6f 	rsbcs	r6, r7, pc, ror #28
  f4:	00746e69 	rsbseq	r6, r4, r9, ror #28
  f8:	20554e47 	subscs	r4, r5, r7, asr #28
  fc:	2e342043 	cdpcs	0, 3, cr2, cr4, cr3, {2}
 100:	00322e37 	eorseq	r2, r2, r7, lsr lr
 104:	726f6873 	rsbvc	r6, pc, #7536640	; 0x730000
 108:	6e692074 	mcrvs	0, 3, r2, cr9, cr4, {3}
 10c:	69750074 	ldmdbvs	r5!, {r2, r4, r5, r6}^
 110:	0038746e 	eorseq	r7, r8, lr, ror #8
 114:	676e6f6c 	strbvs	r6, [lr, -ip, ror #30]!
 118:	746e6920 	strbtvc	r6, [lr], #-2336	; 0x920
 11c:	67697300 	strbvs	r7, [r9, -r0, lsl #6]!
 120:	2064656e 	rsbcs	r6, r4, lr, ror #10
 124:	72616863 	rsbvc	r6, r1, #6488064	; 0x630000
	...

Disassembly of section .comment:

00000000 <.comment>:
   0:	43434700 	movtmi	r4, #14080	; 0x3700
   4:	4728203a 			; <UNDEFINED> instruction: 0x4728203a
   8:	2029554e 	eorcs	r5, r9, lr, asr #10
   c:	2e372e34 	mrccs	14, 1, r2, cr7, cr4, {1}
  10:	Address 0x00000010 is out of bounds.


Disassembly of section .ARM.attributes:

00000000 <.ARM.attributes>:
   0:	00003141 	andeq	r3, r0, r1, asr #2
   4:	61656100 	cmnvs	r5, r0, lsl #2
   8:	01006962 	tsteq	r0, r2, ror #18
   c:	00000027 	andeq	r0, r0, r7, lsr #32
  10:	4d524105 	ldfmie	f4, [r2, #-20]	; 0xffffffec
  14:	45363239 	ldrmi	r3, [r6, #-569]!	; 0x239
  18:	00532d4a 	subseq	r2, r3, sl, asr #26
  1c:	01080506 	tsteq	r8, r6, lsl #10
  20:	04120109 	ldreq	r0, [r2], #-265	; 0x109
  24:	01150114 	tsteq	r5, r4, lsl r1
  28:	01180317 	tsteq	r8, r7, lsl r3
  2c:	011a0119 	tsteq	sl, r9, lsl r1
  30:	Address 0x00000030 is out of bounds.


Disassembly of section .debug_frame:

00000000 <.debug_frame>:
   0:	0000000c 	andeq	r0, r0, ip
   4:	ffffffff 			; <UNDEFINED> instruction: 0xffffffff
   8:	7c020001 	stcvc	0, cr0, [r2], {1}
   c:	000d0c0e 	andeq	r0, sp, lr, lsl #24
  10:	00000018 	andeq	r0, r0, r8, lsl r0
	...
  1c:	00000018 	andeq	r0, r0, r8, lsl r0
  20:	8b080e42 	blhi	203930 <main+0x203930>
  24:	42018e02 	andmi	r8, r1, #2, 28
  28:	00040b0c 	andeq	r0, r4, ip, lsl #22
