document.addEventListener("DOMContentLoaded", function () {
    const FORM = document.getElementById("FORM");
    const mensagem = document.getElementById("mensagem");

    FORM.addEventListener("submit", function (event) {
        event.preventDefault();

        const email = document.getElementById("email").value;
        const pwd = document.getElementById("pwd").value;

        if (email.trim() === "" || pwd.trim() === "") {
            mensagem.style.display = "block";
        } else {
            mensagem.style.display = "none";
        }
    });
});

