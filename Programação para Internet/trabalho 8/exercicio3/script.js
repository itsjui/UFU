const campoInteresse = document.querySelector("input");
campoInteresse.addEventListener("keyup", e => {
    if(e.key === "Enter"){
        const novoLi = document.createElement("li");
        const novoSpan = document.createElement("span");
        const novoBotao = document.createElement("button");

        novoSpan.textContent = campoInteresse.value;
        novoBotao.textContent= 'X';

        novoLi.appendChild(novoSpan);
        novoLi.appendChild(novoBotao);
        const listaInteresses = document.querySelector("ol").appendChild(novoLi);
        novoBotao.onclick = function(){
            listaInteresses.remove()
        }
        campoInteresse.value = '';
    }

})
