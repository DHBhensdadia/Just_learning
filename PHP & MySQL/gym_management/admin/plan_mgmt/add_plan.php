<?php
require_once "../../config.php";
require_once "../../backend/admin_auth_check.php";

const PLAN_NAME_REQUIRED = 'Please enter plan name';
const DURATION_REQUIRED = 'Please enter duration';
const PRICE_REQUIRED = 'Please enter price';

$errors = [];
$inputs = [];

// Processing form data when form is submitted
if ($_SERVER["REQUEST_METHOD"] == "POST") {

    // sanitize and validate plan name
    $plan_name = filter_input(INPUT_POST, 'plan_name', FILTER_SANITIZE_SPECIAL_CHARS);
    $inputs['plan_name'] = $plan_name;
    if ($plan_name) {
        $plan_name = trim($plan_name);
        if ($plan_name === '') {
            $errors['plan_name'] = PLAN_NAME_REQUIRED;
        }
    } else {
        $errors['plan_name'] = PLAN_NAME_REQUIRED;
    }

    // sanitize and validate duration
    $duration_months = filter_input(INPUT_POST, 'duration_months', FILTER_SANITIZE_NUMBER_INT);
    $inputs['duration_months'] = $duration_months;
    if (!$duration_months || trim($duration_months) === '') {
        $errors['duration_months'] = DURATION_REQUIRED;
    }

    // sanitize and validate price
    $price = filter_input(INPUT_POST, 'price', FILTER_SANITIZE_SPECIAL_CHARS);
    $inputs['price'] = $price;
    if (!$price || trim($price) === '') {
        $errors['price'] = PRICE_REQUIRED;
    }

    // Only proceed to DB if no errors
    if (count($errors) === 0) {
        $sql = "INSERT INTO plans (plan_name, duration_months, price) VALUES (?, ?, ?)";

        if ($stmt = mysqli_prepare($link, $sql)) {
            mysqli_stmt_bind_param($stmt, "sid", $param_plan_name, $param_duration, $param_price);
            $param_plan_name = $plan_name;
            $param_duration = $duration_months;
            $param_price = $price;

            if (mysqli_stmt_execute($stmt)) {
                mysqli_stmt_close($stmt);
                mysqli_close($link);
                header("location: plans.php");
                exit();
            } else {
                echo "Something went wrong. Please try again later.";
            }
        }
        mysqli_stmt_close($stmt);
    }
    mysqli_close($link);
}

$page_title = "Add Plan";
require BASE_PATH . '/frontend/views/admin/plan_mgmt/add_plan.php';
