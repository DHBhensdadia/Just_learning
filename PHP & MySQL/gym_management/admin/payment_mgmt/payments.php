<?php
require_once "../../config.php";
require_once "../../backend/admin_auth_check.php";

// Fetch all payments with member names and plan names
$sql = "SELECT py.*, m.name AS member_name, p.plan_name FROM payments py JOIN members m ON py.member_id = m.member_id JOIN plans p ON py.plan_id = p.plan_id ORDER BY py.payment_date DESC";
$result = mysqli_query($link, $sql);
$payments = [];
while ($row = mysqli_fetch_array($result)) {
    $payments[] = $row;
}
mysqli_free_result($result);
mysqli_close($link);

$page_title = "Payment Management";
require BASE_PATH . '/frontend/views/admin/payment_mgmt/payments.php';
