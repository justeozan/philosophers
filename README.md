# Philosophers

Philosophers is a project from the school 42, designed to explore the concept of multithreading and synchronization in the context of the dining philosophers problem.

## 📜 Table of Contents

- [About](#about)
- [Problem Statement](#problem-statement)
- [Usage](#usage)
- [Installation](#installation)
- [Implementation Details](#implementation-details)
- [Contributing](#contributing)
- [License](#license)

## 📖 About

The Philosophers project is part of the curriculum at 42, where students learn about multithreading and synchronization in the context of the dining philosophers problem. The goal of the project is to implement a solution that simulates the dining philosophers problem, ensuring that philosophers can eat without deadlock or starvation.

## 🔍 Problem Statement

The dining philosophers problem is a classic problem in computer science and concurrency. It involves a number of philosophers sitting at a table, with a bowl of spaghetti in front of each philosopher. There are forks placed between each pair of adjacent philosophers. The philosophers spend their time thinking and eating, but they need both forks to eat. The challenge is to design a solution where the philosophers can dine without deadlocking or starving.

## 🚀 Usage

To use the Philosophers program, simply compile the source code and run the executable with the appropriate arguments. The program takes several arguments, including the number of philosophers, the time it takes for a philosopher to eat, think, and sleep, and the maximum time a philosopher can stay alive without eating.

```
./philosophers [number_of_philosophers] [time_to_die] [time_to_eat] [time_to_sleep] [optional: number_of_times_each_philosopher_must_eat]
```

## 💾 Installation

To install Philosophers, simply clone the repository and compile the program using the provided Makefile.

```bash
git clone https://github.com/your_username/philosophers.git
cd philosophers/philo/
make
```

This will generate the `philosophers` executable file that you can run with the appropriate arguments.

## 🛠️ Implementation Details

The Philosophers program is implemented in C and uses the pthreads library for multithreading. It consists of several modules, including the main program logic, functions for initializing and managing philosophers and forks, and synchronization mechanisms to prevent deadlock and starvation.

## 🤝 Contributing

Contributions to Philosophers are welcome! If you find any bugs or want to suggest improvements, feel free to open an issue or submit a pull request on GitHub.

## 📄 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
