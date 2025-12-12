# OpenArchitectCore

**OpenArchitectCore** is the central runtime and UI container for a modular system designed to connect multiple sensors and actuators. It provides a foundation where independently developed modules can be integrated seamlessly into a unified interface.

The project follows an open, extensible architecture allowing multiple contributors to develop modules without interfering with each other's code.

---

## Key Features

### Modular Plugin System

* Load modules at runtime via Qt plugin interfaces.
* Clear separation between the Core UI and external modules.
* Each developer can deliver UI components as independent QML/Qt plugins.

### Unified UI Container

* Hosts user-facing panels inside a managed QML workspace.
* Provides shared UI components, theming, window management, and layout policies.
* Ensures consistent user experience across all modules.

### QML-Driven Component Integration

* Modules provide QML UI panels dynamically loaded by the Core.
* Core manages engine, lifecycle, and context bindings shared across modules.

### Open Architecture Principles

* Decouples modules from the underlying platform.
* Enables collaboration without exposing unnecessary internal code.

---

## Repository Structure

```
.
├── bin/
│   ├── OpenArchitectCore         # Compiled executable
│   └── Plugins/
│       └── libSensor1Plugin.so   # Built plugin libraries
├── Core/
│   ├── coreui.qrc
│   ├── main.cpp
│   ├── OpenArchitectCore.pro
│   ├── qml/
│   │   └── MainWindow.qml       # Core UI
│   ├── TacticalPluginInterface.hpp
│   └── UIEngine.hpp
├── OpenArchitect.pro             # Top-level qmake project
├── OpenArchitect.pro.user
└── Plugins/
    ├── build/
    │   └── Debug/               # Plugin build output
    ├── Interfaces/
    │   └── TacticalPluginInterface.hpp
    └── Sensor1Plugin/
        ├── qml/
        │   └── Sensor1Panel.qml
        ├── Sensor1Plugin.cpp
        ├── Sensor1Plugin.hpp
        ├── Sensor1Plugin.pro
        ├── sensor1.qrc
        └── TacticalPluginInterface.hpp
```

---

## Plugin Architecture Overview

OpenArchitectCore uses a **strict plugin contract**, allowing third-party modules to work without altering the Core.

**Each plugin must provide:**

* A C++ class implementing the defined interface (e.g., `TacticalPluginInterface`).
* A QML panel exported to the Core via `createComponent()`.
* Optional data-binding or command APIs exposed to the shared context.

**Core responsibilities:**

* Load plugin metadata.
* Instantiate QML components.
* Inject shared services (logging, message bus, theming, security).
* Manage panel lifecycle.

---

## Building

**Requirements:**

* Qt 5.14+ or Qt 6.x
* qmake
* C++17 toolchain

**Steps:**

```bash
git clone https://github.com/<your-account>/OpenArchitectCore.git
cd OpenArchitectCore/Core
qmake
make -j4
```

The executable will automatically load any compliant plugins found in:

```
<repository>/bin/Plugins/
```

---

## Developing a Plugin

1. Create a new folder under `Plugins/` for your module (e.g., `Sensor1Plugin`).
2. Include Core-provided interface headers (e.g., `TacticalPluginInterface.hpp`).
3. Implement the required C++ plugin class.
4. Provide a QML panel (e.g., `Sensor1Panel.qml`).
5. Export the plugin using Qt’s plugin macros.
6. Build the plugin and copy the resulting `.so`/`.dll` to `bin/Plugins/`.

**Example: Loading a Plugin Panel in C++**

```cpp
auto plugin = loader.load("Sensor1Plugin");
QQuickItem* panel = plugin->createComponent(engine, parentItem);

```

---

## License

MIT License unless otherwise specified by your organization.

---

## Roadmap

* Standardized message bus API for inter-module communication.
* Theming and style framework for a unified UI.
* Runtime capability discovery and dynamic panel placement.
* Optional web-based interface using QML/Qt for WebAssembly.

---

## Contact

For questions, contributions, or integration assistance, open an Issue or Pull Request.
