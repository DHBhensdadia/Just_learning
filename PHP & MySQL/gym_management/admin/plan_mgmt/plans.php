<?php
require_once "../../config.php";
require_once "../../backend/admin_auth_check.php";

// Fetch all plans into array
$sql = "SELECT * FROM plans ORDER BY plan_id";
$result = mysqli_query($link, $sql);
$all_plans = [];
while ($row = mysqli_fetch_array($result)) {
    $all_plans[] = $row;
}
mysqli_free_result($result);
mysqli_close($link);

$page_title = "Plan Management";
require BASE_PATH . '/frontend/views/admin/plan_mgmt/plans.php';
