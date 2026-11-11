<?php

include 'banco.php';

$query = $conecao->prepare("INSERT INTO cidade (cidade, uf) VALUES (:cidade, :uf)");
$query->execute([':cidade' => $_GET['cidade'], ':uf' => $_GET['uf']]);

echo json_encode(['inseridas' => $query->rowCount()]);

sleep(2000);
header("Location: https://localhost:8080");