<?php require BASE_PATH . '/frontend/components/header.php'; ?>
<?php require BASE_PATH . '/frontend/components/admin_nav.php'; ?>

<h1>Delete Member</h1>

<?php if (isset($error)): ?>
    <p class="error"><?php echo $error; ?></p>
    <p><a href="<?php echo BASE_URL; ?>/admin/member_mgmt/members.php">Back to Members</a></p>
<?php else: ?>
    <form action="<?php echo $_SERVER["PHP_SELF"]; ?>" method="post">
        <input type="hidden" name="id" value="<?php echo $id; ?>"/>
        <p>Are you sure you want to delete this member?</p>
        <p>This will also delete all their payment records.</p><br/>
        <p>
            <input type="submit" value="Yes, Delete">
            <a href="<?php echo BASE_URL; ?>/admin/member_mgmt/members.php">No, Cancel</a>
        </p>
    </form>
<?php endif; ?>

<?php require BASE_PATH . '/frontend/components/footer.php'; ?>
