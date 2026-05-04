<?php require BASE_PATH . '/frontend/components/header.php'; ?>
<?php require BASE_PATH . '/frontend/components/member_nav.php'; ?>

<h2>My Profile</h2>

<?php if (isset($_GET["success"])): ?>
    <p class="success">Profile updated successfully!</p>
<?php endif; ?>

<form action="<?php echo $_SERVER["PHP_SELF"]; ?>" method="post">
    <label>Name</label>
    <input type="text" name="name" value="<?php echo $inputs['name'] ?? $name ?? '' ?>">
    <small><?php echo $errors['name'] ?? '' ?></small>
    <label>Email (cannot change)</label>
    <input type="text" name="email" value="<?php echo $email ?? '' ?>" disabled>
    <label>Phone</label>
    <input type="text" name="phone" value="<?php echo $inputs['phone'] ?? $phone ?? '' ?>">
    <label>New Password (leave blank to keep current)</label>
    <input type="password" name="new_password">
    <input type="submit" value="Update Profile">
</form>

<p><a href="<?php echo BASE_URL; ?>/member/dashboard.php">Back to Dashboard</a></p>

<?php require BASE_PATH . '/frontend/components/footer.php'; ?>
