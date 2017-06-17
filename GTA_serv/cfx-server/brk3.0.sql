-- phpMyAdmin SQL Dump
-- version 4.6.4
-- https://www.phpmyadmin.net/
--
-- Client :  127.0.0.1
-- Généré le :  Mar 25 Avril 2017 à 17:09
-- Version du serveur :  5.7.14
-- Version de PHP :  5.6.25

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Base de données :  `gta5_gamemode_essential`
--
CREATE DATABASE IF NOT EXISTS `gta5_gamemode_essential` DEFAULT CHARACTER SET latin1 COLLATE latin1_swedish_ci;
USE `gta5_gamemode_essential`;

-- --------------------------------------------------------

--
-- Structure de la table `bans`
--

CREATE TABLE `bans` (
  `id` int(10) NOT NULL,
  `banned` varchar(50) NOT NULL DEFAULT '0',
  `banner` varchar(50) NOT NULL,
  `reason` varchar(150) NOT NULL DEFAULT '0',
  `expires` datetime NOT NULL,
  `timestamp` datetime NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Structure de la table `coordinates`
--

CREATE TABLE `coordinates` (
  `id` int(11) UNSIGNED NOT NULL,
  `x` double DEFAULT NULL,
  `y` double DEFAULT NULL,
  `z` double DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Contenu de la table `coordinates`
--

INSERT INTO `coordinates` (`id`, `x`, `y`, `z`) VALUES
(1, 2222.84301757813, 5578.4443359375, 53.7291946411133),
(2, 2477.29931640625, 3784.62109375, 41.4352760314941),
(3, -1476.54870605469, 171.836669921875, 55.8890762329102),
(4, 2645.97143554688, 2806.37280273438, 33.9922828674316),
(5, 1038.34326171875, 2261.36840820313, 43.729866027832),
(6, 172.151062011719, 2279.62280273438, 92.6908645629883),
(7, -1767.95, 2201.6, 102.744),
(8, 857.683, -1958.85, 29.54),
(9, 466.075, -1847.81, 27.8526);

-- --------------------------------------------------------

--
-- Structure de la table `items`
--

CREATE TABLE `items` (
  `id` int(11) UNSIGNED NOT NULL,
  `libelle` varchar(255) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Contenu de la table `items`
--

INSERT INTO `items` (`id`, `libelle`) VALUES
(1, 'Cuivre'),
(2, 'Fer'),
(3, 'Or'),
(4, 'Weed'),
(5, 'Pain'),
(6, 'Eau'),
(7, 'Coca'),
(8, 'Pefra'),
(9, 'Lingo de cuivre'),
(10, 'Grappe de raisins\r\n'),
(11, 'Tonneau de vin');

-- --------------------------------------------------------

--
-- Structure de la table `jobs`
--

CREATE TABLE `jobs` (
  `job_id` int(11) NOT NULL,
  `job_name` varchar(40) NOT NULL,
  `salary` int(11) NOT NULL DEFAULT '500'
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Contenu de la table `jobs`
--

INSERT INTO `jobs` (`job_id`, `job_name`, `salary`) VALUES
(1, 'Chomeur', 500),
(2, 'Policier', 1200),
(3, 'Pompier', 1200),
(4, 'Mineur', 700),
(5, 'Chauffeur de taxi', 1000),
(6, 'Vigneron', 850);

-- --------------------------------------------------------

--
-- Structure de la table `recolt`
--

CREATE TABLE `recolt` (
  `ID` int(11) UNSIGNED NOT NULL,
  `raw_id` int(11) UNSIGNED DEFAULT NULL,
  `treated_id` int(11) UNSIGNED DEFAULT NULL,
  `job_id` int(11) DEFAULT NULL,
  `price` int(11) DEFAULT NULL,
  `field_id` int(10) UNSIGNED DEFAULT NULL,
  `treatment_id` int(10) UNSIGNED DEFAULT NULL,
  `seller_id` int(10) UNSIGNED DEFAULT NULL
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Contenu de la table `recolt`
--

INSERT INTO `recolt` (`ID`, `raw_id`, `treated_id`, `job_id`, `price`, `field_id`, `treatment_id`, `seller_id`) VALUES
(1, 4, 8, NULL, 100, 1, 2, 3),
(2, 1, 9, 4, 65, 4, 5, 6),
(3, 10, 11, 6, 75, 7, 8, 9);

-- --------------------------------------------------------

--
-- Structure de la table `user_inventory`
--

CREATE TABLE `user_inventory` (
  `user_id` varchar(255) CHARACTER SET utf8mb4 NOT NULL DEFAULT '',
  `item_id` int(11) UNSIGNED NOT NULL,
  `quantity` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Contenu de la table `user_inventory`
--

INSERT INTO `user_inventory` (`user_id`, `item_id`, `quantity`) VALUES
('steam:1100001016a2e39', 4, 18);

-- --------------------------------------------------------

--
-- Structure de la table `users`
--

CREATE TABLE `users` (
  `identifier` varchar(255) NOT NULL DEFAULT '',
  `group` varchar(50) NOT NULL DEFAULT '0',
  `permission_level` int(11) NOT NULL DEFAULT '0',
  `money` double NOT NULL DEFAULT '0',
  `bankbalance` int(32) DEFAULT '0',
  `job` int(11) DEFAULT '1',
  `lastpos` varchar(255) DEFAULT '{241.609985351563, -877.769958496094,  30.4920997619629, 0}'
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Index pour les tables exportées
--

--
-- Index pour la table `bans`
--
ALTER TABLE `bans`
  ADD PRIMARY KEY (`id`);

--
-- Index pour la table `coordinates`
--
ALTER TABLE `coordinates`
  ADD PRIMARY KEY (`id`);

--
-- Index pour la table `items`
--
ALTER TABLE `items`
  ADD PRIMARY KEY (`id`);

--
-- Index pour la table `jobs`
--
ALTER TABLE `jobs`
  ADD PRIMARY KEY (`job_id`);

--
-- Index pour la table `recolt`
--
ALTER TABLE `recolt`
  ADD PRIMARY KEY (`ID`),
  ADD KEY `raw_id` (`raw_id`),
  ADD KEY `treated_id` (`treated_id`),
  ADD KEY `job_id` (`job_id`),
  ADD KEY `field_id` (`field_id`),
  ADD KEY `treatment_id` (`treatment_id`),
  ADD KEY `seller_id` (`seller_id`);

--
-- Index pour la table `user_inventory`
--
ALTER TABLE `user_inventory`
  ADD PRIMARY KEY (`user_id`,`item_id`),
  ADD KEY `item_id` (`item_id`);

--
-- Index pour la table `users`
--
ALTER TABLE `users`
  ADD PRIMARY KEY (`identifier`);

--
-- AUTO_INCREMENT pour les tables exportées
--

--
-- AUTO_INCREMENT pour la table `bans`
--
ALTER TABLE `bans`
  MODIFY `id` int(10) NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT pour la table `coordinates`
--
ALTER TABLE `coordinates`
  MODIFY `id` int(11) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=10;
--
-- AUTO_INCREMENT pour la table `items`
--
ALTER TABLE `items`
  MODIFY `id` int(11) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=12;
--
-- AUTO_INCREMENT pour la table `jobs`
--
ALTER TABLE `jobs`
  MODIFY `job_id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=7;
--
-- AUTO_INCREMENT pour la table `recolt`
--
ALTER TABLE `recolt`
  MODIFY `ID` int(11) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=4;
--
-- Contraintes pour les tables exportées
--

--
-- Contraintes pour la table `user_inventory`
--
ALTER TABLE `user_inventory`
  ADD CONSTRAINT `user_inventory_ibfk_2` FOREIGN KEY (`item_id`) REFERENCES `items` (`id`);
--
-- Base de données :  `gta5_script_carshop`
--
CREATE DATABASE IF NOT EXISTS `gta5_script_carshop` DEFAULT CHARACTER SET latin1 COLLATE latin1_swedish_ci;
USE `gta5_script_carshop`;

-- --------------------------------------------------------

--
-- Structure de la table `vehicles`
--

CREATE TABLE `vehicles` (
  `owner` varchar(50) CHARACTER SET utf8 NOT NULL,
  `model` varchar(50) CHARACTER SET utf8 DEFAULT NULL,
  `colour` varchar(50) CHARACTER SET utf8 DEFAULT '0',
  `scolour` varchar(50) CHARACTER SET utf8 DEFAULT '0',
  `plate` varchar(50) CHARACTER SET utf8 DEFAULT '0',
  `wheels` int(11) DEFAULT '0',
  `windows` int(11) DEFAULT '0',
  `platetype` int(11) DEFAULT '0',
  `exhausts` int(11) DEFAULT '0',
  `grills` int(11) DEFAULT '0',
  `spoiler` int(11) DEFAULT '0'
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Index pour les tables exportées
--

--
-- Index pour la table `vehicles`
--
ALTER TABLE `vehicles`
  ADD KEY `Index 1` (`plate`);
--
-- Base de données :  `gta5_script_customization`
--
CREATE DATABASE IF NOT EXISTS `gta5_script_customization` DEFAULT CHARACTER SET latin1 COLLATE latin1_swedish_ci;
USE `gta5_script_customization`;

-- --------------------------------------------------------

--
-- Structure de la table `outfits`
--

CREATE TABLE `outfits` (
  `identifier` varchar(50) CHARACTER SET utf8 NOT NULL,
  `hair` int(11) DEFAULT NULL,
  `haircolour` int(11) DEFAULT NULL,
  `torso` int(11) DEFAULT NULL,
  `torsotexture` int(11) DEFAULT NULL,
  `torsoextra` int(11) DEFAULT NULL,
  `torsoextratexture` int(11) DEFAULT NULL,
  `pants` int(11) DEFAULT NULL,
  `pantscolour` int(11) DEFAULT NULL,
  `shoes` int(11) DEFAULT NULL,
  `shoescolour` int(11) DEFAULT NULL,
  `bodyaccesoire` int(11) DEFAULT NULL,
  `undershirt` int(11) DEFAULT NULL,
  `armor` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
--
-- Base de données :  `gta5_script_stats`
--
CREATE DATABASE IF NOT EXISTS `gta5_script_stats` DEFAULT CHARACTER SET latin1 COLLATE latin1_swedish_ci;
USE `gta5_script_stats`;

-- --------------------------------------------------------

--
-- Structure de la table `users`
--

CREATE TABLE `users` (
  `identifier` varchar(50) CHARACTER SET utf8 NOT NULL,
  `playtime` double DEFAULT NULL,
  `shotsfired` double DEFAULT NULL,
  `kmdriven` double DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Contenu de la table `users`
--

INSERT INTO `users` (`identifier`, `playtime`, `shotsfired`, `kmdriven`) VALUES
('steam:1100001016a2e39', 14, 0, 0);

--
-- Index pour les tables exportées
--

--
-- Index pour la table `users`
--
ALTER TABLE `users`
  ADD PRIMARY KEY (`identifier`);
--
-- Base de données :  `gta5_script_turfs`
--
CREATE DATABASE IF NOT EXISTS `gta5_script_turfs` DEFAULT CHARACTER SET latin1 COLLATE latin1_swedish_ci;
USE `gta5_script_turfs`;

-- --------------------------------------------------------

--
-- Structure de la table `turfs`
--

CREATE TABLE `turfs` (
  `identifier` varchar(50) CHARACTER SET utf8 NOT NULL,
  `SANDY` tinyint(4) DEFAULT '0'
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Contenu de la table `turfs`
--

INSERT INTO `turfs` (`identifier`, `SANDY`) VALUES
('steam:1100001016a2e39', 0);
--
-- Base de données :  `gta5_script_weaponshop`
--
CREATE DATABASE IF NOT EXISTS `gta5_script_weaponshop` DEFAULT CHARACTER SET latin1 COLLATE latin1_swedish_ci;
USE `gta5_script_weaponshop`;

-- --------------------------------------------------------

--
-- Structure de la table `owned`
--

CREATE TABLE `owned` (
  `identifier` varchar(50) CHARACTER SET utf8 NOT NULL,
  `weapon` varchar(50) CHARACTER SET utf8 DEFAULT NULL,
  `withdraw_cost` int(10) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
