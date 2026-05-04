<?php
require_once "../config.php";
require_once "../backend/auth_check.php";

$page_title = "Member Dashboard";
mysqli_close($link);
require BASE_PATH . '/frontend/views/member/dashboard.php';
