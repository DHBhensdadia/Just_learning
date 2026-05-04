<?php
require_once "../config.php";
require_once "../backend/auth_check.php";

// Get current plan details
$sql = "SELECT m.join_date, p.plan_name, p.duration_months, p.price FROM members m LEFT JOIN plans p ON m.plan_id = p.plan_id WHERE m.member_id = ?";
$plan_name = "";
$duration_months = 0;
$price = 0;
$join_date = "";

if ($stmt = mysqli_prepare($link, $sql)) {
    mysqli_stmt_bind_param($stmt, "i", $param_id);
    $param_id = $_SESSION["member_id"];

    if (mysqli_stmt_execute($stmt)) {
        $result = mysqli_stmt_get_result($stmt);
        if (mysqli_num_rows($result) == 1) {
            $row = mysqli_fetch_array($result, MYSQLI_ASSOC);
            $plan_name = $row["plan_name"];
            $duration_months = $row["duration_months"];
            $price = $row["price"];
            $join_date = $row["join_date"];
        }
    }
    mysqli_stmt_close($stmt);
}

// Get latest payment to calculate valid_until
$valid_until = "";
$last_payment_date = "";

$sql = "SELECT py.payment_date, p.duration_months FROM payments py JOIN plans p ON py.plan_id = p.plan_id WHERE py.member_id = ? ORDER BY py.payment_date DESC LIMIT 1";

if ($stmt = mysqli_prepare($link, $sql)) {
    mysqli_stmt_bind_param($stmt, "i", $param_id);
    $param_id = $_SESSION["member_id"];

    if (mysqli_stmt_execute($stmt)) {
        $result = mysqli_stmt_get_result($stmt);
        if (mysqli_num_rows($result) == 1) {
            $payment_row = mysqli_fetch_array($result, MYSQLI_ASSOC);
            $last_payment_date = $payment_row["payment_date"];
            $months = $payment_row["duration_months"];
            $valid_until = date('Y-m-d', strtotime($last_payment_date . " + $months months"));
        }
    }
    mysqli_stmt_close($stmt);
}

mysqli_close($link);

$page_title = "My Subscription";
require BASE_PATH . '/frontend/views/member/subscription.php';
