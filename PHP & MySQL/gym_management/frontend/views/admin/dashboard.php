<?php require BASE_PATH . '/frontend/components/header.php'; ?>
<?php require BASE_PATH . '/frontend/components/admin_nav.php'; ?>

<h1>Dashboard</h1>
<p>Welcome, <?php echo $_SESSION["name"]; ?></p>

<div class="stats">
    <div class="stat-card">
        <h3>Total Members</h3>
        <p><?php echo $total_members; ?></p>
    </div>
    <div class="stat-card">
        <h3>All-Time Revenue</h3>
        <p>&#8377;<?php echo $all_time_revenue; ?></p>
    </div>
    <div class="stat-card">
        <h3>This Month's Revenue</h3>
        <p>&#8377;<?php echo $this_month_revenue; ?></p>
    </div>
    <div class="stat-card">
        <h3>Revenue Increment</h3>
        <p>&#8377;<?php echo $revenue_increment; ?></p>
    </div>
</div>

<?php require BASE_PATH . '/frontend/components/footer.php'; ?>
