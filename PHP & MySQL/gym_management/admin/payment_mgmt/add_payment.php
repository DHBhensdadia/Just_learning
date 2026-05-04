<?php
require_once "../../config.php";
require_once "../../backend/admin_auth_check.php";

const MEMBER_REQUIRED = 'Please select a member';
const PLAN_REQUIRED = 'Please select a plan';
const AMOUNT_REQUIRED = 'Please enter amount';
const DATE_REQUIRED = 'Please enter payment date';

$errors = [];
$inputs = [];

// Processing form data when form is submitted
if ($_SERVER["REQUEST_METHOD"] == "POST") {

    // validate member selection
    $member_id = filter_input(INPUT_POST, 'member_id', FILTER_SANITIZE_NUMBER_INT);
    $inputs['member_id'] = $member_id;
    if (!$member_id || trim($member_id) === '') {
        $errors['member_id'] = MEMBER_REQUIRED;
    }

    // validate plan selection
    $plan_id = filter_input(INPUT_POST, 'plan_id', FILTER_SANITIZE_NUMBER_INT);
    $inputs['plan_id'] = $plan_id;
    if (!$plan_id || trim($plan_id) === '') {
        $errors['plan_id'] = PLAN_REQUIRED;
    }

    // sanitize and validate amount
    $amount = filter_input(INPUT_POST, 'amount', FILTER_SANITIZE_SPECIAL_CHARS);
    $inputs['amount'] = $amount;
    if ($amount) {
        $amount = trim($amount);
        if ($amount === '') {
            $errors['amount'] = AMOUNT_REQUIRED;
        }
    } else {
        $errors['amount'] = AMOUNT_REQUIRED;
    }

    // validate date
    $payment_date = filter_input(INPUT_POST, 'payment_date', FILTER_SANITIZE_SPECIAL_CHARS);
    $inputs['payment_date'] = $payment_date;
    if (!$payment_date || trim($payment_date) === '') {
        $errors['payment_date'] = DATE_REQUIRED;
    }

    // Only proceed to DB if no errors
    if (count($errors) === 0) {

        // Insert payment record
        $sql = "INSERT INTO payments (member_id, plan_id, amount, payment_date) VALUES (?, ?, ?, ?)";

        if ($stmt = mysqli_prepare($link, $sql)) {
            mysqli_stmt_bind_param($stmt, "iids", $param_member_id, $param_plan_id, $param_amount, $param_payment_date);
            $param_member_id = $member_id;
            $param_plan_id = $plan_id;
            $param_amount = $amount;
            $param_payment_date = $payment_date;

            if (mysqli_stmt_execute($stmt)) {
                mysqli_stmt_close($stmt);

                // Also update the member's current plan
                $sql = "UPDATE members SET plan_id = ? WHERE member_id = ?";
                if ($stmt2 = mysqli_prepare($link, $sql)) {
                    mysqli_stmt_bind_param($stmt2, "ii", $param_plan_id, $param_member_id);
                    $param_plan_id = $plan_id;
                    $param_member_id = $member_id;
                    mysqli_stmt_execute($stmt2);
                    mysqli_stmt_close($stmt2);
                }

                mysqli_close($link);
                header("location: payments.php");
                exit();
            } else {
                echo "Something went wrong. Please try again later.";
            }
        }
        mysqli_stmt_close($stmt);
    }
}

// Fetch members for dropdown
$members = [];
$sql = "SELECT member_id, name, email FROM members WHERE role = 'member' ORDER BY name";
$result = mysqli_query($link, $sql);
while ($row = mysqli_fetch_array($result)) {
    $members[] = $row;
}
mysqli_free_result($result);

// Fetch plans for dropdown
$plans = [];
$sql = "SELECT * FROM plans ORDER BY plan_name";
$result = mysqli_query($link, $sql);
while ($row = mysqli_fetch_array($result)) {
    $plans[] = $row;
}
mysqli_free_result($result);
mysqli_close($link);

$page_title = "Record Payment";
require BASE_PATH . '/frontend/views/admin/payment_mgmt/add_payment.php';
