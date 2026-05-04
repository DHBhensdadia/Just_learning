-- phpMyAdmin SQL Dump
-- version 5.2.1
-- https://www.phpmyadmin.net/
--
-- Host: localhost
-- Generation Time: Apr 30, 2026 at 07:19 PM
-- Server version: 10.4.28-MariaDB
-- PHP Version: 8.2.4

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `gym_management`
--

-- --------------------------------------------------------

--
-- Table structure for table `members`
--

CREATE TABLE `members` (
  `member_id` int(11) NOT NULL,
  `name` varchar(100) NOT NULL,
  `email` varchar(150) NOT NULL,
  `password` varchar(255) NOT NULL,
  `phone` varchar(15) DEFAULT NULL,
  `role` enum('admin','member') DEFAULT 'member',
  `join_date` date NOT NULL,
  `plan_id` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `members`
--

INSERT INTO `members` (`member_id`, `name`, `email`, `password`, `phone`, `role`, `join_date`, `plan_id`) VALUES
(1, 'Nikola', 'admin@gym.com', '$2y$10$Qo.qpn9vnkJwD8GXmXgEi.Un.g92JXOEUdGaxE9o44TPzpgHTsCVW', '9999999999', 'admin', '2026-04-29', NULL),
(2, 'Dhyey', 'dhyey@gmail.com', '$2y$10$BlVxbttcT8LeXwq5V9h5kevoJ2gEtXWTn1/0qyColqsTvle0tb1Ve', '9087651234', 'member', '2026-04-29', 2),
(3, 'Aarav Sharma', 'aarav@example.com', '$2y$10$qtP99kC2TWuZqVhVpIJX/.0fOf030BbKBnxYGkraB.cNQLiOOOBei', '9876543210', 'member', '2025-06-15', 1),
(4, 'Priya Patel', 'priya@example.com', '$2y$10$RIdDfXbU/9THfVTWEwLSOerdMZIiODVH20qjXb6IgjYVkuPnQcAbG', '9876543211', 'member', '2025-08-01', 2),
(5, 'Rohan Mehta', 'rohan@example.com', '$2y$10$A9U5pva4Q1nRAVfeKwaGpebZeyuLKpwc7Fxuv9YeZv2B9BFrHFo8.', '9876543212', 'member', '2025-11-10', 3),
(6, 'Sneha Iyer', 'sneha@example.com', '$2y$10$sJHHy3SIryClH7t/MoCf3e1WuofcJ7EWosZ6uSddDESzJRorbxUIm', '9876543213', 'member', '2026-01-20', 4);

-- --------------------------------------------------------

--
-- Table structure for table `payments`
--

CREATE TABLE `payments` (
  `payment_id` int(11) NOT NULL,
  `member_id` int(11) NOT NULL,
  `plan_id` int(11) NOT NULL,
  `amount` decimal(10,2) NOT NULL,
  `payment_date` date NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `payments`
--

INSERT INTO `payments` (`payment_id`, `member_id`, `plan_id`, `amount`, `payment_date`) VALUES
(1, 2, 2, 1200.00, '2026-04-29'),
(2, 3, 1, 500.00, '2025-06-15'),
(3, 4, 2, 1200.00, '2025-08-01'),
(4, 5, 3, 2000.00, '2025-11-10'),
(5, 6, 4, 3500.00, '2026-01-20'),
(6, 3, 1, 500.00, '2026-02-15'),
(7, 4, 2, 1200.00, '2026-03-01'),
(8, 5, 3, 2000.00, '2026-03-10'),
(9, 6, 4, 3500.00, '2026-04-05'),
(10, 3, 1, 500.00, '2026-04-15'),
(11, 4, 2, 1200.00, '2026-04-22');

-- --------------------------------------------------------

--
-- Table structure for table `plans`
--

CREATE TABLE `plans` (
  `plan_id` int(11) NOT NULL,
  `plan_name` varchar(100) NOT NULL,
  `duration_months` int(11) NOT NULL,
  `price` decimal(10,2) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `plans`
--

INSERT INTO `plans` (`plan_id`, `plan_name`, `duration_months`, `price`) VALUES
(1, 'Basic', 1, 500.00),
(2, 'Standard', 3, 1200.00),
(3, 'Premium', 6, 2000.00),
(4, 'Annual', 12, 3500.00);

--
-- Indexes for dumped tables
--

--
-- Indexes for table `members`
--
ALTER TABLE `members`
  ADD PRIMARY KEY (`member_id`),
  ADD UNIQUE KEY `email` (`email`),
  ADD KEY `plan_id` (`plan_id`);

--
-- Indexes for table `payments`
--
ALTER TABLE `payments`
  ADD PRIMARY KEY (`payment_id`),
  ADD KEY `member_id` (`member_id`),
  ADD KEY `plan_id` (`plan_id`);

--
-- Indexes for table `plans`
--
ALTER TABLE `plans`
  ADD PRIMARY KEY (`plan_id`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `members`
--
ALTER TABLE `members`
  MODIFY `member_id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=7;

--
-- AUTO_INCREMENT for table `payments`
--
ALTER TABLE `payments`
  MODIFY `payment_id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=12;

--
-- AUTO_INCREMENT for table `plans`
--
ALTER TABLE `plans`
  MODIFY `plan_id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=5;

--
-- Constraints for dumped tables
--

--
-- Constraints for table `members`
--
ALTER TABLE `members`
  ADD CONSTRAINT `members_ibfk_1` FOREIGN KEY (`plan_id`) REFERENCES `plans` (`plan_id`);

--
-- Constraints for table `payments`
--
ALTER TABLE `payments`
  ADD CONSTRAINT `payments_ibfk_1` FOREIGN KEY (`member_id`) REFERENCES `members` (`member_id`),
  ADD CONSTRAINT `payments_ibfk_2` FOREIGN KEY (`plan_id`) REFERENCES `plans` (`plan_id`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
