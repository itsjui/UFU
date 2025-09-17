function section (element, value) {
    console.log(element.nextElementSibling)
    element.nextElementSibling.style.display = value
}

document.querySelectorAll('h2').forEach((subtitle) => {
  subtitle.addEventListener('click', () => section(subtitle, 'none'))
  subtitle.addEventListener('dblclick', () => section(subtitle, 'block'))
})