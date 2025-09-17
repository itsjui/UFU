<?php

require "../conexaoMysql.php";
$pdo = mysqlConnect();

$nome = $_POST["nome"] ?? "";
$telefone = $_POST["telefone"] ?? "";

try {

  // NÃO FAÇA ISSO! Exemplo de código vulnerável a inj. de S-Q-L
  $sql = <<<SQL
  INSERT INTO aluno (nome, telefone)
  VALUES ('$nome', '$telefone');
  SQL;  

  // Experimente fazer o cadastro de um novo aluno preenchendo 
  // o campo telefone utilizando o texto disponibilizado pelo professor
  // nos slides de aula
  /*$pdo->exec($sql);
  header("location: mostra-alunos.php");
  exit(); */

   $pdo->prepare($sql);
   $pdo->exec($sql);
  header("location: mostra-alunos.php");
  exit();
  }
catch (Exception $e) {  
  exit('Falha ao cadastrar os dados: ' . $e->getMessage());
}

// Como explicado pelo professor em sala de aula, o programa está com riscos de ataque devido a falta do "prepare" 
// que utiliza uma tecnica de segurança no pré processamento do sdados inseridos pelo usuario, alem disso poderá 
// ser inserido o rollback para evitar eventuais problemas de cadastro.