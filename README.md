# LSQL: Lightweight SQL Engine

LSQL is a high-performance, minimalist database engine written in **C11**. Unlike traditional RDBMS with rigid storage, LSQL utilizes a **Dynamic Schema Architecture**, leveraging raw memory offsets and pointer arithmetic to manage data with near-zero overhead.

## 🚀 Key Features

* **Dynamic Schema Evolution:** Define tables, columns, and data types at runtime without recompilation.
* **Manual Memory Management:** Uses `void*` buffers and calculated offsets to eliminate unnecessary padding and maximize cache locality.
* **C11 Optimized:** Specifically tuned for `cc 11.1.0` standards, utilizing modern C safety and performance primitives.
* **Modular Design:** Strict decoupling between the hardware-abstracted logic and the user interface.

---

## 🛠 Technical Architecture

The engine manages rows as contiguous memory blocks. Instead of using rigid structs, LSQL calculates the position of each field dynamically:

$$Address = (char*)base\_ptr + column\_offset$$

### Data Types Supported
* **TYPE_INT:** Fixed 4-byte width.
* **TYPE_TEXT:** Variable-width storage based on user definition.

---

## 📂 Project Structure

```text
.
├── Makefile       # Build configuration
├── lib/           # Header files (.h)
├── src/           # Core engine implementation (.c)
└── README.md      # Technical documentation
