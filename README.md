# 📘 Student Grade Manager (C Project)

This was one of the very first projects I started when learning C programming. It began as a simple program to collect a student's name, ID, and grade — but as I learned more about C, I kept improving and expanding it.

What started out as just `scanf` and `printf` is now a modular, file-based grade manager that uses structs, dynamic memory, binary files, and text exports — all from scratch using pure C.

---

## 🛠 Features

- 🧾 **Add & View Student Records**
- 🧠 **Validate grades and student IDs**
- 📁 **Save and load data to/from a binary file**
- 📝 **Export student reports to a readable text file**
- 🧠 **Grade-based performance levels**
- ✅ **Modular design using multiple functions and a struct**

---

## 🔨 Technologies & Concepts Practiced

This project has evolved as I practiced new concepts in C:

| Feature Added             | Concept Practiced              |
|---------------------------|--------------------------------|
| Input/output              | `scanf`, `fgets`, `printf`     |
| Validation                | `strspn`, string manipulation  |
| Structs                   | Custom `Student` type          |
| Dynamic memory            | `malloc`, `realloc`, `free`    |
| File I/O (binary)         | `fopen`, `fwrite`, `fread`     |
| File I/O (text export)    | formatted `fprintf` reporting  |
| Modular programming       | Splitting logic into functions |
| Header files (planned)    | Reusability + cleaner design   |

---

## 🧪 How to Run

```bash
make       # Compiles the code
./student  # Runs the program
make clean # Cleans the compiled file
```

Or compile manually with:

```bash
gcc student.c -o student
./student
```

> ⚠️ On first run, the program will say `No file found. Starting fresh.` — this is expected. After saving student data, it’ll load automatically next time.

---

## 📌 Planned Future Additions

I'm actively improving this project as I learn more. Here's what I'm thinking about next:

- 🗑️ **Delete a student** from the list
- 🔍 **Search by ID or name**
- 📚 **Sort by name or grade**
- 📦 **Split into `main.c`, `student.c`, and `student.h`**
- 📄 **Switch to JSON or CSV export** for broader compatibility
- 💬 **Command-line options** like `--export` or `--view-only`
- 🌐 (far future) **GUI version with GTK or web interface using C back-end**

---

## 📁 File Structure

```
student.c           # Main program source
Makefile            # Compile automation
.gitignore          # Ignore binary and temp files
students.dat        # Auto-saved binary file (after first run)
student_report.txt  # Exported readable report (if you use Export option)
```

---

## 🙌 Why I Made This

This wasn’t just a school assignment — it became a way for me to apply what I was learning in real time. Every new concept I picked up, I tried to plug it into this project to see how it works in practice.

It's a personal milestone, and also a growing proof-of-progress in my journey with C programming.

---

Feel free to fork, study, or build on this. Contributions or feedback are always welcome. 💻🚀
