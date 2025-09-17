const box = document.querySelector(".container");
const imagens = document.querySelectorAll(".container img");

let count = 0;

function slider(){
    count++;

    if(count > imagens.length -1){
        count = 0;
    }
    box.style.transform = `translateX(${-count * 100}%)`;


}
setInterval(slider, 5000);




