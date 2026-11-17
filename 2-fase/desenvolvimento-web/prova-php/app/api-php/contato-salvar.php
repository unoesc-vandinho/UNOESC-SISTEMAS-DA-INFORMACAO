<?php
require __DIR__ . '/conexao.php';
exigirPost();

$nome = campo('nome'); $email = campo('email'); $mensagem = campo('mensagem');
if ($nome === '' || $mensagem === '' || !filter_var($email, FILTER_VALIDATE_EMAIL)
    || mb_strlen($nome) > 120 || mb_strlen($email) > 150) {
    responder(['sucesso' => false, 'mensagem' => 'Dados inválidos. Verifique os campos.'], 422);
}

try {
    $st = $pdo->prepare('INSERT INTO contatos (nome, email, mensagem) VALUES (?, ?, ?)');
    $st->execute([$nome, $email, $mensagem]);
    responder(['sucesso' => true, 'mensagem' => 'Mensagem enviada com sucesso!']);
} catch (PDOException $e) {
    responder(['sucesso' => false, 'mensagem' => 'Erro ao gravar a mensagem.'], 500);
}
