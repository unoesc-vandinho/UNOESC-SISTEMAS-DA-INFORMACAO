<?php
require __DIR__ . '/conexao.php';

try {
    $dados = $pdo->query('SELECT id, nome, descricao, texto, nota, foto, criado_em
                          FROM depoimentos ORDER BY criado_em DESC, id DESC')->fetchAll();
    responder(['sucesso' => true, 'depoimentos' => $dados]);
} catch (PDOException $e) {
    responder(['sucesso' => false, 'mensagem' => 'Erro ao listar depoimentos.'], 500);
}
