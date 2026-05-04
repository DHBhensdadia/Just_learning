<?php require BASE_PATH . '/frontend/components/header.php'; ?>
<?php require BASE_PATH . '/frontend/components/member_nav.php'; ?>

<h2>Available Membership Plans</h2>

<?php if (count($plans) > 0): ?>
    <table>
        <thead>
            <tr>
                <th>Plan Name</th>
                <th>Duration (Months)</th>
                <th>Price</th>
            </tr>
        </thead>
        <tbody>
            <?php foreach ($plans as $row): ?>
                <tr>
                    <td><?php echo $row["plan_name"]; ?></td>
                    <td><?php echo $row["duration_months"]; ?></td>
                    <td>₹<?php echo $row["price"]; ?></td>
                </tr>
            <?php endforeach; ?>
        </tbody>
    </table>
<?php else: ?>
    <p><em>No plans available at the moment.</em></p>
<?php endif; ?>

<p><a href="<?php echo BASE_URL; ?>/member/dashboard.php">Back to Dashboard</a></p>

<?php require BASE_PATH . '/frontend/components/footer.php'; ?>
