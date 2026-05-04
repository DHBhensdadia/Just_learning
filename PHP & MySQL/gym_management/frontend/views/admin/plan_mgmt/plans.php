<?php require BASE_PATH . '/frontend/components/header.php'; ?>
<?php require BASE_PATH . '/frontend/components/admin_nav.php'; ?>

<h2>Plan Management</h2>
<p><a href="<?php echo BASE_URL; ?>/admin/plan_mgmt/add_plan.php">Add New Plan</a></p>

<?php if (count($all_plans) > 0): ?>
    <table>
        <thead>
            <tr>
                <th>ID</th>
                <th>Plan Name</th>
                <th>Duration (Months)</th>
                <th>Price</th>
                <th>Action</th>
            </tr>
        </thead>
        <tbody>
            <?php foreach ($all_plans as $row): ?>
                <tr>
                    <td><?php echo $row["plan_id"]; ?></td>
                    <td><?php echo $row["plan_name"]; ?></td>
                    <td><?php echo $row["duration_months"]; ?></td>
                    <td>₹<?php echo $row["price"]; ?></td>
                    <td>
                        <a href="<?php echo BASE_URL; ?>/admin/plan_mgmt/edit_plan.php?id=<?php echo $row["plan_id"]; ?>">Edit</a>&nbsp;
                        <a href="<?php echo BASE_URL; ?>/admin/plan_mgmt/delete_plan.php?id=<?php echo $row["plan_id"]; ?>">Delete</a>
                    </td>
                </tr>
            <?php endforeach; ?>
        </tbody>
    </table>
<?php else: ?>
    <p><em>No plans found.</em></p>
<?php endif; ?>

<?php require BASE_PATH . '/frontend/components/footer.php'; ?>
