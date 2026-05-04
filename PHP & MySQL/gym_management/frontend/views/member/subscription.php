<?php require BASE_PATH . '/frontend/components/header.php'; ?>
<?php require BASE_PATH . '/frontend/components/member_nav.php'; ?>

<h2>My Subscription</h2>

<?php if (!empty($plan_name) && !empty($valid_until)): ?>
    <table>
        <tr><th>Plan Name</th><td><?php echo $plan_name; ?></td></tr>
        <tr><th>Duration</th><td><?php echo $duration_months; ?> months</td></tr>
        <tr><th>Price</th><td>₹<?php echo $price; ?></td></tr>
        <tr><th>Join Date</th><td><?php echo $join_date; ?></td></tr>
        <tr><th>Last Payment</th><td><?php echo $last_payment_date; ?></td></tr>
        <tr><th>Valid Until</th><td><?php echo $valid_until; ?></td></tr>
    </table>
<?php else: ?>
    <p><em>No active subscription. Please contact the admin.</em></p>
<?php endif; ?>

<p><a href="<?php echo BASE_URL; ?>/member/dashboard.php">Back to Dashboard</a></p>

<?php require BASE_PATH . '/frontend/components/footer.php'; ?>
