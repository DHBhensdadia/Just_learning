<?php require BASE_PATH . '/frontend/components/header.php'; ?>
<?php require BASE_PATH . '/frontend/components/admin_nav.php'; ?>

<h1>Delete Plan</h1>

<?php if (isset($error)): ?>
    <p class="error"><?php echo $error; ?></p>
    <p><a href="<?php echo BASE_URL; ?>/admin/plan_mgmt/plans.php">Back to Plans</a></p>
<?php else: ?>
    <form action="<?php echo $_SERVER["PHP_SELF"]; ?>" method="post">
        <input type="hidden" name="id" value="<?php echo $id; ?>"/>
        <p>Are you sure you want to delete this plan?</p><br/>
        <p>
            <input type="submit" value="Yes, Delete">
            <a href="<?php echo BASE_URL; ?>/admin/plan_mgmt/plans.php">No, Cancel</a>
        </p>
    </form>
<?php endif; ?>

<?php require BASE_PATH . '/frontend/components/footer.php'; ?>
