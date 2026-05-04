<div class="app-layout">
    <!-- Sidebar Navigation -->
    <aside class="sidebar">
        <div class="sidebar-brand">
            <div class="brand-icon">
                <svg viewBox="0 0 28 28" fill="none" xmlns="http://www.w3.org/2000/svg">
                    <rect x="2" y="2" width="24" height="24" rx="6" stroke="currentColor" stroke-width="1.5"/>
                    <path d="M9 14h10M14 9v10" stroke="currentColor" stroke-width="1.5" stroke-linecap="round"/>
                </svg>
            </div>
            <div>
                <div class="brand-text">GymFlow</div>
                <div class="brand-sub">Member Portal</div>
            </div>
        </div>

        <nav class="sidebar-nav">
            <a href="<?php echo BASE_URL; ?>/member/dashboard.php" class="<?php echo (strpos($_SERVER['PHP_SELF'], 'dashboard.php') !== false) ? 'active' : ''; ?>">
                <span class="nav-icon"><svg viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-linecap="round" stroke-linejoin="round"><rect x="3" y="3" width="7" height="7" rx="1"/><rect x="14" y="3" width="7" height="7" rx="1"/><rect x="3" y="14" width="7" height="7" rx="1"/><rect x="14" y="14" width="7" height="7" rx="1"/></svg></span> Dashboard
            </a>
            <a href="<?php echo BASE_URL; ?>/member/profile.php" class="<?php echo (strpos($_SERVER['PHP_SELF'], 'profile.php') !== false) ? 'active' : ''; ?>">
                <span class="nav-icon"><svg viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-linecap="round" stroke-linejoin="round"><path d="M20 21v-2a4 4 0 0 0-4-4H8a4 4 0 0 0-4 4v2"/><circle cx="12" cy="7" r="4"/></svg></span> Profile
            </a>
            <a href="<?php echo BASE_URL; ?>/member/subscription.php" class="<?php echo (strpos($_SERVER['PHP_SELF'], 'subscription.php') !== false) ? 'active' : ''; ?>">
                <span class="nav-icon"><svg viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-linecap="round" stroke-linejoin="round"><path d="M2 3h6a4 4 0 0 1 4 4v14a3 3 0 0 0-3-3H2z"/><path d="M22 3h-6a4 4 0 0 0-4 4v14a3 3 0 0 1 3-3h7z"/></svg></span> My Subscription
            </a>
            <a href="<?php echo BASE_URL; ?>/member/payments.php" class="<?php echo (strpos($_SERVER['PHP_SELF'], 'payments.php') !== false) ? 'active' : ''; ?>">
                <span class="nav-icon"><svg viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-linecap="round" stroke-linejoin="round"><rect x="1" y="4" width="22" height="16" rx="2" ry="2"/><line x1="1" y1="10" x2="23" y2="10"/></svg></span> Payment History
            </a>
            <a href="<?php echo BASE_URL; ?>/member/plans.php" class="<?php echo (strpos($_SERVER['PHP_SELF'], 'plans.php') !== false && strpos($_SERVER['PHP_SELF'], 'member') !== false) ? 'active' : ''; ?>">
                <span class="nav-icon"><svg viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-linecap="round" stroke-linejoin="round"><path d="M14 2H6a2 2 0 0 0-2 2v16a2 2 0 0 0 2 2h12a2 2 0 0 0 2-2V8z"/><polyline points="14 2 14 8 20 8"/><line x1="16" y1="13" x2="8" y2="13"/><line x1="16" y1="17" x2="8" y2="17"/><polyline points="10 9 9 9 8 9"/></svg></span> View Plans
            </a>
        </nav>

        <div class="sidebar-footer">
            <a href="<?php echo BASE_URL; ?>/logout.php">
                <span class="nav-icon"><svg viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-linecap="round" stroke-linejoin="round"><path d="M9 21H5a2 2 0 0 1-2-2V5a2 2 0 0 1 2-2h4"/><polyline points="16 17 21 12 16 7"/><line x1="21" y1="12" x2="9" y2="12"/></svg></span> Logout
            </a>
        </div>
    </aside>

    <!-- Main Content Area -->
    <main class="main-content">
