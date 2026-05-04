<?php require BASE_PATH . '/frontend/components/header.php'; ?>
<?php require BASE_PATH . '/frontend/components/member_nav.php'; ?>

<h2>Payment History</h2>

<?php if (count($payments) > 0): ?>
    <table>
        <thead>
            <tr>
                <th>Payment ID</th>
                <th>Plan Name</th>
                <th>Amount</th>
                <th>Date</th>
            </tr>
        </thead>
        <tbody>
            <?php foreach ($payments as $payment): ?>
                <tr>
                    <td><?php echo $payment["payment_id"]; ?></td>
                    <td><?php echo $payment["plan_name"]; ?></td>
                    <td>₹<?php echo $payment["amount"]; ?></td>
                    <td><?php echo $payment["payment_date"]; ?></td>
                </tr>
            <?php endforeach; ?>
        </tbody>
    </table>
    <p><strong>Total Amount Spent: ₹<?php echo $total_spent; ?></strong></p>
<?php else: ?>
    <p><em>No payment records found.</em></p>
<?php endif; ?>

<p><a href="<?php echo BASE_URL; ?>/member/dashboard.php">Back to Dashboard</a></p>

<?php require BASE_PATH . '/frontend/components/footer.php'; ?>
