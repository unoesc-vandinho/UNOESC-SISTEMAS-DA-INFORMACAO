# Aula LAMP (PHP + MariaDB)

Ambiente de desenvolvimento com Docker para as aulas de PHP e banco de dados, em 3 containers.

## Serviços

| Serviço | Imagem | Endereço |
|---|---|---|
| `web` | `php:8.5-apache` (+ `pdo_mysql`, ver `Dockerfile`) | http://localhost:8081 |
| `db` | `mariadb:11` | Interno (host `db`, porta 3306) |
| `phpmyadmin` | `phpmyadmin:5` | http://localhost:8080 |

## Como usar

```bash
docker compose up -d --build
docker compose down
```

- Os arquivos da pasta `app/` são servidos pelo Apache.
- Banco `banco2026`, usuário `admin`, senha `admin` (root também `admin`).
- Os dados ficam no volume `db-data` e sobrevivem ao `docker compose down`. Para zerar o banco: `docker compose down -v`.

## Observações

- A imagem oficial do PHP não traz o driver `pdo_mysql`, por isso o `Dockerfile`.
- O `web` só sobe depois que o `db` estiver saudável (healthcheck).
- Em `app/back/banco.php` o host do banco é `db`, o nome do serviço no compose.
