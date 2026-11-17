-- phpMyAdmin SQL Dump
-- version 5.2.3
-- https://www.phpmyadmin.net/
--
-- Host: db
-- Tempo de geração: 17/11/2026 às 23:39
-- Versão do servidor: 11.8.9-MariaDB-ubu2404
-- Versão do PHP: 8.3.36

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Banco de dados: `pintinho_amarelinho`
--

-- --------------------------------------------------------

--
-- Estrutura para tabela `contatos`
--

CREATE TABLE `contatos` (
  `id` int(11) NOT NULL,
  `nome` varchar(120) NOT NULL,
  `email` varchar(150) NOT NULL,
  `mensagem` text NOT NULL,
  `criado_em` datetime NOT NULL DEFAULT current_timestamp()
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_uca1400_ai_ci;

-- --------------------------------------------------------

--
-- Estrutura para tabela `depoimentos`
--

CREATE TABLE `depoimentos` (
  `id` int(11) NOT NULL,
  `nome` varchar(120) NOT NULL,
  `descricao` varchar(150) DEFAULT NULL,
  `texto` text NOT NULL,
  `nota` tinyint(4) NOT NULL DEFAULT 5,
  `foto` varchar(200) DEFAULT NULL,
  `criado_em` datetime NOT NULL DEFAULT current_timestamp()
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_uca1400_ai_ci;

--
-- Despejando dados para a tabela `depoimentos`
--

INSERT INTO `depoimentos` (`id`, `nome`, `descricao`, `texto`, `nota`, `foto`, `criado_em`) VALUES
(1, 'Mariana Albuquerque', 'Tutora do Milo (Golden Retriever)', 'Sempre foi uma batalha levar o Milo ao veterinário; ele tremia só de ver a porta de vidro de outros lugares. Na Pintinho Amarelinho, o silêncio da recepção e a luz suave mudaram tudo. A Dra. Clara atendeu no chão, no ritmo dele, sem pressa. A transparência na explicação dos exames me deu uma paz que eu nunca tinha sentido antes.', 5, 'img/milo_WH_400x400px.jpg', '2026-03-14 10:00:00'),
(2, 'Gabriel Zanin', 'Tutor da Amora (Gata SRD)', 'Precisei de um ultrassom de emergência para a Amora e temia o estresse que isso causaria nela, que é arredia com estranhos. O Dr. Pedro foi impecável: preparou o ambiente, aqueceu o gel do exame e me deixou acariciar a cabeça dela durante todo o procedimento. O diagnóstico foi direto, objetivo e sem rodeios desnecessários.', 5, 'img/amora_WH_400x400px.jpg', '2026-05-22 10:00:00'),
(3, 'Camila Duarte', 'Tutora da Pipoca (Spitz Alemão)', 'O serviço de estética animal deles é incomparável. A Pipoca tem pânico de barulho de secador e sempre voltava estressada de petshops convencionais. No Spa da Pintinho Amarelinho, o isolamento acústico e a delicadeza no manejo fizeram ela voltar tranquila para casa, com o pelo impecável e sem cheiro forte de perfume barato.', 5, 'img/pipoca_WH_400x400px.jpg', '2026-08-08 10:00:00'),
(4, 'Lucas Ferreira', 'Tutor do Bento (Beagle)', 'O check-up preventivo anual do Bento foi um divisor de águas. Descobrimos precocemente uma leve alteração articular e pudemos ajustar a dieta e os exercícios antes de qualquer dor. O atendimento acolhedor e a pontualidade são raros de encontrar hoje em dia. Recomendo de olhos fechados!', 5, 'img/cliente04_WH_400x400px.jpg', '2026-08-29 10:00:00'),
(5, 'Beatriz Mendes', 'Tutora da Luna (Felina Persa)', 'A clínica tem uma energia de serenidade impressionante. Minha gata Luna odeia caixas de transporte, mas ao entrar na sala silenciosa com difusor de feromônios, ela ficou dócil. O respeito demonstrado pelos profissionais transforma uma visita clínica em um momento de pura segurança.', 5, 'img/cliente05_WH_400x400px.jpg', '2026-09-05 10:00:00');

-- --------------------------------------------------------

--
-- Estrutura para tabela `orcamentos`
--

CREATE TABLE `orcamentos` (
  `id` int(11) NOT NULL,
  `nome` varchar(120) NOT NULL,
  `email` varchar(150) NOT NULL,
  `telefone` varchar(20) NOT NULL,
  `cep` varchar(9) NOT NULL,
  `endereco` varchar(200) NOT NULL,
  `bairro` varchar(100) DEFAULT NULL,
  `cidade` varchar(100) NOT NULL,
  `uf` char(2) NOT NULL,
  `data_desejada` date NOT NULL,
  `servico` varchar(150) NOT NULL,
  `observacoes` text NOT NULL,
  `criado_em` datetime NOT NULL DEFAULT current_timestamp()
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_uca1400_ai_ci;

-- --------------------------------------------------------

--
-- Estrutura para tabela `profissionais`
--

CREATE TABLE `profissionais` (
  `id` int(11) NOT NULL,
  `nome` varchar(150) NOT NULL,
  `cargo` varchar(120) NOT NULL,
  `descricao` text NOT NULL,
  `especialidades` varchar(255) NOT NULL COMMENT 'separadas por vírgula',
  `foto` varchar(200) NOT NULL,
  `link_agendamento` varchar(300) NOT NULL,
  `texto_botao` varchar(80) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_uca1400_ai_ci;

--
-- Despejando dados para a tabela `profissionais`
--

INSERT INTO `profissionais` (`id`, `nome`, `cargo`, `descricao`, `especialidades`, `foto`, `link_agendamento`, `texto_botao`) VALUES
(1, 'Dra. Clara Letícia Daniela Rodrigues', 'Médica Veterinária Chefe', 'Com mais de uma década de experiência clínica e cirúrgica, a Dra. Clara lidera a equipe médica da Pintinho Amarelinho com um perfil pautado pela precisão técnica e escuta atenta aos tutores.', 'Terapia Intensiva,Amigo dos Felinos,Certificação Manejo Gentil', 'img/profissional01.jpg', 'https://wa.me/5549988951764?text=Olá!%20Gostaria%20de%20agendar%20uma%20consulta%20com%20a%20Dra.%20Clara.', 'Agendar Consulta'),
(2, 'Dr. Pedro Henrique Isaac Lucca Novaes', 'Cirurgião & Diagnóstico por Imagem', 'Especialista em Cirurgia de Tecidos Moles e Mestre em Ciências Veterinárias. Referência em procedimentos minimamente invasivos e ultrassonografia abdominal avançada de pequenos animais.', 'Cirurgia Tecidos Moles,Ultrassonografia,Anestesiologia', 'img/profissional02.avif', 'https://wa.me/5549988951764?text=Olá!%20Gostaria%20de%20agendar%20com%20o%20Dr.%20Pedro.', 'Agendar com Dr. Pedro');

-- --------------------------------------------------------

--
-- Estrutura para tabela `servicos`
--

CREATE TABLE `servicos` (
  `id` int(11) NOT NULL,
  `titulo` varchar(150) NOT NULL,
  `categoria` varchar(80) NOT NULL,
  `descricao` text NOT NULL,
  `preco` decimal(10,2) NOT NULL,
  `imagem` varchar(200) NOT NULL,
  `pagina` varchar(100) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_uca1400_ai_ci;

--
-- Despejando dados para a tabela `servicos`
--

INSERT INTO `servicos` (`id`, `titulo`, `categoria`, `descricao`, `preco`, `imagem`, `pagina`) VALUES
(1, 'Consulta Clínica Integrativa & Check-up', 'Clínica & Prevenção', 'Uma avaliação minuciosa da saúde geral do pet em consultório com iluminação suave e técnicas de manejo gentil e livre de estresse. Foco em prevenção e nutrição.', 180.00, 'img/servico-checkup_WH_640x426px.jpg', 'consulta-clinica.html'),
(2, 'Diagnóstico por Ultrassonografia', 'Diagnóstico Avançado', 'Investigação diagnóstica avançada realizada em ambiente tranquilo, avaliando órgãos abdominais e tecidos moles com alta resolução e apoio contínuo ao tutor.', 260.00, 'img/utrassonografia_WH_640x426px.jpg', 'ultrassonografia.html'),
(3, 'Estética Animal Calm & Spa', 'Petshop & Grooming', 'Banho terapêutico e tosa de baixa estimulação sensorial. Controle acústico, cosméticos veganos e secadores silenciosos para uma experiência relaxante.', 135.00, 'img/pet-model_WH_640x426px.jpg', 'estetica-calm-spa.html');

--
-- Índices para tabelas despejadas
--

--
-- Índices de tabela `contatos`
--
ALTER TABLE `contatos`
  ADD PRIMARY KEY (`id`);

--
-- Índices de tabela `depoimentos`
--
ALTER TABLE `depoimentos`
  ADD PRIMARY KEY (`id`);

--
-- Índices de tabela `orcamentos`
--
ALTER TABLE `orcamentos`
  ADD PRIMARY KEY (`id`);

--
-- Índices de tabela `profissionais`
--
ALTER TABLE `profissionais`
  ADD PRIMARY KEY (`id`);

--
-- Índices de tabela `servicos`
--
ALTER TABLE `servicos`
  ADD PRIMARY KEY (`id`);

--
-- AUTO_INCREMENT para tabelas despejadas
--

--
-- AUTO_INCREMENT de tabela `contatos`
--
ALTER TABLE `contatos`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT de tabela `depoimentos`
--
ALTER TABLE `depoimentos`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=6;

--
-- AUTO_INCREMENT de tabela `orcamentos`
--
ALTER TABLE `orcamentos`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT de tabela `profissionais`
--
ALTER TABLE `profissionais`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=3;

--
-- AUTO_INCREMENT de tabela `servicos`
--
ALTER TABLE `servicos`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=4;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
