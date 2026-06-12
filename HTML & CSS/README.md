<p align="center">
  A multi-page <strong>Personal Portfolio Website</strong> built with pure HTML5 and CSS3.<br/>
  <sub>Semantic markup · responsive design · editorial typography · advanced forms</sub>
</p>

<br/>

---

<br/>

### <img src=".github/assets/icon-overview.svg" width="18" height="18" alt=""/> &nbsp; Overview

**Portfolio** is a seven-page personal website with an editorial design aesthetic — warm tones, serif typography, and clean card-based layouts. No JavaScript, no frameworks, just hand-written HTML and CSS.

Built as a hands-on project to learn **HTML5 semantics**, **CSS layout techniques**, and **form design** from the ground up.

<br/>

| Area | What It Covers |
|:---|:---|
| **Semantic HTML5** | `<nav>`, `<main>`, `<section>`, `<footer>`, `<article>`, `<fieldset>`, `<legend>` |
| **Typography** | Google Fonts — Playfair Display (headings) + Lora (body), editorial hierarchy |
| **Layout** | Flexbox navigation, CSS Grid hobby cards, responsive breakpoints |
| **Forms** | Two full forms — 12+ input types, fieldsets, validation attributes |
| **Styling** | Custom design system — no Bootstrap, no Tailwind, vanilla CSS throughout |
| **Responsive** | Mobile-first media queries, fluid spacing, flexible grids |

<br/>

---

<br/>

### <img src=".github/assets/icon-pages.svg" width="18" height="18" alt=""/> &nbsp; Pages

Seven pages, each demonstrating different HTML and CSS techniques:

<br/>

| Page | File | Key Features |
|:---|:---|:---|
| **Home** | [`index.html`](index.html) | Hero card with portrait, social links, two-column Flexbox layout |
| **Education** | [`education.html`](education.html) | Semantic `<table>` with `<thead>` / `<tbody>`, academic data |
| **Experience** | [`experience.html`](experience.html) | Multiple content cards, bold labels with gold accent color |
| **Hobbies** | [`hobbies.html`](hobbies.html) | CSS Grid image cards (2-column), `<img>` with alt text |
| **Quote** | [`quote.html`](quote.html) | Styled blockquote cards, `<small>` attribution |
| **Contact** | [`contact.html`](contact.html) | Form — text, email, tel, date, time, select, textarea |
| **Feedback** | [`feedback.html`](feedback.html) | Form — number, range, radio buttons, checkboxes, url |

<br/>

---

<br/>

### <img src=".github/assets/icon-palette.svg" width="18" height="18" alt=""/> &nbsp; Design System

The entire site uses a custom editorial design system defined in [`css/common.css`](css/common.css) — no external CSS frameworks.

<br/>

**Typography**

| Role | Font | Source |
|:---|:---|:---|
| Headings | Playfair Display | Google Fonts |
| Body text | Lora | Google Fonts |
| Fallbacks | Georgia, Times New Roman, serif | System |

<br/>

**Color Palette**

| Token | Hex | Usage |
|:---|:---|:---|
| Background | `#FAF6EE` | Warm off-white page background |
| Text | `#3A2520` | Deep brown body text |
| Headings | `#2A1610` | Near-black heading color |
| Accent | `#7C2D3A` | Burgundy — links, active states, hover underlines |
| Accent hover | `#5E1F2B` | Darker burgundy on hover |
| Gold | `#B8943E` | Bold labels, gradient accent bar |
| Muted | `#8C7468` | Nav links, footer text |
| Card border | `#E2D8C5` | Warm beige borders and dividers |
| Footer bg | `#F0EAD6` | Slightly darker beige for footer |

<br/>

---

<br/>

### <img src=".github/assets/icon-code.svg" width="18" height="18" alt=""/> &nbsp; HTML Features

Techniques demonstrated across the seven pages:

- **Semantic elements** — `<nav>`, `<main>`, `<section>`, `<footer>`, `<header>`, `<article>`
- **Tables** — `<table>`, `<thead>`, `<tbody>`, `<tr>`, `<th>`, `<td>` for structured data
- **Images** — `<img>` with descriptive `alt` attributes, responsive sizing
- **Links** — internal page navigation, external links with `target="_blank"` and `rel="noopener"`
- **Metadata** — `<meta charset>`, `<meta viewport>`, `<meta description>`, `<title>` per page
- **Accessibility** — `aria-label` on icon links, `<label>` + `for` attribute pairing on all form inputs

<br/>

---

<br/>

### <img src=".github/assets/icon-form.svg" width="18" height="18" alt=""/> &nbsp; Form Features

Two forms ([`contact.html`](contact.html) and [`feedback.html`](feedback.html)) cover a wide range of HTML form elements:

<br/>

| Element | Type | Attributes Used |
|:---|:---|:---|
| `<input>` | `text` | `placeholder`, `required` |
| `<input>` | `email` | `placeholder`, `required` |
| `<input>` | `tel` | `placeholder` |
| `<input>` | `date` | `min` |
| `<input>` | `time` | `min`, `max` |
| `<input>` | `number` | `min`, `max`, `step`, `required` |
| `<input>` | `range` | `min`, `max`, `value` |
| `<input>` | `url` | `placeholder` |
| `<input>` | `radio` | `name` grouping |
| `<input>` | `checkbox` | `name`, `value` |
| `<select>` | dropdown | `<option>`, `disabled selected` |
| `<textarea>` | multiline | `rows`, `placeholder`, `required` |
| `<fieldset>` | grouping | `<legend>` titles |
| `<button>` | submit | form submission |

<br/>

---

<br/>

### <img src=".github/assets/icon-layout.svg" width="18" height="18" alt=""/> &nbsp; CSS Features

Key CSS techniques used in the design system:

- **Google Fonts import** — `@import url()` for Playfair Display and Lora
- **Global reset** — `*` box-sizing, margin/padding reset
- **Pseudo-elements** — `::before` gradient accent bar at page top, `::after` animated nav underlines
- **Sticky navigation** — `position: sticky` with `backdrop-filter`-style translucent background
- **Transitions** — `transition: width 0.2s ease` for smooth hover underline animations
- **Flexbox** — navigation layout, footer links, hero card columns
- **CSS Grid** — two-column hobby card grid
- **Media queries** — `@media (max-width: 768px)` for mobile responsive adjustments
- **Custom form styling** — `.range-wrap` for slider, `.option-label` for radio/checkbox groups

<br/>

---

<br/>

### <img src=".github/assets/icon-folder.svg" width="18" height="18" alt=""/> &nbsp; Project Structure

```
HTML & CSS/
│
├── README.md
│
├── index.html                   Home — hero card with portrait
├── education.html               Education — academic table
├── experience.html              Experience — work history cards
├── hobbies.html                 Hobbies — image card grid
├── quote.html                   Quote — styled blockquotes
├── contact.html                 Contact — multi-fieldset form
├── feedback.html                Feedback — rating & survey form
│
├── css/                     ← Stylesheets
│   ├── common.css               Shared design system (navbar, footer, cards, reset)
│   ├── home.css                 Hero section layout
│   ├── education.css            Table styling
│   ├── contact.css              Contact form styles
│   ├── feedback.css             Feedback form styles
│   ├── hobbies.css              Hobby grid cards
│   └── quote.css                Blockquote styles
│
└── images/                  ← Static assets
    ├── My_Portrait.png          Profile photo (hero section)
    ├── profile.png              Alternate profile image
    ├── Light.png                Decorative image
    ├── hobby_movies.png         Hobby card — movies
    ├── hobby_volleyball.png     Hobby card — volleyball
    ├── hobby_software.png       Hobby card — software
    └── hobby_reading.png        Hobby card — reading
```

<br/>

---

<br/>

### <img src=".github/assets/icon-book.svg" width="18" height="18" alt=""/> &nbsp; What I Learned

This project was built as part of my learning journey. Key takeaways:

- **HTML5 semantics** — structuring pages with meaningful elements instead of generic `<div>` tags
- **Multi-page architecture** — linking pages with consistent navigation and shared stylesheets
- **CSS design systems** — building a reusable set of colors, typography, and component styles
- **Form design** — using fieldsets, legends, labels, and diverse input types with validation
- **Responsive layout** — Flexbox for linear layouts, Grid for two-dimensional card layouts
- **Typography** — pairing serif fonts (display + body) for an editorial aesthetic
- **Pseudo-elements** — `::before` and `::after` for decorative elements without extra HTML
- **Accessibility basics** — `aria-label`, `alt` text, `<label>` + `for` attribute pairing


<br/>

---

<br/>

This project is licensed under the [MIT License](../LICENSE).

<p align="center">
  <br/>
  <sub>Built by <a href="https://github.com/Celestial-Coder-DHB">Devansh</a></sub>
</p>
