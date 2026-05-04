<p align="center">
  <sub>DOCS / TEST CREDENTIALS</sub>
</p>

# Test Credentials

Login credentials for all seeded accounts in the database. These are for **testing and development only**.

<br/>

> **⚠ Security notice:** These are dummy accounts with weak passwords. Never use these patterns in production.

<br/>

---

<br/>

## Admin Account

| Field | Value |
|:---|:---|
| **Name** | Admin |
| **Email** | `admin@gym.com` |
| **Password** | `admin123` |
| **Role** | `admin` |
| **Login form** | Use the **Admin Login** section on the login page |

<br/>

---

<br/>

## Member Accounts

| Name | Email | Password | Phone | Plan |
|:---|:---|:---|:---|:---|
| Aarav Sharma | `aarav@example.com` | `aarav@123` | 9876543210 | Basic — ₹500/mo |
| Priya Patel | `priya@example.com` | `priya@123` | 9876543211 | Standard — ₹1,200/3mo |
| Rohan Mehta | `rohan@example.com` | `rohan@123` | 9876543212 | Premium — ₹2,000/6mo |
| Sneha Iyer | `sneha@example.com` | `sneha@123` | 9876543213 | Annual — ₹3,500/yr |

<br/>

### Password pattern

```
firstname@123
```

All first names are lowercase. For example:
- Aarav Sharma → `aarav@123`
- Priya Patel → `priya@123`

<br/>

---

<br/>

## How passwords are stored

Passwords in the database are **bcrypt hashed** using PHP's `password_hash()` function. The values shown above are the plaintext originals — the database never stores them in this form.

Example hash for `admin123`:

```
$2y$10$Qo.qpn9vnkJwD8GXmXgEi.Un.g92JXOEUdGaxE9o44TPzpgHTsCVW
```

Login verification uses `password_verify($input, $stored_hash)`.

<br/>

---

<br/>

## Seeding these accounts

These accounts are created in Steps 6–8 of [`DATABASE_SETUP.md`](DATABASE_SETUP.md), or automatically when importing [`database/gym_management.sql`](../database/gym_management.sql).

<br/>

---

<br/>

<p align="center">
  <sub>Return to the <a href="../README.md">main README</a></sub>
</p>
