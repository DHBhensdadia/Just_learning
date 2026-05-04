<p align="center">
  <sub>DATABASE</sub>
</p>

# Database — gym_management

This folder contains all database assets for the GymFlow project.

<br/>

## Contents

| File | Description |
|:---|:---|
| `gym_management.sql` | Complete phpMyAdmin SQL dump — creates all tables, indexes, constraints, and seed data |
| `screenshots/` | Visual documentation of the database structure from phpMyAdmin |

<br/>

---

<br/>

## Schema Overview

Three tables with foreign key relationships:

```mermaid
erDiagram
    PLANS ||--o{ MEMBERS : "subscribes to"
    PLANS ||--o{ PAYMENTS : "paid for"
    MEMBERS ||--o{ PAYMENTS : "makes"

    PLANS {
        int plan_id PK
        varchar plan_name
        int duration_months
        decimal price
    }

    MEMBERS {
        int member_id PK
        varchar name
        varchar email UK
        varchar password
        varchar phone
        enum role
        date join_date
        int plan_id FK
    }

    PAYMENTS {
        int payment_id PK
        int member_id FK
        int plan_id FK
        decimal amount
        date payment_date
    }
```

<br/>

### Plans

| Column | Type | Notes |
|:---|:---|:---|
| `plan_id` | `INT` | Primary key, auto-increment |
| `plan_name` | `VARCHAR(100)` | Basic, Standard, Premium, Annual |
| `duration_months` | `INT` | 1, 3, 6, or 12 |
| `price` | `DECIMAL(10,2)` | Amount in ₹ |

### Members

| Column | Type | Notes |
|:---|:---|:---|
| `member_id` | `INT` | Primary key, auto-increment |
| `name` | `VARCHAR(100)` | Full name |
| `email` | `VARCHAR(150)` | Unique — used for login |
| `password` | `VARCHAR(255)` | Bcrypt hash |
| `phone` | `VARCHAR(15)` | Nullable |
| `role` | `ENUM('admin','member')` | Defaults to `member` |
| `join_date` | `DATE` | Registration date |
| `plan_id` | `INT` | FK → `plans.plan_id` |

### Payments

| Column | Type | Notes |
|:---|:---|:---|
| `payment_id` | `INT` | Primary key, auto-increment |
| `member_id` | `INT` | FK → `members.member_id` |
| `plan_id` | `INT` | FK → `plans.plan_id` |
| `amount` | `DECIMAL(10,2)` | Amount paid |
| `payment_date` | `DATE` | Date of payment |

<br/>

---

<br/>

## Importing the Database

### Option A — Import the SQL dump (fastest)

1. Open phpMyAdmin → [`http://localhost/phpmyadmin`](http://localhost/phpmyadmin)
2. Click **Import** in the top navigation
3. Select `gym_management.sql` from this folder
4. Click **Go**

This creates the database, all three tables, indexes, constraints, and populates them with seed data including an admin account and 4 test members.

### Option B — Step-by-step setup

Follow the guided instructions in [`docs/DATABASE_SETUP.md`](../docs/DATABASE_SETUP.md) to create each table manually and understand the schema.

<br/>

---

<br/>

## Screenshots from phpMyAdmin

### ER Diagram — Table Relationships

<img src="screenshots/01-er-diagram.png" alt="ER Diagram showing relationships between members, payments, and plans tables" width="700"/>

<br/>

### Database Tables Overview

<img src="screenshots/02-database-tables-overview.png" alt="phpMyAdmin showing all three tables: members (6 rows), payments (11 rows), plans (4 rows)" width="700"/>

<br/>

### Members Table Structure

<img src="screenshots/03-members-table-structure.png" alt="Members table structure showing columns, types, indexes, and foreign keys" width="700"/>

<br/>

### Payments Table Structure

<img src="screenshots/04-payments-table-structure.png" alt="Payments table structure with foreign keys to members and plans" width="700"/>

<br/>

### Plans Table Structure

<img src="screenshots/05-plans-table-structure.png" alt="Plans table with plan_id, plan_name, duration_months, and price columns" width="700"/>

<br/>

---

<br/>

## XAMPP Server Configuration

The project runs on XAMPP with Apache and MySQL:

<img src="screenshots/06-xampp-server-running.png" alt="XAMPP Control Panel showing MySQL Database and Apache Web Server both running" width="500"/>

| Service | Status |
|:---|:---|
| MySQL Database | Running |
| Apache Web Server | Running |
| XAMPP Version | 8.2.4-0 |

<br/>

---

<br/>

<p align="center">
  <sub>See <a href="../docs/DATABASE_SETUP.md">DATABASE_SETUP.md</a> for step-by-step SQL commands to build this schema from scratch.</sub>
</p>
