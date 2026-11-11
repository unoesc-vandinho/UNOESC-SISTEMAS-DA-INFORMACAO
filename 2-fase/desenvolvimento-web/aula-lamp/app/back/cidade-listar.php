<?php

header('Content-Type: application/json; charset=utf-8');
include 'banco.php';

$query = $conecao->query("SELECT * FROM cidade ORDER BY cidade");
$data = $query->fetchAll(PDO::FETCH_ASSOC);

echo json_encode($data);
