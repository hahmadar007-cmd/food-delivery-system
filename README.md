# 🍔 Food Ordering System (C++)

A robust console-based application that simulates a digital food ordering experience. This project was developed to demonstrate intermediate **Object-Oriented Programming (OOP)** concepts and efficient data handling in C++.

---

## 🛠️ Technical Features
* **Abstraction:** Uses a `Restaurant` base class with pure virtual functions to enforce a consistent interface.
* **Polymorphism:** Implements dynamic binding via base class pointers to handle multiple restaurant types (KFC, Dominos) at runtime.
* **Dynamic Cart:** Utilizes `std::vector` to allow users to order multiple items in a single session.
* **File Persistence:** Automatically generates a `bill.txt` file as a permanent record of the transaction.
* **Encapsulation:** Separate classes for `Customer`, `Order`, and `Restaurant` logic.



---

## 🚀 How to Use
1. **Compile:** ```bash
   g++ main.cpp -o FoodSystem
