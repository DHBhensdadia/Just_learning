<?php
session_start();
require_once "../config.php";

// Processing form data when form is submitted
if ($_SERVER["REQUEST_METHOD"] == "POST") {

    // sanitize & validate email
    $email = filter_input(INPUT_POST, 'email', FILTER_SANITIZE_EMAIL);
    if ($email) {
        $email = filter_var($email, FILTER_VALIDATE_EMAIL);
        if ($email === false) {
            header("location: ../index.php?error=1");
            exit();
        }
    } else {
        header("location: ../index.php?error=1");
        exit();
    }

    // sanitize password
    $password = filter_input(INPUT_POST, 'password', FILTER_DEFAULT);
    if (!$password || trim($password) === '') {
        header("location: ../index.php?error=1");
        exit();
    }
    $password = trim($password);

    $login_type = $_POST["login_type"];

    // Prepare a select statement
    $sql = "SELECT * FROM members WHERE email = ? AND role = ?";

    if ($stmt = mysqli_prepare($link, $sql)) {
        // Bind variables to the prepared statement as parameters
        mysqli_stmt_bind_param($stmt, "ss", $param_email, $param_role);

        // Set parameters
        $param_email = $email;
        $param_role = $login_type;

        // Attempt to execute the prepared statement
        if (mysqli_stmt_execute($stmt)) {
            $result = mysqli_stmt_get_result($stmt);

            if (mysqli_num_rows($result) == 1) {
                $row = mysqli_fetch_array($result, MYSQLI_ASSOC);

                // Verify password
                if (password_verify($password, $row["password"])) {
                    // Password is correct, start a new session
                    $_SESSION["member_id"] = $row["member_id"];
                    $_SESSION["name"] = $row["name"];
                    $_SESSION["email"] = $row["email"];
                    $_SESSION["role"] = $row["role"];

                    // Redirect based on role
                    if ($row["role"] == "admin") {
                        header("location: ../admin/dashboard.php");
                        exit();
                    } else {
                        header("location: ../member/dashboard.php");
                        exit();
                    }
                } else {
                    // Wrong password
                    header("location: ../index.php?error=1");
                    exit();
                }
            } else {
                // No account found
                header("location: ../index.php?error=1");
                exit();
            }
        } else {
            echo "Oops! Something went wrong. Please try again later.";
        }

        // Close statement
        mysqli_stmt_close($stmt);
    }

    // Close connection
    mysqli_close($link);
} else {
    // Not a POST request, redirect to login
    header("location: ../index.php");
    exit();
}
