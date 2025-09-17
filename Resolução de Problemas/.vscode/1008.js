function calculaFuncionario(numFunc, hora, valorPorHoras){
    const salario = hora * valorPorHoras;

    console.log(`NUMBER = ${numFunc}`);
    console.log(`SALARY = $ ${salario.toFixed(2)}`);
}

calculaFuncionario(225,100, 5.50);