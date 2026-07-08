# 🚀 File Downloader DLL - URLDownloadToFile

<p align="center">
  <img src="https://img.shields.io/badge/Platform-Windows-blue?style=for-the-badge" />
  <img src="https://img.shields.io/badge/Architecture-x86/x64-red?style=for-the-badge" />
  <img src="https://img.shields.io/badge/Language-C++-success?style=for-the-badge" />
  <img src="https://img.shields.io/badge/Type-DLL-orange?style=for-the-badge" />
</p>

<p align="center">
  <b>Simple Windows DLL that downloads a file from a remote URL using the Windows URL Moniker API.</b>
</p>

---

## ⚠️ Disclaimer

> **For educational purposes only**

- ❌ Do not use this project for unauthorized activities.
- ✅ Only execute it on systems you own or have permission to test.
- ⚖️ The author assumes no responsibility for misuse of this project.

---

# 📖 Overview

This project implements a minimal Windows DLL that exports a function capable of downloading a file from a remote URL.

The DLL receives two command-line arguments:

- Remote URL
- Local destination path

The download is performed using the native Windows API `URLDownloadToFileA`, avoiding external dependencies.

---

## 🔄 Execution Flow

```text
DLL Loaded
      │
      ▼
Exported Function Called
      │
      ▼
Read Command-Line Arguments
      │
      ▼
Validate Parameters
      │
      ▼
URLDownloadToFileA
      │
      ▼
Save File to Disk
```

---

# ⚡ Quick Start

## 1️⃣ Build the DLL

### Visual Studio

```bash
cl /LD DownloadFiles.cpp urlmon.lib
```

or simply build the Visual Studio project.

---

## 2️⃣ Exported Function

The DLL exports:

```text
DownloadFiles
```

Prototype:

```cpp
void DownloadFiles(
    HWND hwnd,
    HINSTANCE hinst,
    LPSTR lpszCmdLine,
    int nCmdShow
);
```

---

## 3️⃣ Execute

Example arguments:

```text
https://example.com/file.zip C:\Users\Public\file.zip
```

The exported function expects both values separated by a space.

---

# 📂 Project Structure

| File | Description |
|------|-------------|
| `DownloadFiles.cpp` | Main DLL source |
| `pch.h` | Precompiled header |
| `README.md` | Project documentation |

---

# 🔧 Implementation Details

The exported function performs the following operations:

1. Receives the command-line string.
2. Splits the arguments into:
   - Download URL
   - Output filename
3. Validates that both parameters exist.
4. Calls `URLDownloadToFileA`.
5. Saves the downloaded file to disk.

If the arguments are missing, a Windows message box is displayed.

---

# 🛠 Windows APIs Used

| API | Purpose |
|------|---------|
| `URLDownloadToFileA` | Download a remote file |
| `MessageBoxA` | Display error messages |
| `DllMain` | DLL entry point |

---

# 📋 Requirements

- 🪟 Windows 10 / Windows 11
- 🛠 Visual Studio
- 📦 Windows SDK
- 📚 `urlmon.lib`

---

# ⚙️ Example

Input arguments:

```text
https://example.org/payload.exe C:\Users\Public\payload.exe
```

The DLL downloads:

```text
https://example.org/payload.exe
```

and stores it as:

```text
C:\Users\Public\payload.exe
```

---

# ✅ Compatibility

| Operating System | Status |
|-----------------|--------|
| Windows 10 | ✔️ Supported |
| Windows 11 | ✔️ Supported |
| Windows Server | ✔️ Supported |

---

# 🌟 Features

- Lightweight implementation
- Native Windows API
- No third-party libraries
- Simple exported interface
- Minimal codebase
- Visual Studio compatible

---

<p align="center">
Made for educational purposes 📚
</p>