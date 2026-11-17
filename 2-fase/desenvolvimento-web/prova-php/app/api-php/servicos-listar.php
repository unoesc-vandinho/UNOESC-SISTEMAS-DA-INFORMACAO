<?php
require __DIR__ . '/conexao.php';

try {
    $dados = $pdo->query('SELECT id, titulo, categoria, descricao, preco, imagem, pagina
                          FROM servicos ORDER BY id')->fetchAll();
    responder(['sucesso' => true, 'servicos' => $dados]);
} catch (PDOException $e) {
    responder(['sucesso' => false, 'mensagem' => 'Erro ao listar serviços.'], 500);
}
