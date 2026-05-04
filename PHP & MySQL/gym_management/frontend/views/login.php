<?php require BASE_PATH . '/frontend/components/header.php'; ?>

<div class="login-wrapper">
    <!-- Left Panel -->
    <div class="login-card">
        <div class="login-brand">
            <h1>GymFlow</h1>
        </div>

        <?php if (isset($_GET["error"])): ?>
            <p class="error">Invalid email or password. Please try again.</p>
        <?php endif; ?>

        <h2>Member Login</h2>
        <form action="<?php echo BASE_URL; ?>/backend/login_handler.php" method="post">
            <input type="hidden" name="login_type" value="member">
            <label>Email</label>
            <input type="text" name="email" placeholder="Enter your email">
            <label>Password</label>
            <input type="password" name="password" placeholder="Enter your password">
            <input type="submit" value="Sign In">
        </form>

        <div class="login-divider">or</div>

        <h2>Admin Login</h2>
        <form action="<?php echo BASE_URL; ?>/backend/login_handler.php" method="post">
            <input type="hidden" name="login_type" value="admin">
            <label>Email</label>
            <input type="text" name="email" placeholder="Admin email">
            <label>Password</label>
            <input type="password" name="password" placeholder="Admin password">
            <input type="submit" value="Sign In">
        </form>
    </div>

    <!-- Right Panel -->
    <div class="login-glass">
        <div class="login-glass-content">
            <div class="glass-logo">GymFlow</div>
        </div>
    </div>
</div>

</body>
</html>
