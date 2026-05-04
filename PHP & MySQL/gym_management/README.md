<p align="center">
  <sub>SOURCE CODE</sub>
</p>

# Application Source — gym_management

This is the complete PHP application. Copy this folder to your XAMPP `htdocs/` directory and rename it to `gym` to run.

<br/>

---

<br/>

## Architecture

The application uses a **backend/frontend separation pattern** — no framework, just organized PHP:

```
gym_management/
├── config.php               ← Single config file (DB credentials + paths)
├── index.php                ← Entry point — renders login page
├── logout.php               ← Destroys session, redirects to login
│
├── backend/                 ← Authentication layer
│   ├── login_handler.php        POST handler — validates credentials
│   ├── auth_check.php           Guard — member session required
│   └── admin_auth_check.php     Guard — admin session required
│
├── admin/                   ← Admin business logic (no HTML)
│   ├── dashboard.php            Queries: member count, revenue stats
│   ├── profile.php              Admin profile update logic
│   ├── member_mgmt/             Full CRUD for members
│   ├── plan_mgmt/               Full CRUD for plans
│   └── payment_mgmt/            Record payments + auto-update plans
│
├── member/                  ← Member business logic (no HTML)
│   ├── dashboard.php            Simple welcome page
│   ├── profile.php              Profile update logic
│   ├── subscription.php         Current plan + expiry calculation
│   ├── payments.php             Payment history query
│   └── plans.php                View available plans
│
└── frontend/                ← Presentation layer
    ├── style.css                Editorial design system (854 lines)
    ├── components/              Shared layout parts
    │   ├── header.php               HTML head + Google Fonts
    │   ├── footer.php               Closes layout wrappers
    │   ├── admin_nav.php            Admin sidebar with SVG icons
    │   └── member_nav.php           Member sidebar with SVG icons
    └── views/                   Page templates
        ├── login.php                Split-panel login page
        ├── admin/                   Admin page templates
        │   ├── dashboard.php
        │   ├── profile.php
        │   ├── member_mgmt/
        │   ├── plan_mgmt/
        │   └── payment_mgmt/
        └── member/                  Member page templates
            ├── dashboard.php
            ├── profile.php
            ├── subscription.php
            ├── payments.php
            └── plans.php
```

<br/>

---

<br/>

## How routing works

There is no routing framework. Each URL maps directly to a PHP file:

```
http://localhost/gym/admin/dashboard.php
                     ↓
admin/dashboard.php  (backend — runs queries, sets variables)
    ↓ require
frontend/views/admin/dashboard.php  (frontend — renders HTML)
```

Every backend file follows the same pattern:

```php
<?php
require_once "../config.php";               // DB connection
require_once "../backend/admin_auth_check.php";  // Auth guard

// ... business logic, SQL queries, set variables ...

$page_title = "Page Name";
require BASE_PATH . '/frontend/views/admin/page.php';  // Render
```

<br/>

---

<br/>

## Design System

The CSS in `frontend/style.css` is a complete design system with:

| Token | Value |
|:---|:---|
| `--bg` | `#f5f3f0` — warm off-white background |
| `--text` | `#1a1a1a` — near-black text |
| `--border` | `#e0ddd8` — subtle warm gray |
| `--font-body` | Inter |
| `--font-heading` | Space Grotesk |
| `--radius` | `100px` — pill buttons |
| `--radius-input` | `8px` — form fields |

Design inspiration: [monopo.london](https://monopo.london) — editorial, typography-first, minimal.

<br/>

---

<br/>

## Security

| Measure | Implementation |
|:---|:---|
| Password hashing | `password_hash()` with `PASSWORD_BCRYPT` |
| Password verification | `password_verify()` on login |
| SQL injection prevention | `mysqli_prepare()` with `bind_param()` |
| Input sanitization | `filter_input()` with `FILTER_SANITIZE_EMAIL` |
| Session management | PHP native sessions with role-based guards |
| Access control | Every protected route includes an auth guard file |

<br/>

---

<br/>

## Modifying the application

| Change | File to edit |
|:---|:---|
| Database credentials | `config.php` |
| URL base path | `config.php` → `BASE_URL` |
| Colors / typography | `frontend/style.css` → CSS variables |
| Navigation links | `frontend/components/admin_nav.php` or `member_nav.php` |
| Add a new admin page | Create in `admin/` + `frontend/views/admin/` + add nav link |
| Add a new member page | Create in `member/` + `frontend/views/member/` + add nav link |

<br/>

---

<br/>

<p align="center">
  <sub>Return to the <a href="../README.md">main README</a></sub>
</p>
