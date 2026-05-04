<?php require BASE_PATH . '/frontend/components/header.php'; ?>
<?php require BASE_PATH . '/frontend/components/admin_nav.php'; ?>

<h2>Payment Management</h2>
<p><a href="<?php echo BASE_URL; ?>/admin/payment_mgmt/add_payment.php">Record New Payment</a></p>

<?php if (count($payments) > 0): ?>
    <table>
        <thead>
            <tr>
                <th>Payment ID</th>
                <th>Member Name</th>
                <th>Plan</th>
                <th>Amount</th>
                <th>Date</th>
            </tr>
        </thead>
        <tbody>
            <?php foreach ($payments as $row): ?>
                <tr>
                    <td><?php echo $row["payment_id"]; ?></td>
                    <td><?php echo $row["member_name"]; ?></td>
                    <td><?php echo $row["plan_name"]; ?></td>
                    <td>₹<?php echo $row["amount"]; ?></td>
                    <td><?php echo $row["payment_date"]; ?></td>
                </tr>
            <?php endforeach; ?>
        </tbody>
    </table>
<?php else: ?>
    <p><em>No payment records found.</em></p>
<?php endif; ?>

<?php require BASE_PATH . '/frontend/components/footer.php'; ?>
