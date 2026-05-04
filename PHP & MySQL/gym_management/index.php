<?php
session_start();
require_once "config.php";

// If already logged in, redirect to dashboard
if (isset($_SESSION["member_id"])) {
    if ($_SESSION["role"] == "admin") {
        header("location: admin/dashboard.php");
        exit();
    } else {
        header("location: member/dashboard.php");
        exit();
    }
}

$page_title = "Login";
require BASE_PATH . '/frontend/views/login.php';
