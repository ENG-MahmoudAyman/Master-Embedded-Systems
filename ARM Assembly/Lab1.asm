RESET  ;CPU entry point
			mov		R0,  #5
			bl		main
			
main
			mov		R2, #0x100
			str		R0, [R2]
			ldr		R3, [R2]
			strb		R0, [R2,#0x1]
			strb		R0, [R2,#0x2]
			strb		R0, [R2,#0x3]
			bl		subtract
			bl		termination
			
subtract
			sub		R0,R0,#1
			cmp		R0,#0
			bne		subtract
			mov		pc,lr
			
termination
