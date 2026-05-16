# LibMark 📘🎯

LibMark is an industry-grade, desktop reading tracker application designed to help users systematically catalog books, track live reading progress, and manage highly granular study notes. Inspired by the sleek, consumer-focused aesthetic of apps like *Bookmory*, LibMark bridges structural elegance with high-performance C++ backend design.

---

## 🚀 Project Objectives
* **OOP Mastery:** Transitioning classroom C++ syntaxes into real-world software architecture separating declarations (`.h`) from operational logic (`.cpp`).
* **Data Integrity:** Enforcing compile-time logic safety patterns such as namespace clustering, encapsulation, explicit constructors, and data-immutable getters.
* **Persistent Storage:** Injecting structural File I/O interfaces to build a local simple database layer that rehydrates app states seamlessly.
* **Decoupled Architecture:** Orchestrating a clean boundary line between the core structural backend engines and visual components via specialized framework engines.

---

## 🛠️ The Technical Stack
* **Core Language:** C++ (OOP Paradigm, Dynamic `std::vector` sequences, Structured System File I/O).
* **Graphical Interface:** Qt Framework & Qt Designer (UI Dashboards, Interactive Progress Bars, Custom Signals & Slots).
* **Storage Schema:** Plain Text Data Serialization or Comma-Separated Values (CSV).
* **Workspace Tooling:** Visual Studio Code / System Terminals + Git Version Control Workflow.

---

## 📂 Structural Architecture & File Topology

To optimize compile-time speeds, modular testing boundaries, and professional code visibility, LibMark rejects monolithic designs and enforces strict file isolation within a dedicated `Libmark` namespace:

```text
📁 libmark/
├── 📄 Main.cpp          # Application bootstrapping and unified execution router
├── 📄 Book.h            # Structural blueprint declaration for the Book entity
├── 📄 Book.cpp          # Factory logic, business computation, and mutations for Books
├── 📄 Note.h            # Data contract