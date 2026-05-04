<?php require BASE_PATH . '/frontend/components/header.php'; ?>
<?php require BASE_PATH . '/frontend/components/admin_nav.php'; ?>

<h2>Edit Plan</h2>

<form action="<?php echo $_SERVER["PHP_SELF"]; ?>?id=<?php echo $id; ?>" method="post">
    <label>Plan Name</label>
    <input type="text" name="plan_name" value="<?php echo $inputs['plan_name'] ?? $plan_name ?? '' ?>">
    <small><?php echo $errors['plan_name'] ?? '' ?></small>
    <label>Duration (Months)</label>
    <input type="number" name="duration_months" value="<?php echo $inputs['duration_months'] ?? $duration_months ?? '' ?>">
    <small><?php echo $errors['duration_months'] ?? '' ?></small>
    <label>Price</label>
    <input type="text" name="price" value="<?php echo $inputs['price'] ?? $price ?? '' ?>">
    <small><?php echo $errors['price'] ?? '' ?></small>
    <input type="hidden" name="id" value="<?php echo $id; ?>"/>
    <input type="submit" value="Update">
    <a href="<?php echo BASE_URL; ?>/admin/plan_mgmt/plans.php">Cancel</a>
</form>

<?php require BASE_PATH . '/frontend/components/footer.php'; ?>
