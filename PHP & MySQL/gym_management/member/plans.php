<?php
require_once "../config.php";
require_once "../backend/auth_check.php";

// Fetch all available plans into array
$sql = "SELECT * FROM plans";
$result = mysqli_query($link, $sql);
$plans = [];
while ($row = mysqli_fetch_array($result)) {
    $plans[] = $row;
}
mysqli_free_result($result);
mysqli_close($link);

$page_title = "Membership Plans";
require BASE_PATH . '/frontend/views/member/plans.php';
