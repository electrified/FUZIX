
	.export __stbyte17

	.setcpu 8080
	.code
__stbyte17:
	mov a,l
	lxi h,17

	mov m,a
	mov l,a
	ret