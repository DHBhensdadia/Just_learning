<?php require BASE_PATH . '/frontend/components/header.php'; ?>
<?php require BASE_PATH . '/frontend/components/admin_nav.php'; ?>

<h2>Add New Member</h2>

<form action="<?php echo $_SERVER["PHP_SELF"]; ?>" method="post">
    <label>Name</label>
    <input type="text" name="name" value="<?php echo $inputs['name'] ?? '' ?>">
    <small><?php echo $errors['name'] ?? '' ?></small>
    <label>Email</label>
    <input type="text" name="email" value="<?php echo $inputs['email'] ?? '' ?>">
    <small><?php echo $errors['email'] ?? '' ?></small>
    <label>Password</label>
    <input type="password" name="password">
    <small><?php echo $errors['password'] ?? '' ?></small>
    <label>Phone</label>
    <input type="text" name="phone" value="<?php echo $inputs['phone'] ?? '' ?>">
    <label>Role</label>
    <select name="role">
        <option value="member">Member</option>
        <option value="admin">Admin</option>
    </select>
    <label>Plan</label>
    <select name="plan_id">
        <option value="">-- No Plan --</option>
        <?php foreach ($plans as $plan): ?>
            <option value="<?php echo $plan["plan_id"]; ?>"><?php echo $plan["plan_name"]; ?> (₹<?php echo $plan["price"]; ?>)</option>
        <?php endforeach; ?>
    </select>
    <label>Join Date</label>
    <input type="date" name="join_date" value="<?php echo date('Y-m-d'); ?>" required>
    <input type="submit" value="Add Member">
    <a href="<?php echo BASE_URL; ?>/admin/member_mgmt/members.php">Cancel</a>
</form>

<?php require BASE_PATH . '/frontend/components/footer.php'; ?>
