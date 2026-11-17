<?php
require __DIR__ . '/conexao.php';
exigirPost();

$nome = campo('nome'); $descricao = campo('descricao'); $texto = campo('texto');
$nota = (int) campo('nota');
if ($nome === '' || $texto === '' || $nota < 1 || $nota > 5
    || mb_strlen($nome) > 120 || mb_strlen($descricao) > 150 || mb_strlen($texto) > 1000) {
    responder(['sucesso' => false, 'mensagem' => 'Dados inválidos. Verifique os campos.'], 422);
}

try {
    $st = $pdo->prepare('INSERT INTO depoimentos (nome, descricao, texto, nota) VALUES (?, ?, ?, ?)');
    $st->execute([$nome, $descricao !== '' ? $descricao : null, $texto, $nota]);
    responder(['sucesso' => true, 'mensagem' => 'Depoimento publicado. Obrigado!']);
} catch (PDOException $e) {
    responder(['sucesso' => false, 'mensagem' => 'Erro ao gravar o depoimento.'], 500);
}
