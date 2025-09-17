<?php
header('Content-Type: application/json; charset=utf-8');

$acao = $_GET['acao'] ?? '';

switch ($acao) {
    case 'listarProdutos':
        $produtos = [
            [
                "id" => 1,
                "nome" => "Smart TV LED 55",
                "preco" => 2900
            ],
            [
                "id" => 2,
                "nome" => "Notebook Ultra Slim 17",
                "preco" => 4300
            ],
            [
                "id" => 3,
                "nome" => "Mouse Óptico XYZ",
                "preco" => 150
            ]
        ];
        echo json_encode($produtos);
        break;

    case 'adicionarProduto':
        echo json_encode(["mensagem" => "Produto adicionado com sucesso!"]);
        break;

    case 'excluirProduto':
        echo json_encode(["mensagem" => "Produto excluído com sucesso!"]);
        break;

    default:
        echo json_encode(["erro" => "Ação não reconhecida."]);
        break;
}
?>
