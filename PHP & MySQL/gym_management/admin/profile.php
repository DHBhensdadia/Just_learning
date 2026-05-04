<?php
require_once "../config.php";
require_once "../backend/admin_auth_check.php";

const NAME_REQUIRED = 'Please enter your name';

$errors = [];
$inputs = [];

// Processing form data when form is submitted
if ($_SERVER["REQUEST_METHOD"] == "POST") {

    // sanitize and validate name
    $name = filter_input(INPUT_POST, 'name', FILTER_SANITIZE_SPECIAL_CHARS);
    $inputs['name'] = $name;
    if ($name) {
        $name = trim($name);
        if ($name === '') {
            $errors['name'] = NAME_REQUIRED;
        }
    } else {
        $errors['name'] = NAME_REQUIRED;
    }

    // sanitize phone
    $phone = filter_input(INPUT_POST, 'phone', FILTER_SANITIZE_SPECIAL_CHARS);
    $inputs['phone'] = $phone;
    if ($phone) {
        $phone = trim($phone);
    } else {
        $phone = '';
    }

    $new_password = trim($_POST["new_password"]);

    // Only proceed to DB if no errors
    if (count($errors) === 0) {

        if (!empty($new_password)) {
            $hashed_password = password_hash($new_password, PASSWORD_DEFAULT);
            $sql = "UPDATE members SET name=?, phone=?, password=? WHERE member_id=?";

            if ($stmt = mysqli_prepare($link, $sql)) {
                mysqli_stmt_bind_param($stmt, "sssi", $param_name, $param_phone, $param_password, $param_id);
                $param_name = $name;
                $param_phone = $phone;
                $param_password = $hashed_password;
                $param_id = $_SESSION["member_id"];

                if (mysqli_stmt_execute($stmt)) {
                    $_SESSION["name"] = $name;
                    mysqli_stmt_close($stmt);
                    mysqli_close($link);
                    header("location: profile.php?success=1");
                    exit();
                } else {
                    echo "Something went wrong. Please try again later.";
                }
            }
            mysqli_stmt_close($stmt);
        } else {
            $sql = "UPDATE members SET name=?, phone=? WHERE member_id=?";

            if ($stmt = mysqli_prepare($link, $sql)) {
                mysqli_stmt_bind_param($stmt, "ssi", $param_name, $param_phone, $param_id);
                $param_name = $name;
                $param_phone = $phone;
                $param_id = $_SESSION["member_id"];

                if (mysqli_stmt_execute($stmt)) {
                    $_SESSION["name"] = $name;
                    mysqli_stmt_close($stmt);
                    mysqli_close($link);
                    header("location: profile.php?success=1");
                    exit();
                } else {
                    echo "Something went wrong. Please try again later.";
                }
            }
            mysqli_stmt_close($stmt);
        }
    }
}

// Fetch current admin data (GET or failed POST)
$sql = "SELECT * FROM members WHERE member_id = ?";
if ($stmt = mysqli_prepare($link, $sql)) {
    mysqli_stmt_bind_param($stmt, "i", $param_id);
    $param_id = $_SESSION["member_id"];

    if (mysqli_stmt_execute($stmt)) {
        $result = mysqli_stmt_get_result($stmt);
        if (mysqli_num_rows($result) == 1) {
            $row = mysqli_fetch_array($result, MYSQLI_ASSOC);
            if (count($errors) === 0) {
                $name = $row["name"];
                $phone = $row["phone"];
            }
            $email = $row["email"];
        }
    }
    mysqli_stmt_close($stmt);
}
mysqli_close($link);

$page_title = "Admin Profile";
require BASE_PATH . '/frontend/views/admin/profile.php';
