function validateForm (e) {
    let form = e.target
    console.log(e)
    let isValid = true

    const user = form.elements.usuario.nextElementSibling
    const password = form.elements.senha.nextElementSibling
    const email = form.elements.email.nextElementSibling

    user.textContent = ''
    password.textContent = ''
    email.textContent = ''

    if (form.usuario.value === '') {
        user.textContent = 'Usuário deve ser preenchido'
        isValid = false
    }

    if (form.senha.value === '') {
        password.textContent = 'A senha deve ser preenchida'
        isValid = false
    }

    if (form.email.value === '') {
        email.textContent = 'O email deve ser preenchido'
        isValid = false
    }

    if (!isValid) e.preventDefault()
}

document.forms.cadastro.onsubmit = validateForm