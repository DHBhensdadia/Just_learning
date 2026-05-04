<?php require BASE_PATH . '/frontend/components/header.php'; ?>
<?php require BASE_PATH . '/frontend/components/admin_nav.php'; ?>

<h2>Member Management</h2>
<p><a href="<?php echo BASE_URL; ?>/admin/member_mgmt/add_member.php">Add New Member</a></p>

<?php if (count($members) > 0): ?>
    <table>
        <thead>
            <tr>
                <th>ID</th>
                <th>Name</th>
                <th>Email</th>
                <th>Phone</th>
                <th>Role</th>
                <th>Plan</th>
                <th>Join Date</th>
                <th>Action</th>
            </tr>
        </thead>
        <tbody>
            <?php foreach ($members as $row): ?>
                <tr>
                    <td><?php echo $row["member_id"]; ?></td>
                    <td><?php echo $row["name"]; ?></td>
                    <td><?php echo $row["email"]; ?></td>
                    <td><?php echo $row["phone"]; ?></td>
                    <td><?php echo $row["role"]; ?></td>
                    <td><?php echo $row["plan_name"] ? $row["plan_name"] : "N/A"; ?></td>
                    <td><?php echo $row["join_date"]; ?></td>
                    <td>
                        <a href="<?php echo BASE_URL; ?>/admin/member_mgmt/edit_member.php?id=<?php echo $row["member_id"]; ?>">Edit</a>&nbsp;
                        <a href="<?php echo BASE_URL; ?>/admin/member_mgmt/delete_member.php?id=<?php echo $row["member_id"]; ?>">Delete</a>
                    </td>
                </tr>
            <?php endforeach; ?>
        </tbody>
    </table>
<?php else: ?>
    <p><em>No members found.</em></p>
<?php endif; ?>

<?php require BASE_PATH . '/frontend/components/footer.php'; ?>
