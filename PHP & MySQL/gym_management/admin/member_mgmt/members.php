<?php
require_once "../../config.php";
require_once "../../backend/admin_auth_check.php";

// Fetch all members with plan names into array
$sql = "SELECT m.*, p.plan_name FROM members m LEFT JOIN plans p ON m.plan_id = p.plan_id ORDER BY m.member_id";
$result = mysqli_query($link, $sql);
$members = [];
while ($row = mysqli_fetch_array($result)) {
    $members[] = $row;
}
mysqli_free_result($result);
mysqli_close($link);

$page_title = "Member Management";
require BASE_PATH . '/frontend/views/admin/member_mgmt/members.php';
