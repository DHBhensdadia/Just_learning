<?php
require_once "../../config.php";
require_once "../../backend/admin_auth_check.php";

const NAME_REQUIRED = 'Please enter member name';

$errors = [];
$inputs = [];

// Processing form data when form is submitted
if (isset($_POST["id"]) && !empty($_POST["id"])) {
    $id = $_POST["id"];

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

    $role = $_POST["role"];
    $plan_id = !empty($_POST["plan_id"]) ? $_POST["plan_id"] : NULL;
    $current_plan_id = $plan_id;

    $new_password = trim($_POST["new_password"]);

    // Only proceed to DB if no errors
    if (count($errors) === 0) {

        if (!empty($new_password)) {
            $hashed_password = password_hash($new_password, PASSWORD_DEFAULT);
            $sql = "UPDATE members SET name=?, phone=?, role=?, plan_id=?, password=? WHERE member_id=?";

            if ($stmt = mysqli_prepare($link, $sql)) {
                mysqli_stmt_bind_param($stmt, "sssisi", $param_name, $param_phone, $param_role, $param_plan_id, $param_password, $param_id);
                $param_name = $name;
                $param_phone = $phone;
                $param_role = $role;
                $param_plan_id = $plan_id;
                $param_password = $hashed_password;
                $param_id = $id;

                if (mysqli_stmt_execute($stmt)) {
                    mysqli_stmt_close($stmt);
                    mysqli_close($link);
                    header("location: members.php");
                    exit();
                } else {
                    echo "Something went wrong. Please try again later.";
                }
            }
            mysqli_stmt_close($stmt);
        } else {
            $sql = "UPDATE members SET name=?, phone=?, role=?, plan_id=? WHERE member_id=?";

            if ($stmt = mysqli_prepare($link, $sql)) {
                mysqli_stmt_bind_param($stmt, "sssii", $param_name, $param_phone, $param_role, $param_plan_id, $param_id);
                $param_name = $name;
                $param_phone = $phone;
                $param_role = $role;
                $param_plan_id = $plan_id;
                $param_id = $id;

                if (mysqli_stmt_execute($stmt)) {
                    mysqli_stmt_close($stmt);
                    mysqli_close($link);
                    header("location: members.php");
                    exit();
                } else {
                    echo "Something went wrong. Please try again later.";
                }
            }
            mysqli_stmt_close($stmt);
        }
    }

    // Need email for the view on failed validation
    $sql = "SELECT email FROM members WHERE member_id = ?";
    if ($stmt = mysqli_prepare($link, $sql)) {
        mysqli_stmt_bind_param($stmt, "i", $param_id);
        $param_id = $id;
        if (mysqli_stmt_execute($stmt)) {
            $result = mysqli_stmt_get_result($stmt);
            if (mysqli_num_rows($result) == 1) {
                $row = mysqli_fetch_array($result, MYSQLI_ASSOC);
                $email = $row["email"];
            }
        }
        mysqli_stmt_close($stmt);
    }

} else {
    // Fetch member data for editing
    if (isset($_GET["id"]) && !empty(trim($_GET["id"]))) {
        $id = trim($_GET["id"]);

        $sql = "SELECT * FROM members WHERE member_id = ?";
        if ($stmt = mysqli_prepare($link, $sql)) {
            mysqli_stmt_bind_param($stmt, "i", $param_id);
            $param_id = $id;

            if (mysqli_stmt_execute($stmt)) {
                $result = mysqli_stmt_get_result($stmt);
                if (mysqli_num_rows($result) == 1) {
                    $row = mysqli_fetch_array($result, MYSQLI_ASSOC);
                    $name = $row["name"];
                    $email = $row["email"];
                    $phone = $row["phone"];
                    $role = $row["role"];
                    $current_plan_id = $row["plan_id"];
                } else {
                    header("location: members.php");
                    exit();
                }
            }
        }
        mysqli_stmt_close($stmt);
    } else {
        header("location: members.php");
        exit();
    }
}

// Fetch plans for dropdown
$plans = [];
$sql = "SELECT * FROM plans";
$result = mysqli_query($link, $sql);
while ($row = mysqli_fetch_array($result)) {
    $plans[] = $row;
}
mysqli_free_result($result);
mysqli_close($link);

$page_title = "Edit Member";
require BASE_PATH . '/frontend/views/admin/member_mgmt/edit_member.php';
