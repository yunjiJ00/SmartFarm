.text
.global team1
team1:
	mov r0, #1
	ldr r1,=message
	ldr r2,=len
	mov r7,#4
	swi 0
	mov pc, lr
.data
message:
	.asciz "Hello smartfarm This is team1\n"
len=.-message
