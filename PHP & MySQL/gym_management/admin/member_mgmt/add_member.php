<?php
require_once "../../config.php";
require_once "../../backend/admin_auth_check.php";

const NAME_REQUIRED = 'Please enter member name';
const EMAIL_REQUIRED = 'Please enter email';
const EMAIL_INVALID = 'Please enter a valid email';
const PASSWORD_REQUIRED = 'Please enter password';

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

    // sanitize & validate email
    $email = filter_input(INPUT_POST, 'email', FILTER_SANITIZE_EMAIL);
    $inputs['email'] = $email;
    if ($email) {
        $email = filter_var($email, FILTER_VALIDATE_EMAIL);
        if ($email === false) {
            $errors['email'] = EMAIL_INVALID;
        }
    } else {
        $errors['email'] = EMAIL_REQUIRED;
    }

    // validate password
    $input_password = filter_input(INPUT_POST, 'password', FILTER_DEFAULT);
    if ($input_password) {
        $input_password = trim($input_password);
        if ($input_password === '') {
            $errors['password'] = PASSWORD_REQUIRED;
        }
    } else {
        $errors['password'] = PASSWORD_REQUIRED;
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
    $join_date = $_POST["join_date"];

    // Only proceed to DB if no errors
    if (count($errors) === 0) {
        $hashed_password = password_hash($input_password, PASSWORD_DEFAULT);

        // Prepare an insert statement
        $sql = "INSERT INTO members (name, email, password, phone, role, join_date, plan_id) VALUES (?, ?, ?, ?, ?, ?, ?)";

        if ($stmt = mysqli_prepare($link, $sql)) {
            mysqli_stmt_bind_param($stmt, "ssssssi", $param_name, $param_email, $param_password, $param_phone, $param_role, $param_join_date, $param_plan_id);

            $param_name = $name;
            $param_email = $email;
            $param_password = $hashed_password;
            $param_phone = $phone;
            $param_role = $role;
            $param_join_date = $join_date;
            $param_plan_id = $plan_id;

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

// Fetch plans for dropdown (GET or failed POST)
$plans = [];
$sql = "SELECT * FROM plans";
$result = mysqli_query($link, $sql);
while ($row = mysqli_fetch_array($result)) {
    $plans[] = $row;
}
mysqli_free_result($result);
mysqli_close($link);

$page_title = "Add Member";
require BASE_PATH . '/frontend/views/admin/member_mgmt/add_member.php';
