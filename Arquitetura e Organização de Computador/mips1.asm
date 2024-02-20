.data
	#area para dados na memoria principal
	msg: .asciiz "Olá, mundo!" #mensagem a ser exibida para o usuario
.text
	#area para instruções de programa.
	li $v0, 4 #instrução para impressao de String
	la $a0, msg #indicar o endereço em que esta a mensagem
	syscall #faça
