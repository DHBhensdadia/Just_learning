<?php require BASE_PATH . '/frontend/components/header.php'; ?>
<?php require BASE_PATH . '/frontend/components/admin_nav.php'; ?>

<h2>Edit Member</h2>

<form action="<?php echo $_SERVER["PHP_SELF"]; ?>?id=<?php echo $id; ?>" method="post">
    <label>Name</label>
    <input type="text" name="name" value="<?php echo $inputs['name'] ?? $name ?? '' ?>">
    <small><?php echo $errors['name'] ?? '' ?></small>
    <label>Email (cannot change)</label>
    <input type="text" value="<?php echo $email ?? '' ?>" disabled>
    <label>Phone</label>
    <input type="text" name="phone" value="<?php echo $inputs['phone'] ?? $phone ?? '' ?>">
    <label>Role</label>
    <select name="role">
        <option value="member" <?php echo (isset($role) && $role == "member") ? "selected" : ""; ?>>Member</option>
        <option value="admin" <?php echo (isset($role) && $role == "admin") ? "selected" : ""; ?>>Admin</option>
    </select>
    <label>Plan</label>
    <select name="plan_id">
        <option value="">-- No Plan --</option>
        <?php foreach ($plans as $plan): ?>
            <option value="<?php echo $plan["plan_id"]; ?>" <?php echo (isset($current_plan_id) && $plan["plan_id"] == $current_plan_id) ? "selected" : ""; ?>><?php echo $plan["plan_name"]; ?></option>
        <?php endforeach; ?>
    </select>
    <label>New Password (leave blank to keep current)</label>
    <input type="password" name="new_password">
    <input type="hidden" name="id" value="<?php echo $id; ?>"/>
    <input type="submit" value="Update">
    <a href="<?php echo BASE_URL; ?>/admin/member_mgmt/members.php">Cancel</a>
</form>

<?php require BASE_PATH . '/frontend/components/footer.php'; ?>
