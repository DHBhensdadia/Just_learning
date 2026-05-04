<?php
require_once "../../config.php";
require_once "../../backend/admin_auth_check.php";

// Process delete operation after confirmation
if (isset($_POST["id"]) && !empty($_POST["id"])) {

    // Check if any members are using this plan
    $sql = "SELECT COUNT(*) AS count FROM members WHERE plan_id = ?";
    if ($stmt = mysqli_prepare($link, $sql)) {
        mysqli_stmt_bind_param($stmt, "i", $param_id);
        $param_id = trim($_POST["id"]);
        mysqli_stmt_execute($stmt);
        $result = mysqli_stmt_get_result($stmt);
        $row = mysqli_fetch_array($result);
        $member_count = $row["count"];
        mysqli_stmt_close($stmt);
    }

    if ($member_count > 0) {
        $error = "Cannot delete this plan. $member_count member(s) are currently using it.";
        $id = trim($_POST["id"]);
    } else {
        $sql = "DELETE FROM plans WHERE plan_id = ?";
        if ($stmt = mysqli_prepare($link, $sql)) {
            mysqli_stmt_bind_param($stmt, "i", $param_id);
            $param_id = trim($_POST["id"]);

            if (mysqli_stmt_execute($stmt)) {
                mysqli_stmt_close($stmt);
                mysqli_close($link);
                header("location: plans.php");
                exit();
            } else {
                echo "Oops! Something went wrong. Please try again later.";
            }
        }
        mysqli_stmt_close($stmt);
    }
    mysqli_close($link);
} else {
    if (!isset($_GET["id"]) || empty(trim($_GET["id"]))) {
        header("location: plans.php");
        exit();
    }
    $id = trim($_GET["id"]);
}

$page_title = "Delete Plan";
require BASE_PATH . '/frontend/views/admin/plan_mgmt/delete_plan.php';
