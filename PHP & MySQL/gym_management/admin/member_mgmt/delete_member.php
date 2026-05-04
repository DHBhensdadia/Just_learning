<?php
require_once "../../config.php";
require_once "../../backend/admin_auth_check.php";

// Process delete operation after confirmation
if (isset($_POST["id"]) && !empty($_POST["id"])) {

    // First delete related payments
    $sql = "DELETE FROM payments WHERE member_id = ?";
    if ($stmt = mysqli_prepare($link, $sql)) {
        mysqli_stmt_bind_param($stmt, "i", $param_id);
        $param_id = trim($_POST["id"]);
        mysqli_stmt_execute($stmt);
        mysqli_stmt_close($stmt);
    }

    // Now delete the member
    $sql = "DELETE FROM members WHERE member_id = ?";
    if ($stmt = mysqli_prepare($link, $sql)) {
        mysqli_stmt_bind_param($stmt, "i", $param_id);
        $param_id = trim($_POST["id"]);

        if (mysqli_stmt_execute($stmt)) {
            mysqli_stmt_close($stmt);
            mysqli_close($link);
            header("location: members.php");
            exit();
        } else {
            echo "Oops! Something went wrong. Please try again later.";
        }
    }
    mysqli_stmt_close($stmt);
    mysqli_close($link);
} else {
    if (!isset($_GET["id"]) || empty(trim($_GET["id"]))) {
        header("location: members.php");
        exit();
    }
    $id = trim($_GET["id"]);
}

$page_title = "Delete Member";
require BASE_PATH . '/frontend/views/admin/member_mgmt/delete_member.php';
