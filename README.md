# 🚀 CyberScanner CLI Framework

> A high-performance, modular **C++ cybersecurity scanning framework** designed for ethical hacking, penetration testing, and research.

---

## ⚡ Overview

CyberScanner is a **command-line based network scanning framework** inspired by tools like Nmap.
It is built using **modern C++** with a modular architecture, making it easy to expand into a full cybersecurity platform.

---

## 🔥 Features

* 🔎 TCP Port Scanning (multi-threaded)
* 🌐 Hostname Resolution
* 📡 Banner Grabbing (basic service detection)
* 🧠 Modular Architecture (CLI + Scanner + Utils)
* ⚡ High Performance (C++ + threading)
* 💻 Interactive CLI Interface

---

## 🏗️ Project Structure

```
cyberscanner/
├── main.cpp
├── cli/
│   ├── cli.h
│   ├── cli.cpp
├── scanner/
│   ├── scanner.h
│   ├── scanner.cpp
├── utils/
│   ├── resolver.h
│   ├── resolver.cpp
├── Makefile
```

---

## 🛠️ Installation

### 1. Clone the Repository

```bash
git clone https://github.com/yourusername/cyberscanner.git
cd cyberscanner
```

### 2. Build the Project

```bash
make
```

---

## 🚀 Usage

Run the CLI:

```bash
./cyberscanner
```

### 📌 Commands

| Command                                           | Description             |
| ------------------------------------------------- | ----------------------- |
| `scan <target> <start_port> <end_port> <threads>` | Scan a target           |
| `help`                                            | Show available commands |
| `exit`                                            | Exit the CLI            |

---

### 🔍 Example

```bash
cyber> scan scanme.nmap.org 1 1000 100
```

---

## 🧪 Sample Output

```
[*] Resolving...
[*] Target IP: 45.33.32.156
[*] Starting scan...

[OPEN] Port 22 | SSH-2.0-OpenSSH
[OPEN] Port 80 | HTTP/1.1 200 OK

[*] Scan complete.
```

---

## ⚙️ Requirements

* Linux (Ubuntu/Kali recommended)
* g++ (C++17 or later)
* pthread support

Install dependencies:

```bash
sudo apt update
sudo apt install g++ make -y
```

---

## 🧠 How It Works

1. CLI parses user commands
2. Target is resolved to IP
3. Multi-threaded scanner attempts TCP connections
4. Open ports are detected
5. Optional banner grabbing extracts service info

---

## 🔥 Roadmap

* [ ] SYN Scan (raw sockets)
* [ ] OS Fingerprinting
* [ ] Service Detection Database
* [ ] CVE Integration
* [ ] AI-based Vulnerability Analysis 🤖
* [ ] JSON Output + Report Generator
* [ ] GUI Dashboard

---

## ⚠️ Disclaimer

This tool is intended for:

* ✅ Educational purposes
* ✅ Ethical hacking
* ✅ Authorized penetration testing

**Do NOT use this tool on systems without permission.**
Unauthorized scanning may be illegal.

---

## 🤝 Contributing

Contributions are welcome!

1. Fork the repo
2. Create a new branch
3. Submit a pull request

---

## 📜 License

MIT License

---

## 👨‍💻 Author

Developed by **Cybertarr-A**

---

## ⭐ Support

If you like this project:

* ⭐ Star the repo
* 🍴 Fork it
* 🧠 Build your own extensions

---

## 🚀 Vision

CyberScanner is the foundation of a larger system:

```
Scan → Analyze → Predict → Exploit → Report
```

Future goal: Build a full **CyberWarrior AI Security Framework** 🔥
