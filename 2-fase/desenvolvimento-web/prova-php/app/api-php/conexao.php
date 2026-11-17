<?php
// Conexão PDO com o MariaDB (host "db" = nome do serviço no docker-compose).
header('Content-Type: application/json; charset=utf-8');

function responder(array $dados, int $status = 200): void {
    http_response_code($status);
    echo json_encode($dados, JSON_UNESCAPED_UNICODE);
    exit;
}

function exigirPost(): void {
    if ($_SERVER['REQUEST_METHOD'] !== 'POST') {
        responder(['sucesso' => false, 'mensagem' => 'Método não permitido.'], 405);
    }
}

function campo(string $nome): string {
    return trim($_POST[$nome] ?? '');
}

try {
    $pdo = new PDO(
        'mysql:host=db;dbname=pintinho_amarelinho;charset=utf8mb4',
        'admin', 'admin',
        [PDO::ATTR_ERRMODE => PDO::ERRMODE_EXCEPTION,
         PDO::ATTR_DEFAULT_FETCH_MODE => PDO::FETCH_ASSOC]
    );
} catch (PDOException $e) {
    responder(['sucesso' => false, 'mensagem' => 'Falha ao conectar ao banco.'], 500);
}
