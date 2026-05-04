<?php
require_once "../config.php";
require_once "../backend/auth_check.php";

// Get payment history for this member
$sql = "SELECT py.payment_id, py.amount, py.payment_date, p.plan_name FROM payments py JOIN plans p ON py.plan_id = p.plan_id WHERE py.member_id = ? ORDER BY py.payment_date DESC";
$payments = [];

if ($stmt = mysqli_prepare($link, $sql)) {
    mysqli_stmt_bind_param($stmt, "i", $param_id);
    $param_id = $_SESSION["member_id"];

    if (mysqli_stmt_execute($stmt)) {
        $result = mysqli_stmt_get_result($stmt);
        while ($row = mysqli_fetch_array($result, MYSQLI_ASSOC)) {
            $payments[] = $row;
        }
        mysqli_free_result($result);
    }
    mysqli_stmt_close($stmt);
}

// Get total amount spent
$total_spent = 0;
$sql = "SELECT COALESCE(SUM(amount), 0) AS total FROM payments WHERE member_id = ?";

if ($stmt = mysqli_prepare($link, $sql)) {
    mysqli_stmt_bind_param($stmt, "i", $param_id);
    $param_id = $_SESSION["member_id"];

    if (mysqli_stmt_execute($stmt)) {
        $result = mysqli_stmt_get_result($stmt);
        $row = mysqli_fetch_array($result, MYSQLI_ASSOC);
        $total_spent = $row["total"];
    }
    mysqli_stmt_close($stmt);
}

mysqli_close($link);

$page_title = "Payment History";
require BASE_PATH . '/frontend/views/member/payments.php';
