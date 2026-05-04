<?php
session_start();

// Check if user is logged in as admin
if (!isset($_SESSION["member_id"]) || $_SESSION["role"] !== "admin") {
    // Try to use BASE_URL if config was loaded, otherwise fallback
    $redirect = defined('BASE_URL') ? BASE_URL . '/index.php' : '../index.php';
    header("location: " . $redirect);
    exit();
}
