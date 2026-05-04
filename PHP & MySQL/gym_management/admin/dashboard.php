<?php
require_once "../config.php";
require_once "../backend/admin_auth_check.php";

// Total Members
$sql = "SELECT COUNT(*) AS total FROM members WHERE role = 'member'";
$result = mysqli_query($link, $sql);
$row = mysqli_fetch_array($result);
$total_members = $row["total"];

// All-Time Revenue
$sql = "SELECT COALESCE(SUM(amount), 0) AS total FROM payments";
$result = mysqli_query($link, $sql);
$row = mysqli_fetch_array($result);
$all_time_revenue = $row["total"];

// This Month's Revenue
$sql = "SELECT COALESCE(SUM(amount), 0) AS total FROM payments WHERE MONTH(payment_date) = MONTH(CURDATE()) AND YEAR(payment_date) = YEAR(CURDATE())";
$result = mysqli_query($link, $sql);
$row = mysqli_fetch_array($result);
$this_month_revenue = $row["total"];

// Last Month's Revenue
$sql = "SELECT COALESCE(SUM(amount), 0) AS total FROM payments WHERE MONTH(payment_date) = MONTH(CURDATE() - INTERVAL 1 MONTH) AND YEAR(payment_date) = YEAR(CURDATE() - INTERVAL 1 MONTH)";
$result = mysqli_query($link, $sql);
$row = mysqli_fetch_array($result);
$last_month_revenue = $row["total"];

$revenue_increment = $this_month_revenue - $last_month_revenue;

mysqli_close($link);

$page_title = "Admin Dashboard";
require BASE_PATH . '/frontend/views/admin/dashboard.php';
