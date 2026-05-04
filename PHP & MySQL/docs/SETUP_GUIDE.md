<p align="center">
  <sub>DOCS / SETUP GUIDE</sub>
</p>

# Setup Guide

Complete walkthrough for getting GymFlow running on your local machine with XAMPP.

<br/>

---

<br/>

## Prerequisites

| Software | Minimum Version | Download |
|:---|:---|:---|
| XAMPP | 8.2.4 | [apachefriends.org](https://www.apachefriends.org/) |
| Web Browser | Any modern browser | — |

> XAMPP bundles **Apache**, **MySQL (MariaDB)**, **PHP**, and **phpMyAdmin** — no separate installs needed.

<br/>

---

<br/>

## Step 1 — Start XAMPP

Open the XAMPP Control Panel and start both services:

| Service | Required |
|:---|:---|
| **MySQL Database** | ✓ Must be running |
| **Apache Web Server** | ✓ Must be running |

Both should show **Running** status (green indicator).

<br/>

---

<br/>

## Step 2 — Set up the database

Open phpMyAdmin at [`http://localhost/phpmyadmin`](http://localhost/phpmyadmin).

**Choose one approach:**

| Method | Instructions |
|:---|:---|
| **Quick import** | Go to **Import** → upload [`database/gym_management.sql`](../database/gym_management.sql) → Click **Go** |
| **Step-by-step** | Follow [`docs/DATABASE_SETUP.md`](DATABASE_SETUP.md) — paste each SQL block in order |

Both methods create the same result: the `gym_management` database with 3 tables and seed data.

<br/>

---

<br/>

## Step 3 — Deploy to htdocs

Copy the `gym_management/` folder into your XAMPP `htdocs/` directory and **rename it to `gym`**:

### macOS

```bash
cp -r gym_management /Applications/XAMPP/htdocs/gym
```

### Windows

```
Copy gym_management\ folder to C:\xampp\htdocs\
Rename it to: gym
```

### Final path should be

```
htdocs/
  └── gym/
      ├── config.php
      ├── index.php
      ├── admin/
      ├── member/
      ├── backend/
      └── frontend/
```

<br/>

> **⚠ Folder name matters.** The app's `BASE_URL` is set to `/gym` by default.
> If you use a different name, update the constant in `config.php`:
>
> ```php
> define('BASE_URL', '/your-folder-name');
> ```

<br/>

---

<br/>

## Step 4 — Open in browser

Navigate to:

```
http://localhost/gym/
```

You should see the GymFlow login page with two forms — Member and Admin.

<br/>

---

<br/>

## Step 5 — Login

| Role | Email | Password |
|:---|:---|:---|
| **Admin** | `admin@gym.com` | `admin123` |
| **Member** | `aarav@example.com` | `aarav@123` |

> See [`TEST_CREDENTIALS.md`](TEST_CREDENTIALS.md) for all test accounts.

<br/>

---

<br/>

## Configuration Reference

All settings live in [`gym_management/config.php`](../gym_management/config.php):

| Constant | Default | Description |
|:---|:---|:---|
| `DB_SERVER` | `localhost` | Database host |
| `DB_USERNAME` | `root` | Database user (XAMPP default) |
| `DB_PASSWORD` | *(empty)* | Database password (XAMPP default) |
| `DB_NAME` | `gym_management` | Database name |
| `BASE_URL` | `/gym` | URL path — must match folder name in `htdocs/` |
| `BASE_PATH` | `__DIR__` | Filesystem root — auto-resolved, don't change |

<br/>

---

<br/>

## How the Application Works

### Architecture

```
Backend PHP files (logic only)  →  require  →  Frontend view templates (HTML only)
```

- **Backend files** (`admin/`, `member/`) run database queries, set variables, then `require` a view template
- **Frontend files** (`frontend/views/`) render HTML using the variables set by the backend
- **No framework** — direct PHP with `require` statements

### Authentication Flow

1. User submits login form → `backend/login_handler.php`
2. Handler queries `members` table by email and role
3. Password verified with `password_verify()` against bcrypt hash
4. On success → session variables set (`member_id`, `name`, `email`, `role`)
5. Redirect to admin or member dashboard based on role

### Auth Guards

Every protected page includes a guard file at the top:

| Guard | Protects | Checks |
|:---|:---|:---|
| `auth_check.php` | Member pages | Session exists + role is `member` |
| `admin_auth_check.php` | Admin pages | Session exists + role is `admin` |

### Key Behaviors

| Feature | How it works |
|:---|:---|
| **Subscription expiry** | Calculated from last payment date + plan duration (not stored in DB) |
| **Recording payment** | When admin records a payment, member's `plan_id` is auto-updated |
| **Password storage** | All passwords are bcrypt hashed — never stored as plaintext |
| **Input sanitization** | Login uses `filter_input()` with `FILTER_SANITIZE_EMAIL` |
| **SQL injection prevention** | All queries use `mysqli_prepare()` with bound parameters |

<br/>

---

<br/>

## Troubleshooting

<details>
<summary><strong>Login fails with correct credentials</strong></summary>

<br/>

The password hash in the database may not match. Re-run Step 6 from [`DATABASE_SETUP.md`](DATABASE_SETUP.md) to insert the admin with the correct bcrypt hash.

</details>

<details>
<summary><strong>CSS / styles not loading</strong></summary>

<br/>

Check that `BASE_URL` in `config.php` matches your folder name in `htdocs/`. The CSS is loaded via:

```html
<link rel="stylesheet" href="<?php echo BASE_URL; ?>/frontend/style.css">
```

If your folder is named `gym_app` instead of `gym`, update:

```php
define('BASE_URL', '/gym_app');
```

</details>

<details>
<summary><strong>Database connection error</strong></summary>

<br/>

- Verify MySQL is running in XAMPP
- Check credentials in `config.php` match your XAMPP setup
- Ensure the `gym_management` database exists in phpMyAdmin

</details>

<details>
<summary><strong>Page shows blank / 500 error</strong></summary>

<br/>

- Check PHP error log in XAMPP
- Ensure PHP version is 8.2+ (for `password_hash()` and modern syntax)
- Verify all files were copied correctly to `htdocs/gym/`

</details>

<br/>

---

<br/>

<p align="center">
  <sub>Return to the <a href="../README.md">main README</a></sub>
</p>
