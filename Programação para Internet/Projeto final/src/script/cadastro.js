function verificaSenha(){
    const senha = document.getElementById("passwordUser").value;
    const confirmarSenha = document.getElementById("confirmPasswordUser").value;
    const mensagem = document.getElementById("passwordMensagem");

    if(senha === confirmarSenha){
        mensagem.textContent = "✔";
        mensagem.style.color = "green";
    }else {
        mensagem.textContent = "As senhas precisam ser iguais!";
        mensagem.style.color = "red"
    }
}