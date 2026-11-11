<?php

include 'banco.php';

$query = $conecao->prepare("DELETE FROM cidade WHERE ibge = :ibge");
$query->execute([':ibge' => $_GET['ibge']]);

echo $conecao->lastInsertId();