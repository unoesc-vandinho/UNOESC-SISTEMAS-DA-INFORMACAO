<?php
require __DIR__ . '/conexao.php';

try {
    $dados = $pdo->query('SELECT id, nome, cargo, descricao, especialidades, foto, link_agendamento, texto_botao
                          FROM profissionais ORDER BY id')->fetchAll();
    responder(['sucesso' => true, 'profissionais' => $dados]);
} catch (PDOException $e) {
    responder(['sucesso' => false, 'mensagem' => 'Erro ao listar profissionais.'], 500);
}
