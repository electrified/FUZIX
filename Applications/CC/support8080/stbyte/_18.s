
	.export __stbyte18

	.setcpu 8080
	.code
__stbyte18:
	mov a,l
	lxi h,18

	mov m,a
	mov l,a
	ret