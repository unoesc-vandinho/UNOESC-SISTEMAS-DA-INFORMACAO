<?php
require __DIR__ . '/conexao.php';
exigirPost();

$d = [];
foreach (['nome','email','telefone','cep','endereco','bairro','cidade','uf','data_desejada','servico','observacoes'] as $c) {
    $d[$c] = campo($c);
}
$d['uf'] = strtoupper($d['uf']);

$dataOk = DateTime::createFromFormat('Y-m-d', $d['data_desejada']) !== false;
if ($d['nome'] === '' || $d['telefone'] === '' || $d['endereco'] === '' || $d['cidade'] === ''
    || $d['servico'] === '' || $d['observacoes'] === '' || !$dataOk
    || !filter_var($d['email'], FILTER_VALIDATE_EMAIL)
    || !preg_match('/^\d{5}-?\d{3}$/', $d['cep'])
    || !preg_match('/^[A-Z]{2}$/', $d['uf'])
    || mb_strlen($d['nome']) > 120 || mb_strlen($d['telefone']) > 20) {
    responder(['sucesso' => false, 'mensagem' => 'Dados inválidos. Verifique os campos.'], 422);
}

try {
    $st = $pdo->prepare('INSERT INTO orcamentos
        (nome, email, telefone, cep, endereco, bairro, cidade, uf, data_desejada, servico, observacoes)
        VALUES (:nome, :email, :telefone, :cep, :endereco, :bairro, :cidade, :uf, :data_desejada, :servico, :observacoes)');
    $st->execute($d);
    responder(['sucesso' => true, 'mensagem' => 'Orçamento registrado com sucesso!']);
} catch (PDOException $e) {
    responder(['sucesso' => false, 'mensagem' => 'Erro ao gravar o orçamento.'], 500);
}
