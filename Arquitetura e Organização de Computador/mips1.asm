.data
	#area para dados na memoria principal
	msg: .asciiz "Ol�, mundo!" #mensagem a ser exibida para o usuario
.text
	#area para instru��es de programa.
	li $v0, 4 #instru��o para impressao de String
	la $a0, msg #indicar o endere�o em que esta a mensagem
	syscall #fa�a
