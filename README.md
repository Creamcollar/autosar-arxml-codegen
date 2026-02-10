Testing
# AUTOSAR - MCAL Generator

![License: GPL v3](https://img.shields.io/badge/License-GPLv3-blue.svg)

A desktop application for generating AUTOSAR MCAL (Microcontroller Abstraction Layer) configurations and code from ARXML files. This tool simplifies the process of configuring and generating drivers for the DIO, ADC, CAN module.

## Application Overview

<img width="7672" height="3416" alt="image" src="asserts/Archiecture.png"/>

## Features Involved

| Peripheral Config Editor | Raw XML View | Edit and Build |
| :---: | :---: | :---: |
| ![Peripheral Config Editor](asserts/PeripheralConfigEditor.png) | ![Raw XML View](asserts/RawXML.png) | ![Edit and Build](asserts/EditAndBuild.png) |

## Features

*   **ARXML Parsing:** Import and parse AUTOSAR XML (.arxml) files.
*   **Configuration Viewing:** View the parsed ARXML data in a structured format.
*   **Code Generation:** Generate C code for the DIO module based on the ARXML configuration.
*   **User-Friendly GUI:** An intuitive graphical user interface built with tkinter.

## Technologies Used

*   **Language:** Python
*   **GUI Framework:** Tkinter
*   **Template Engine:** Parse library
*   **Data Format:** ARXML (AUTOSAR XML)
 
## Building from Source (For Integrators)

If you want to modify the code or build the application from source, follow these instructions.

### Prerequisites

*   Python 3.x
*   pip (Python package installer)
*   Git

### Installation

1.  **Clone the repository:**
    ```bash
    git clone https://github.com/Creamcollar/autosar-arxml-codegen.git
    ```
2.  **Navigate to the project directory:**
    ```bash
    cd autosar-arxml-codegen
    ```
3.  **Create an env**
    ```bash
    python -m venv venv
    # On Unix/Linux/macOS:
    source venv/bin/activate
    
    # On Windows Command Prompt:
    venv\Scripts\activate
    ```

5.  **Install the required dependencies:**
    ```bash
    pip install -r requirements.txt
    ```

### Running the Application from Source

```bash
python main.py
```

## License
This project is licensed under the GNU General Public License v3.0 (GPL-3.0)

You are free to use, study, modify, and redistribute this software,
provided that any redistributed or modified versions are released
under the same license.

See the [LICENSE](LICENSE) file for full details.

## Mentorship & Guidance:
- [Jegan Amirthalingam](https://www.linkedin.com/in/jegan-amirthalingam-44734738/) - for technical guidance and review

## Developers

*   **Aruvi B** - *Junior SDV Consultant* - [LinkedIn](https://linkedin.com/in/aruvib)
*   **Auroshaa A** - *Junior SDV Consultant – Cybersecurity* - [LinkedIn](https://www.linkedin.com/in/auroshaa-a-11587a294/)

This project is brought to you by [CreamCollar](https://www.creamcollar.com/).











