<?php require BASE_PATH . '/frontend/components/header.php'; ?>
<?php require BASE_PATH . '/frontend/components/admin_nav.php'; ?>

<h2>Record New Payment</h2>

<form action="<?php echo $_SERVER["PHP_SELF"]; ?>" method="post">
    <label>Member</label>
    <select name="member_id">
        <option value="">-- Select Member --</option>
        <?php foreach ($members as $member): ?>
            <option value="<?php echo $member["member_id"]; ?>" <?php echo (isset($inputs['member_id']) && $inputs['member_id'] == $member["member_id"]) ? "selected" : ""; ?>><?php echo $member["name"]; ?> (<?php echo $member["email"]; ?>)</option>
        <?php endforeach; ?>
    </select>
    <small><?php echo $errors['member_id'] ?? '' ?></small>
    <label>Plan</label>
    <select name="plan_id">
        <option value="">-- Select Plan --</option>
        <?php foreach ($plans as $plan): ?>
            <option value="<?php echo $plan["plan_id"]; ?>" <?php echo (isset($inputs['plan_id']) && $inputs['plan_id'] == $plan["plan_id"]) ? "selected" : ""; ?>><?php echo $plan["plan_name"]; ?> (₹<?php echo $plan["price"]; ?>)</option>
        <?php endforeach; ?>
    </select>
    <small><?php echo $errors['plan_id'] ?? '' ?></small>
    <label>Amount (₹)</label>
    <input type="text" name="amount" value="<?php echo $inputs['amount'] ?? '' ?>">
    <small><?php echo $errors['amount'] ?? '' ?></small>
    <label>Payment Date</label>
    <input type="date" name="payment_date" value="<?php echo $inputs['payment_date'] ?? date('Y-m-d') ?>">
    <small><?php echo $errors['payment_date'] ?? '' ?></small>
    <input type="submit" value="Record Payment">
    <a href="<?php echo BASE_URL; ?>/admin/payment_mgmt/payments.php">Cancel</a>
</form>

<?php require BASE_PATH . '/frontend/components/footer.php'; ?>
