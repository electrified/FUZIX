
	.export __stbyte8

	.setcpu 8080
	.code
__stbyte8:
	mov a,l
	lxi h,8

	mov m,a
	mov l,a
	ret